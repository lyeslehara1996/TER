#include <iostream>
#include "somme.h"

void saisie(int &a, int &b) {
    std::cout << "Donner deux valeurs a et b :" << std::endl;
    std::cin >> a >> b;
}

float somme(int a, int b) {
    return a + b;
}

void affichage(float s) {
    std::cout << "La somme des deux nombres a et b est : " << s << std::endl;
}
