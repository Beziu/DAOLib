#include "PostleitzahlenDAO.h"

PostleitzahlenDAO::PostleitzahlenDAO()
{

}

bool PostleitzahlenDAO::insertPostleitzahl(const QString &PLZ, const QString &Ort)
{
    QString SQL = "INSERT INTO Postleitzahlen ";
    SQL += "(PLZ, ORT) ";
    SQL += "VALUES (";
    SQL += DAOLib::dbString(PLZ) + ", ";
    SQL += DAOLib::dbString(Ort) + ")";

    return DAOLib::executeNonQuery(SQL) > 0;
}

bool PostleitzahlenDAO::postleitzahlExists(const QString &PLZ, const QString &Ort)
{
    QString SQL = "SELECT COUNT(*) FROM Postleitzahlen ";
    SQL += "WHERE PLZ = " + DAOLib::dbString(PLZ);
    SQL += " AND ORT = " + DAOLib::dbString(Ort);

    bool OK;

    QVariant count = DAOLib::executeScalar(SQL, OK);

    if (!OK)
        return false;
    else
        return count.toInt() > 0;
   
}

void PostleitzahlenDAO::deleteTable()
{

    // QString SQL = "DELETE TABLE Postleitzahlen";

    // oder, schnellere Variante (gehört aber nicht zum SQL Standard)
     QString SQL = "TRUNCATE TABLE Postleitzahlen";

     DAOLib::executeNonQuery(SQL);
}

int PostleitzahlenDAO::getRowCount()
{

    QString SQL = "SELECT COUNT(*) FROM Postleitzahlen";
    bool OK;

    QVariant count = DAOLib::executeScalar(SQL, OK);

    if (!OK)
        return 0;
    else
        return count.toInt();
   
}

QSqlTableModel *PostleitzahlenDAO::readPostleitzahlenIntoTableModel()
{
    QSqlTableModel* tableModel = new QSqlTableModel(nullptr, 
										  DAOLib::getDatabaseConnection());
    
    tableModel->setTable("Postleitzahlen");
    // Zmiany w tabeli są dokonywane tylko przez program.
    // Änderungen der Tabelle werden nur vom Programm durchgeführt.
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableModel->select();

    return tableModel;
    
}

Postleitzahl *PostleitzahlenDAO::readPostleitzahl(qint64 key)
{
    Postleitzahl* plz = nullptr;
    bool OK;

    QString SQL = "SELECT PRIMARYKEY, PLZ, ORT, TIMESTAMP FROM Postleitzahlen ";
    SQL += "WHERE PRIMARYKEY = " + QString::number(key);

    QSqlQuery* query = DAOLib::executeQuery(SQL, OK);
    if (!OK)
    {
        delete query;
        return plz;
    }

    // Zmiana pozycji na pierwsza
    query->first();

    plz = new Postleitzahl();
    plz->setPrimaryKey(query->value("PRIMARYKEY").toLongLong());
    plz->setPLZ(query->value("PLZ").toString());
    plz->setOrt(query->value("ORT").toString());
    plz->setTimeStamp(query->value("TIMESTAMP").toString());

    delete query;
    return plz;
    
}

bool PostleitzahlenDAO::updatePostleitzahl(qint64 key, const QString &PLZ, const QString &Ort)
{
    QString SQL = "UPDATE Postleitzahlen ";
    SQL += "SET PLZ = " + DAOLib::dbString(PLZ) + ", ";
    SQL += "ORT = " + DAOLib::dbString(Ort);
    SQL += " WHERE PRIMARYKEY = " + QString::number(key);

    return DAOLib::executeNonQuery(SQL) > 0;
}

qint64 PostleitzahlenDAO::getLastIdentity()
{
    QString SQL = "SELECT @@IDENTITY";
    bool OK;

    QVariant identity = DAOLib::executeScalar(SQL, OK);

    if (!OK)
        return -1;
    else
        return identity.toLongLong();
   
}

bool PostleitzahlenDAO::deletePostleitzahl(qint64 key)
{
    QString SQL = "DELETE FROM Postleitzahlen ";
    SQL += "WHERE PRIMARYKEY = " + QString::number(key);

    return DAOLib::executeNonQuery(SQL) > 0;
    
}



