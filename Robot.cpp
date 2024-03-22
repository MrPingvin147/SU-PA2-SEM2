#include "Robot.h"

Robot::Robot(Client& cl, QString robot_name) : mName{robot_name}, mCl{&cl}
{
    mCl->addRobot(mName);
}

Robot::~Robot()
{
    mCl->removeRobot(mName);
}

void Robot::assignTask(unsigned int task_id)
{
    mTask = task_id;
    bool success = mCl->addRobotTask(mName, mTask);

    if (!success)
    {
        return;
    }
    std::array<QVariant,3> task = mCl->getTask(mTask);

    qDebug() << "Id | " << "Description | " << "Time";
    qDebug() << task[0].toInt() << " | "  << task[1].toString() << " | " << task[2].toInt();
    qDebug() << "";
}

void Robot::doTask()
{
    if (mTask == -1)
    {
        qDebug() << "No Current task";
        qDebug() << "";
        return;
    }
    // Do Task

    // Remove Task after completion
    if (mCl->removeRobotTask(mName))
    {
        mCl->removeTask(mTask);
        mTask = -1;
    }
    else
    {
        qDebug() << "Failed to remove task after completion";
        qDebug() << "";
    }
}
