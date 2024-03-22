#include <iostream>
#include <iomanip>
#include <string>

#include "Robot.h"

void exercise1()
{
    QSqlQuery query;

    query.exec("select e.fname, e.address from department as d, employee as e where dname like \"research\";");

    qDebug() << "fname | " << "adress";
    while (query.next())
    {
        QString fname = query.value(0).toString();
        QString adress = query.value(1).toString();

         qDebug() << fname << " | "  << adress;
    }

    query.clear();
}

int main(int argc, char *argv[])
{
    Client cl{"localhost", "company", "root", "Tqk97wew."};

    // Exercise 1
    exercise1();

    cl.ChangeDatabase("localhost", "robot_worker", "root", "Tqk97wew.");

    try {
        if ((std::string)argv[1] == "task")
        {
            if ((std::string)argv[2] == "print")
            {
                cl.printTasks();
            }
            else if((std::string)argv[2] == "add")
            {
                cl.addTask(argv[3], static_cast<double>(*argv[4]));
            }
            else if((std::string)argv[2] == "remove")
            {
                cl.removeTask(static_cast<unsigned int>(*argv[3]));
            }
        }
    }  catch (std::logic_error ex) {
        ex.what();
    }

    cl.printTasks();

    Robot rb{cl, "Vacume Cleaner"};
    //rb.doTask(1, cl);

    return 0;
}
