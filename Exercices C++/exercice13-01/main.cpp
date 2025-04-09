#include <iostream>
#include <vector>
#include "Forme.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"
#include "getPlusGrandRayon.hpp"

int main() {
    std::vector<Forme*> v{
        new Cercle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Cercle{Point{4, 5, 6}, 3}
    };

    

    std::cout << "Le plus grand rayon est : " << getPlusGrandRayon(v) << '\n';

 

    return 0;
}