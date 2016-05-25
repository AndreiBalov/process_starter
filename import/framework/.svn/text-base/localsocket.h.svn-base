#ifndef LOCALSOCKET_H
#define LOCALSOCKET_H

#include "ipcnode.h"
#include <QLocalSocket>
#include <QString>
#include <QHash>

class SocketInterface;
class Loger;

/**
 * @brief The LocalSocket class
 * @detailed Клиентская часть для межпроцессного взаимодействия через QLocalSocket
 */
class LocalSocket : public IpcNode
{
    Q_OBJECT
public:
    /**
     * @brief LocalSocket
     * @param socketName
     * @param serverName
     * @param loger - указатель на класс, предоставляющий методы логирования работы
     * @param parent
     */
    explicit LocalSocket(const QString& serverName,
                               QObject *parent = nullptr,
                               SocketInterface* socket = nullptr);
    ~LocalSocket();

    /**
     * @brief nodeConnection
     */
    void nodeConnection() override;

public slots:
    /**
     * @brief transmitMessage
     * @param data
     * @return
     */
    bool transmitMessage(const QByteArray& data, quint32 receiverNode = 0) override;


protected:
    void timerEvent(QTimerEvent* event);

private slots:
    /**
     * @brief socketError - ошибки, выдаваемые сокетом
     */
    void socketError(QLocalSocket::LocalSocketError error);

    /**
     * @brief socketConnected - соединение с сервером установлено
     */
    void connectionEnable();

    /**
     * @brief connectionDisable - соединение с сервером разорвано
     */
    void connectionDisable();

    /**
     * @brief incomingData - пришли данные из сокета
     */
    void incomingData();


private:
    Loger* loger_ = nullptr;
    SocketInterface* socket_; /*!< интерфейс для работы с сокетом, который взаимодействует с сервером */
    QString serverName_;
    int reconnectTimer_; /*!< идентификатор таймера, запускаемого при разрыве соединения с сервером, для попыток переподключится*/
};

#endif // LOCALSOCKET_H
