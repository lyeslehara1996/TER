#ifndef IMAGERGB_HPP
#define IMAGERGB_HPP


#include "Image.hpp"
#include <cstddef>
#include <vector>
#include <stdexcept>


class ImageRGB : public Image<unsigned char>{

public :

ImageRGB(const std::vector<unsigned char>& rgbdata, size_t width, size_t height);
ImageRGB(const std::vector<unsigned char>& grayImage, size_t width, size_t height, const std::vector<unsigned char>& lut);
    
const std::vector<unsigned char>& getRGBData() const;
void savePPM(const std::string& filename) const;
std::vector<unsigned char> loadLUTBinary(const std::string& filename);

template <typename T>
std::vector<T> readRawImageRGB(const std::string& filename, size_t width, size_t height, size_t channels, bool bigEndian = false) ;

template <typename T>
std::vector<T> convertRGBToGrayscale(const std::vector<uint8_t>& rgbImage, size_t width, size_t height);
private: 
std::vector<unsigned char> _rgbData;

};

ImageRGB::ImageRGB(const std::vector<unsigned char>& rgbData, size_t width, size_t height)
    : Image<unsigned char>(width, height), _rgbData(rgbData) {}

    ImageRGB::ImageRGB(const std::vector<unsigned char>& grayImage, size_t width, size_t height, const std::vector<unsigned char>& lut)
    : Image<unsigned char>(width, height), _rgbData(width * height * 3)
{
    if (lut.size() != 256 * 3) {
        throw std::runtime_error("LUT invalide. Elle doit contenir exactement 256x3 valeurs.");
    }

    for (size_t i = 0; i < grayImage.size(); ++i) {
        unsigned char intensity = grayImage[i];
        size_t lutIndex = intensity * 3;

        _rgbData[3 * i + 0] = lut[lutIndex + 0]; // R
        _rgbData[3 * i + 1] = lut[lutIndex + 1]; // G
        _rgbData[3 * i + 2] = lut[lutIndex + 2]; // B
    }
}
const std::vector<unsigned char>& ImageRGB::getRGBData() const {
    return _rgbData;
}



void ImageRGB::savePPM(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur : impossible de créer le fichier " << filename << std::endl;
        return;
    }

    file << "P6\n" << getWidth() << " " << getHeigth()<< "\n255\n";
    file.write(reinterpret_cast<const char*>(_rgbData.data()), getWidth() * getWidth() * 3);
    file.close();
}


std::vector<unsigned char> loadLUTBinary(const std::string& filename) {
    std::vector<unsigned char> lut(256 * 3);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur lecture LUT binaire.\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
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




#endif