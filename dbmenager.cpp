#include "dbmenager.h"
#include <QtSql>
#include <QSqlDatabase>

DBMenager::DBMenager()
{

}

void DBMenager::connect()
{
    mDB = QSqlDatabase::addDatabase("QSQLITE");
    mDB.setDatabaseName("/home/jkwiatkowski/Documents/test.db");

    isDBOpen();
}

QSqlQuery DBMenager::executeSqlCmd(const std::string& cmd)
{
    isDBOpen();

    QSqlQuery query;

    if(!query.exec(QString::fromStdString(cmd)))
    {
        qInfo() << mDB.lastError().text();
        qInfo() << query.lastError().text();
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    return query;
}

void DBMenager::executeSqlCmd(const QSqlQuery& cmd)
{

}

bool DBMenager::isDBOpen()
{
    if(!mDB.open())
    {
        qInfo() << "Could not open connection!";
        qInfo() << mDB.lastError().text();
        throw std::runtime_error(mDB.lastError().text().toStdString());
        return false;
    }
    return true;
}

