#ifndef TRANSMITER_H
#define TRANSMITER_H

#include <QByteArray>
#include <QObject>
#include <memory>

/**
 * @brief The IpcCommunicator class
 * @detailed Класс, предоставляющий функционал передачи данных между процессами
 */
class Transmiter : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief IpcCommunicator
     * @param serverName - имя сервера, нужно как для клиента так и для сервера
     * @param parent
     */
    Transmiter(const QString& serverName, QObject* parent = 0) : serverName_(serverName), QObject(parent){}
    virtual ~Transmiter(){}

    /**
     * @brief initialization
     * @detailed выполнить инициализацию коммуникатора
     * @return 0/1 - выполнена или не выполнена инициализация
     */
    virtual bool initialization() = 0;

    /**
     * @brief serverName
     * @return
     */
    QString serverName() { return serverName_; }

public slots:
    /**
     * @brief transmitMessage
     * @detailed - в реализации необходимо скопировать данные
     * @param data - данные для передачи
     */
    virtual void transmitMessage(const QByteArray& data, quint32 receiveNode = 0) = 0;

private slots:
    /**
     * @brief receiveMessage - данные от ipcnode'ов
     * @param data
     * @param sourceNode
     */
    virtual void receiveMessage(std::shared_ptr<QByteArray> data, quint32 sourceNode = 0) = 0;

signals:
    /**
     * @brief sigReceivedMessage - входящее сообщение
     * @param data - shared ptr в котором передаются входящие данные
     * @param source - источник данных(идентификатор)
     */
    void sigReceivedMessage(std::shared_ptr<QByteArray> data, quint32 source);

private:
    QString serverName_;
};

#endif // TRANSMITER_H
