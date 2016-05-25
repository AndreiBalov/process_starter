#ifndef CLEANEXIT_H
#define CLEANEXIT_H

#include <QtCore/QCoreApplication>
#include <QDebug>

class CleanExit:public QObject
{
    Q_OBJECT
public:
    explicit CleanExit(QObject* _parent = 0);
    static void exitQt(int _sig);
};

#endif // CLEANEXIT_H
