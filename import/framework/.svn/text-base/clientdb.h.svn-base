#ifndef CLIENTDB_H
#define CLIENTDB_H
#include <QVariant>
#include <QSemaphore>
#include <QSharedPointer>
#include <QTimer>
#include <QThread>

#include "transmitterclient.h"

class ClientDB:public QObject
{
    Q_OBJECT
    QThread timerThread;
    int timerId_;
    TransmitterClient* pSocket_;
    QSemaphore reqSem_;
    bool serverConnectionStatus_;
    bool responseStatus_;
    bool operationStatus_;
    QVariant requestedVal_;
    QTimer* pWaitingTimer_;
    int interval;

    bool waitResponse();
public:
    ClientDB(QString _serverName = "serverDB", QObject* _pParent = 0);
    bool isServerConnectionValid();
    void setInterval(int _msec){interval = _msec;}
    int getInerval(){return interval;}

    void connectToDB(QString _dbName);
    void disconnectFromDB(QString _dbName);
    void checkConnectionWithDB(QString _dbName);
    void createDB(QString _dbName);
    void deleteDB(QString _dbName);
    void doesDBexist(QString _dbName);
    void createObjectType(QString _dbName,\
                          QString _typeName,\
                          QString _fullTypeName,\
                          QString _parentTypeName);
    void createProperty(QString _dbName,\
                        QString _typeName,\
                        QString _propName,\
                        QString _fullPropertyName,\
                        QString _initVal);
    void createProperty(QString _dbName,\
                        QString _typeName,\
                        QString _propName,\
                        QString _fullPropertyName,\
                        qint32 _initVal);
    void createProperty(QString _dbName,\
                        QString _typeName,\
                        QString _propertyName,\
                        QString _fullPropertyName,\
                        double _initVal);
    void createObject(QString _dbName,\
                      QString _typeName,
                      QString _objName);
    void deleteObject(QString _dbName,\
                      QString _objName);
    void setValue(QString _dbName,\
                  QString _objName,\
                  QString _propertyName,\
                  qint32 _propertyValue);
    void setValue(QString _dbName,\
                  QString _objName,\
                  QString _propertyName,\
                  QString _propertyValue);
    void setValue(QString _dbName,\
                  QString _objName,\
                  QString _propertyName,\
                  double _propertyValue);
    void describeOnData(QString _dbName, QString _objName, QString _propName);
    void denyDescriptionOnData(QString _dbName,\
                               QString _objName,\
                               QString _propName);
    void getPropertyValue(QString _dbName,\
                              QString _objName,\
                              QString _propName);

    enum CLIENT_DB_ERROR{INVALID_MESSAGE_ID, WAITING_TIME_IS_UP};
private slots:
    void statusHandler(bool);
    void incomingMessageHandler(quint64, QByteArray);
    void breakWaiting();
signals:
    void error(CLIENT_DB_ERROR);
    void connectedToDB(bool _status);
    void describedData(QString, QString, QString, QVariant);
    void getData(QString _dbName, QString _objName, QString _propVal,\
                 QVariant _val);
};

#endif // CLIENTDB_H
