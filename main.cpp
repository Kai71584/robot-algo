/*
fichier: main.cpp
autheur: Pierre-Antoine Lajoie
dernière MAJ: 2024-12-06 14:30
description: parcours le labyrinthe avec un Robot
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "graphe.h"
#include "robot.h"
using namespace std;

void labyrinthe(Robot r,graphe g, pair<int,int> depart, pair<int,int> arrive){
    
}


int main(){

    Robot monRobot = Robot("NN");
    graphe monGraphe;

    int monTab[7][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    monGraphe.creerConnexions(monTab);
    
    pair<int,int> p1 = {1,1};

    monGraphe.DFS(p1);

    monRobot.avancer();
    monRobot.afficheDir();
    monRobot.roterD();
    monRobot.avancer();
    monRobot.afficheDir();
    
    cout<< "Ceci est notre main" ;
    return 0;
}