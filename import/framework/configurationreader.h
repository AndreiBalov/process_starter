/** @file configurationreader.h
    @brief Файл содержит описание класса ConfigurationReader.
    @details
    @author Васильев С.В.
    @version 1.0.0
    @date февраль 2016 г.
*/
#ifndef CONFIGURATIONREADER_H
#define CONFIGURATIONREADER_H

#include <memory>

class ProcessConfiguration;

/** @brief Абстрактный класс, определяющий интерфейс чтения конфигурации процесса
    @details
*/
class ConfigurationReader
{
public:
    virtual ~ConfigurationReader() {};

    /** @brief Функция чтения конфигурации плагинов.
        @return указатель на объект PluginsConfiguration, содержащий считанную конфигурацию плагинов
    */
    virtual std::shared_ptr<ProcessConfiguration> read() = 0;
};

#endif // CONFIGURATIONREADER_H
