#ifndef IPCNODE_H
#define IPCNODE_H

#include <QObject>
#include <QByteArray>
#include <memory>

/**
 * @brief The IpcNode class
 * @detailed Интерфейсный класс для межпроцессного взаимодействия
 */
class IpcNode : public QObject
{
    Q_OBJECT
public:
    explicit IpcNode(QObject *parent = nullptr);
    virtual ~IpcNode();

    /**
     * @brief nodeConnection - выполнить соединение с другим процессом
     * @param receiver
     */
    virtual void nodeConnection() = 0;

public slots:
    /**
     * @brief transmitMessage функция передачи сообщения по ipc
     * @param data - ссылка на данные
     * @param receiverNode - если ipcNode не один(сервер), то нужно указать какому получателю отправить
     * @return
     */
    virtual bool transmitMessage(const QByteArray& data, quint32 receiverNode = 0) = 0;

signals:
    /**
     * @brief incomingMessage - входящие данные от другого процесса
     * @param data - указатель на данные
     * @param source - дескриптор сокета, от которого пришло сообщение
     */
    void incomingMessage(std::shared_ptr<QByteArray> data, quint32 sourceNode);

    /**
     * @brief nodeStatus
     * @param nodeId идентификатор подключённого узла
     */
    void nodeStatus(quint32 nodeId, bool state);
};

#endif // IPCNODE_H
