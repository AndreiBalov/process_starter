#ifndef PROCESSEXCEPTIONS_H
#define PROCESSEXCEPTIONS_H

#include <stdexcept>

class ProcessException : public std::exception
{
public:
    ProcessException(const std::string& msg)
    {
        errorMessage = msg;
    }
    virtual ~ProcessException() noexcept {}

    const char* what() const noexcept
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};


class InvalidKeyException : public ProcessException
{
public:
    InvalidKeyException(const std::string& msg)
        : ProcessException(msg) {}

    virtual ~InvalidKeyException() noexcept {}

};

class MultipleKeyException : public ProcessException
{
public:
    MultipleKeyException(const std::string& msg)
        : ProcessException(msg) {}

    virtual ~MultipleKeyException() noexcept {}
};

class ConfigException : public ProcessException
{
public:
    ConfigException(const std::string& msg)
        : ProcessException(msg) {}

    virtual ~ConfigException() noexcept {}
};

class PluginLoadException : public ProcessException
{
public:
    PluginLoadException(const std::string& msg)
        : ProcessException(msg) {}

    virtual ~PluginLoadException() noexcept {}
};

class PluginInitException : public ProcessException
{
public:
    PluginInitException(const std::string& msg)
        : ProcessException(msg) {}

    virtual ~PluginInitException() noexcept {}
};

#endif // PROCESSEXCEPTIONS_H
