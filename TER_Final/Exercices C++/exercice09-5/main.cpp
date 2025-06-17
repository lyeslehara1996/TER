#include <iostream>
#include <cmath>


// Fonction de test : f(x) = x^2
double f(double x) {
    return x * x;
}

// Primitive analytique de x^2
double primitive_x2(double a, double b) {
    return (b * b * b - a * a * a) / 3.0;
}

// Intégration par trapèzes
double integration_trapeze(double a, double b, int n, double (*func)(double)) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }
    return h * sum;
}

// Intégration par Simpson
double integration_simpson(double a, double b, int n, double (*func)(double)) {
    if (n % 2 != 0) ++n; // Simpson nécessite n pair
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * func(x);
    }
    return h * sum / 3.0;
}

int main() {
    double a = 0, b = 3;
    int n = 100;

    double exact = primitive_x2(a, b);
    double approx_trap = integration_trapeze(a, b, n, f);
    double approx_simpson = integration_simpson(a, b, n, f);

    std::cout << "Intégrale exacte : " << exact << std::endl;
    std::cout << "Méthode des trapèzes : " << approx_trap << std::endl;
    std::cout << "Méthode de Simpson : " << approx_simpson << std::endl;

    return 0;
}