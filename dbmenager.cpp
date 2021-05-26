#include "dbmenager.h"
#include <QtSql>
#include <QSqlDatabase>

DBMenager::DBMenager()
{

}

void DBMenager::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jarek/testDB");

    if(!db.open())
    {
        qInfo() << "Could not open connection!";
        qInfo() << db.lastError().text();
    }
    else
    {
        qInfo() << "Connected, lets make a query...";
        QSqlQuery query;
        QString cmd;
        cmd = "SELECT * FROM Users";
        if(!query.exec(cmd))
        {
            qInfo() << db.lastError().text();
            qInfo() << query.lastError().text();
        }
        else
        {
            qInfo() << "Got query results: " << query.size();
            while (query.next())
            {
                int id = query.value(0).toInt();
                QString name = query.value(1).toString();
                qInfo() << id << " " << name << "\n";
            }
        }
    }
}

void DBMenager::executeSqlCmd(const std::string& cmd)
{

}

void DBMenager::executeSqlCmd(const QSqlQuery& cmd)
{

}

