#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <memory>
#include "common.h"

//class ConfigurationParameter;
class PluginConfiguration;

/**
 * @brief The PluginInterface class
 * @detailed Класс интерфейса для всех плагинов
 */
class PluginInterface
{
public:
    virtual ~PluginInterface(){}

    //virtual quint8 init(QVector<std::shared_ptr<ConfigurationParameter>> parameters) = 0;
    virtual quint8 init(const PluginConfiguration& configuration) = 0;

    /** @brief Функция получения типа модуля расширения
        @return тип модуля
    */
    virtual PluginType getModuleType() const = 0;

    /** @brief Функция получения версии модуля расширения
        @return версию модуля расширения
    */
    virtual QString getModuleVersion() const = 0;

    /**
     * @brief getModuleName
     * @return имя плагина
     */
    virtual QString getModuleName() const = 0;

    virtual QVector<PluginInterface*> getInternalPlugins() const = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "com.burevestnik.framework.PluginInterface/1.0")
#endif // PLUGININTERFACE_H




