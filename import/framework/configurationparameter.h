#ifndef CONFIGURATIONPARAMETER_H
#define CONFIGURATIONPARAMETER_H

#include <QString>

class ConfigurationParameter
{
public:
    enum ConfigurationParameterType {
        STRING_PARAMETER,
        PLUGIN_PARAMETER
    };

    ConfigurationParameter(const QString& name) : name_(name) {}

    virtual ~ConfigurationParameter() {};

    virtual QString name() const
    {
        return name_;
    }

    virtual ConfigurationParameterType type() const = 0;

protected:
    const QString name_;
};

#endif // CONFIGURATIONPARAMETER_H
