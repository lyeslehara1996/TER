#include <iostream>
#include <math.h>

const double g = 9.8;


double hauteur_chute(double h0, double t) {
    double h = h0 - 0.5 * g * p * t * t;
    return (h > 0) ? h : 0; // Si h < 0, retourner 0 (l'objet est au sol)
}

int main() {
    double h0, t;

    
    std::cout << "Entrez la hauteur initiale de l'objet  ";
    std::cin >> h0;

   
    std::cout << "Entrez le temps écoulé (en secondes) : ";
    std::cin >> t;

    
    double hauteur = hauteur_chute(h0, t);

   
    std::cout << "La hauteur de l'objet après " << t << " secondes est de " << hauteur << " mètres." << std::endl;

    return 0;
}