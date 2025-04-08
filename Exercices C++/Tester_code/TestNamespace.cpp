#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <type_traits>

namespace v1_0 {

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

void savePPM(const std::vector<uint8_t>& imageRGB, size_t width, size_t height, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(imageRGB.data()), imageRGB.size());
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
std::vector<uint8_t> readRawImage8(const std::string& filename, size_t width, size_t height) {
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<uint8_t> image(width * height);
    if (!ifs) {
        std::cerr << "Erreur ouverture fichier RAW 8 bits.\n";
        return image;
    }
    ifs.read(reinterpret_cast<char*>(image.data()), image.size());
    return image;
}

void writeRawImage8(const std::vector<uint8_t>& image, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Erreur écriture fichier RAW 8 bits.\n";
        return;
    }
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
}

template <typename SrcType, typename DstType>
std::vector<DstType> convertImage(const std::vector<SrcType>& input, SrcType srcMax, DstType dstMax) {
    std::vector<DstType> output(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        float normalized = static_cast<float>(input[i]) / static_cast<float>(srcMax);
        output[i] = static_cast<DstType>(normalized * dstMax);
    }
    return output;
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

} // end namespace

int main() {
    size_t width = 256, height = 256;

    auto imgBlanche = v1_0::createWhiteImage<uint8_t>(
        v1_0::allocationImage<uint8_t>(width, height), 255);
    v1_0::savePGM(imgBlanche, width, height, "imgBlanche.pgm");

    auto imgRGB = v1_0::createRGBImage(width, height, 51, 102, 255);
    v1_0::savePPM(imgRGB, width, height, "imgBleue.ppm");

    auto imgSin = v1_0::allocationImage<uint8_t>(width, height);
    v1_0::createSinusoidalImage(imgSin, width, height, 0.1, 255);
    v1_0::savePGM(imgSin, width, height, "imgSinusoidale.pgm");

    auto imgDamier = v1_0::allocationImage<uint8_t>(width, height);
    v1_0::createCheckerboardImage(imgDamier, width, height, 16, 0, 255);
    v1_0::savePGM(imgDamier, width, height, "imgDamier.pgm");

    v1_0::writeRawImage8(imgBlanche, "imgBlanche.raw");
    auto imageLue = v1_0::readRawImage8("imgBlanche.raw", width, height);
    v1_0::savePGM(imageLue, width, height, "imageLueDepuisRAW.pgm");

    std::vector<uint16_t> img16(width * height, 60000);
    auto img8 = v1_0::convertImage<uint16_t, uint8_t>(img16, 65535, 255);
    v1_0::savePGM(img8, width, height, "converted8bits.pgm");

    auto lut = v1_0::loadLUTBinary("LUT/16_equal.lut");
    auto colorized = v1_0::applyLUT(img8, lut);
    v1_0::savePPM(colorized, width, height, "colorized.ppm");

    auto lutt = v1_0::loadLUTBinary("Auxctq.lut");
    auto imgGris = v1_0::createWhiteImage<uint8_t>(v1_0::allocationImage<uint8_t>(width, height), 127);
    auto imgCouleur = v1_0::applyLUT(imgGris, lutt);
    v1_0::savePPM(imgCouleur, width, height, "imgFaussesCouleurs.ppm");

    // Tests lecture/écriture 16 bits endian
    std::vector<uint16_t> imgEndian(width * height, 0x1234);
    v1_0::writeRawImage<uint16_t>(imgEndian, "img16_LE.raw", false);
    v1_0::writeRawImage<uint16_t>(imgEndian, "img16_BE.raw", true);

    auto imgLE = v1_0::readRawImage<uint16_t>("img16_LE.raw", width, height, false);
    auto imgBE = v1_0::readRawImage<uint16_t>("img16_BE.raw", width, height, true);

    auto imgLE8 = v1_0::convertImage<uint16_t, uint8_t>(imgLE, 65535, 255);
    auto imgBE8 = v1_0::convertImage<uint16_t, uint8_t>(imgBE, 65535, 255);
    v1_0::savePGM(imgLE8, width, height, "img16_LE_visual.pgm");
    v1_0::savePGM(imgBE8, width, height, "img16_BE_visual.pgm");

    return 0;
}
