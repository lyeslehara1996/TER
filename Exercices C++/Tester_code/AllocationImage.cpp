#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstdint>

namespace v1_0 {

// Allocation d'une image générique
template <typename T>
std::vector<T> allocateImage(size_t width, size_t height) {
    return std::vector<T>(width * height);
}

// Création d'une image blanche
template <typename T>
std::vector<T> createWhiteImage(size_t width, size_t height, T maxValue) {
    return std::vector<T>(width * height, maxValue);
}
//sauvegarder l image dans le repertoire 
void savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P5\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    ofs.close();
}

//afficher la matrice d une image 
void printImage(const std::vector<uint8_t>& image, size_t width, size_t height) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            std::cout << std::setw(4) << static_cast<int>(image[y * width + x]) << " ";
        }
        std::cout << '\n';
    }
}
} // namespace v1_0

// Test des fonctionnalités
int main() {
    size_t width = 256, height = 256;
    auto imgWhite = v1_0::createWhiteImage<uint8_t>(width, height, 255);
    std::cout << "Images générées avec succès!" << std::endl;

    v1_0::savePGM(imgWhite, width, height, "white_image.pgm");
    auto imgallocation = v1_0::allocateImage<uint8_t>(width, height);
   v1_0::printImage(imgWhite, 255, 255);

    return 0;
}