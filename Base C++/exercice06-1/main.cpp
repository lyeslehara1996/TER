#include <iostream>
#include <math.h>

const double g = 9.8;


double hauteur_chute(double h0, double t) {
    double h = h0 - 0.5 * g  * t * t;
    return (h > 0) ? h : 0; 
}

int main() {

    double h0, t;

    try {
       
        std::cout << "Entrez la hauteur initiale de l'objet (mètres) : ";
        std::cin >> h0;

        if (h0 <= 0) {
            throw std::invalid_argument("La hauteur doit être un superieur a 0");
        }
        std::cout << "Entrez le temps écoulé (en secondes) : ";
        std::cin >> t;


        double hauteur = hauteur_chute(h0, t);
        std::cout << "Après " << t << " secondes, la hauteur de l'objet est de " << hauteur << " mètres." << std::endl;

        
        
        std::cout << "L'objet a atteint le sol après " << t << " secondes." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}