#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"
#include "Point.hpp"

class Triangle : public Forme {
private:
//Relation d'une composition 
    Point p1, p2, p3;

public:
    Triangle(Point a, Point b, Point c);

    std::ostream& affiche(std::ostream& os) const override;
};

#endif
