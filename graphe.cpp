/*
fichier: robot.cpp
autheur: William Roy
dernière MAJ: 2024-12-17 13:40 William
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

    listeadjacence2[p1].insert(f);
};

void GrapheLabyrinthe::creerConnexions(vector<vector<int>> tab)
{
    string a;

    size_t ligne = tab.size();      // nombre de lignes
    size_t colonne = tab[0].size(); // nombre de colonnes

    int n = static_cast<int>(ligne);
    int g = static_cast<int>(colonne);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {

            ajouterSommet(i, j);
        }
    }

    for (int i = 0; i < n; i++) // double boucle for pour parcourir le tableau
    {
        for (int j = 0; j < g; j++)
        {

            if (tab[i][j] == 0) // si le sommet est 0
            {

                Position p1 = {i, j};

                if (i + 1 < n && tab[i + 1][j] == 0)// si le voisin sud du sommet est 0
                {
                    // sud
                    a = "SS";
                    Position p2 = {i + 1, j};
                    ajouterArrete(p1, p2, a);
                }

                if (i - 1 >= 0 && tab[i - 1][j] == 0)// si le voisin nord du sommet est 0
                {
                    // nord
                    a = "NN";
                    Position p2 = {i - 1, j};
                    ajouterArrete(p1, p2, a);
                }

                if (j + 1 < n && tab[i][j + 1] == 0)// si le voisin est du sommet est 0
                {
                    // est
                    a = "EE";
                    Position p2 = {i, j + 1};
                    ajouterArrete(p1, p2, a);
                }

                if (j - 1 >= 0 && tab[i][j - 1] == 0)// si le voisin ouest du sommet est 0
                {
                    // ouest
                    a = "OO";
                    Position p2 = {i, j - 1};
                    ajouterArrete(p1, p2, a);
                }
            }
        }
    }
};

//Récupère les voisins du sommet
vector<Voisins> GrapheLabyrinthe::voisins_possibles(Position p1)
{

    vector<Voisins> voisinss;

    if (listeadjacence2.find(p1) != listeadjacence2.end())
    {

        for (auto voisin : listeadjacence2[p1])
        {
            voisinss.push_back(voisin);
        }
    }

    return voisinss;// retourne les voisins du sommet
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