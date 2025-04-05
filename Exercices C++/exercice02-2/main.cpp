#include <iostream>
#include "somme.h"

int main() {
    int a, b;
    saisie(a, b);
    float s = somme(a, b);
    affichage(s);
    return 0;
}
