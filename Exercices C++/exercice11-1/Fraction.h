#ifndef POINT2D_H // Vérifie si MATH_UTILS_H n'est pas encore défini
#define POINT2D_H

class Fraction
{
private:
    int _a;
    int _b;

public:
    Fraction();
    Fraction(int a, int b);
    void affiche();
    Fraction operator*(Fraction f);
    void simplifier();
};

#endif