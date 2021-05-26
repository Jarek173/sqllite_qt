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
    void executeSqlCmd(const std::string& cmd);
    void executeSqlCmd(const QSqlQuery& cmd);
private:
};

#endif // DBMENAGER_H
