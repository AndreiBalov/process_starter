#include "abstractprocess.h"
#include "coreclient.h"
#include "xmlconfigurationreader.h"
#include "processconfiguration.h"
#include "getopt.h"
#include "configurationpluginparameter.h"
#include "plugininterface.h"
#include <QCoreApplication>
#include <QtGui/QApplication>

AbstractProcess::AbstractProcess(QMap<QString,QString>& arguments, QObject* parent) throw (std::invalid_argument) : QObject(parent)
{
    coreClient_ = nullptr;
    QString configName = (arguments.find("c")) != arguments.end() ? arguments["c"] : throw std::invalid_argument("can't find argument 'c'");
    if(arguments.size() == 3)
    {
        QString coreServerName = (arguments.find("s")) != arguments.end() ? arguments["s"] : throw std::invalid_argument("can't find argument 's'");
        processName_   = (arguments.find("n")) != arguments.end() ? arguments["n"] : throw std::invalid_argument("can't find argument 'n'");
        coreClient_    = new CoreClient(coreServerName, this);
    }
    configReader_ = std::unique_ptr<ConfigurationReader>(new XmlConfigurationReader(configName));
}

AbstractProcess::~AbstractProcess()
{

}

QHash<QString,QString> AbstractProcess::argumentsParse(const char* keys, int argc, char* argv[]) throw (InvalidKeyException,
                                                                                                       MultipleKeyException)
{
    QString keyStr(keys);
    QHash<QString,QString> parameters;
    int optResult = 0;
    while((optResult = getopt(argc, argv, keys)) != -1)
    {
        if(keyStr.contains(optResult))
        {
            // если такого аргумента еще нет
            if(parameters.find(QString(optResult)) == parameters.end())
            {
                parameters[QString(optResult)] = QString(optarg);
            }
            else
            {
                throw MultipleKeyException(QString(optResult).toStdString());
            }
        }
        else
        {
            throw InvalidKeyException(QString(optopt).toStdString());
        }
    }
    return parameters;
}

std::shared_ptr<ProcessConfiguration> AbstractProcess::configParse() throw (ConfigException)
{
    std::shared_ptr<ProcessConfiguration> config = configReader_->read();
    if (config)
    {
        return config;
    }
    else
    {
        throw ConfigException;
    }
}

PluginInterface* AbstractProcess::loadPlugin(const QString& file)
{
    QPluginLoader loader(file);
    QObject* object = loader.instance();
    if (!object)
        return nullptr;
    return qobject_cast<PluginInterface*>(object);
}

QString AbstractProcess::processtypeToStr(const ProcessType processType) const
{
    QString strType = "";
    switch (processType)
    {
        case PROCESS_CORE:
            strType = "core";
            break;
        case PROCESS_CHANNEL:
            strType = "channel";
            break;
        case PROCESS_TASK:
            strType = "task";
            break;
        case PROCESS_STORE:
            strType = "store";
            break;
        case PROCESS_GUI:
            strType = "gui";
            break;
        case PROCESS_NONE:
            strType = "unknown";
            break;
        default:
            strType = "unknown";
    }
    return strType;
}

void AbstractProcess::addInternalPluginsInfo(const PluginInterface& plugin) const
{
    QVector<PluginInterface*> internalPlugins = plugin.getInternalPlugins();
    for( const auto plugin : internalPlugins)
    {
        QString moduleName = plugin->getModuleName();
        QString moduleType = QString::number(plugin->getModuleType());
        QString moduleVersion = plugin->getModuleVersion();
        if(coreClient_)
            coreClient_->addPluginInfo(moduleName, moduleType, moduleVersion, "");
    }
}

int AbstractProcess::init(int argc, char* argv[]) throw (PluginLoadException,
                                                         PluginInitException)
{
    std::shared_ptr<ProcessConfiguration> config = configParse();
    ProcessType processType = config->getProcessType();

    QCoreApplication* app = nullptr;
    if (processType == PROCESS_GUI)
        app = new QApplication(argc, argv);
    else
        app = new QCoreApplication(argc, argv);
    QTextCodec* codec = QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    std::shared_ptr<ConfigurationPluginParameter> pluginParameter = config->getPluginParameter();
    auto plugin = loadPlugin(pluginParameter->getFileName());

    if (!plugin)
        throw PluginLoadException(pluginParameter->getFileName().toStdString());

    if (plugin->init(pluginParameter->getPluginConfiguration()) != 0)
        throw PluginInitException(plugin->getModuleName().toStdString());
    if(coreClient_)
    {
        coreClient_->setModuleInfo(processName_, processtypeToStr(processType), VERSION);
        coreClient_->addPluginInfo(plugin->getModuleName(), QString::number(plugin->getModuleType()), plugin->getModuleVersion(), pluginParameter->getVersion());
        addInternalPluginsInfo(*plugin);
        coreClient_->start();
    }

    return app->exec();
}


