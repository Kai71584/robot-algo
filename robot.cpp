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
    robot(char dirInit)
    {
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

    void roterD()
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

    void pointeVers(char versDir)
    {
        //vérifie ou le robot veux aller et tourne selon ou le robot pointe déjà
        switch (versDir)
        {
        case 'N':
        case 'n':
            switch (direction)
            {
            case 'O':
            case 'o':
                roterD();
                break;

            case 'S':
            case 's':
                roterD();
                roterD();
                break;

            case 'E':
            case 'e':
                roterG();
                break;

            default:
                break;
            }
            break;

        case 'O':
        case 'o':
            switch (direction)
            {
            case 'N':
            case 'n':
                roterG();
                break;

            case 'S':
            case 's':
                roterD();
                break;

            case 'E':
            case 'e':
                roterG();
                roterG();
                break;

            default:
                break;
            }
            break;

        case 'S':
        case 's':
            switch (direction)
            {
            case 'N':
            case 'n':
                roterG();
                roterG();
                break;

            case 'O':
            case 'o':
                roterG();
                break;

            case 'E':
            case 'e':
                roterD();
                break;

            default:
                break;
            }
            break;

        case 'E':
        case 'e':
            switch (direction)
            {
            case 'N':
            case 'n':
                roterD();
                break;

            case 'O':
            case 'o':
                roterG();
                roterG();
                break;

            case 'S':
            case 's':
                roterG();
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
};
