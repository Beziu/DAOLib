#ifndef POSTLEITZAHL_H
#define POSTLEITZAHL_H

#include <QObject>

#include "DAOLib.h"

class DAOLIB_EXPORT Postleitzahl
{
public:
    Postleitzahl();

    void setPrimaryKey(qint64 key);
    qint64 getPrimaryKey() const;

    void setPLZ(const QString& PLZ);
    QString getPLZ() const;

    void setOrt(const QString& Ort);
    QString getOrt() const;

    void setTimeStamp(const QString& Val);
    QString getTimeStamp() const;

private:
    qint64 primaryKey;
    QString plz;
    QString ort;
    QString timeStamp;

};

#endif // POSTLEITZAHL_H
