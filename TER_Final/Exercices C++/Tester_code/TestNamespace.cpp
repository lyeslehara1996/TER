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


template <typename SrcType, typename DstType>
std::vector<DstType> convertImage(const std::vector<SrcType>& input, SrcType srcMax, DstType dstMax) {
    std::vector<DstType> output(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
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

int main() {

    using namespace v1_0;

    const size_t width = 256;
    const size_t height = 256;

    // 1. Allocation d'une image
    std::vector<uint8_t> image = allocationImage<uint8_t>(width, height);
    std::cout << "Image allouée (" << width << "x" << height << ")\n";

    // 2. Création image blanche
    auto whiteImage = createWhiteImage(image, uint8_t(255));
    writeRawImage8(whiteImage, "white.raw");

    // 3. Mire sinusoïdale
    auto sinusImage16 = createSinusoidalImage<uint16_t>(width, height, 0.1, 65535);
    writeRawImage(sinusImage16, "sinus16.raw", false);

    // 4. Damier
    auto checkerboard = createCheckerboardImage<uint8_t>(width, height, 32, 0, 255);
    writeRawImage8(checkerboard, "checker.raw");

    // 5. Lecture d’image 16 bits avec endianness
    auto image16LE = readRawImage<uint16_t>("sinus16.raw", width, height, false); // little endian
    auto image16BE = readRawImage<uint16_t>("sinus16.raw", width, height, true);  // big endian
    std::cout << "Lecture des images 16 bits avec endianness faite.\n";

      // 5. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      
      // 5. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 6. Conversion vers 8 bits
      auto imageCoeur8 = convertImage<uint16_t, uint8_t>(imageCoeurLE, 65535, 255);
      writeRawImage8(imageCoeur8, "imageCoeur8.raw");
  
      auto sinogram8 = convertImage<uint16_t, uint8_t>(sinogramLE, 65535, 255);
      writeRawImage8(sinogram8, "imageCoeur8.raw");
  
      // 7. Application LUT binaire
      auto lut = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\BlackOnWhite.lut)"); // Assurez-vous que ce fichier existe
      auto colorImage = applyLUT(imageCoeur8, lut);
      savePPM(colorImage, width, height, "imageCoeur8color_from_lut.ppm");
  
      auto lutsinogram = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brown.lut)"); // Assurez-vous que ce fichier existe
      auto colorImagesinogram = applyLUT(sinogram8, lutsinogram);
      savePPM(colorImagesinogram, width, height, "sinogram8color_from_lut.ppm");
  
      // 8. Sauvegarde d’images PGM
      savePGM(imageCoeur8, width, height, "imageCoeur8.pgm");
      savePGM(sinogram8, width, height, "sinogram8.pgm");
  
      std::cout << "Tous les traitements sont terminés.\n";
  
      return 0;
}
