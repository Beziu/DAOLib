#include "Postleitzahl.h"

Postleitzahl::Postleitzahl()
{

}

void Postleitzahl::setPrimaryKey(qint64 value)
{
    primaryKey = value;
}

qint64 Postleitzahl::getPrimaryKey() const
{
    return  primaryKey;;
}

void Postleitzahl::setPLZ(const QString &value)
{
    plz = value;
}

QString Postleitzahl::getPLZ() const
{
    return plz;
}

void Postleitzahl::setOrt(const QString &value)
{
    ort = value;
}

QString Postleitzahl::getOrt() const
{
    return ort;
}

void Postleitzahl::setTimeStamp(const QString& value)
{
    timeStamp = value;
}

QString Postleitzahl::getTimeStamp() const
{
    return timeStamp;
}
