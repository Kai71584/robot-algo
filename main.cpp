/*
fichier: main.cpp
autheur: Pierre-Antoine Lajoie
dernière MAJ: 2024-12-09 13:40 P-A et William
description: parcours le labyrinthe avec un Robot
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "graphe.h"
#include "robot.h"

using namespace std;

void trouver_chemin(Robot r, GrapheLabyrinthe g, pair<int, int> depart, pair<int, int> arrive)
{
    cout << "Notre robot pointe vers ";
    r.afficheDir();
    cout << ", il commence en: (" << depart.first << "," << depart.second << ") et fini le labyrinthe en arrivant à: (" << arrive.first << "," << arrive.second << ")." << endl;

    // on fait un DFS pour parcourir le GrapheLabyrinthe

    unordered_set<std::pair<int, int>, pair_hash> visite; // collection des noeuds visités

    stack<pair<int, int>> pile;   // pile des voisins/noeuds à visiter
    stack<pair<int, int>> chemin; // pile des voisins/noeuds sur le chemin

    visite.insert(depart); // ajoute depart dans visite
    pile.push(depart);     // on ajoute le départ comme noeud à visiter
    chemin.push(depart);
    pair<int, int> pcourant = depart; // on commence à départ

    while (!pile.empty() && pcourant != arrive)
    {
        // Orientation
        r.mouvementOriente(pcourant, pile.top());

        if (pile.top() != pcourant)
        {
            // avancer
            r.avancer();
        }

        pcourant = pile.top();
        chemin.push(pcourant);
        visite.insert(pcourant);
        pile.pop();

        // On affiche notre position actuelle
        cout << "Point: ";
        cout << chemin.top().first << "," << chemin.top().second << " " << endl;

        bool aucunVoisinAFaire = true;

        // tant qu'il y as des voisins a faire et que on est pas arrivé à la fin
        while (aucunVoisinAFaire && pcourant != arrive)
        {
            for (Voisins &voisinsommet : g.voisins_possibles(chemin.top())) // récupère les voisins du sommetcourant
            {

                if (visite.find(voisinsommet.getPositionnement()) == visite.end()) // vérifie qu'on n'a pas encore visité les voisins de sommetcourant
                {
                    pile.push(voisinsommet.getPositionnement()); // ajoute voisinsommet dans la pile
                    aucunVoisinAFaire = false;                   // Il y as des voisins à faire, donc on veux sortir de cette boucle
                }
            }

            // si aucun voisin à faire
            if (aucunVoisinAFaire)
            {
                pair<int, int> tempCourant = chemin.top();
                chemin.pop(); // recule

                
                r.mouvementOriente(tempCourant, chemin.top());
                //r.mouvementOriente(make_pair(5,5), make_pair(5,4));
                
                if (chemin.top() != tempCourant)
                {
                    // avancer
                    r.avancer();
                }
                pcourant = chemin.top();
                // affiche la nouvelle position
                cout << "Point: ";
                cout << chemin.top().first << "," << chemin.top().second << " " << endl;
            }
        }
    }
}

int main()
{

    cout << "Ceci est notre main" << endl;

    // on crée notre robot et note GrapheLabyrinthe
    Robot monRobot = Robot();
    GrapheLabyrinthe monGraphe;

    // tableau qui sert à populer notre GrapheLabyrinthe
    vector<vector<int>> monTab = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}};



    // on popule le GrapheLabyrinthe
    monGraphe.creerConnexions(monTab);

    // on crée notre départ et notre entrée
    pair<int, int> depart = {2, 1};
    pair<int, int> fin = {3, 3};

    // parcours du labyrinthe
    trouver_chemin(monRobot, monGraphe, depart, fin);

    return 0;
}