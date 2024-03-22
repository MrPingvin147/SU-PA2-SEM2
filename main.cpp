#include <iostream>
#include <iomanip>
#include <string>

#include "Robot.h"

void exercise0()
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
    qDebug() << "";

    query.clear();
}

int main(int argc, char *argv[])
{
    Client cl{"localhost", "company", "root", "Tqk97wew."};

    // Exercise 0
    // exercise0();

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
        else if ((std::string)argv[1] == "robot")
        {
            if ((std::string)argv[2] == "print")
            {
                cl.printRobots();
            }
            else if((std::string)argv[2] == "-n")
            {
                QString name = argv[3];
                Robot rb4{cl,name};
                if ((std::string)argv[4] == "-t")
                {
                    cl.printTasks();
                    rb4.assignTask(static_cast<int>(*argv[5] - 48));
                    if ((std::string)argv[6] == "-e")
                    {
                        cl.printRobots();
                        rb4.doTask();
                        cl.printTasks();
                    }
                }
                cl.printRobots();
            }
        }
    }  catch (std::logic_error ex) {
        ex.what();
    }

    /*cl.printTasks();

    Robot rb1{cl, "Vacume Cleaner"};

    rb1.assignTask(4);

    Robot rb3{cl, "Robot Arm"};
    rb3.assignTask(7);
    cl.printRobots();

    rb1.doTask();
    cl.printTasks();
    cl.printRobots();
    {
        Robot rb2{cl, "Lawn mower"};
        rb2.assignTask(4);
        cl.printRobots();
    }
    cl.printRobots();*/
    return 0;
}
