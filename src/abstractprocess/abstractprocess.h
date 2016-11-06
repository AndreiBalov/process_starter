#ifndef ABSTRACTPROCESS_H
#define ABSTRACTPROCESS_H

#include <QObject>
#include <QHash>
#include <memory>
#include "processexceptions.h"
#include "common.h"

class CoreClient;
class ConfigurationReader;
class PluginInterface;
class PluginSetting;
class PluginParameter;
class ProcessConfiguration;

/**
 * @brief The AbstractProcess class
 * @defined Класс процеса, расширяемого плагинами
 */
class AbstractProcess : public QObject
{
    Q_OBJECT
public:
    explicit AbstractProcess(QMap<QString,QString>& arguments, QObject* parent = 0) throw (std::invalid_argument);
    ~AbstractProcess();

    /**
     * @brief processConfig
     * @detailed Разбор файла конфигурации, создание плагинов, передача данных версий процесса и плагинов в ядро
     * и настройка объектов межпроцессного взаимодействия, указанных в файле конфигурации
     */
    int init(int argc, char* argv[]) throw (PluginInitException,
                                            PluginLoadException);

    /**
     * @brief argumentsParse - разбор строки с аргументами процессов
     * @param keys - строка с ключами
     * @param argc - количество аргументов
     * @param argv - массив строк
     * @return map с ключами и его значениями
     */
    static QHash<QString,QString> argumentsParse(const char* keys, int argc, char* argv[]) throw (InvalidKeyException,
                                                                                                 MultipleKeyException);
private:
    /**
     * @brief configParse считать файл конфигурации
     * @return указатель на описатель процесса
     */
    std::shared_ptr<ProcessConfiguration> configParse() throw (ConfigException);

    /**
     * @brief loadPlugin - загрузка плагина
     * @param file - имя файла(вместе с путём)
     * @return указатель на PluginInterface
     */
    PluginInterface* loadPlugin(const QString& file);

    /**
     * @brief processtypeToStr Преобразование типа процесса в строку
     * @param processType тип процесса
     * @return строчное представление
     */
    QString processtypeToStr(const ProcessType processType) const;

    /**
     * @brief addInternalPluginsInfo Добавить данные по встроенным плагинам для ядра
     * @param plugin ссылка на объект плагина
     */
    void addInternalPluginsInfo(const PluginInterface& plugin) const;

private:
    QHash<QString,QString>  processArguments_; /*!< аргументы процесса */
    QString                 processName_;      /*!< имя процесса, назначенное ядром */
    CoreClient*             coreClient_                = nullptr; /*!< IPC клиент для связи с ядром */
    std::unique_ptr<ConfigurationReader> configReader_ = nullptr; /*!< для чтения файла конфигурации */
};

#endif // ABSTRACTPROCESS_H
