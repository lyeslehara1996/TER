#include <iostream>
#include "Operation.hpp"

float addition(float a, float b) {
     return a + b; 
    
    }
float soustraction(float a, float b) {
     return a - b; 
}
float multiplication(float a, float b) {
     return a * b; 
}
float division(float a, float b) {
    if (b != 0) {
        return a / b;
    }else{

        std::cout << "Erreur : division par zéro.\n";
        return 0;
    }
}

void afficheOperation(float x, float y, float (*operation)(float, float)) {
    float res = operation(x, y);
    std::cout << x << " op " << y << " = " << res << " (pointeur de fonction)\n";
}

// Affichage avec std::function
void afficheOperationF(float x, float y, std::function<float(float, float)> operation) {
    float res = operation(x, y);
    std::cout << x << " op " << y << " = " << res << " (std::function)\n";
}
