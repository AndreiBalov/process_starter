#ifndef SERVERDB_H
#define SERVERDB_H
#include "transmitterserver.h"
#include "tsubscriptionmanager.h"
#include "databaseinterface.h"

class ServerDB:public QObject
{
    Q_OBJECT
public:
    ServerDB(const QString& _serverName,\
             DatabaseInterface* _pDB,\
             QObject* _pParent);
    ~ServerDB();
    enum DB_MESSAGE_ID{CONNECT_TO_DB,\
                       DISCONNECT_FROM_DB,\
                       CHECK_CONNECTION_WITH_DB,\
                       CREATE_DB,\
                       DELETE_DB,\
                       DOES_DB_EXIST,\
                       CREATE_OBJECT_TYPE,\
                       CREATE_STRING_PROPERTY,\
                       CREATE_INT32_PROPERTY,\
                       CREATE_DOUBLE_PROPERTY,\
                       CREATE_OBJECT,\
                       DELETE_OBJECT,\
                       SET_INT32_VAL,\
                       SET_STRING_VAL,\
                       SET_DOUBLE_VAL,\
                       GET_OBJECT_VAL,\
                       DESCRIBE_ON_DATA,\
                       DENY_DESCRIPTION_ON_DATA,\
                       DESCRIBED_DATA};
private slots:
    void incomingMessageHandler(const quint64& _id,\
                                const QByteArray& _buff,\
                                const quint32& _node);
    void statusTransmitterServerHandler(quint32 _node, bool _status);
private:
    TransmitterServer* pSocket_;
    TSubscriptionManager<QByteArray>* pSubscription_;
    DatabaseInterface* pDB_;
    QString sendingErrString;
    bool sendResponse(const quint32& _node,\
                      ServerDB::DB_MESSAGE_ID _id,\
                      const bool& _response);
    bool sendValue(const quint32& _node,\
                   const QString& _dbName,\
                   const QString& _objectName,\
                   const QString& _propertyName,\
                   const QVariant& _propertyValue);
    bool sendDescribedData(const QString& _dbName,\
                           const QString& _objName,\
                           const QString& _propertyName,
                           const QVariant& _propertyValue);
};

#endif // SERVERDB_H
