#ifndef DBMENAGER_H
#define DBMENAGER_H

#include <string>
#include <QtSql>
#include <QSqlQuery>

class DBMenager
{
public:
    DBMenager();
    void connect();
    QSqlQuery executeSqlCmd(const std::string& cmd);
    void executeSqlCmd(const QSqlQuery& cmd);
private:
    QSqlDatabase mDB;
    bool isDBOpen();
};

#endif // DBMENAGER_H
