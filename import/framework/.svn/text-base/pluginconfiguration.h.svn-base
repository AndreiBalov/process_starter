#ifndef PLUGINCONFIGURATION_H
#define PLUGINCONFIGURATION_H

#include <memory>
#include <QString>
#include <QVector>

class ConfigurationParameter;

class PluginConfiguration
{
public:
    PluginConfiguration();
    bool addParameter(std::shared_ptr<ConfigurationParameter> parameter);
    std::shared_ptr<ConfigurationParameter> getParameter(const QString& name) const;

private:
    QVector<std::shared_ptr<ConfigurationParameter>> parameters_;
};

#endif // PLUGINCONFIGURATION_H
