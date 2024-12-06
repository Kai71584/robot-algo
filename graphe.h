#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include "Etiquette.h"
#include <stack>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);  // Hachage du premier élément de la paire
        auto h2 = std::hash<T2>{}(p.second); // Hachage du second élément de la paire
        // Combine les deux hachages en un seul
        return h1 ^ (h2 << 1);  // Hachage combiné avec un décalage pour réduire les collisions
    }
};
struct Position {
    int x;

    int y;

    Position(int x1, int y1){

        x=x1;

        y=y1;
    };
};
class Coord
{
public:
    Coord() {

    };

    Coord(int coordX, int coordY, int valeurs)
    {

        x = coordX;

        y = cordY;

        valeur = valeurs;
    };

    Coord(int )

    int getX()
    {

        return x;
    }

    int getY()
    {
        return y;
    }

    int getValeur(){
        return valeur;
    }


    int setX(int coordX){

        x = coordX;

        return x;
    }

    int setY(int coordY){

        y=coordY;

        return y;
    }

    int setValeur(int valeurs){
        valeur = valeurs;

        return valeur;
    }

private:
    int x;
    int y;
    int valeur;

    pair<int,int>;
};

class graphe
{
public:
    // Ajoute un sommet avec une étiquette d'objet
    void ajouterSommet(const std::string &sommet, const Etiquette &etiq)
    {
        if (sommets.find(sommet) != sommets.end())
        {
            throw std::runtime_error("Le sommet existe déjà.");
        }
        sommets[sommet] = etiq;
    }

     void ajouterSommett(int x, int y, const Etiquette &etiq)
    {
        if (sommets.find(sommet) != sommets.end())
        {
            throw std::runtime_error("Le sommet existe déjà.");
        }



        //sommets[p] = etiq;


        positions.insert(make_pair(x,y));

        positions[{x,y}]=etiq;
    }

    void arreterr(pair<int,int>& p1, pair<int,int>& p2){

        string a="fdsidfhsdkjf";

        voisin[p1].insert(p2,a)
    }

    void taf(){
        string a="sfsd";
        set<Voisin> voisinage;
        int tab[8][9];
        n=8;
        g=9;
        for(int i=0;i<n; i++){
            for(int j=0;j<g;i++){

                if(tab[i][j]==1){

                    if(tab[i+1][j]==1){
                        //sud
                        a="SS";
                        voisinage.insert(Voisin(make_pair(i+1,j),a));
                    }
                    if(tab[i-1][j]==1){
                        //nord
                        a="NN";
                        voisinage.insert(Voisin(make_pair(i-1,j),a));
                    }
                    if(tab[i][j+1]==1){
                        //est
                        a="EE";
                        voisinage.insert(Voisin(make_pair(i,j+1),a));
                    }
                    if(tab[i][j-1]==1){
                        //ouest
                        a="OO";
                        voisinage.insert(Voisin(make_pair(i,j-1),a));
                    }



                    if(tab[i-1][j-1]==1){
                        voisinage.insert(Voisin(make_pair(i-1,j-1),a));
                    }
                    if(tab[i+1][j-1]==1){
                        voisinage.insert(Voisin(make_pair(i+1,j-1),a));
                    }
                    if(tab[i+1][j+1]==1){
                        voisinage.insert(Voisin(make_pair(i+1,j+1),a));
                    }
                    if(tab[i-1][j+1]==1){
                        voisinage.insert(Voisin(make_pair(i-1,j+1),a));
                    }

                }
                listeadjacence[make_pair(i,j)].insert(voisinage);
            }
        }
    }



    void voisinde(pair<int,int>& p){

        auto it = listeadjacence.find(p);
        if (it != listeadjacence.end()) {
        for (const auto& voisin : it->second) {
        std::cout << "(" << voisin->.first.first << ", " << voisin->first.second << ")" << "nom" << voisin->second<<std::endl;
        }
        }
        else {
            cout << "Introuvable" << endl;
        }
    }



    void AjouterSommet2(Coord coord)
    {

        // sommetss[i][j] = {};
        //sommets2[{i, j}] = {};

        sommets1[coord]={};
    }

    void AjouterSommet3(int x,int y){

        
        sommets1[pair<x,y>];


    }

    void AjouterArete3(Coord coord1, Coord coord2){

         c char;
        if (coord2.getX() > coord1.getX() && coord1.getY() == coord2.getY())
        {
            cout << 'E' << endl;
            c = 'E';
        }
        if (coord2.getX() < coord1.getX() && coord1.getY() == coord2.getY())
        {
            cout << 'O' << endl;
            c = 'O';
        }
        if (coord2.getX() == coord1.getX() && coord1.getY() < coord2.getY())
        {
            cout << 'S' << endl;
            c = 'S';
        }
        if (coord2.getX() == coord1.getX() && coord1.getY() > coord2.getY())
        {
            cout << 'N' << endl;
            c = 'N';
        }

        aretes11[coord1][coord2]=c;


    }

    void AjouterArete2(const std::int &i1, const std::int &j1, const std::int &i2, const std::int &j2)
    {

        c char;
        if (i2 > i1 && j1 == j2)
        {
            cout << 'E' << endl;
            c = 'E';
        }
        if (i2 < i1 && j1 == j2)
        {
            cout << 'O' << endl;
            c = 'O';
        }
        if (i2 == i1 && j1 < j2)
        {
            cout << 'S' << endl;
            c = 'S';
        }
        if (i2 == i1 && j1 > j2)
        {
            cout << 'N' << endl;
            c = 'N';
        }
        aretess[i1][j1].insert(i2, j2, c);
    }

    void AjouterArete4(const pair<int, int> p1, const pair<int, int> p2)
    {

        int i1=p1.first
        int j1=p1.second;

        int i2=p2.first;
        int j2=p2.second;
        
        c char;
        if (i2 > i1 && j1 == j2)
        {
            cout << 'E' << endl;
            c = 'E';
        }
        if (i2 < i1 && j1 == j2)
        {
            cout << 'O' << endl;
            c = 'O';
        }
        if (i2 == i1 && j1 < j2)
        {
            cout << 'S' << endl;
            c = 'S';
        }
        if (i2 == i1 && j1 > j2)
        {
            cout << 'N' << endl;
            c = 'N';
        }

        arretesss.(p1, p2, c);
    }

    void construiregraphe(int tableau[][]){

        int n;
        int g;

        

        for(int i=0; i<n; i++){
            for(int j=0;k<g;j++){

                int valeur = tab[i][j];
                Coord coord(i,j,valeur);

                AjouterSommet2(coord);
                
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0;k<g;j++){

               if(tab[i][j]==0){

                    if(tab[i+1][j]==0){
                        
                    }
                     if(tab[i-1][j]==0){
                        
                    }
                     if(tab[i][j+1]==0){
                        
                    }
                     if(tab[i][j-1]==0){
                        
                    }

               }
            }
        }

    }

    // Ajoute une arête avec une étiquette d'objet entre deux sommets
    void ajouterArete(const std::string &u, const std::string &v, const Etiquette &etiq)
    {
        if (sommets.find(u) == sommets.end() || sommets.find(v) == sommets.end())
        {
            throw std::runtime_error("Un ou plusieurs sommets n'existent pas.");
        }
        aretes[u][v] = etiq;
    }

    void ajouterAretet(Position p1, Position p2, const Etiquette &etiq)
    {
        if (sommets.find(p1) == sommets.end() || sommets.find(p2) == sommets.end())
        {
            throw std::runtime_error("Un ou plusieurs sommets n'existent pas.");
        }
        aretes[p1][p2] = etiq;
    }

    // Modifie l'étiquette d'un sommet existant
    void modifierEtiquetteSommet(const std::string &sommet, const Etiquette &nouvelleEtiq)
    {
        if (sommets.find(sommet) == sommets.end())
        {
            throw std::runtime_error("Le sommet n'existe pas.");
        }
        sommets[sommet] = nouvelleEtiq;
    }

    // Modifie l'étiquette d'une arête existante
    void modifierEtiquetteArete(const std::string &u, const std::string &v, const Etiquette &nouvelleEtiq)
    {
        if (aretes[u].find(v) == aretes[u].end())
        {
            throw std::runtime_error("L'arête n'existe pas.");
        }
        aretes[u][v] = nouvelleEtiq;
    }

    // Affiche les sommets avec leurs étiquettes
    void afficherSommets() const
    {
        for (const auto &[sommet, etiq] : sommets)
        {
            std::cout << "Sommet: " << sommet << ", Etiquette: ";
            etiq.afficher();
            std::cout << "\n";
        }
    }

    // Affiche les arêtes avec leurs étiquettes
    void afficherAretes() const
    {
        for (const auto &[u, destinations] : aretes)
        {
            for (const auto &[v, etiq] : destinations)
            {
                std::cout << "Arete: " << u << " -> " << v << ", Etiquette: ";
                etiq.afficher();
                std::cout << "\n";
            }
        }
    }

    std::unordered_set<std::pair<int, int>> recuperationsvoisisn(pair<int, int> a)
    {

        std::unordered_set<std::pair<int, int>> point;

        if (sommetssr.find(a) != sommetssr.end())
        {
            for (const auto &voisin : sommetssr[a])
            {
                point.push_back(voisin);
            }
        }
        else
        {
            throw std::runtime_error("Le sommet n'existe pas.");
        }

        return point;
    }

    void DFS(const std::int &i, const std::int &j)
    {
        stack<std::pair<int, int>> pile; // pile
        std::unordered_set<std::pair<int, int>> visite;

        visite.insert({i, j});
        pile.push({i, j});

        while (!pile.empty())
        {

            pair<int, int> a = pile.top();

            pile.pop();

            cout << a << end;

            for (const pair<int, int> &voisinsommet : recuperationvoisins(a))
            {
                if (visite.find(voisinsommet) == visite.end())
                {
                    pile.push(voisinsommet);
                    visite.insert(voisinsommet);
                }
            }
        }
    }

    void initialisationgraphe(int[][] a)
    {

        int b = sizeof(a) / sizeof(a[0]);
        int c = sizeof(a) / sizeof(a[0][0]);
        for (int i = 0; i < b, i++)
        {

            for (int j = 0; i < c; j++)
            {

                AjouterSommet2(i, j);
            }
        }

        for (int i = 0; i < b, i++)
        {

            for (int j = 0; i < c; j++)
            {

                if (a[i][j] == 0)
                {

                    if (a[i][j] == 0 && a[i + 1][j] == 0)
                    { // Est
                        AjouterArete2(i, j, i + 1, j);
                    }
                    if (a[i][j] == 0 && a[i - 1][j] == 0)
                    { // Ouest
                        AjouterArete2(i, j, i - 1, j);
                    }
                    if (a[i][j] == 0 && a[i][j + 1] == 0)
                    { // Nord
                        AjouterArete2(i, j, i, j + 1);
                    }
                    if (a[i][j] == 0 && a[i][j - 1] == 0)
                    { // Sud
                        AjouterArete2(i, j, i, j - 1);
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


   set::<pair<int,int>> positions;

   set::<pair<int,int>, std::string> Voisin;

   std::unordered_map<positions, vector<Voisin*>, pair_hash> listeadjacence;



   /* std::unordered_map<std::int, Etiquette> sommetsr;

    std::unordered_map(pair<int, int>) sommetssr;

    std::unordered_map<std::int, std::unordered_map<std::int /*, Etiquette std::char*///>> sommets;

    /*std::unordered_map<pair<int, int>> sommets2;

    std::unordered_map < std::int, std::unordered_map<std::int, <std::unordered_map<std::int, std::unordered_map<std::int, std::char>>>> aretess;

    std::unordered_map<pair<int, int>, pair<int, int>, char> arretessss;

    unordered_map<
    std::unordered_map<Coord coordonnes>sommets1;
    std::unordered_map<Coord, std::unordered_map<Coord, char>> aretes11;*/


};