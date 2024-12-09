/*
fichier: robot.cpp
autheur: Pierre-Antoine Lajoie
dernière MAJ: 2024-12-09 15:00 P-A
description: fonctions de la classe Robot
*/

#include "robot.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;


// constructeur
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

// constructeur par défaut
Robot::Robot()
{
    direction = "EE";
};

// fait avancer le robot
void Robot::avancer()
{
    cout << "avance de 10cm" << endl;
}

// fait reculer le robot
void Robot::reculer()
{
    cout << "recule de 10cm" << endl;
}

// fait tourner le robot à gauche
void Robot::roterG()
{
    cout << "roter 90 degrées gauche" << endl;

    if (direction == "NN")
    {
        direction = "OO";
    }
    else if (direction == "OO")
    {
        direction = "SS";
    }
    else if (direction == "SS")
    {
        direction = "EE";
    }
    else if (direction == "EE")
    {
        direction = "NN";
    }
}

// fait tourner le robot à droite
void Robot::roterD()
{
    cout << "roter 90 degrées droite" << endl;

    if (direction == "NN")
    {
        direction = "EE";
    }
    else if (direction == "EE")
    {
        direction = "SS";
    }
    else if (direction == "SS")
    {
        direction = "OO";
    }
    else if (direction == "OO")
    {
        direction = "NN";
    }
}

// affiche la direction dans laquelle le robot
void Robot::afficheDir()
{
    cout << direction;
}