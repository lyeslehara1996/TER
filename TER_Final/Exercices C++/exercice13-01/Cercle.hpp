#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"
#include "Point.hpp"

class Cercle : public Forme {
private:
    Point centre;
    double rayon;

public:
    Cercle(Point c, double r);

    std::ostream& affiche(std::ostream& os) const override;
    double getRayon() const;
};

#endif
