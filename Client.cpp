#include "Client.h"

Client::Client(QString hostName, QString databaseName, QString userName, QString userPassword)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);  // Change to username
    db.setPassword(userPassword);  // Change to password
    qDebug() << "Database opened: " << db.open();
    qDebug() << "";
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
    qDebug() << "";
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
    qDebug() << "";
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
        return std::array<QVariant,3>{-1,0,0};
    }
    else
    {
        return std::array<QVariant,3>{query.value(0),query.value(1),query.value(2)};
    }
}

void Client::addTask(QString taskDescription, double time)
{
    query.clear();

    query.prepare("Insert into task (description, time) values(?,?)");
    query.addBindValue(taskDescription);
    query.addBindValue(time);

    qDebug() << "Insertet values into task: " << query.exec();
    qDebug() << "";
}

void Client::removeTask(unsigned int task_id)
{

    query.clear();

    query.prepare("set foreign_key_checks = 0; Delete FROM task where task_id = ?; set foreign_key_checks = 1");
    query.addBindValue(task_id);

    qDebug() << "Removed task: " << query.exec();
    qDebug() << "";
}

void Client::printRobots()
{
    query.clear();

    query.exec("SELECT * FROM robot");

    qDebug() << "Name | " << "task_id";
    while (query.next())
    {
        QString name = query.value(0).toString();
        int task_id = query.value(1).toInt();

         qDebug() << name << " | "  << task_id;
    }
    qDebug() << "";
}

void Client::addRobot(QString robot_name)
{
    query.clear();
    query.prepare("Insert into robot (name) values(?)");
    query.addBindValue(robot_name);
    qDebug() << "Insertet values into robot: " << query.exec();
    qDebug() << "";
}

void Client::removeRobot(QString robot_name)
{
    query.clear();

    query.prepare("Delete FROM robot where name = ?");
    query.addBindValue(robot_name);

    qDebug() << "Removed robot: " << query.exec();
    qDebug() << "";
}

bool Client::addRobotTask(QString robot_name, int task_id)
{
    query.clear();

    query.prepare("update robot set current_task = ? where name = ?");
    query.addBindValue(task_id);
    query.addBindValue(robot_name);


    if (!query.exec())
    {
        qDebug() << "Failed to add task to robot could be dublicate or wrong task_id";
        qDebug() << "";
        return false;
    }
    else
    {
        qDebug() << "succesfully added task to robot: true";
        qDebug() << "";
        return true;
    }
}

bool Client::removeRobotTask(QString robot_name)
{
    query.clear();
    query.prepare("update robot set current_task = NULL where name = ?");
    query.addBindValue(robot_name);


    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << "";
        return false;
    }
    else
    {
        qDebug() << "succesfully added task to robot: true";
        qDebug() << "";
        return true;
    }
}
