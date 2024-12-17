#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "graphe.h"
#include "robot.h"
#include "explorateur.h"
using namespace std;

int main()
{

    cout << "Ceci est notre main" << endl;

    // on crée notre robot et note GrapheLabyrinthe
    Robot monRobot = Robot();
    GrapheLabyrinthe monGraphe;
    Explorateur explorateur;
    Labyrinthe labyrinthe;


    vector<vector<int>>tableau = labyrinthe.generer_labyrinthe();
    // on popule le GrapheLabyrinthe
    monGraphe = explorateur.labyrinthe_to_graphe(tableau);

    // on crée notre départ et notre entrée
    Position depart = {2, 1};
    Position fin = {3, 3};

    // parcours du labyrinthe
    explorateur.trouver_chemin(monRobot, monGraphe, depart, fin);

    return 0;
}