#include "abstractprocess.h"

#include "configurationpluginparameter.h"
#include "processconfiguration.h"

#include <QCoreApplication>
#include <QtGui/QApplication>

#include "getopt.h"

AbstractProcess::AbstractProcess(QMap<QString,QString>& arguments, QObject* parent) throw (std::invalid_argument)
    : QObject(parent)
{
    // обязательный аргумент с файлом конфигурации
    QString configName = (arguments.find("c")) != arguments.end() ? arguments["c"] : throw std::invalid_argument("can't find argument 'c'");
    configReader_ = std::unique_ptr<ConfigurationReader>(new XmlConfigurationReader(configName));
    // аргументы, необходимые только в режиме запуска через coreprocess
    if(arguments.size() == 3)
    {
        processName_           = (arguments.find("n")) != arguments.end() ? arguments["n"] : throw std::invalid_argument("can't find argument 'n'");
        QString coreServerName = (arguments.find("s")) != arguments.end() ? arguments["s"] : throw std::invalid_argument("can't find argument 's'");
        coreClient_            = std::unique_ptr<CoreClient>(new CoreClient(coreServerName));
    }
}

QMap<QString,QString> AbstractProcess::argumentsParse(const char* keys, int argc, char* argv[]) throw (InvalidKeyException,
                                                                                                       MultipleKeyException)
{
    QString keyStr(keys);
    QMap<QString,QString> parameters;
    int optResult = 0;
    while((optResult = getopt(argc, argv, keys)) != -1)
    {
        if(keyStr.contains(optResult))
        {
            // если такого аргумента еще нет
            if(parameters.find(QString(optResult)) == parameters.end())
            {
                parameters.insert(QString(optResult), QString(optarg));
            }
            else
            {
                throw MultipleKeyException("Multiple key argument \"" + QString(optResult).toStdString()
                                            + "\". Use arguments in one instance!");
            }
        }
        else
        {
            throw InvalidKeyException("Invalid key \"" + QString(optopt).toStdString()
                                       + "\" Use keys -n -s -c !");
        }
    }
    return parameters;
}

int AbstractProcess::init(int argc, char* argv[]) throw (ProcessException)
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
    plugin_ = std::unique_ptr<PluginInterface>(loadPlugin(pluginParameter->getFileName()));
    if (!plugin_)
        throw ProcessException("Can't create plugin " + pluginParameter->getFileName().toStdString());

    if (plugin_->init(pluginParameter->getPluginConfiguration()) != 0)
        throw ProcessException("Can't init plugin " + plugin_->getModuleName().toStdString());
    if(coreClient_)
    {
        coreClient_->setModuleInfo(processName_, processtypeToStr(processType), VERSION);
        coreClient_->addPluginInfo(plugin_->getModuleName(), QString::number(plugin_->getModuleType()), plugin_->getModuleVersion(), pluginParameter->getVersion());
        addInternalPluginsInfo(*plugin_);
        coreClient_->start();
    }
    return app->exec();
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
        throw ConfigException("Can't read config file!");
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
    QString strType = "unknown";
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
    }
    return strType;
}

void AbstractProcess::addInternalPluginsInfo(const PluginInterface& plugin) const
{
    auto internalPlugins = plugin.getInternalPlugins();
    for(const auto plugin : internalPlugins)
    {
        QString moduleName    = plugin->getModuleName();
        QString moduleType    = QString::number(plugin->getModuleType());
        QString moduleVersion = plugin->getModuleVersion();
        if(coreClient_)
            coreClient_->addPluginInfo(moduleName, moduleType, moduleVersion, "");
    }
}
