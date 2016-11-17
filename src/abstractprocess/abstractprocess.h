#ifndef ABSTRACTPROCESS_H
#define ABSTRACTPROCESS_H

#include "coreclient.h"
#include "xmlconfigurationreader.h"
#include "plugininterface.h"
#include "processexceptions.h"
#include "common.h"

#include <QObject>
#include <QMap>
#include <memory>

class PluginSetting;
class PluginParameter;
class ProcessConfiguration;

/**
 * @brief The AbstractProcess class
 * @defined Класс процеса, расширяемого плагинами
 * Получает данные из файла конфигурации и создаёт объект плагина,
 * который будет выполнятся в этом процессе
 */
class AbstractProcess : public QObject
{
    Q_OBJECT
public:
    explicit AbstractProcess(QMap<QString,QString>& arguments, QObject* parent = 0) throw (std::invalid_argument);

    /**
     * @brief processConfig
     * @detailed Разбор файла конфигурации, создание плагинов, передача данных версий процесса и плагинов в ядро
     * и настройка объектов межпроцессного взаимодействия, указанных в файле конфигурации
     */
    int init(int argc, char* argv[]) throw (ProcessException);

    /**
     * @brief argumentsParse - разбор строки с аргументами процессов
     * @param keys - строка с ключами
     * @param argc - количество аргументов
     * @param argv - массив строк
     * @return map с ключами и его значениями
     */
    static QMap<QString,QString> argumentsParse(const char* keys, int argc, char* argv[]) throw (InvalidKeyException,
                                                                                                 MultipleKeyException);
private:
    /**
     * @brief configParse считать файл конфигурации
     * @return указатель на структуру описания процесса
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
     * @return строчное стредставление
     */
    QString processtypeToStr(const ProcessType processType) const;

    /**
     * @brief addInternalPluginsInfo Добавить данные по встроенным плагинам для ядра
     * @param plugin
     */
    void addInternalPluginsInfo(const PluginInterface& plugin) const;

private:
    QString                              processName_;            //!< имя процесса, назначенного ядром
    std::unique_ptr<CoreClient>          coreClient_   = nullptr; //!< IPC клиент для связи с ядром
    std::unique_ptr<ConfigurationReader> configReader_ = nullptr; //!< объект чтения файла конфигурации
    std::unique_ptr<PluginInterface>     plugin_       = nullptr; //!< загруженный плагин
};

#endif // ABSTRACTPROCESS_H
