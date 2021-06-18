#include "DAOLib.h"

// Initialisierung der statischen Variablen
QSqlDatabase DAOLib::dbConn = QSqlDatabase();
QString DAOLib::serverName = QString();
QString DAOLib::dbName = QString();

DAOLib::DAOLib()
{
}

bool DAOLib::connectToDatabase(const QString &driver, 
						 const QString &driverName, 
						 const QString &hostName,
						 const QString &databaseName)
{
    bool isDBOpen = false;

    // Tworzy ciąg połączenia
    // Verbindungszeichenfolge erstellen
    QString connectionString = driverName + ";";
    connectionString += "Server=" + hostName + ";";
    connectionString += "Database=" + databaseName + ";";

    // W przypadku uwierzytelniania systemu Windows
    // Mit Windows Authentifizierung
    connectionString += "Trusted_Connection=Yes;";

    dbConn = QSqlDatabase::addDatabase(driver, databaseName);

    // Ciąg połączenia  przypisać
    // Verbindungszeichenfolge zuweisen
    dbConn.setDatabaseName(connectionString);

    // Otwarta baza danych
    // Datenbank öffnen
    isDBOpen = dbConn.open();

    dbName = QString();
    serverName = QString();

    if (!isDBOpen)
    {
        QMessageBox::critical(nullptr, "Datenbankfehler",
                              QString("Fehler beim Öffnen der Datenbank: %1")
						.arg(dbConn.lastError().text()));
    }
    else
    {
        dbName = databaseName;
        serverName = hostName;
    }

    return isDBOpen;
}

void DAOLib::closeConnection()
{
    dbConn.close();
}

QSqlDatabase DAOLib::getDatabaseConnection()
{
    return dbConn;
}

QString DAOLib::getDatabaseName()
{
    return dbName;
}

QString DAOLib::dbString(QString value)
{
    // Ująć łańcuch w pojedynczy cudzysłów,
    // oraz wszelkie cudzysłowy, które mogą wystąpić w obrębie
    // ciągu znaków z podwójnym cudzysłowem.
    // Zeichenkette in einfache Anführungszeichen setzen,
    // und alle evtl. vorkommenden Hochkommas innerhalb
    // der Zeichenkette durch doppelte Hochkommas ersetzen.
   return "'" + value.replace("'", "''") + "'";
}

QString DAOLib::dbDate(QDate datum)
{
   return dbString(datum.toString("yyyy-MM-dd"));
}


int DAOLib::executeNonQuery(const QString &SQL)
{

    int retValue = -1;

    QSqlQuery query = QSqlQuery(dbConn);

    if (!query.exec(SQL))
        QMessageBox::critical(nullptr, "SQL-Fehler",
                              QString("Fehler beim Zugriff auf die Datenbank: %1")
						.arg(query.lastError().text()));
    else
        retValue = query.numRowsAffected();

    return retValue;
}

QVariant DAOLib::executeScalar(const QString &SQL, bool &OK)
{
    OK = false;
    QVariant retValue = 0;

    QSqlQuery query = QSqlQuery(dbConn);
    bool qryValue = query.exec(SQL);

    if (!qryValue)
    {
        QMessageBox::critical(nullptr, "SQL-Fehler",
                              QString("Fehler beim Zugriff auf die Datenbank: %1")
						.arg(query.lastError().text()));
        return retValue;
    }

    // Pozycja w pierwszym zapisie danych w zapytaniu
    // Auf den ersten Datensatz innerhalb der Query positionieren
    query.first();
    OK = true;

    return query.value(0);
}

QSqlQuery *DAOLib::executeQuery(const QString &SQL, bool &OK)
{
    QSqlQuery* query = new QSqlQuery(dbConn);
    OK = query->exec(SQL);
    return query;
}





