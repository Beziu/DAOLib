#include "DateStyledItemDelegate.h"

DateStyledItemDelegate::DateStyledItemDelegate(QWidget* parent, QString dateFormat) : QStyledItemDelegate (parent)
{
    this->dateFormat = dateFormat;

}

QString DateStyledItemDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
   // Prüfen, ob der Wert in ein Datum konvertiert werden kann
   if (value.canConvert<QDate>())
      return locale.toString(value.toDate(), dateFormat);
   else
      return value.toString();
}

