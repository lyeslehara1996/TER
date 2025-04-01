#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f1, f2;
    std::cout << "Entrer la fraction 1: ";
    std::cin >> f1;
    std::cout << "Entrer la fraction 2: ";
    std::cin >> f2;
    std::cout << f1 << " * " << f2 << " est " << f1 * f2 << '\n';

    return 0;
}