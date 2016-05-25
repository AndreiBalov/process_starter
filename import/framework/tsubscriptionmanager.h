#ifndef TSUBSCRIPTIONMANAGER_H
#define TSUBSCRIPTIONMANAGER_H

#include <QMultiHash>
#include <QVector>

template<class T>
/** @brief Класс предназначен для управления подпиской на данные.
    @details Класс осуществляет управление подпиской на какие-либо данные.
        Данные представляют собой идентификатор типа quint64.
        Подписчик на данные представляет собой идентификатор типа quint32.
*/

class TSubscriptionManager
{
public:
    TSubscriptionManager()
    {

    }
    ~TSubscriptionManager(){

    }

    /** @brief Функция добавления подписки
        @param subscriber идентификатор подписчика на данные
        @param data идентификатор данных, на которые осуществляется подписка
    */
    void addSubscription(quint32 subscriber, T& data){
        if (!subscribers_.contains(data, subscriber))
            subscribers_.insert(data, subscriber);
    }

    /** @brief Функция удаления подписки одного подписчика на указанные данные
        @param subscriber идентификатор подписчика
        @param data идентификатор данных, на которые удаляется подписка
    */
    void deleteSubscription(quint32 subscriber, T& data){
        auto it = subscribers_.find(data);
        while (it != subscribers_.end() && it.key() == data)
        {
            if (it.value() == subscriber)
                it = subscribers_.erase(it);
            else
                ++it;
        }
    }

    /** @brief Функция удаления подписки одного подписчика на все данные
        @param subscriber идентификатор подписчика
    */
    void deleteSubscription(quint32 subscriber){
        auto it = subscribers_.begin();
        while (it != subscribers_.end())
        {
            if (it.value() == subscriber)
                it = subscribers_.erase(it);
            else
                ++it;
        }
    }

    /** @brief Функция получения списка подписчиков на данные
        @param data идентификатор данных, для которых осуществляется выборка подписчиков
        @return список подписчиков на данные
    */
    QVector<quint32> getSubscribers(T& data) const;

private:
    QMultiHash<T, quint32> subscribers_;	//!< список подписчиков на данные (ключ - ид.данных, значение - ид.подписчика)
};

template <class T>
QVector<quint32> TSubscriptionManager<T>::getSubscribers(T& data) const{
    QVector<quint32> vec;
    auto it = subscribers_.find(data);
    for (; it != subscribers_.end() && it.key() == data; ++it)
        vec.push_back(it.value());
    return vec;
}



#endif // TSUBSCRIPTIONMANAGER_H
