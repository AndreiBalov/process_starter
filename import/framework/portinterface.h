/*!
* \file  portinterface.h
* \brief Описывает интерфейс работы с портом расширения
* \author Балов А.С. отд.0448
*/
#ifndef PORTINTERFACE
#define PORTINTERFACE

#include <QString>
#include <memory>
#include "plugininterface.h"

class SocketHandler;

/*!
 * \brief The PortInterface class - класс интерфейса для модулей расширения реализующие порт.
 * \detailed Включает в себя интерфейс спецификации всех модулей расширения для контроля типа и версии
 */
class PortInterface : public PluginInterface
{
public:
    // виртулаьный деструктор для того, что бы компилятор не выдавал warning об отсутствии виртуального
    // деструктора при наличии виртуальных методов
    virtual ~PortInterface(){}

    //virtual quint8 init(QVector<std::shared_ptr<ConfigurationParameter>> parameters) = 0;

    /*!
     * \brief Открывает порт с переданными параметрами
     * \param param - вектор параметров, формат определеяется конкретным модулей расширения
     * \param SocketHandler - если нужен, то передаём, если нет то nullptr
     */
    //TODO: вектор должен состоять из QVariant для универсальности
    //virtual quint8 init(const QMultiMap<QString, QString>& param, SocketHandler* socket) = 0;

    /*!
     * \brief Закрывает порт
     */
    virtual void closePort() = 0;

    /*!
     * \brief Отправка сообщения в сеть
     * \param data - массив данных, в формате, определяемым транспортгным уровнем
     */
    virtual void transmitMessage(std::shared_ptr<QByteArray>) = 0;
};

Q_DECLARE_INTERFACE(PortInterface, "com.burevestnik.framework.PortInterface/1.0")
#endif // PORTINTERFACE
