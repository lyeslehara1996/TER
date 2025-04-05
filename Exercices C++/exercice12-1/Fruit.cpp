#include<iostream>
#include "Fruit.h"
#include<string>
using namespace std;



Fruit::Fruit(std::string nom, std::string couleur):_nom{nom},_couleur{couleur}{}

std::string Fruit::getnom() const{
    return _nom;
}
std::string Fruit::getcouleur()const {

    return _couleur;
}