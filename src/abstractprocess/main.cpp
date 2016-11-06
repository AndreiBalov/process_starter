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
        qDebug() << QString::fromStdString(a.what());
        exit(EXIT_FAILURE);
    }
    catch(...)
    {
        qDebug() << "Undefined exception";
        exit(EXIT_FAILURE);
    }
}
