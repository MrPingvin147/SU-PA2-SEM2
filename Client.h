#ifndef CLIENT_H
#define CLIENT_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

class Client
{
public:
    Client(QString hostName, QString databaseName, QString userName, QString userPassword);

    void ChangeDatabase(QString hostName, QString databaseName, QString userName, QString userPassword);

    void printTasks();

    void addTask(QString taskDescription, double time);
    std::array<QVariant,3> getTask(unsigned int task_id);
    void removeTask(unsigned int task_id);

    void addRobot(QString robot_name);
    void removeRobot(QString robot_name);
private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // CLIENT_H
