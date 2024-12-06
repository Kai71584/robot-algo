#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
;

class robot
{
private:
    /* data */
    string direction;

public:
    robot(string dirInit)
    {
        if (dirInit == "NN" || dirInit == "OO" || dirInit == "SS" || dirInit == "EE")
        {
            direction = dirInit;
        }
        else
        {
            direction = "EE";
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

        if (direction=="NN")
        {
            direction = "OO";
        } else if (direction=="OO")
        {
            direction = "SS";
        }else if (direction=="SS")
        {
            direction = "EE";
        }else if (direction=="EE")
        {
            direction = "NN";
        }
        
        
    }

    void roterD()
    {
        cout << "roter 90 degrées droite" << endl;

        if (direction=="NN")
        {
            direction = "EE";
        } else if (direction=="EE")
        {
            direction = "SS";
        }else if (direction=="SS")
        {
            direction = "OO";
        }else if (direction=="OO")
        {
            direction = "NN";
        }
    }
};
