#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdint>
#include <type_traits>

namespace v1_0 {
using namespace v1_0;
template <typename T>
std::vector<T> allocationImage(size_t width, size_t height) {
    return std::vector<T>(width * height);
}

template <typename T>
std::vector<T> createWhiteImage(const std::vector<T>& image, T maxValue) {
    return std::vector<T>(image.size(), maxValue);
}

void savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P5\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
}


std::vector<uint8_t> createRGBImage(size_t width, size_t height, uint8_t R, uint8_t G, uint8_t B) {
    std::vector<uint8_t> imageRGB(width * height * 3);
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

template <typename T>
std::vector<T> createSinusoidalImage(size_t width, size_t height, double frequency, T maxValue) {
    static_assert(std::is_arithmetic<T>::value, "T doit être un type numérique");

    std::vector<T> image(width * height);

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            double normalized = std::sin(frequency * x) * 0.5 + 0.5; // dans [0,1]
            image[y * width + x] = static_cast<T>(normalized * maxValue);
        }
    }

    return image;
}

template <typename T>
std::vector<T> createCheckerboardImage(size_t width, size_t height, size_t squareSize, T color1, T color2) {
    static_assert(std::is_arithmetic<T>::value, "T doit être un type numérique");

    std::vector<T> image(width * height);

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            bool isEvenSquare = ((x / squareSize) + (y / squareSize)) % 2 == 0;
            image[y * width + x] = isEvenSquare ? color1 : color2;
        }
    }

    return image;
}




template <typename T>
std::vector<T> readRawImage8bit(const std::string& filename, size_t width, size_t height) {
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<T> image(width * height);

    if (!ifs) {
        std::cerr << "Erreur ouverture fichier RAW.\n";
        return image;
    }

    ifs.read(reinterpret_cast<char*>(image.data()), image.size() * sizeof(T));

    if (!ifs) {
        std::cerr << "Erreur lors de la lecture du fichier.\n";
    }

    return image;
}

void writePGMImage8(const std::vector<uint8_t>& image, const std::string& filename, int width, int height) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Erreur d'écriture fichier PGM.\n";
        return;
    }

    // Écriture du header PGM (P5 = format binaire)
    ofs << "P5\n" << width << " " << height << "\n255\n";

    // Écriture des pixels en binaire
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
}

std::vector<uint16_t> readRawImage16(const std::string& filename, size_t width, size_t height, bool fileIsBigEndian) {
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<uint16_t> image(width * height);
    if (!ifs) {
        std::cerr << "Erreur ouverture fichier RAW 16 bits.\n";
        return image;
    }

    for (size_t i = 0; i < image.size(); ++i) {
        uint8_t byte1 = ifs.get();
        uint8_t byte2 = ifs.get();

        uint16_t pixel;

        if (fileIsBigEndian) {
            pixel = (byte1 << 8) | byte2; // Big endian
        } else {
            pixel = (byte2 << 8) | byte1; // Little endian
        }

        image[i] = pixel;
    }

    return image;
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




// === FONCTIONS GÉNÉRIQUES RAW AVEC ENDIANNESS ===
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
    static_assert(std::is_integral<T>::value, "T doit être un type entier");

    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Erreur écriture RAW " << sizeof(T)*8 << " bits.\n";
        return;
    }

    for (T val : image) {
        uint8_t bytes[sizeof(T)];
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

} 