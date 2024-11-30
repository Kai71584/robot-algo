#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include "Etiquette.h"
#include <stack>
#include <queue>
using namespace std;

class graphe {
public:
    // Ajoute un sommet avec une étiquette d'objet
    void ajouterSommet(const std::string& sommet, const Etiquette& etiq) {
        if (sommets.find(sommet) != sommets.end()) {
            throw std::runtime_error("Le sommet existe déjà.");
        }
        sommets[sommet] = etiq;
    }

    void AjouterSommet2(const std::int& i, const std::int& j){



        sommetss[i][j] = {};
    }

    void AjouterArete2(const std::int& i1, const std::int& j1,const std::int& i2, const std::int& j2){

        c char;
        if(i2>i1 && j1==j2){
            cout << 'E'<<endl;
            c='E';
        }
        if(i2<i1 && j1==j2){
            cout << 'O' << endl;
            c='O';
        }
        if(i2==i1 && j1<j2){
            cout << 'S' << endl;
            c='S';
        }
        if(i2==i1 && j1>j2){
            cout << 'N' << endl;
            c='N';
        }
        aretess[i1][j1].insert(i2,j2,c);
    }

    // Ajoute une arête avec une étiquette d'objet entre deux sommets
    void ajouterArete(const std::string& u, const std::string& v, const Etiquette& etiq) {
        if (sommets.find(u) == sommets.end() || sommets.find(v) == sommets.end()) {
            throw std::runtime_error("Un ou plusieurs sommets n'existent pas.");
        }
        aretes[u][v] = etiq;
    }

    // Modifie l'étiquette d'un sommet existant
    void modifierEtiquetteSommet(const std::string& sommet, const Etiquette& nouvelleEtiq) {
        if (sommets.find(sommet) == sommets.end()) {
            throw std::runtime_error("Le sommet n'existe pas.");
        }
        sommets[sommet] = nouvelleEtiq;
    }

    // Modifie l'étiquette d'une arête existante
    void modifierEtiquetteArete(const std::string& u, const std::string& v, const Etiquette& nouvelleEtiq) {
        if (aretes[u].find(v) == aretes[u].end()) {
            throw std::runtime_error("L'arête n'existe pas.");
        }
        aretes[u][v] = nouvelleEtiq;
    }

    // Affiche les sommets avec leurs étiquettes
    void afficherSommets() const {
        for (const auto& [sommet, etiq] : sommets) {
            std::cout << "Sommet: " << sommet << ", Etiquette: ";
            etiq.afficher();
            std::cout << "\n";
        }
    }

    // Affiche les arêtes avec leurs étiquettes
    void afficherAretes() const {
        for (const auto& [u, destinations] : aretes) {
            for (const auto& [v, etiq] : destinations) {
                std::cout << "Arete: " << u << " -> " << v << ", Etiquette: ";
                etiq.afficher();
                std::cout << "\n";
            }
        }
    }

    std::unordered_set<std::pair<int,int>> recuperationsvoisisn(pair<int,int> a){

        std::unordered_set<std::pair<int,int>> point;

        if(sommetssr.find(a)!= sommetssr.end()){
            for(const auto &voisin:sommetssr[a]){
                point.push_back(voisin);
            }
        }
        else {
        throw std::runtime_error("Le sommet n'existe pas.");
        }



        return point;
    }

    void DFS(const std::int& i, const std::int& j){
        stack<std::pair<int,int>> pile;//pile
        std::unordered_set<std::pair<int,int>> visite;

        visite.insert({i,j});
        pile.push({i,j});

        while(!pile.empty()){

            pair<int,int> a = pile.top();

            pile.pop();

            cout << a << end;

            for(const pair<int,int> &voisinsommet: recuperationvoisins(a)){
                if(visite.find(voisinsommet)== visite.end()){
                    pile.push(voisinsommet);
                    visite.insert(voisinsommet);
                }
            }



        }
    }


    void initialisationgraphe(int[][] a){

        int b = sizeof(a)/sizeof(a[0]);
        int c = sizeof(a)/sizeof(a[0][0]);
        for(int i=0; i<b, i++){

            for(int j=0; i<c; j++){

                AjouterSommet2(i,j);
            }
        }

         for(int i=0; i<b, i++){

            for(int j=0; i<c; j++){

                if(a[i][j]==0){

                    if(a[i][j]==0 && a[i+1][j]==0){ // Est
                        AjouterArete2(i,j,i+1,j);
                    }
                    if(a[i][j]==0 && a[i-1][j]==0){ // Ouest
                        AjouterArete2(i,j,i-1,j);
                    }
                    if(a[i][j]==0 && a[i][j+1]==0){ // Nord
                        AjouterArete2(i,j,i,j+1);
                    }
                    if(a[i][j]==0 && a[i][j-1]==0){ // Sud
                        AjouterArete2(i,j,i,j-1);
                    }
                }
            }
        }

    }

private:
    // Map de sommets avec leurs étiquettes d'objets
    std::unordered_map<std::string, Etiquette> sommets;

    // Map d'adjacence pour les arêtes, chaque arête ayant une étiquette d'objet
    std::unordered_map<std::string, std::unordered_map<std::string, Etiquette>> aretes;

    std::unordered_map<std::int, Etiquette> sommetsr;

    std::unordered_map(pair<int,int>) sommetssr;

    std::unordered_map<std::int, std::unordered_map<std::int/*, Etiquette std::char*/>> sommets;

    std::unordered_map<std::int, std::unordered_map<std::int,<std::unordered_map<std::int,std::unordered_map<std::int, std::char>>>> aretess;

    std::unordered_map(pair<int,int>, pair<int,int>, char) arretessss;
};