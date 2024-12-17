/*
fichier: explorateur.h
autheur: William Roy
dernière MAJ: 2024-12-17 18:15
description: déclarations de la classe explorateyr
*/


#ifndef __EXPLORATEUR_H__
#define __EXPLORATEUR_H__

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include "graphe.h"
#include "robot.h"



class Explorateur{
private:

public:
Explorateur(){};

GrapheLabyrinthe labyrinthe_to_graphe(vector<vector<int>>); //crée le graphe

void trouver_chemin(Robot , GrapheLabyrinthe , Position, Position); //navigue le labyrinthe
};

#endif