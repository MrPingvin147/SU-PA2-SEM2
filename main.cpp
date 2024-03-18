#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

#include <iostream>
#include <iomanip>
#include <string>

void exercise1()
{
    QSqlQuery query;

    qDebug() << query.exec("select e.fname, e.address from department as d, employee as e where dname like \"research\";");

    qDebug() << "fname | " << "adress";
    while (query.next())
    {
        QString fname = query.value(0).toString();
        QString adress = query.value(1).toString();

         qDebug() << fname << " | "  << adress;
    }
}

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("company");
    db.setUserName("root");  // Change to username
    db.setPassword("Tqk97wew.");  // Change to password
    db.open();


    // Exercise 1
    exercise1();

    return 0;
}
