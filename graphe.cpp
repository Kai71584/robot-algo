/*
fichier: robot.cpp
autheur: William Roy
dernière MAJ: 2024-12-17 18:15 William et P-A
description: fonctions de la classe GrapheLabyrinthe
*/

#include "graphe.h"
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
#include <vector>

using namespace std;

GrapheLabyrinthe::GrapheLabyrinthe()
{
}

Labyrinthe::Labyrinthe(){

}

Position Voisins::getPositionnement()
{
    return this->positionnement;
}

void Voisins::setPositionnement(Position position)
{
    this->positionnement = position;
}

string Voisins::getDirection()
{
    return this->direction;
}

void Voisins::setDirection(string d)
{
    this->direction = d;
}

void GrapheLabyrinthe::ajouterSommet(int a, int b)
{

    Position t = make_pair(a, b);

    if (positions.find(t) != positions.end())
    {
        throw runtime_error("Le sommet existe déjà.");
    }

    positions.insert(t);
};

void GrapheLabyrinthe::ajouterArrete(Position p1, Position p2, string a)
{

    Voisins f;
    f.setPositionnement(p2);
    f.setDirection(a);

    listeArretes[p1].insert(f);
};


//Récupère les voisins du sommet
vector<Voisins> GrapheLabyrinthe::voisins_possibles(Position p1)
{

    vector<Voisins> vectVoisins;

    if (listeArretes.find(p1) != listeArretes.end())
    {

        for (auto voisin : listeArretes[p1])
        {
            vectVoisins.push_back(voisin);
        }
    }

    return vectVoisins;// retourne les voisins du sommet
};

//modèle initiale pour le labyrinthe
void GrapheLabyrinthe::DFS(Position p1)
{

    unordered_set<Position, pair_hash> visite;

    stack<Position> pile;

    visite.insert(p1); // ajoute p1 dans visite
    pile.push(p1);

    while (!pile.empty())
    {

        Position pcourant = pile.top();

        pile.pop();

        cout << pcourant.first << "," << pcourant.second << " " << endl;

        for (Voisins &voisinsommet : voisins_possibles(pcourant)) // récupère les voisins du sommetcourant
        {
            if (visite.find(voisinsommet.getPositionnement()) == visite.end()) // vérifie qu'on n'a pas encore visité les voisins de sommetcourant
            {

                pile.push(voisinsommet.getPositionnement());     // ajoute voisinsommet dans la pile
                visite.insert(voisinsommet.getPositionnement()); // ajoute voisinsommet dans visite
            }
        }
    }
};