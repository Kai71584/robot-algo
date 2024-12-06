#include <iostream>
#include <unordered_map>
#include <unordered_set>
//#include "graphe.h"
#include "robot.h"
using namespace std;


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