#include <iostream>
#include "Point2D.h"

int main()
{
    Point2D P{};
    Point2D P1{3.0, 4.0};
    P.affiche();
    P1.affiche();

    std::cout << "la distance entre deux point est : " << P.distance(P1) << std::endl;
    std::cout << "la distance entre deux point est avec ami: " << distanceEntre(P, P1) << std::endl;

    return 0;
}