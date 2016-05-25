/** @file transmitterclient.h
    @brief Файл содержит описание класса TransmitterClient.
    @details
    @author Васильев С.В.
    @version 1.0.0
    @date февраль 2016 г.
*/
#ifndef TRANSMITTERCLIENT_H
#define TRANSMITTERCLIENT_H

#include <QObject>
#include <memory>

class IpcNode;

/** @brief Класс предназначен для взаимодействия с процессом-сервером, предоставляющим определенный сервис.
    @details
*/
class TransmitterClient : public QObject
{
    Q_OBJECT
public:
    /** @brief Конструктор
        @param serverName имя процесса-сервера, для подключения к которому создается клиент
        @param parent родитель
    */
    explicit TransmitterClient(const QString& serverName, QObject *parent = 0);


    /** @brief Функция запуска клиента (соединение с процессом-сервером)
    */
    void start();

    /** @brief Функция подписки/отписки на сообщения процесса-сервера
        @param descriptor дескриптор сообщения, на которое осуществляется подписка/отписка
        @param subscription флаг выполнения подписки/отписки (true - подписка, false - отписка)
    */
    void subscribe(quint64 descriptor, bool subscription = true);

    /** @brief Функция подписки/отписки на сообщения процесса-сервера
        @param descriptors перечень дескрипторов сообщений, на которые осуществляется подписка/отписка
        @param subscription флаг выполнения подписки/отписки (true - подписка, false - отписка)
    */
    void subscribe(QVector<quint64> descriptors, bool subscription = true);

public slots:
    /** @brief Функция передачи сообщения процессу-серверу
        @param descriptor дескриптор передаваемого сообщения
        @param data данные, передаваемые в сообщении
    */
    void transmitMessage(quint64 descriptor, const QByteArray& data);

signals:
    /** @brief Сигнал, возникающий при получении сообщения от процесса-сервера
        @param descriptor дескриптор полученного сообщения
        @param data данные, полученные в сообщении
    */
    void incomingMessage(quint64 descriptor, const QByteArray& data);

    /** @brief Сигнал, возникающий при изменении статуса соединения с процессом-сервером
        @param status флаг статуса соединения (true - соединение установлено, false - соединение разорвано)
    */
    void connectionStatus(bool status);

private:
    IpcNode* node_; //!< Указатель на объект, через который осуществляется взаимодействие с процессом сервером

private slots:
    /** @brief Слот, вызываемый при возникновении сигнала от объекта node_ при получении сообщения от процесса-сервера
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

#endif // TRANSMITTERCLIENT_H
