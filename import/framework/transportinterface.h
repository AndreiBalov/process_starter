#ifndef TRANSPORTINTERFACE
#define TRANSPORTINTERFACE

#include "plugininterface.h"
#include <QByteArray>
#include <memory>

class TransportMessage;

/** @brief Интерфейс работы с транспортным уровнем канала обмена
    @details Описывает интерфейс работы с транспортным уровнем канала обмена
*/
class TransportInterface : public PluginInterface
{
public:
    virtual ~TransportInterface() {}

public:
    /** @brief Осуществляет обработку сообщения, принятого из порта.
        @details Обработка сообщения выполняется в соответствии с правилами транспортного уровня.
        @param data - указатель на массив данных в формате, определяемом транспортным уровнем.
    */
    virtual void handlingMessageFromPort(std::shared_ptr<QByteArray> data) = 0;

    /** @brief Осуществляет обработку сообщений и дальнейшую передачу их в порт.
        @param data - массив данных в формате, определяемом транспортным уровнем
    */
    virtual void transmitMessageHandler(std::shared_ptr<TransportMessage> data) = 0;
};

Q_DECLARE_INTERFACE(TransportInterface, "com.burevestnik.framework.transportinterface/1.0")

#endif // TRANSPORTINTERFACE
