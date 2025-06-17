#ifndef POINT2D_H 
#define POINT2D_H

class Point2D
{

public:
    Point2D(double x, double y);
    Point2D();
    void affiche();
    double distance(Point2D p);
    //methode amie n'est pas une methode nembre mais peux acceder aux attributs privé, 
    //n'est pas obligé de créer l objet pour faire appel a cette methode 
    friend double distanceEntre(Point2D p1, Point2D p2);

    private:
    double _x;
    double _y;

};

#endif