#ifndef POINT2D_H // Vérifie si MATH_UTILS_H n'est pas encore défini
#define POINT2D_H

class Point2D
{
private:
    double m_x;
    double m_y;

public:
    Point2D(double x, double y);
    Point2D();
    void affiche();
    double distance(Point2D p);
    friend double distanceEntre(Point2D p1, Point2D p2);
};

#endif