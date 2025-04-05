#ifndef FRUIT_H // Vérifie si MATH_UTILS_H n'est pas encore défini
#define FRUIT_H

#include<string>

class Fruit
{
private:
    std::string  _nom;
    std::string _couleur;

public:

Fruit(std::string nom, std::string couleur);
std::string getnom() const;
std::string getcouleur()const;

   
};

#endif