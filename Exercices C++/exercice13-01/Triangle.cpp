#include "Triangle.hpp"

Triangle::Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {}

std::ostream& Triangle::affiche(std::ostream& os) const {
    return os << "Triangle(" << p1 << ", " << p2 << ", " << p3 << ")";
}
