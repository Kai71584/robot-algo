#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
;

class robot
{
private:
    /* data */
    char direction;
    

public:
    robot(char dirInit){
        switch (dirInit)
        {
        case 'N':
        case 'n':
        case 'O':
        case 'o':
        case 'S':
        case 's':
        case 'E':
        case 'e':        
        direction = dirInit;
        break;

        default:
        cout << "Direction non reconnue, le robot pointe vers le nord par défaut" << endl;
            direction = 'N';
            break;
        }
    };
    ~robot();

    void avancer()
    {
        cout << "avance de 10cm" << endl;
    }

    void reculer()
    {
        cout << "recule de 10cm" << endl;
    }

    void roterG()
    {
        cout << "roter 90 degrées gauche" << endl;
        
        switch (direction)
        {
        case 'N':
        case 'n':
            direction = 'O';
            break;

        case 'O':
        case 'o':
            direction = 'S';
            break;

        case 'S':
        case 's':
            direction = 'E';
            break;

        case 'E':
        case 'e':
            direction = 'N';
            break;

        default:
            break;
        }
    }

    void RoterD()
    {
        cout << "roter 90 degrées droite" << endl;

         switch (direction)
        {
        case 'N':
        case 'n':
            direction = 'E';
            break;

        case 'O':
        case 'o':
            direction = 'N';
            break;

        case 'S':
        case 's':
            direction = 'O';
            break;

        case 'E':
        case 'e':
            direction = 'S';
            break;

        default:
            break;
        }
    }
};
