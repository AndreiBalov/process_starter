/** @file xmlconfigurationreader.h
    @brief Файл содержит описание класса XmlConfigurationReader.
    @details
    @version 1.0.0
    @date февраль 2016 г.
*/
#ifndef XMLCONFIGURATIONREADER_H
#define XMLCONFIGURATIONREADER_H

#include <QString>
#include <memory>
#include <QtXml>
#include "configurationreader.h"
#include "common.h"

class QFile;
class ProcessConfiguration;
class ConfigurationPluginParameter;

/** @brief Kласс, реализующий чтение конфигурации процесса из xml-файла
    @details
*/
class XmlConfigurationReader : public ConfigurationReader
{
public:
    /** @brief Конструктор
        @param fileName имя xml-файла, содержащего конфигурацию процесса
    */
    XmlConfigurationReader(const QString& fileName);

    ~XmlConfigurationReader();

    /** @brief Функция чтения конфигурации процесса.
        @return указатель на объект ProcessConfiguration, содержащий считанную конфигурацию процесса
    */
    std::shared_ptr<ProcessConfiguration> read();

private:
    QString fileName_; //!< имя xml-файла конфигурации процесса

    /** @brief Функция, выполняющая разбор xml-файла конфигурации и сохранение считанной информации в объекте ProcessConfiguration
        @return указатель на объект ProcessConfiguration, содержащий считанную конфигурацию процесса
    */
    std::shared_ptr<ProcessConfiguration> parse(QFile* file);

    bool parsePluginSection(QDomNode& levelNode, std::shared_ptr<ConfigurationPluginParameter>& pluginParameter);

    ProcessType strToProcesstype(const QString& str) const;
};

#endif // XMLCONFIGURATIONREADER_H
