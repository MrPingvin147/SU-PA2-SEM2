#ifndef CLIENT_H
#define CLIENT_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

class Client
{
public:
    Client(QString hostName, QString databaseName, QString userName, QString userPassword);

    void printTasks();

private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // CLIENT_H
