#include "robot.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;
;

Robot::Robot(string dirInit)
{
    if (dirInit == "NN" || dirInit == "OO" || dirInit == "SS" || dirInit == "EE")
    {
        direction = dirInit;
    }
    else
    {
        direction = "EE";
    }
}

Robot::~Robot() {};

void Robot::avancer()
{
    cout << "avance de 10cm" << endl;
}

void Robot::reculer()
    {
        cout << "recule de 10cm" << endl;
    }

void Robot::roterG()
    {
        cout << "roter 90 degrées gauche" << endl;

        if (direction=="NN")
        {
            direction = "OO";
        } else if (direction=="OO")
        {
            direction = "SS";
        }else if (direction=="SS")
        {
            direction = "EE";
        }else if (direction=="EE")
        {
            direction = "NN";
        }
        
        
    }

void Robot::roterD()
    {
        cout << "roter 90 degrées droite" << endl;

        if (direction=="NN")
        {
            direction = "EE";
        } else if (direction=="EE")
        {
            direction = "SS";
        }else if (direction=="SS")
        {
            direction = "OO";
        }else if (direction=="OO")
        {
            direction = "NN";
        }
    }