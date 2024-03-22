#include "Robot.h"

Robot::Robot(Client& cl, QString robot_name) : mName{robot_name}, mCl{&cl}
{
    mCl->addRobot(mName);
}

Robot::~Robot()
{
    mCl->removeRobot(mName);
}

void Robot::doTask(unsigned int task_id)
{
    std::array<QVariant,3> task = mCl->getTask(task_id);

    if (task[0].toInt() == -1)
    {
        return;
    }

    // Do Task
    qDebug() << "Id | " << "Description | " << "Time";
    qDebug() << task[0].toInt() << " | "  << task[1].toString() << " | " << task[2].toInt();
    // Remove Task after completion
    mCl->removeTask(task_id);
}
