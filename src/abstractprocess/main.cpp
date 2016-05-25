#include <QDebug>
#include <stdexcept>
#include "cleanexit.h"
#include "abstractprocess.h"

const char* optstr = "n:s:c:";

int main(int argc, char *argv[])
{
    CleanExit cleanexit;

    try
    {
        QMap<QString,QString> parameters = AbstractProcess::argumentsParse(optstr, argc, argv);
        AbstractProcess process(parameters);
        return process.init(argc, argv);
    }

    catch(std::exception& a)
    {
        std::string str = a.what();
        qDebug() << QString::fromStdString(str);
        exit(EXIT_FAILURE);
    }
    catch(...)
    {
        qDebug() << "Undefined exception";
        exit(EXIT_FAILURE);
    }


    // Процессу можно передать один параметр(файл конфигурации), тогда процесс не будет подключатся к серверу
    // или нужно передавать все 3
    // + 1 передаётся по умолчанию, это имя процесса
    //if(1/*argc == 4 || argc == 2*/)
   // {
    //}
   // else
    //{
    //    qDebug() << "Invalid parameters count. Need -n Name -s coreServerName -c config file OR ONLY -cconfig";
    //    exit(EXIT_FAILURE);
   // }
}
