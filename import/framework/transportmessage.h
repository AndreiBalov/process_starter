/** @file transportmessage.h
    @brief Файл содержит описание класса TransportMessage.
    @details
	@author Васильев С.В.
	@version 1.0.0
	@date декабрь 2015 г.
*/
#ifndef TRANSPORTMESSAGE_H
#define TRANSPORTMESSAGE_H

#include <QByteArray>
#include <QMetaType>
#include <QHash>
#include <memory>

/** @brief Транспортное сообщение для всех протоколов
    @details
*/
class TransportMessage
{
public:
   // TransportMessage(): source_(0), receiver {}
    /**
     * @brief TransportMessage - для сборки сообщения,
     * @param source
     * @param receiver
     * @param descr
     * @param data
     * @param parameters
     */
    TransportMessage( quint32 source = 0,
                      quint32 receiver = 0,
                      quint32 descr = 0,
                      std::shared_ptr<QByteArray> data = nullptr,
                      std::shared_ptr<QHash<QString, quint32>> parameters = nullptr );

    /**
     * @brief TransportMessage
     * @param data
     */
   // TransportMessage( std::shared_ptr<QByteArray> data = nullptr );

    TransportMessage( const TransportMessage& other );
    ~TransportMessage();

    /** @brief Возвращает массив байт, содержащий информационную часть сообщения.
        @return указатель на массив байт, содержащий информационную часть сообщения, или nullptr - при отсутствии информационной части.
    */
    std::shared_ptr<QByteArray> data() const { return data_; }

    /** @brief Возвращает дескриптор сообщения.
        @return дескриптор сообщения.
    */
    quint32 descriptor() const { return descriptor_; }

    /** @brief Возвращает адрес источника сообщения.
        @return адрес источника сообщения.
    */
    quint32 source() const { return source_; }

    /**
     * @brief receiver
     * @return число, обозначающее адрес приёмника сообщения
     */
    quint32 receiver() const { return  receiver_; }

    /**
     * @brief parameters
     * @return
     */
    std::shared_ptr<QHash<QString, quint32>> parameters() { return parameters_; }

private:
    quint32 descriptor_;
    quint32 source_;
    quint32 receiver_;
    std::shared_ptr<QByteArray> data_;
    std::shared_ptr<QHash<QString, quint32>> parameters_;

    // запрещаем присваивание
    TransportMessage& operator= (const TransportMessage& other );
};

Q_DECLARE_METATYPE( TransportMessage )

#endif // TRANSPORTMESSAGE_H
