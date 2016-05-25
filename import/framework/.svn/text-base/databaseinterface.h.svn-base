#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QString>
#include <QtSql>


class DatabaseInterface
{
public:
    struct EnumPropertyValue
    {
        QString name;     //!< название значения перечисления
        QString fullName; //!< полное название значения перечисления (используется только для интерфейса)
    };

    /** @brief Функция создания соединения с базой данных
        @param [in] databaseName наименование базы данных
        @return true если соединение с БД установлено, false - в противном случае
    */
    virtual bool createDatabaseConnection(const QString& databaseName) = 0;

    /** @brief Функция удаления соединения с базой данных
        @param [in] databaseName наименование базы данных
        @return true если удаление соединения с БД выполнено успешно, false - в противном случае
    */
    virtual void deleteDatabaseConnection(const QString& databaseName) = 0;

    /** @brief Функция проверки наличия соединения с базой данных
        @param [in] databaseName наименование базы данных
        @return true если соединение с БД установлено, false - в противном случае
    */
    virtual bool isDatabaseConnectionExist(const QString& databaseName) = 0;

    /** @brief Функция создания базы данных (выполняет создание всех необходимых таблиц)
        @param [in] databaseName наименование базы данных
        @return true если создание БД выполнено успешно, false - в противном случае
    */
    virtual bool createDatabase(const QString& databaseName) = 0;

    /** @brief Функция удаления базы данных
        @param [in] databaseName наименование базы данных
        @return true если удаление БД выполнено успешно, false - в противном случае
    */
    virtual bool deleteDatabase(const QString& databaseName) = 0;

    /** @brief Функция проверки наличия базы данных
        @param [in] databaseName наименование базы данных
        @return true если база данных существует, false - в противном случае
    */
    virtual bool isDatabaseExist(const QString& databaseName) = 0;

    /** @brief Функция создания типа объекта
        @param [in] databaseName наименование базы данных
        @param [in] typeName наименование типа объекта (используется для поиска объектов данного типа)
        @param [in] fullTypeName полное наименование типа объекта (используется только для интерфейса)
        @param [in] parentTypeName наименование типа объекта родителя
        @return true если создание типа объекта выполнено, false - в противном случае
    */
    virtual bool createObjectType(const QString& databaseName, const QString& typeName, const QString& fullTypeName = "", const QString& parentTypeName = "") = 0;

    /** @brief Функция создания свойства типа объекта для хранения значения типа String
        @param [in] databaseName наименование базы данных
        @param [in] typeName наименование типа объекта, для которого создается свойство
        @param [in] propertyName наименование свойства типа объекта
        @param [in] fullPropertyName полное наименование свойства типа объекта (используется только для интерфейса)
        @return true если создание свойства типа объекта выполнено, false - в противном случае
    */
    virtual bool createProperty(const QString& databaseName, const QString& typeName, const QString& propertyName, const QString& initValue, const QString& fullPropertyName = "") = 0;

    /** @brief Функция создания свойства типа объекта для хранения значения типа int32
        @param [in] databaseName наименование базы данных
        @param [in] typeName наименование типа объекта, для которого создается свойство
        @param [in] propertyName наименование свойства типа объекта
        @param [in] fullPropertyName полное наименование свойства типа объекта (используется только для интерфейса)
        @return true если создание свойства типа объекта выполнено, false - в противном случае
    */
    virtual bool createProperty(const QString& databaseName, const QString& typeName, const QString& propertyName, qint32 initValue, const QString& fullPropertyName = "") = 0;

    /** @brief Функция создания свойства типа объекта для хранения значения типа double
        @param [in] databaseName наименование базы данных
        @param [in] typeName наименование типа объекта, для которого создается свойство
        @param [in] propertyName наименование свойства типа объекта
        @param [in] fullPropertyName полное наименование свойства типа объекта (используется только для интерфейса)
        @return true если создание свойства типа объекта выполнено, false - в противном случае
    */
    virtual bool createProperty(const QString& databaseName, const QString& typeName, const QString& propertyName, double initValue, const QString& fullPropertyName = "") = 0;

//    /** @brief Функция создания типа связи объектов
//        @param [in] typeName наименование типа связи
//        @param [in] fullTypeName полное наименование типа связи (используется только для интерфейса)
//        @return true если создание типа связи выполнено, false - в противном случае
//    */
//    virtual bool createRelationType(const QString& databaseName, const QString& typeName, const QString& fullTypeName) = 0;

//    /** @brief Функция создания допустимой связи двух типов объектов
//        @param [in] parentObjectTypeName наименование типа родительского объекта
//        @param [in] childObjectTypeName наименование типа подчиненного объекта
//        @return true если создание допустимой связи двух типов объектов выполнено, false - в противном случае
//    */
//    virtual bool createAllowedRelation(const QString& databaseName, const QString& parentObjectTypeName, const QString& childObjectTypeName) = 0;

    /** @brief Функция добавления объекта (сущности)
        @param [in] typeName наименование типа добавляемого объекта
        @param [in] objectName наименование добавляемого объекта (сущности)
        @return true если добавление объекта выполнено, false - в противном случае
    */
    virtual bool createObject(const QString& databaseName, const QString& typeName, const QString& objectName) = 0;

    /** @brief Функция удаления объекта (сущности)
        @param [in] objectName наименование удаляемого объекта (сущности)
        @return true если удаление объекта выполнено, false - в противном случае
    */
    virtual bool deleteObject(const QString& databaseName, const QString& objectName) = 0;

//    /** @brief Функция создания связи объектов (сущности)
//        @param [in] parentObjectName наименование родительского объекта
//        @param [in] childObjectName наименование подчиненного объекта
//        @return true если добавление связи объектов выполнено, false - в противном случае
//    */
//    virtual bool createObjectRelation(const QString& databaseName, const QString& parentObjectName, const QString& childObjectName) = 0;

    /** @brief Функция установки значения свойства типа String объекта
        @param [in] objectName наименование объекта, для которого осуществляется установка значения свойства
        @param [in] propertyName наименование свойства, установка которого осуществляется
        @param [in] propertyValue устанавливаемое значение свойства
        @return true если установка свойства объекта выполнено, false - в противном случае
    */
    virtual bool setPropertyValue(const QString& databaseName, const QString& objectName, const QString& propertyName, const QString& propertyValue) = 0;

    /** @brief Функция установки значения свойства типа int объекта
        @param [in] objectName наименование объекта, для которого осуществляется установка значения свойства
        @param [in] propertyName наименование свойства, установка которого осуществляется
        @param [in] propertyValue устанавливаемое значение свойства
        @return true если установка свойства объекта выполнено, false - в противном случае
    */
    virtual bool setPropertyValue(const QString& databaseName, const QString& objectName, const QString& propertyName, qint32 propertyValue) = 0;

    /** @brief Функция установки значения свойства типа double объекта
        @param [in] objectName наименование объекта, для которого осуществляется установка значения свойства
        @param [in] propertyName наименование свойства, установка которого осуществляется
        @param [in] propertyValue устанавливаемое значение свойства
        @return true если установка свойства объекта выполнено, false - в противном случае
    */
    virtual bool setPropertyValue(const QString& databaseName, const QString& objectName, const QString& propertyName, double propertyValue) = 0;

//    /** @brief Функция получения наименований объектов заданного типа
//        @param [in] typeName наименование типа запрашиваемых объектов
//        @param [out] objectNames наименования объектов
//        @return true если запрос выполнен успешно и false - в противном случае
//    */
//    virtual bool getObjects(const QString& databaseName, const QString& typeName, QStringList& objectNames) = 0;

    /** @brief Функция получения значения указанного свойства объекта
        @param [in] objectName наименование объекта
        @param [in] propertyName наименование запрашиваемого свойства объекта
        @param [out] propertyValue значение свойства
        @return true если запрос выполнен успешно и false - в противном случае
    */
    virtual bool getPropertyValue(const QString& databaseName, const QString& objectName, const QString& propertyName, QVariant& propertyValue) const = 0;

//    /** @brief Функция получения значений указанных свойств объекта
//        @param [in] objectName наименование объекта
//        @param [in] propertyNames список наименований запрашиваемых свойств объекта
//        @param [out] propertyValues значения свойств
//        @return true если запрос выполнен успешно и false - в противном случае
//    */
//    virtual bool getPropertyValues(const QString& databaseName, const QString& objectName, const QStringList& propertyNames, QVector<QVariant>& propertyValues) = 0;

//    /** @brief Функция получения значений всех свойств объекта
//        @param [in] objectName наименование объекта
//        @param [out] propertyValues значения свойств
//        @return true если запрос выполнен успешно и false - в противном случае
//    */
//    virtual bool getAllPropertyValues(const QString& databaseName, const QString& objectName, QVector<QVariant>& properties) = 0;
};

#endif // DATABASEINTERFACE_H
