#ifndef POSTLEITZAHLENDAO_H
#define POSTLEITZAHLENDAO_H

#include <QObject>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>

#include "DAOLib.h"
#include "Postleitzahl.h"

class DAOLIB_EXPORT PostleitzahlenDAO
{
public:
    // Dodawanie rekordu.  Klucz główny i znacznik czasu są generowane 
    // automatycznie przez przypisana baza danych.
    // Hinzufügen des Datensatzes. Primärschlüssel und Timestamp 
    // werden automatisch von der Datenbank vergeben.
    static bool insertPostleitzahl(const QString& PLZ, const QString& Ort);
    static bool postleitzahlExists(const QString& PLZ, const QString& Ort);
    static void deleteTable();
    static int getRowCount();
    static QSqlTableModel* readPostleitzahlenIntoTableModel();
    static Postleitzahl *readPostleitzahl(qint64 key);
    static bool updatePostleitzahl(qint64 key, const QString& PLZ, const QString& Ort);
    static qint64 getLastIdentity();
    static bool deletePostleitzahl(qint64 key);

private:
    // Prywatny konstruktor uniemożliwia utworzenie tej klasy.
    // Wszystkie metody są statyczne.
    // Privater Konstruktor
    // Verhindert das Erstellen dieser Klasse.
    // Alle Methoden sind statisch.
    PostleitzahlenDAO();
};

#endif // POSTLEITZAHLENDAO_H
