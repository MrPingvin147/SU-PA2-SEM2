#ifndef ROBOT_H
#define ROBOT_H

#include "Client.h"

class Robot
{
public:
    Robot(Client& cl, QString robot_name);
    ~Robot();

    void assignTask(unsigned int task_id);
    void doTask();

private:
    Client* mCl;
    QString mName;
    int mTask;
};

#endif // ROBOT_H
