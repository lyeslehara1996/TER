/*
Ce que tu viens de faire est bien… sauf les doublons et les includes manquants. 👉 Il n’y a pas de séparation possible avec un .cpp quand on travaille avec des templates.
Solution propre :

Soit tout dans .hpp comme ici

Soit .hpp + .tpp

Si tu veux, je peux te générer la version .hpp + .tpp toute prête.

👉 Si t’es ok on le range ensemble proprement.

EXPLICATION:


 Mais regarde bien : ce que tu viens de faire ici, c'est mettre la déclaration ET toute l'implémentation dans le .hpp.
Et c’est exactement comme ce que je te proposais avec le .tpp :

➡️ Les templates doivent être définis dans le même fichier (ou inclus dans le header) sinon le compilateur ne peut pas les instancier correctement.

*/


#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstddef>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <type_traits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T>
class Image {
public:
    Image(size_t width, size_t height);
    size_t getWidth() const;
    size_t getHeigth() const;
    const std::vector<T>& getData() const;
    void setData(const std::vector<T>& data);
    
     std::vector<T> createWhiteImage();
     std::vector<T> createSinusoidalImage(double frequency);
     std::vector<T> createCheckerboardImage(size_t squareSize);

    void savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) const;
    void writeRawImage(const std::string& filename) const;
    void printImage(const std::vector<T>& image, size_t nbCols, size_t nbRows) const;

     std::vector<T> readRawImage(const std::string& filename, size_t width, size_t height, bool bigEndian = false);
    template<typename SrcType, typename DstType>
     std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjustDynamics);


    T& operator()(size_t x, size_t y);
    const T& operator()(size_t x, size_t y) const;

private:
    size_t _width;
    size_t _height;
    std::vector<T> _data;
};

// Implémentations

template<typename T>
Image<T>::Image(size_t width, size_t height)
    : _width(width), _height(height), _data(width * height) {}

template<typename T>
size_t Image<T>::getWidth() const { return _width; }

template<typename T>
size_t Image<T>::getHeigth() const { return _height; }

template<typename T>
const std::vector<T>& Image<T>::getData() const { return _data; }

template<typename T>
void Image<T>::setData(const std::vector<T>& data) {
    _data = data;}


template<typename T>
 std::vector<T> Image<T>::createWhiteImage() {
    std::fill(_data.begin(), _data.end(), std::numeric_limits<T>::max());
    return _data;
}

template<typename T>

std::vector<T> Image<T>::createSinusoidalImage(double frequency) {
    for (size_t y = 0; y < _height; ++y) {
        for (size_t x = 0; x < _width; ++x) {
            double val = std::sin(2 * M_PI * frequency * x / _width);
            double normalized = (val + 1.0) * 0.5;
            (*this)(x, y) = static_cast<T>(normalized * std::numeric_limits<T>::max());
        }
    }
    return _data;
}

template<typename T>
 std::vector<T> Image<T>::createCheckerboardImage(size_t squareSize) {
    for (size_t y = 0; y < _height; ++y) {
        for (size_t x = 0; x < _width; ++x) {
            bool isWhite = ((x / squareSize) % 2 == (y / squareSize) % 2);
            (*this)(x, y) = isWhite ? std::numeric_limits<T>::max() : 0;
        }
    }
    return _data;
}

template<typename T>
void Image<T>::savePGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) const {
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P5\n" << width << " " << height << "\n255\n";
    ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
}

template<typename T>
void Image<T>::writeRawImage(const std::string& filename) const {
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(reinterpret_cast<const char*>(_data.data()), _data.size() * sizeof(T));
    ofs.close();
}

template<typename T>
std::vector<T> Image<T>::readRawImage(const std::string& filename, size_t width, size_t height, bool bigEndian) {
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

template<typename T>
void Image<T>::printImage(const std::vector<T>& image, size_t nbCols, size_t nbRows) const {
    for (size_t y = 0; y < nbRows; ++y) {
        for (size_t x = 0; x < nbCols; ++x) {
            std::cout << std::setw(4) << int(image[y * _width + x]) << " ";
        }
        std::cout << std::endl;
    }
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

template<typename T>
T& Image<T>::operator()(size_t x, size_t y) {
    return _data[y * _width + x];
}

template<typename T>
const T& Image<T>::operator()(size_t x, size_t y) const {
    return _data[y * _width + x];
}

#endif
