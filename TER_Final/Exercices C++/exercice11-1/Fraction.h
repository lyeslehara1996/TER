#ifndef POINT2D_H // Vérifie si MATH_UTILS_H n'est pas encore défini
#define POINT2D_H

class Fraction
{
//les méthodes 
public:
//constructeur sans paramètres
    Fraction();
//constructeur avec paramètres 
    Fraction(int a, int b);


    void affiche();
    Fraction operator*(Fraction f);
    void simplifier();

//les attributs 
private:
    int _a;
    int _b;

};

#endif