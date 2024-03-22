#include "Client.h"

Client::Client(QString hostName, QString databaseName, QString userName, QString userPassword)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);  // Change to username
    db.setPassword(userPassword);  // Change to password
    qDebug() << "Database opened: " << db.open();
    query = QSqlQuery{db};
}

void Client::ChangeDatabase(QString hostName, QString databaseName, QString userName, QString userPassword)
{
    db.close();
    db.removeDatabase("qt_sql_default_connection");
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);  // Change to username
    db.setPassword(userPassword);  // Change to password
    qDebug() << "Database opened: " << db.open();
    query = QSqlQuery{db};
}

void Client::printTasks()
{
    query.clear();

    query.exec("SELECT * FROM task");

    qDebug() << "Id | " << "Description | " << "Time";
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString description = query.value(1).toString();
        int time = query.value(2).toInt();

         qDebug() << id << " | "  << description << " | " << time;
    }
}

std::array<QVariant,3> Client::getTask(unsigned int task_id)
{
    query.clear();

    query.prepare("SELECT * FROM task where task_id = ?");
    query.addBindValue(task_id);
    query.exec();

    // Check if it found the table row
    if (!query.first())
    {
        qDebug() << "Found task: false";
        return std::array<QVariant,3>{-1,0,0};
    }
    else
    {
        qDebug() << "Found task: true";
        return std::array<QVariant,3>{query.value(0),query.value(1),query.value(2)};
    }
}

void Client::addTask(QString taskDescription, double time)
{
    query.clear();

    query.prepare("Insert into task (description, time) values(?,?)");
    query.addBindValue(taskDescription);
    query.addBindValue(time);

    qDebug() << "Insertet values: " << query.exec();
}

void Client::removeTask(unsigned int task_id)
{
    query.clear();

    query.prepare("Delete FROM task where task_id = ?");
    query.addBindValue(task_id);

    qDebug() << "Removed task: " << query.exec();
}
