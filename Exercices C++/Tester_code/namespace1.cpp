#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

// Alias pour une image 2D en niveaux de gris
using Image2D = std::vector<std::vector<T>>;


Image2D allocateImage(size_t width, size_t height) {
    return Image2D(height, std::vector<uint8_t>(width, 0));
}


//creation d une image blanche 
// la methode fill sert a remplir tout les element de vecteur avec d un nombre ici 255 pour creer une image blanche 

void createWhiteImage(Image2D& image) {
    for (auto& row : image) {
        std::fill(row.begin(), row.end(), 255);
    }
}


// Fonction pour allouer une image 2D de dimensions spécifiées
Image2D allocateImage(size_t width, size_t height) {
    return Image2D(height, std::vector<uint8_t>(width, 0));
}

// Fonction pour créer une image blanche (tous les pixels à 255)
void createWhiteImage(Image2D& image) {
    for (auto& row : image) {
        std::fill(row.begin(), row.end(), 255);
    }
}

// Fonction pour afficher l'image dans la console
void printImage(const Image2D& image) {
    for (const auto& row : image) {
        for (auto pixel : row) {
            std::cout << std::setw(4) << static_cast<int>(pixel) << " ";
        }
        std::cout << '\n';
    }
}

// Fonction pour enregistrer l'image au format PGM
void savePGM(const Image2D& image, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture.\n";
        return;
    }
    size_t height = image.size();
    size_t width = height ? image[0].size() : 0;
    ofs << "P5\n" << width << " " << height << "\n255\n";
    for (const auto& row : image) {
        ofs.write(reinterpret_cast<const char*>(row.data()), row.size());
    }
    ofs.close();
}

int main() {
    size_t width = 256;   // Largeur de l'image
    size_t height = 256;  // Hauteur de l'image

    // Étape 1 : Allouer l'image
    Image2D image = allocateImage(width, height);

    // Étape 2 : Créer une image blanche
    createWhiteImage(image);

    // Étape 3 : Afficher l'image
    std::cout << "Contenu de l'image blanche :\n";
    printImage(image);

    // Étape 4 : Enregistrer l'image au format PGM
    std::string filename = "image_blanche.pgm";
    savePGM(image, filename);
    std::cout << "Image blanche enregistrée sous '" << filename << "'.\n";

    return 0;
}
