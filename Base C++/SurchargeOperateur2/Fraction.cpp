#include <iostream>
#include <numeric>
#include "Fraction.h"

using namespace std;

Fraction::Fraction() : _a{0}, _b{1} {}
Fraction::Fraction(int a, int b) : _a{a}, _b{b} {}

void Fraction::affiche()
{

    std::cout << _a << " / " << _b << std::endl;
}

Fraction operator*(Fraction f1, Fraction f2)
{
    int a = f1._a * f2._a;
    int b = f1._b * f2._b;

    return Fraction(a, b).simplifier();
}

Fraction Fraction::simplifier()
{

    int min_val = (_a < _b) ? _a : _b;  
        for (int i = min_val; i > 1; --i) { 
            if (_a % i == 0 && _b % i == 0) {
                return Fraction(_a / i, _b / i);
            }
        }
        return *this;
}

std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    out << f._a << "/" << f._b;
    return out;
}
std::istream &operator>>(std::istream &in, Fraction &f)
{
    char slash;
    in >> f._a >> slash >> f._b;
    f.simplifier();
    return in;
}