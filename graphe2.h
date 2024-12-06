#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include<set>
using namespace std;
struct pair_hash {
    //template <typename T1, typename T2>
    std::size_t operator() (const std::pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);  // Hachage du premier élément de la paire
        auto h2 = std::hash<int>{}(p.second); // Hachage du second élément de la paire
        // Combine les deux hachages en un seul
        return h1 ^ h2 ;  // Hachage combiné avec un décalage pour réduire les collisions
    }
};

struct voisins{

    pair<int,int> positionnement;
    string direction;

};
/*struct Voisin {
    int destination; // Noeud de destination
    string label; // Étiquette optionnelle pour l'arête
};
struct Position {
    int x;

    int y;

    Position(int x1, int y1){

        x=x1;

        y=y1;
    };
};*/


class graphe2{

public:

graphe2();


void ajouterSommett(int,int);

void arreterr(pair<int,int>,pair<int,int>,string);

void taf();

std::vector<voisins> voisinde(pair<int,int>);

void DFS(pair<int,int>);


private:

  set<pair<int,int>> positions;

   unordered_set<pair<int,int>, std::string> voisin;

   std::unordered_map<pair<int,int>, vector<pair<int,int>, std::string>, pair_hash> listeadjacence;

    std::unordered_map<pair<int,int>, set<voisins>, pair_hash> listeadjacence2;


};