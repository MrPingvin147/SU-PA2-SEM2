#include "Client.h"

Client::Client(QString hostName, QString databaseName, QString userName, QString userPassword)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);  // Change to username
    db.setPassword(userPassword);  // Change to password
    db.open();
    query = QSqlQuery{db};
}

void Client::printTasks()
{
    query.exec("SELECT * FROM task");

    qDebug() << "Id | " << "Description | " << "Time";
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString description = query.value(1).toString();
        int time = query.value(2).toInt();

         qDebug() << id << " | "  << description << " | " << time;
    }
    query.clear();
}
