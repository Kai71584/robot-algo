#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include "graphe.h"

using namespace std;

// Classe pour représenter une étiquette complexe
class Etiquette {
public:
    Etiquette(char c, const std::string& description = "")
        : poids(c), description(description) {}

    // Accesseurs et mutateurs
    int getPoids() const { return poids; }
    void setPoids(int p) { poids = p; }

    std::string getDescription() const { return description; }
    void setDescription(const std::string& desc) { description = desc; }

    // Affiche les informations de l'étiquette
    void afficher() const {
        std::cout << "Poids: " << poids << ", Description: " << description;
    }

private:
    char c;
    std::string description;
};