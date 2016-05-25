/** @file tra
 * nsmitterserver.h
    @brief Файл содержит описание класса TransmitterServer.
    @details
    @author Васильев С.В.
    @version 1.0.0
    @date февраль 2016 г.
*/
#ifndef TRANSMITTERSERVER_H
#define TRANSMITTERSERVER_H

#include <QObject>
#include <memory>

class IpcNode;
class SubscriptionManager;

/** @brief Класс предназначен для взаимодействия с процессами-клиентами, подписаными на сообщения данного сервиса.
    @details
*/
class TransmitterServer : public QObject
{
    Q_OBJECT
public:
    /** @brief Конструктор
        @param serverName имя процесса-сервера
        @param parent родитель
    */
    explicit TransmitterServer(const QString& serverName, QObject *parent = 0);

    ~TransmitterServer();

    /** @brief Функция запуска взаимодействия с процессами-клиентами
    */
    void start();

public slots:
    /** @brief Функция передачи сообщения процессам-клиентам с использованием механизма подписки.
        @param descriptor дескриптор передаваемого сообщения
        @param data данные, передаваемые в сообщении
    */
    void transmitMessage(quint64 descriptor, const QByteArray& data);

    /** @brief Функция передачи сообщения указанному процессу-клиенту (не использует механизм подписки).
        @param descriptor дескриптор передаваемого сообщения
        @param data данные, передаваемые в сообщении
        @param destinationNode идентификатор узла-получателя сообщения
        @return true если сообщение успешно отправлено, false - в противном случае
    */
    bool transmitMessage(quint64 descriptor, const QByteArray& data, quint32 destinationNode);

signals:
    /** @brief Сигнал, возникающий при получении сообщения от процесса-клиента
        @param descriptor дескриптор полученного сообщения
        @param data данные, полученные в сообщении
    */
    void incomingMessage(quint64 descriptor, const QByteArray& data, quint32 sourceNode);

    /** @brief Сигнал, возникающий при изменении статуса соединения с процессом-клиентом
        @param node идентификатор процесса-клиента
        @param status флаг статуса соединения (true - соединение установлено, false - соединение разорвано)
    */
    void connectionStatus(quint32 node, bool status);

private:
    //указатель на объект класса, реализующий работу по подписке процессов-клиентов на сообщения
    SubscriptionManager* subscriptionManager_;

    //указатель на объект, через который осуществляется взаимодействие с процессами-клиентами
    IpcNode* node_;

    /** @brief Функция обработки полученного сообщения с данными
        @param data данные сообщения
    */
    void dataProcessing(QByteArray& data, quint32 sourceNode);

    /** @brief Функция обработки полученного сообщения подписки
        @param data данные сообщения
        @param sourceNode идентификатор процесса-клиента, от которого получено сообщение
        @param subscription флаг подписки/отписки (true - подписка, false - отписка)
    */
    void subscriptionProcessing(QByteArray& data, quint32 sourceNode, bool subscription);

private slots:
    /** @brief Слот, вызываемый при возникновении сигнала от объекта node_ при получении сообщения от процесса-клиента
        @param data данные, полученные в сообщении
        @param sourceNode не используется
    */
    void nodeIncomingMessage(std::shared_ptr<QByteArray> data, quint32 sourceNode);

    /** @brief Слот, вызываемый при возникновении сигнала от объекта node_ при изменении статуса соединения
        @param node идентификатор узла
        @param status флаг статуса соединения (true - соединение установлено, false - соединение разорвано)
    */
    void nodeStatus(quint32 node, bool status);
};

#endif // TRANSMITTERSERVER_H
