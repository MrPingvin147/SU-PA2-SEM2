#include "Robot.h"

Robot::Robot()
{

}

void Robot::doTask(unsigned int task_id, Client client)
{
    std::array<QVariant,3> task = client.getTask(task_id);

    if (task[0].toInt() == -1)
    {
        return;
    }

    // Do Task
    qDebug() << "Id | " << "Description | " << "Time";
    qDebug() << task[0].toInt() << " | "  << task[1].toString() << " | " << task[2].toInt();
    // Remove Task after completion
    //client.removeTask(task_id);
}
