#ifndef CORECLIENT_H
#define CORECLIENT_H

#include <QtCore>
#include "transmitterclient.h"

class CoreClient : public QObject
{
    Q_OBJECT
public:
    explicit CoreClient(QString _serverName, QObject *pParent = 0);
    ~CoreClient();
    void setModuleInfo(QString _name, QString _moduleType, \
                       QString _currentModuleVersion);
    void addPluginInfo(QString _name, QString _moduleType,\
                       QString _currentModuleVersion,\
                       QString _fileModuleVersion);
    enum ErrorInfoId{NO_MODULE_INFO,\
                     INVALID_DESCRIPTOR};
    void start() {pClient_->start();}
private:
    QString serverName_;
    TransmitterClient* pClient_;
    QString moduleInfo_;
    QString pluginInfo_;
    QString makeMessage();
    void sendModuleInfo();
signals:
    void error(ErrorInfoId _id);
private slots:
    void getMessage(quint64, QByteArray);
    void printStatus(bool);
};

#endif // CORECLIENT_H
