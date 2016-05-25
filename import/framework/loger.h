#ifndef LOGER_H
#define LOGER_H

#include <QString>
#include <QFile>

/**
 * @brief The Loger class
 * @detailed Простой логер, записывает указанную строку в файл с указанием времени записи в формате гг.мм.дд : чч.мм.сс.мкс
 * функцию записи можно переопределить
 */
class Loger
{
public:
    /**
     * @brief Loger
     * @param fileName - если не указано имя файла то будет создан system.log по умолчанию
     */
    Loger(const QString& fileName = 0);
    virtual ~Loger();

    /**
     * @brief addRecord
     * @param record - строка для записи в лог
     */
    virtual void addRecord(const QString record);

    /**
     * @brief saveAs
     * @param newName - имя файла, под которым хотим сохранить лог, при этом запись будет
     * продолжена в файл, переданный в конструктор
     */
    void saveAs(const QString newName);

    /**
     * @brief clear - очистить весь лог
     */
    void clear();
private:
    QFile* logFile_;
    QString logName_;
};

#endif // LOGER_H
