#include <iostream>
#include <vector>
#include "Forme.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"

int getPlusGrandRayon(const std::vector<Forme*>& formes) {
    int max = 0;
    for (Forme* f : formes) {
        Cercle* c = dynamic_cast<Cercle*>(f);
        if (c) {
            if (c->getRayon() > max)
                max = c->getRayon();
        }
    }
    return max;
}

int main() {
    std::vector<Forme*> v{
        new Cercle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Cercle{Point{4, 5, 6}, 3}
    };

       for (const Forme* f : v) {
        f->affiche(std::cout);
    }

    std::cout << "Le plus grand rayon est : " << getPlusGrandRayon(v) << '\n';

    return 0;
}