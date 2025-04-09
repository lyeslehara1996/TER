#include "getPlusGrandRayon.hpp"
#include "Cercle.hpp"
#include <algorithm>

double getPlusGrandRayon(const std::vector<Forme*>& formes) {
    double maxRayon = 0.0;

    for (const Forme* f : formes) {
        const Cercle* c = dynamic_cast<const Cercle*>(f);
        if (c && c->getRayon() > maxRayon) {
            maxRayon = c->getRayon();
        }
    }

    return maxRayon;
}
