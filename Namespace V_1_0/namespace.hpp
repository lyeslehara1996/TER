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

    //La reponse à la Première question 
    /*
    la création d'images particulières (blanche, mire sinusoïdale, damier)
    */

    // Allocation d'une image
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
    std::vector<T> createSinusoidalImage(size_t width, size_t height, double frequency) {
        std::vector<T> image(width * height);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                double val = std::sin(2 * M_PI * frequency * x / width);
                double normalized = (val + 1.0) * 0.5; // [0, 1]
                image[y * width + x] = static_cast<T>(normalized * std::numeric_limits<T>::max());
            }
        }
        return image;
    }

    // Damier
    template <typename T>
    std::vector<T> createCheckerboardImage(size_t width, size_t height, size_t squareSize) {
        std::vector<T> image(width * height);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                bool isWhite = ((x / squareSize) % 2 == (y / squareSize) % 2);
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

    // Sauvegarde en PGM pour des types 16 bits (comme uint16_t)
    void savePGM16(const std::vector<uint16_t>& image, size_t width, size_t height, const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P5\n" << width << " " << height << "\n65535\n";
        for (auto val : image) {
            ofs.put(val >> 8);    // High byte
            ofs.put(val & 0xFF);  // Low byte
        }
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
    void savePPM(const std::vector<uint8_t>& imageRGB, size_t width, size_t height, const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P6\n" << width << " " << height << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(imageRGB.data()), imageRGB.size());
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


std::vector<uint8_t> loadLUTBinary(const std::string& filename) {
    std::vector<uint8_t> lut(256 * 3);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur lecture LUT binaire.\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
}


std::vector<uint8_t> applyLUT(const std::vector<uint8_t>& grayImage, const std::vector<uint8_t>& lut) {
    std::vector<uint8_t> colorImage(grayImage.size() * 3);
    for (size_t i = 0; i < grayImage.size(); ++i) {
        uint8_t val = grayImage[i];
        colorImage[i * 3 + 0] = lut[val * 3 + 0];
        colorImage[i * 3 + 1] = lut[val * 3 + 1];
        colorImage[i * 3 + 2] = lut[val * 3 + 2];
    }
    return colorImage;
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
std::vector<T> readRawImage3C(const std::string& filename, int width, int height, int channels = 3, bool littleEndian = true) {
    size_t expectedSize = static_cast<size_t>(width) * height * channels * sizeof(T);
    std::vector<T> image(expectedSize / sizeof(T));

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("readRawImage: Failed to open file.");
    }

    file.read(reinterpret_cast<char*>(image.data()), expectedSize);
    if (file.gcount() != static_cast<std::streamsize>(expectedSize)) {
        throw std::runtime_error("readRawImage: File size doesn't match expected dimensions.");
    }

    if (!littleEndian) {
        // Si l'ordre des octets est big-endian, inverser les octets de chaque pixel (supposé être de type T)
        for (auto& pixel : image) {
            // Supposons que T est un type à plusieurs octets (comme uint16_t, uint32_t, float, etc.)
            char* pixelBytes = reinterpret_cast<char*>(&pixel);
            std::reverse(pixelBytes, pixelBytes + sizeof(T));  // Inverser l'ordre des octets
        }
    }

    return image;
}


template<typename T>
std::vector<T> readRawImageRGB(const std::string& filename, size_t width, size_t height, 
                                size_t channels = 3, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
                  "T doit être un type numérique.");

    const size_t numValues = width * height * channels;
    const size_t expectedBytes = numValues * sizeof(T);

    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        throw std::runtime_error("Erreur : impossible d'ouvrir le fichier RAW.");
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize != static_cast<std::streamsize>(expectedBytes)) {
        throw std::runtime_error("Erreur : taille du fichier incohérente avec les dimensions et les canaux.");
    }

    std::vector<T> image(numValues);

    if (bigEndian && sizeof(T) > 1) {
        for (size_t i = 0; i < numValues; ++i) {
            uint8_t bytes[sizeof(T)];
            file.read(reinterpret_cast<char*>(bytes), sizeof(T));
            T value = 0;
            for (size_t b = 0; b < sizeof(T); ++b)
                value = (value << 8) | bytes[b];
            image[i] = value;
        }
    } else {
        file.read(reinterpret_cast<char*>(image.data()), expectedBytes);
    }

    return image;
}
}