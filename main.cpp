#include <iostream>
#include <unordered_map>
#include <unordered_set>
//#include "graphe2.h"
#include "robot.h"
using namespace std;

void labyrinthe(Robot r){
    pair<int,int> depart;
    pair<int,int> arrive;
}


int main(){

    Robot r = Robot("NN");

    r.avancer();
    r.afficheDir();
    r.roterD();
    r.avancer();
    r.afficheDir();
    
    cout<< "Ceci est notre main" ;
    return 0;
}