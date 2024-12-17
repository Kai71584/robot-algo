/*
fichier: robot.cpp
autheur: William Roy
dernière MAJ: 2024-12-09 15:00 William
description: fonctions de la classe graphe
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

graphe::graphe()
{
}



pair<int,int> Voisins::getPositionnement(){
    return this->positionnement;
}

void Voisins::setPositionnement(std::pair<int,int> position){
    this->positionnement = position;
}

std::string Voisins::getDirection(){
    return this->direction;
}

void Voisins::setDirection(string d){
    this-> direction = d;
}

void graphe::ajouterSommet(int a, int b)
{

    std::pair<int, int> t = make_pair(a, b);

    if (positions.find(t) != positions.end())
    {
        throw std::runtime_error("Le sommet existe déjà.");
    }

    positions.insert(t);
};

void graphe::ajouterArrete(pair<int, int> p1, pair<int, int> p2, std::string a)
{

    Voisins f;
    f.setPositionnement(p2);
    f.setDirection(a);
    // voisin[p1].insert(make_pair(p2,a));

    listeadjacence2[p1].insert(f);
};

void graphe::creerConnexions(vector<vector<int>> tab)
{
    std::string a;

    
    size_t ligne = tab.size(); // nombre de lignes
    size_t colonne = tab[0].size();//nombre de colonnes
    
    int n=static_cast<int>(ligne);
    int g=static_cast<int>(colonne);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {

            ajouterSommet(i,j);

        
        }
        
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {

            if (tab[i][j] == 0)
            {

                pair<int, int> p1 = {i, j};

                if (i + 1 < n && tab[i + 1][j] == 0)
                {
                    // sud
                    a = "SS";
                    pair<int, int> p2 = {i + 1, j};
                    ajouterArrete(p1, p2, a);
                }

                if (i-1>=0 && tab[i - 1][j] == 0)
                {
                    // nord
                    a = "NN";
                    pair<int, int> p2 = {i - 1, j};
                    ajouterArrete(p1, p2, a);
                }

                if (j + 1 < n &&tab[i][j + 1] == 0)
                {
                    // est
                    a = "EE";
                    pair<int, int> p2 = {i, j + 1};
                    ajouterArrete(p1, p2, a);
                }

                if (j-1>=0 && tab[i][j - 1] == 0)
                {
                    // ouest
                    a = "OO";
                    pair<int, int> p2 = {i, j - 1};
                    ajouterArrete(p1, p2, a);
                }
            }
        }
    }
};

vector<Voisins> graphe::voisinde(pair<int, int> p1)
{

    vector<Voisins> voisinss;

    if (listeadjacence2.find(p1) != listeadjacence2.end())
    {

        for (auto voisin : listeadjacence2[p1])
        {
            voisinss.push_back(voisin);
        }
    }

    return voisinss;
};

void graphe::DFS(pair<int, int> p1)
{

    unordered_set<std::pair<int, int>,pair_hash> visite;

    stack<pair<int, int>> pile;

    visite.insert(p1); // ajoute p1 dans visite
    pile.push(p1);

    while (!pile.empty())
    {

        pair<int, int> pcourant = pile.top();

        pile.pop();

        cout << pcourant.first << "," << pcourant.second << " " <<endl;

        /*vector<Voisins> bb = voisinde(pcourant);
        unordered_set<pair<int, int>, pair_hash> abc;

        for (Voisins aa : bb)
        {
            abc.insert(aa.getPositionnement());
        }

        for (pair<int, int> elem : abc)
        {
            if (visite.find(elem) == visite.end())
            {
                // si élément n'est pas trouvé dans visite
            }
        }

        if (visite == abc)
        { // regarde s'il tous les voisins de ce coin la sont fait
            stack<pair<int, int>> p2;
            for (pair<int, int> d : visite)
            {
                p2.push(d);
            }

            pcourant = p2.top();
            p2.pop();

            // recommencer tant que visite == abc
            // cela veut dire recommence tant que tous les visites du voisinage ne sont pas faite
            // pas terminer manque une boucle
        }*/

        for (Voisins &voisinsommet : voisinde(pcourant)) // récupère les voisins du sommetcourant
        {
            if (visite.find(voisinsommet.getPositionnement()) == visite.end()) // vérifie qu'on n'a pas encore visité les voisins de sommetcourant
            {

                pile.push(voisinsommet.getPositionnement());     // ajoute voisinsommet dans la pile
                visite.insert(voisinsommet.getPositionnement()); // ajoute voisinsommet dans visite
            }
        }
    }
};