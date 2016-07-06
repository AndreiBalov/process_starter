/*!
* \file   module.h
* \brief  Файл содержит класс, реализующий хранение и доступ к типу и версии программного модуля
*/

#ifndef MODULE
#define MODULE

#include <QString>
#include "common.h"

class Module
{
public:
    /*!
     * \brief Конструктор с параметрами
     * \param moduleType - тип модуля, определяется разработчиком
     * \param version    - версия модуля
     */
    Module(PluginType  type = PLUGIN_NONE,
           const QString& version = "",
           const QString& name = "");
    ~Module(){}

    /*!
     * \brief Установить параметры модуля
     * \param moduleType - тип модуля
     * \param version    - версия модуля
     */
    void setModuleSpecification(PluginType  type,
                                const QString& version,
                                const QString& name);

    /*!
     * \brief Вернуть тип модуля
     * \return uint8_t тип модуля, классификация модулей этим классом не определяется
     */
    PluginType getModuleType() const;

    /*!
     * \brief Вернуть версию модуля
     * \return std::string версия модуля, формат строки "1.2.3.23456"
     */
    QString getModuleVersion() const;

    /**
     * @brief getModuleName
     * @return имя плагина
     */
    QString getModuleName() const;

private:
    PluginType  type_;    /*!< Тип плагина(порт, транспорт, БД,...) */
    QString version_; /*!< Версия ПО, формат "xx.xx.xx.xxxxx"  */
    QString name_;    /*!< Название модуля */
};
#endif // MODULE
