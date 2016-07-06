/** @file processconfiguration.h
    @brief Файл содержит описание класса ProcessConfiguration.
    @details
    @version 1.0.0
    @date февраль 2016 г.
*/
#ifndef PROCESSCONFIGURATION_H
#define PROCESSCONFIGURATION_H

#include <QMap>
#include <QString>
#include <memory>
#include "common.h"

class ConfigurationPluginParameter;

/** @brief Класс, предназначенный для хранения считанной конфигурации процесса
    @details
*/
class ProcessConfiguration
{
public:
    ProcessConfiguration();

    void setProcessType(const ProcessType processType);

    ProcessType getProcessType() const;

    void addParameter(const QString& name, const QString& value);

    QString getParameterValue(const QString& name) const;

    void setPluginParameter(std::shared_ptr<ConfigurationPluginParameter> parameter);

    std::shared_ptr<ConfigurationPluginParameter> getPluginParameter() const;

private:
    QMap<QString, QString> processParameters_;
    std::shared_ptr<ConfigurationPluginParameter> pluginParameter_;

    ProcessType processType_;
};

#endif // PROCESSCONFIGURATION_H
