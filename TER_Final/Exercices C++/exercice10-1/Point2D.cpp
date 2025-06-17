
#include <iostream>
#include "Point2D.h"
#include "Math.h"
//valeur par defaut initialisée 0
Point2D::Point2D() : _x{0}, _y{0} {}
//constructeur avec paramètres
Point2D::Point2D(double x, double y) : _x{x}, _y{y} {}

void Point2D::affiche()
{

    std::cout << "Point2D ( " << _x << " , " << _y << " ) " << std::endl;
}

double Point2D::distance(Point2D p)
{

    return sqrt((p._x - _x) * (p._x - _x) + (p._y - _y) * (p._y - _y));
}

double distanceEntre(Point2D p1, Point2D p2)
{

    return sqrt((p2._x - p1._x) * (p2._x - p1._x) + (p2._y - p1._y) * (p2._y - p1._y));
}