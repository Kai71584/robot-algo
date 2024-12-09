/*
fichier: main.cpp
autheur: Pierre-Antoine Lajoie
dernière MAJ: 2024-12-06 15:00
description: parcours le labyrinthe avec un Robot
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "graphe.h"
#include "robot.h"
using namespace std;

void labyrinthe(Robot r, graphe g, pair<int, int> depart, pair<int, int> arrive)
{
    cout << "Notre robot pointe vers ";
    r.afficheDir(); 
    cout <<", il commence en: (" << depart.first << "," << depart.second << ") et fini le labyrinthe en arrivant à: (" << arrive.first << "," << arrive.second << ")." << endl;

    // on fait un DFS de base pour simuler le robot
    g.DFS(depart);
}

int main()
{

    cout << "Ceci est notre main"<<endl;

    // onh crée notre robot et note graphe
    Robot monRobot = Robot("SS");
    graphe monGraphe;

    // tableau qui sert à populer notre graphe
    int monTab[7][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}};

    // on popule le graph
    monGraphe.creerConnexions(monTab);

    // on crée notre départ et notre entrée
    pair<int, int> depart = {1, 1};
    pair<int, int> fin = {4, 6};

    

    // parcours du labyrinthe
    labyrinthe(monRobot, monGraphe, depart, fin);

   

    return 0;
}