#include "Cercle.hpp"

Cercle::Cercle(Point c, double r) : centre(c), rayon(r) {}

std::ostream& Cercle::affiche(std::ostream& os) const {
    return os << "Cercle(" << centre << ", radius " << rayon << ")";
}

double Cercle::getRayon() const {
    return rayon;
}
