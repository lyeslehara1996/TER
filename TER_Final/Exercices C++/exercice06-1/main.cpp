#include <iostream>
#include <cmath>

const float G = 9.81f;

float calculHauteur(float h0, float t) {
    return h0 - 0.5f * G * t * t;
}

int main() {
    float h0;
    std::cout << "Entrez la hauteur initiale (en mètres) : ";
    std::cin >> h0;

    float t = 0.0f;          
    float hauteur = h0;       
    float pas = 0.5f;         
    

    // Boucle tant que l'objet est au-dessus du sol
    while (hauteur > 0) {
        hauteur = calculHauteur(h0, t);
        if (hauteur < 0) hauteur = 0; // éviter les valeurs négatives

        std::cout << "t = " << t << " hauteur = " << hauteur << " m\n";
        t += pas;
    }

    std::cout << " L'objet a touché le sol à t = " << t - pas << " s.\n";

    return 0;
}
