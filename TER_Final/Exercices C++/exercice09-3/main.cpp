#include <iostream>
#include <functional>
#include "Operation.hpp"

void saisie(float& x, float& y, char& op) {
    std::cout << "Entrez deux nombres : ";
    std::cin >> x >> y;
    std::cout << "Entrez une opération (+, -, *, /) : ";
    std::cin >> op;
}

int main() {
    float x, y;
    char op;
    saisie(x, y, op);

    switch (op) {
        case '+': afficheOperation(x, y, addition); break;
        case '-': afficheOperation(x, y, soustraction); break;
        case '*': afficheOperation(x, y, multiplication); break;
        case '/': afficheOperation(x, y, division); break;
        default:
            std::cout << "Opérateur non valide.\n";
    }

    std::function<float(float, float)> f;
    switch (op) {
        case '+': f = [](float a, float b) { return a + b; }; break;
        case '-': f = [](float a, float b) { return a - b; }; break;
        case '*': f = [](float a, float b) { return a * b; }; break;
        case '/': f = [](float a, float b) { return b != 0 ? a / b : 0.0f; }; break;
        default:
            std::cout << "Opérateur non valide (lambda).\n";
            return 1;
    }

    afficheOperationF(x, y, f); // appel avec lambda via std::function

    return 0;
}
