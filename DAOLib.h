#ifndef DAOLIB_H
#define DAOLIB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QMessageBox>
#include <QDate>

#include "DAOLib_global.h"

class DAOLIB_EXPORT DAOLib
{
public:
    // Logowanie do bazy danych za pomocą uwierzytelniania Windows
    // Datenbankanmeldung mit Windows-Authentifizierung
    static bool connectToDatabase(const QString& driver,
                                  const QString& driverName,
                                  const QString& hostName,
                                  const QString& databaseName);

    static void closeConnection();
    static QSqlDatabase getDatabaseConnection();
    static QString getDatabaseName();
    static QString dbString(QString);
    static QString dbDate(QDate);

    static int executeNonQuery(const QString& SQL);
    static QVariant executeScalar(const QString& SQL, bool &OK);
    static QSqlQuery* executeQuery(const QString& SQL, bool &OK);

private:

    // Prywatny konstruktor uniemożliwia utworzenie tej klasy.
    // Wszystkie metody są statyczne.
    // Privater Konstruktor
    // Verhindert das Erstellen dieser Klasse.
    // Alle Methoden sind statisch.
    DAOLib();

    static QSqlDatabase dbConn;
    static QString serverName;
    static QString dbName;

};

#endif // DAOLIB_H
