#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction F{};
    Fraction F1{2, 5};
    Fraction F2{3, 8};
    Fraction F3{F1 * F2};

    F.affiche();
    F1.affiche();
    F2.affiche();
    F3.affiche();

    return 0;
}