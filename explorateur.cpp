#include "explorateur.h"


GrapheLabyrinthe Explorateur::labyrinthe_to_graphe(vector<vector<int>> tab)
{
    string a;
    GrapheLabyrinthe graphe;
    size_t ligne = tab.size();      // nombre de lignes
    size_t colonne = tab[0].size(); // nombre de colonnes

    int n = static_cast<int>(ligne);
    int g = static_cast<int>(colonne);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {

            graphe.ajouterSommet(i, j);
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
                    graphe.ajouterArrete(p1, p2, a);
                }

                if (i - 1 >= 0 && tab[i - 1][j] == 0)// si le voisin nord du sommet est 0
                {
                    // nord
                    a = "NN";
                    Position p2 = {i - 1, j};
                    graphe.ajouterArrete(p1, p2, a);
                }

                if (j + 1 < n && tab[i][j + 1] == 0)// si le voisin est du sommet est 0
                {
                    // est
                    a = "EE";
                    Position p2 = {i, j + 1};
                    graphe.ajouterArrete(p1, p2, a);
                }

                if (j - 1 >= 0 && tab[i][j - 1] == 0)// si le voisin ouest du sommet est 0
                {
                    // ouest
                    a = "OO";
                    Position p2 = {i, j - 1};
                    graphe.ajouterArrete(p1, p2, a);
                }
            }
        }
    }

    return graphe;
};

void Explorateur::trouver_chemin(Robot r, GrapheLabyrinthe g, Position depart, Position arrive)
{
    cout << "Notre robot pointe vers ";
    r.afficheDir();
    cout << ", il commence en: (" << depart.first << "," << depart.second << ") et fini le labyrinthe en arrivant à: (" << arrive.first << "," << arrive.second << ")." << endl;

    // on fait un DFS pour parcourir le GrapheLabyrinthe

    unordered_set<Position, pair_hash> visite; // collection des noeuds visités

    stack<Position> pile;   // pile des voisins/noeuds à visiter
    stack<Position> chemin; // pile des voisins/noeuds sur le chemin

    visite.insert(depart); // ajoute depart dans visite
    pile.push(depart);     // on ajoute le départ comme noeud à visiter
    chemin.push(depart);
    Position pcourant = depart; // on commence à départ

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
                Position tempCourant = chemin.top();
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