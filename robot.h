#ifndef __ROBOT_H__
#define __ROBOT_H__
#include <iostream>
using namespace std;

class Robot
{
private:
    /* data */
    string direction;

public:
    Robot(string dirInit);
    Robot();

    void afficheDir();

    void avancer();

    void reculer();

    void roterG();

    void roterD();
};

#endif
