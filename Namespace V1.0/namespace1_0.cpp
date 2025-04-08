#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <iomanip>
namespace v1_0 {
    using Image2D = std::vector<std::vector<uint8_t>>;

//allocation de memoire pour une image 2D  pour un seul vecteur 

template <typename T>
std::vector<T> allocationImage(size_t width, size_t height) {
    return std::vector<T>(width * height);
}

/*allocation de l image 2D avec une ligge qui est un vecteur  (vecteur de vecteur )

Cette méthode crée un vecteur de vecteurs, chaque vecteur interne représentant une ligne de l'image
Utilisez un std::vector de std::vector si vous avez besoin d'une structure plus flexible, capable de gérer
des images avec des dimensions variables ou irrégulières, au prix d'une utilisation mémoire potentiellement plus élevée.

En général, pour des raisons de performance et d'efficacité, il est recommandé d'utiliser un seul std::vector pour représenter une image 2D.
*/
Image2D allocateImage(size_t width, size_t height) {
    return Image2D(height, std::vector<uint8_t>(width, 0));
}

//creation d une image blanche 
// la methode fill sert a remplir tout les element de vecteur avec d un nombre ici 255 pour creer une image blanche 

void createWhiteImage(Image2D& image) {
    for (auto& row : image) {
        std::fill(row.begin(), row.end(), 255);
    }}

//en utilisant template avec un type génerique 
template <typename T>
std::vector<T> createWhiteImage(const std::vector<T>& image, T maxValue) {
    return std::vector<T>(image.size(), maxValue);
}

void savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P5\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    ofs.close();
}


//affichage de l image 
void printImage(const std::vector<uint8_t>& image, size_t width, size_t height) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            std::cout << std::setw(4) << static_cast<int>(image[y * width + x]) << " ";
        }
        std::cout << '\n';
    }
}


//create image RGB

std::vector<uint8_t> createRGBImage(size_t width, size_t height, uint8_t R, uint8_t G, uint8_t B) {
    std::vector<uint8_t> imageRGB(width * height * 3); // 3 composantes par pixel

    for (size_t i = 0; i < width * height; ++i) {
        imageRGB[i * 3 + 0] = R;
        imageRGB[i * 3 + 1] = G;
        imageRGB[i * 3 + 2] = B;
    }

    return imageRGB;
}
void savePPM(const std::vector<uint8_t>& imageRGB, size_t width, size_t height, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(imageRGB.data()), imageRGB.size());
    ofs.close();
}



//creation image sinusoidale

void createSinusoidalImage(std::vector<uint8_t>& image, size_t width, size_t height, double frequency, uint8_t maxValue) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            // Calcul de l'intensité sinusoïdale en fonction de la position horizontale (x)
            uint8_t value = static_cast<uint8_t>((std::sin(frequency * x) * 0.5 + 0.5) * maxValue);
            image[y * width + x] = value;
        }
    }
}



//creation motif damier

void createCheckerboardImage(std::vector<uint8_t>& image, size_t width, size_t height, size_t squareSize, uint8_t color1, uint8_t color2) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            // Calcul de la couleur basée sur la position de la case
            bool isEvenSquare = ((x / squareSize) + (y / squareSize)) % 2 == 0;
            image[y * width + x] = isEvenSquare ? color1 : color2;
        }
    }
}

 // Lecture d'un fichier .raw (8 bits par pixel)
 std::vector<uint8_t> readRawImage8(const std::string& filename, size_t width, size_t height) {
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<uint8_t> image(width * height);

    if (!ifs) {
        std::cerr << "Erreur lors de l'ouverture du fichier RAW pour lecture.\n";
        return image;
    }

    ifs.read(reinterpret_cast<char*>(image.data()), image.size());
    return image;
}


// Écriture d'un fichier .raw (8 bits par pixel)
void writeRawImage8(const std::vector<uint8_t>& image, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);

    if (!ofs) {
        std::cerr << "Erreur lors de l'ouverture du fichier RAW pour écriture.\n";
        return;
    }

    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
}


// Conversion avec adaptation de dynamique (optionnelle)
template <typename SrcType, typename DstType>
std::vector<DstType> convertImage(const std::vector<SrcType>& input, SrcType srcMax, DstType dstMax) {
    std::vector<DstType> output(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        // Normalisation et conversion
        float normalized = static_cast<float>(input[i]) / static_cast<float>(srcMax);
        output[i] = static_cast<DstType>(normalized * dstMax);
    }

    return output;
}

// LUT : tableau de 256 * 3 = 768 valeurs uint8_t (R, G, B pour chaque niveau de gris)
std::vector<uint8_t> applyLUT(const std::vector<uint8_t>& grayImage, const std::vector<uint8_t>& lut) {
    std::vector<uint8_t> colorImage(grayImage.size() * 3);

    for (size_t i = 0; i < grayImage.size(); ++i) {
        uint8_t val = grayImage[i];
        colorImage[i * 3 + 0] = lut[val * 3 + 0]; // R
        colorImage[i * 3 + 1] = lut[val * 3 + 1]; // G
        colorImage[i * 3 + 2] = lut[val * 3 + 2]; // B
    }

    return colorImage;
}

std::vector<uint8_t> loadLUTBinary(const std::string& filename) {
    std::vector<uint8_t> lut(256 * 3);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur de lecture LUT binaire\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
}

std::vector<uint8_t> loadLUTText(const std::string& filename) {
    std::vector<uint8_t> lut;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur de lecture LUT texte\n";
        return lut;
    }
    int val;
    while (file >> val) {
        lut.push_back(static_cast<uint8_t>(val));
    }
    return lut;
}

}



int main(){
    size_t width = 256;   // Largeur de l'image
    size_t height = 256;  // Hauteur de l'image

    auto Allocimg =   v1_0::allocationImage<uint8_t>(width,height);


    //utilisation d'un seul vecteur 
    auto imgBlanche = v1_0::createWhiteImage<uint8_t>(Allocimg, 255);
    
    std::cout << "Contenu de l'image blanche :\n";
    v1_0::printImage(imgBlanche,width,height);

    std::string filename = "imgBlanche.pgm";
  v1_0::savePGM(imgBlanche, width, height,filename);
  std::cout << "Image blanche enregistrée sous '" << filename << "'.\n";

  //image RGP
  auto imgRGB = v1_0::createRGBImage(width, height, 51, 102, 255);
  std::string rgbFilename = "imgBleue.ppm";
  v1_0::savePPM(imgRGB, width, height, rgbFilename);
  std::cout << "Image RGB bleue enregistrée sous '" << rgbFilename << "'.\n";

    // Création de la mire sinusoïdale
  auto imgSinusoidale = v1_0::allocationImage<uint8_t>(width, height);
  v1_0::createSinusoidalImage(imgSinusoidale, width, height, 0.1, 255);  // fréquence 0.1
  std::string SinusoidaleFilename = "imgSinusoidale.pgm";
  v1_0::savePGM(imgSinusoidale, width, height, SinusoidaleFilename);
  std::cout << "Image Sinusoidale enregistrée sous '" << SinusoidaleFilename << "'.\n";
 // Création du damier
 auto imgDamier = v1_0::allocationImage<uint8_t>(width, height);
 v1_0::createCheckerboardImage(imgDamier, width, height, 16, 0, 255);  // carrés de 16 pixels
 std::string damierFilename = "imgDamier.pgm";
 v1_0::savePGM(imgDamier, width, height, damierFilename);
 std::cout << "Image en damier enregistrée sous '" << damierFilename << "'.\n";


  // Enregistrement RAW
  std::string rawFilename = "imgBlanche.raw";
  v1_0::writeRawImage8(imgBlanche, rawFilename);
  std::cout << "Image blanche enregistrée au format RAW sous '" << rawFilename << "'.\n";

  // Lecture RAW
  auto imageLue = v1_0::readRawImage8(rawFilename, width, height);
  std::cout << "Image RAW relue depuis '" << rawFilename << "'.\n";

  // Vérification (optionnelle) : enregistrer en PGM après lecture RAW
  v1_0::savePGM(imageLue, width, height, "imageLueDepuisRAW.pgm");
  std::cout << "Image RAW relue sauvegardée au format PGM.\n";

// Conversion uint16_t -> uint8_t avec dynamique
std::vector<uint16_t> img16bits(width * height, 60000); // exemple 16 bits
auto img8bits = v1_0::convertImage<uint16_t, uint8_t>(img16bits, 65535, 255);
v1_0::savePGM(img8bits, width, height, "converted8bits.pgm");

// LUT : application de fausses couleurs
auto lut = v1_0::loadLUTBinary("LUT\\LUT\\16_equal.lut");  // ou loadLUTText("LUT.txt");
auto colorized = v1_0::applyLUT(img8bits, lut);
v1_0::savePPM(colorized, width, height, "colorized.ppm");

auto imgGris = v1_0::createWhiteImage<uint8_t>(v1_0::allocationImage<uint8_t>(256, 256), 127); // Image grise

auto lutt = v1_0::loadLUTBinary("Auxctq.lut"); // ou loadLUTText("palette.txt");

auto imgCouleur = v1_0::applyLUT(imgGris, lutt); // Image en fausses couleurs

v1_0::savePPM(imgCouleur, 256, 256, "imgFaussesCouleurs.ppm");

    return 0;
}