#ifndef CONFIGURATIONGROUPPARAMETER_H
#define CONFIGURATIONGROUPPARAMETER_H

#include <QVector>
#include <memory>
#include "configurationparameter.h"
#include "pluginconfiguration.h"

class ConfigurationPluginParameter : public ConfigurationParameter
{
public:
    ConfigurationPluginParameter(const QString& name);
    ~ConfigurationPluginParameter();

    ConfigurationParameter::ConfigurationParameterType type() const override;

    void setFileName(const QString& fileName);

    QString getFileName() const;

    void setVersion(const QString& version);

    QString getVersion() const;

    bool addParameter(std::shared_ptr<ConfigurationParameter> parameter);

    std::shared_ptr<ConfigurationParameter> getParameter(const QString& name) const;

    QVector<std::shared_ptr<ConfigurationParameter>> getAllParameters() const;

    PluginConfiguration getPluginConfiguration() const;

private:
    QVector<std::shared_ptr<ConfigurationParameter>> parameters_;
    QString fileName_;
    QString version_;
};

#endif // CONFIGURATIONGROUPPARAMETER_H
