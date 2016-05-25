#ifndef CONFIGURATIONSINGLEPARAMETER_H
#define CONFIGURATIONSINGLEPARAMETER_H

#include <QString>
#include "configurationparameter.h"

class ConfigurationStringParameter : public ConfigurationParameter
{
public:
    ConfigurationStringParameter(const QString& name, const QString& value);
    ~ConfigurationStringParameter();

    ConfigurationParameter::ConfigurationParameterType type() const override;

    QString value() const;

private:
    const QString value_;
};

#endif // CONFIGURATIONSINGLEPARAMETER_H
