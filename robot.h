/*
fichier: robot.h
autheur: Pierre-Antoine Lajoie
dernière MAJ: 2024-12-17 13:00
description: déclarations de la classe Robot
*/


#ifndef __ROBOT_H__
#define __ROBOT_H__
#include <iostream>
#include <utility>
using namespace std;

class Robot
{
private:
    /* data */
    string direction;

public:
    // constructeurs
    Robot(string dirInit);
    Robot();

    // affiche la direction dans laquelle le robot
    void afficheDir();

    // fait avancer le robot
    void avancer();

    // fait reculer le robot
    void reculer();

    // fait tourner le robot à gauche
    void roterG();

    // fait tourner le robot à droite
    void roterD();

    void mouvementOriente(pair<int,int>,pair<int,int>);
};

#endif
