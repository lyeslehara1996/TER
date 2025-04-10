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
    
    
}    