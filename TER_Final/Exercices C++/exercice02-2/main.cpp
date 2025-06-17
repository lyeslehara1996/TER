#include <iostream>
#include "es.cpp"
void saisie(int &a, int &b); //declaration anticipé
float somme(int a, int b);
void affichage(float s);


int main() {
    int a, b;
    saisie(a, b);
    float s = somme(a, b);
    affichage(s);
    return 0;
}
