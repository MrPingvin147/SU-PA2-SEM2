#ifndef ROBOT_H
#define ROBOT_H

#include "Client.h"

class Robot
{
public:
    Robot();

    void doTask(unsigned int task_id, Client client);

private:
};

#endif // ROBOT_H
