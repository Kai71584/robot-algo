/*
fichier: robot.cpp
autheur: William Roy
dernière MAJ: 2024-12-17 15:00 William
description: déclarations de la classe GrapheLabyrinthe
*/

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
using namespace std;
struct pair_hash
{
     template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);  // Hachage du premier élément de la paire
        auto h2 = std::hash<T2>{}(p.second); // Hachage du second élément de la paire
        // Combine les deux hachages en un seul
        return h1 ^ h2; // Hachage combiné avec un décalage pour réduire les collisions
    }

    template <class T1, class T2>
    bool operator () (const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs) const {
        return lhs == rhs; // Compare les paires pour égalité
    }
};

class Voisins
{
    private:
    Position p;
    //pair<int,int> positionnement;
    std::string direction;
    public:
    pair<int,int> getPositionnement();
    void setPositionnement(pair<int,int>);
    string getDirection();
    void setDirection(string);
    // Définition de l'opérateur < pour permettre la comparaison
    bool operator<(const Voisins& other) const {
        return p.getposition() < other.p.getposition(); // Comparaison par position
    }

    
};

class Position {

    private:
    pair<int,int> position;
    public:
    Position();
    Position(pair<int,int>);
    pair<int,int> getposition() const{
        return this->position;
    };
    
};


class GrapheLabyrinthe
{

public:
    GrapheLabyrinthe();

    void ajouterSommet(int, int);

    void ajouterArrete(pair<int, int>, pair<int, int>, string);

    void creerConnexions(vector<vector<int>>);

    std::vector<Voisins> voisins_possibles(pair<int, int>);

    void DFS(Position position);

private:
    set<pair<int, int>> positions;

    std::unordered_map<Position, set<Voisins>, pair_hash> listeadjacence2;
};

