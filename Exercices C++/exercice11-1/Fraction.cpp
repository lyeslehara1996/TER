#include <iostream>
#include <numeric>
#include "Fraction.h"

Fraction::Fraction() : _a{0}, _b{1} {}
Fraction::Fraction(int a, int b) : _a{a}, _b{b} {}

void Fraction::affiche()
{

    std::cout << _a << " / " << _b << std::endl;
}

Fraction Fraction::operator*(Fraction f)
{
    int a = _a * f._a;
    int b = _b * f._b;

    return Fraction(a, b);
}

void Fraction::simplifier()
{

    int gcd = std::gcd(_a, _b);
    _a /= gcd;
    _b /= gcd;
}
