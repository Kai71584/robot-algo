#include"graphe2.h"
using namespace std;


graphe2::graphe2(){


}



void graphe2::ajouterSommett(int a, int b){

    pair<int,int> t = make_pair(a,b);

    if (positions.find(t) != positions.end())
        {
            throw std::runtime_error("Le sommet existe déjà.");
        }

    positions.insert(t);
};


void graphe2::arreterr(pair<int,int> p1,pair<int,int> p2, string a){


 
    voisins f;
    f.positionnement=p2;
    f.direction=a;
        //voisin[p1].insert(make_pair(p2,a));

    listeadjacence2[p1].insert(f);

};

void graphe2::taf(){
string a;
int tab[8][9];
        int n=8;
        int g=9;
         for(int i=0;i<n; i++){
            for(int j=0;j<g;j++){

                if(tab[i][j]==0){

                    pair<int,int> p1 = {i,j};

                    if(i+1<n &&tab[i+1][j]==0){
                        //sud
                        a="SS";
                        pair<int,int> p2 = {i+1,j};
                        arreterr(p1,p2,a);
                        
                    }

                    if(tab[i-1][j]==0){
                        //nord
                        a="NN";
                        pair<int,int> p2 = {i-1,j};
                        arreterr(p1,p2,a);
                        
                    }

                    if(tab[i][j+1]==0){
                        //est
                        a="EE";
                        pair<int,int> p2 = {i,j+1};
                        arreterr(p1,p2,a);
                        
                    }

                    if(tab[i][j-1]==0){
                        //ouest
                        a="OO";
                        pair<int,int> p2 = {i,j-1};
                        arreterr(p1,p2,a);
                        
                    }



                 

                }
                
            }
        }

};

 

vector<voisins> graphe2::voisinde(pair<int,int> p1){

vector<voisins> voisinss;

if(listeadjacence2.find(p1)!=listeadjacence2.end()){

    for(auto voisin :listeadjacence2[p1]){
        voisinss.push_back(voisin);
    }

}

return voisinss;
};


void graphe2::DFS(pair<int,int> p1){

std::unordered_set<std::pair<int,int>> visite;

stack<pair<int,int>> pile;

visite.insert(p1);//ajoute p1 dans visite
    pile.push(p1);

while(!pile.empty()){

    pair<int,int> pcourant = pile.top();

    pile.pop();

    cout << pcourant.first << "," << pcourant.second << " ";

      for (voisins &voisinsommet : voisinde(pcourant))//récupère les voisins du sommetcourant
        {
            if (visite.find(voisinsommet.positionnement) == visite.end())//vérifie qu'on n'a pas encore visité les voisins de sommetcourant
            {

                pile.push(voisinsommet.positionnement);// ajoute voisinsommet dans la pile
                visite.insert(voisinsommet.positionnement);// ajoute voisinsommet dans visite
            }
        }
}


};