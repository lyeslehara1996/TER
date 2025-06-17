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
    Fraction simplifier();
    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &in, Fraction &fraction);
    friend Fraction operator*(Fraction f1, Fraction f2);
};

#endif