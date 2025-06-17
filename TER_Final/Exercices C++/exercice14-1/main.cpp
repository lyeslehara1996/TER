#include <iostream>
#include "Paire1.hpp"
#include "Paire2.hpp"
#include "PaireChaineValeur.hpp"

int main()
{
    Paire1<int> p1_1{5, 8};
    std::cout << "Paire: " << p1_1.first() << ' ' << p1_1.second() << '\n';

    const Paire1<double> p1_2{2.3, 4.5};
    std::cout << "Paire: " << p1_2.first() << ' ' << p1_2.second() << '\n';

    Paire2<int, double> p2_1{5, 6.7};
    std::cout << "Paire: " << p2_1.first() << ' ' << p2_1.second() << '\n';

    const Paire2<double, int> p2_2{2.3, 4};
    std::cout << "Paire: " << p2_2.first() << ' ' << p2_2.second() << '\n';

    PaireChaineValeur<int> pcv{"Hello", 5};
    std::cout << "Paire: " << pcv.first() << ' ' << pcv.second() << '\n';

    return 0;
}
