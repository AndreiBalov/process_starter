#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <ipcnode.h>
#include <QLocalServer>
#include <QLocalSocket>
#include <QString>
#include <QHash>
#include <memory>
#include <QThread>
class ServerInterface;
class SocketInterface;
class QSharedMemory;

/**
 * @brief The LocalServer class
 * @detailed реализация серверной части QLocalSocket
 */
class LocalServer : public IpcNode
{
    Q_OBJECT
public:
    LocalServer(const QString& serverName, QObject* parent = 0, ServerInterface* server = 0);
    ~LocalServer();

    /**
     * @brief nodeConnection
     * @detailed Поставить сервер на прослушку
     */
    void nodeConnection() override;

public slots:
    /**
     * @brief transmitMessage
     * @detailed Передать данные в сокет
     * @param data - данные
     * @param receiverNode - номер сокета
     * @return результат выполнения
     */
    bool transmitMessage(const QByteArray& data, quint32 receiverNode = 0) override;

private slots:
    /**
     * @brief incomingConnection
     * @detailed новое входящее соединение
     */
    void incomingConnection();

    /**
     * @brief socketError
     * @detailed Слот, в котором обрабатываются ошибки сокетов
     */
    void socketError(QLocalSocket::LocalSocketError);

    /**
     * @brief readIncomingData
     * @detailed Слот, вызываемый при получении данных из сокетов
     */
    void readIncomingData();

private:
    QString serverName_;                       /*!< название сервера */
    ServerInterface* server_;                  /*!< указатель на объект сервера */
    QHash<quint32,SocketInterface*> sockets_;  /*!< соответсвие дескриптора и сокета для передачи/приёма */
    QHash<quintptr, quint32> receiveMessSize_; /*!< размер входящих сообщений от разных клиентов */
    std::shared_ptr<QSharedMemory> shareMemory;
};

#endif // LOCKALSERVER_H
