#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdint>
#include <cmath> 
#include <limits>
#include <iomanip> 
#include <algorithm>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace v1_0 {

    
    template <typename T>
    std::vector<T> allocationImage(size_t width, size_t height) {
        return std::vector<T>(width * height);
    }

    // Image blanche
    template <typename T>
    std::vector<T> createWhiteImage(size_t width, size_t height) {
        return std::vector<T>(width * height, std::numeric_limits<T>::max());
    }

    // Mire sinusoïdale
    template <typename T>
    std::vector<T> SinusoidalImage(size_t width, size_t height, double frequence) {
        std::vector<T> image(width * height);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                double valeur = std::sin(2 * M_PI * frequence * x / width);
                double Valnormaliser = (valeur + 1.0) * 0.5; // normaliser en 0 et 1 
                image[y * width + x] = static_cast<T>(Valnormaliser * std::numeric_limits<T>::max());
            }
        }
        return image;
    }

    // Damier
    template <typename T>
    std::vector<T> ImageDamier(size_t width, size_t height, size_t tailleCase) {
        std::vector<T> image(width * height);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                bool isWhite = ((x / tailleCase) % 2 == (y / tailleCase) % 2);
                image[y * width + x] = isWhite ? std::numeric_limits<T>::max() : 0;
            }
        }
        return image;
    }

    // Sauvegarde en PGM (grayscale)
    void savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P5\n" << width << " " << height << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
   
    template <typename T>
    std::vector<T> createRGBImage(size_t width, size_t height, T R, T G, T B) {
        static_assert(std::is_integral<T>::value, "createRGBImage requiert un type entier");
    
        std::vector<T> imageRGB(width * height * 3);
        for (size_t i = 0; i < width * height; ++i) {
            imageRGB[i * 3 + 0] = R;
            imageRGB[i * 3 + 1] = G;
            imageRGB[i * 3 + 2] = B;
        }
        return imageRGB;
    }
    
    void savePPM(const std::vector<unsigned char>& image, int width, int height, const std::string& filename) {
        std::ofstream file(filename, std::ios::binary);
        if (!file) {
            std::cerr << "Erreur : impossible de créer le fichier " << filename << std::endl;
            return;
        }
    
        // Écrire l'en-tête du fichier PPM
        file << "P6\n" << width << " " << height << "\n255\n";
    
        // Écrire les données de l'image (R, G, B)
        file.write(reinterpret_cast<const char*>(image.data()), width * height * 3);
    
        file.close();
    }

    void printImage(const std::vector<uint8_t>& image, size_t width, size_t height) {
        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                std::cout << std::setw(4) << static_cast<int>(image[y * width + x]) << " ";
            }
            std::cout << '\n';
        }
    }
    // La réponse à la deuxième question 
    /*
    la lecture / écriture de fichiers images au format brut (.raw). 
    A la lecture,il faudra prendre en compte à la fois le codage big endian, 
     et le codage little endian (le plus répandu pour les images codées sur plusieurs octets). 
    */
    
    template <typename T>
std::vector<T> readRawImage(const std::string& filename, size_t width, size_t height, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value, "T doit être un type entier");

    std::ifstream ifs(filename, std::ios::binary);
    std::vector<T> image(width * height);

    if (!ifs) {
        std::cerr << "Erreur ouverture RAW " << sizeof(T)*8 << " bits.\n";
        return image;
    }

    for (size_t i = 0; i < image.size(); ++i) {
        uint8_t bytes[sizeof(T)];
        ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
        T value = 0;
        if (bigEndian) {
            for (size_t b = 0; b < sizeof(T); ++b)
                value = (value << 8) | bytes[b];
        } else {
            for (size_t b = 0; b < sizeof(T); ++b)
                value |= (static_cast<T>(bytes[b]) << (8 * b));
        }
        image[i] = value;
    }

    return image;
}


template <typename T>
void writeRawImage(const std::vector<T>& image, const std::string& filename, bool bigEndian = false) {
    std::ofstream ofs(filename, std::ios::binary);
    for (T val : image) {
        uint8_t bytes[sizeof(T)] = {};
        if (bigEndian) {
            for (size_t b = 0; b < sizeof(T); ++b)
                bytes[sizeof(T) - 1 - b] = (val >> (8 * b)) & 0xFF;
        } else {
            for (size_t b = 0; b < sizeof(T); ++b)
                bytes[b] = (val >> (8 * b)) & 0xFF;
        }
        ofs.write(reinterpret_cast<char*>(bytes), sizeof(T));
    }
}


std::vector<uint8_t> loadLUT(const std::string& filename) {
    std::vector<uint8_t> lut(256 * 3);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur lecture LUT binaire.\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
}


// std::vector<uint8_t> applyLUT(const std::vector<uint8_t>& grayImage, const std::vector<uint8_t>& lut) {
//     std::vector<uint8_t> colorImage(grayImage.size() * 3);
//     for (size_t i = 0; i < grayImage.size(); ++i) {
//         uint8_t val = grayImage[i];
//         colorImage[i * 3 + 0] = lut[val * 3 + 0];
//         colorImage[i * 3 + 1] = lut[val * 3 + 1];
//         colorImage[i * 3 + 2] = lut[val * 3 + 2];
//     }
//     return colorImage;
// }

std::vector<uint8_t> convertRGBToGrayscale(const std::vector<uint8_t>& rgbImage, size_t width, size_t height) {
    std::vector<uint8_t> grayImage(width * height);
    for (size_t i = 0; i < width * height; ++i) {
        uint8_t r = rgbImage[i * 3 + 0];
        uint8_t g = rgbImage[i * 3 + 1];
        uint8_t b = rgbImage[i * 3 + 2];
        grayImage[i] = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
    }
    return grayImage;
}


std::vector<unsigned char> applyLUT(const std::vector<unsigned char>& grayImage, const std::vector<unsigned char>& lut) {
    if (lut.size() % 3 != 0) {
        throw std::runtime_error("Invalid LUT size. It must be a multiple of 3.");
    }

    size_t numColors = lut.size() / 3;
    std::vector<unsigned char> coloredImage(grayImage.size() * 3);

    for (size_t i = 0; i < grayImage.size(); ++i) {
        unsigned char intensity = grayImage[i];

        if (intensity >= numColors) {
            throw std::runtime_error("Gray level out of LUT range");
        }

        size_t lutIndex = intensity * 3;

        coloredImage[3 * i + 0] = lut[lutIndex + 0]; // R
        coloredImage[3 * i + 1] = lut[lutIndex + 1]; // G
        coloredImage[3 * i + 2] = lut[lutIndex + 2]; // B
    }

    return coloredImage;
}


// Conversion de type avec dynamique
template<typename SrcType, typename DstType>
std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjustDynamics) {
    std::vector<DstType> convertedImage(image.size());

    SrcType minVal = *std::min_element(image.begin(), image.end());
    SrcType maxVal = *std::max_element(image.begin(), image.end());

    for (size_t i = 0; i < image.size(); ++i) {
        if (adjustDynamics) {
            convertedImage[i] = static_cast<DstType>(
                ((image[i] - minVal) / static_cast<double>(maxVal - minVal)) * std::numeric_limits<DstType>::max()
            );
        } else {
            convertedImage[i] = static_cast<DstType>(image[i]);
        }
    }

    return convertedImage;
}

template <typename T>
std::vector<T> readRawImageRGB(const std::string& filename, size_t width, size_t height, size_t channels, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value, "T doit être un type entier");
    std::ifstream testFile(filename);
    if (!testFile) {
        std::cerr << "Le fichier n'existe pas ou le chemin est incorrect : " << filename << '\n';
    }
    
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<T> image(width * height * channels);

    if (!ifs) {
        std::cerr << "Erreur ouverture RAW " << sizeof(T) * 8 << " bits.\n";
        return image;
    }

    for (size_t i = 0; i < image.size(); ++i) {
        uint8_t bytes[sizeof(T)];
        ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
        T value = 0;
        if (bigEndian) {
            for (size_t b = 0; b < sizeof(T); ++b)
                value = (value << 8) | bytes[b];
        } else {
            for (size_t b = 0; b < sizeof(T); ++b)
                value |= (static_cast<T>(bytes[b]) << (8 * b));
        }
        image[i] = value;
    }

    return image;
}

}