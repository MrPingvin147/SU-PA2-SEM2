#ifndef ROBOT_H
#define ROBOT_H

#include "Client.h"

class Robot
{
public:
    Robot(Client& cl, QString robot_name);
    ~Robot();


    void doTask(unsigned int task_id);

private:
    Client* mCl;
    QString mName;
};

#endif // ROBOT_H
