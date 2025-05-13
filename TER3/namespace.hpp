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
    std::vector<T> ImageBlanche(size_t width, size_t height) {
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
    void sauvegarderPGM(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P5\n" << width << " " << height << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
   
    template <typename T>
    std::vector<T> RGBImage(size_t width, size_t height, T R, T G, T B) {
        static_assert(std::is_integral<T>::value, "createRGBImage requiert un type entier");
    
        std::vector<T> imageRGB(width * height * 3);
        for (size_t i = 0; i < width * height; ++i) {
            imageRGB[i * 3 + 0] = R;
            imageRGB[i * 3 + 1] = G;
            imageRGB[i * 3 + 2] = B;
        }
        return imageRGB;
    }
    
    void sauvegarderPPM(const std::vector<unsigned char>& image, int width, int height, const std::string& filename) {
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
std::vector<T> LecteurImageRAW(const std::string& filename, size_t width, size_t height, bool bigEndian = false) {
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
void EcritureImageRaw(const std::vector<T>& image, const std::string& filename, bool bigEndian = false) {
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


std::vector<uint8_t> ChargerLUT(const std::string& filename) {
    std::vector<uint8_t> lut(256 * 3);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur de lecture du fichier LUT\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
}



std::vector<uint8_t> convertRGBenGris(const std::vector<uint8_t>& rgbImage, size_t width, size_t height) {
    std::vector<uint8_t> grayImage(width * height);
    for (size_t i = 0; i < width * height; ++i) {
        uint8_t r = rgbImage[i * 3 + 0];
        uint8_t g = rgbImage[i * 3 + 1];
        uint8_t b = rgbImage[i * 3 + 2];
        grayImage[i] = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
    }
    return grayImage;
}


std::vector<unsigned char> applLUT(const std::vector<unsigned char>& grayImage, const std::vector<unsigned char>& lut) {
    if (lut.size() % 3 != 0) {
        throw std::runtime_error("LUT doit contenir un multiple de 3 valeurs RGB.");
    }

    size_t numColors = lut.size() / 3;
    std::vector<unsigned char> coloredImage(grayImage.size() * 3);

    for (size_t i = 0; i < grayImage.size(); ++i) {
        unsigned char intensity = grayImage[i];

        if (intensity >= numColors) {
            throw std::runtime_error("le niveau de gris dépasse la plage de valeurs supportée par la LUT");
        }

        size_t lutIndex = intensity * 3;

        coloredImage[3 * i + 0] = lut[lutIndex + 0]; // R
        coloredImage[3 * i + 1] = lut[lutIndex + 1]; // G
        coloredImage[3 * i + 2] = lut[lutIndex + 2]; // B
    }

    return coloredImage;
}


// Conversion de l'image
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
std::vector<T> LectureImageRawRGB(const std::string& fichier, size_t width, size_t height, size_t cannaux, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value, "T doit être un type entier");
    std::ifstream testFile(fichier);
    if (!testFile) {
        std::cerr << "Le fichier n'existe pas ou le chemin est incorrect : " << fichier << '\n';
    }
    
    std::ifstream ifs(fichier, std::ios::binary);
    std::vector<T> image(width * height * cannaux);

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

namespace v1_1{

    template<typename T>
    class Image {
    public:
        Image(size_t Largeur, size_t Hauteur);
        size_t getLargeur() const;
        size_t getHauteur() const;
        const std::vector<T>& getpixel() const;
        void setPixel(const std::vector<T>& pixel);
        
         std::vector<T> creerImageBlache();
         std::vector<T> creerImageSinusoidal(double frequence);
         std::vector<T> creerImageDamier(size_t tailleCase);
    
        void sauvegarderPGM(const std::vector<uint8_t>& image, size_t Largeur, size_t Hauteur, const std::string& fichier) const;
        void EcritureImageRaw(const std::string& fichier) const;
        void printImage(const std::vector<T>& image, size_t nbCols, size_t nblignes) const;
    
         std::vector<T> LecteurImageRAW(const std::string& fichier, size_t Largeur, size_t Hauteur, bool bigEndian = false);
        template<typename SrcType, typename DstType>
         std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjuster);
    
        T& operator()(size_t x, size_t y);
        const T& operator()(size_t x, size_t y) const;
    
    private:
        size_t _Largeur;
        size_t _Hauteur;
        std::vector<T> _pixel;
    };
    
    // Implémentations
    
    template<typename T>
    Image<T>::Image(size_t Largeur, size_t Hauteur)
        : _Largeur(Largeur), _Hauteur(Hauteur), _pixel(Largeur * Hauteur) {}
    
    template<typename T>
    size_t Image<T>::getLargeur() const { return _Largeur; }
    
    template<typename T>
    size_t Image<T>::getHauteur() const { return _Hauteur; }
    
    template<typename T>
    const std::vector<T>& Image<T>::getpixel() const { return _pixel; }
    
    template<typename T>
    void Image<T>::setPixel(const std::vector<T>& pixel) {
        _pixel = pixel;}
    
    
    template<typename T>
     std::vector<T> Image<T>::creerImageBlache() {
        std::fill(_pixel.begin(), _pixel.end(), std::numeric_limits<T>::max());
        return _pixel;
    }
    
    template<typename T>
    
    std::vector<T> Image<T>::creerImageSinusoidal(double frequence) {
        for (size_t y = 0; y < _Hauteur; ++y) {
            for (size_t x = 0; x < _Largeur; ++x) {
                double val = std::sin(2 * M_PI * frequence * x / _Largeur);
                double normaliser = (val + 1.0) * 0.5;
                (*this)(x, y) = static_cast<T>(normaliser * std::numeric_limits<T>::max());
            }
        }
        return _pixel;
    }
    
    template<typename T>
     std::vector<T> Image<T>::creerImageDamier(size_t tailleCase) {
        for (size_t y = 0; y < _Hauteur; ++y) {
            for (size_t x = 0; x < _Largeur; ++x) {
                bool estBlanc = ((x / tailleCase) % 2 == (y / tailleCase) % 2);
                (*this)(x, y) = estBlanc ? std::numeric_limits<T>::max() : 0;
            }
        }
        return _pixel;
    }
    
    template<typename T>
    void Image<T>::sauvegarderPGM(const std::vector<uint8_t>& image, size_t Largeur, size_t Hauteur, const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs << "P5\n" << Largeur << " " << Hauteur << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
    
    template<typename T>
    void Image<T>::EcritureImageRaw(const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs.write(reinterpret_cast<const char*>(_pixel.data()), _pixel.size() * sizeof(T));
        ofs.close();
    }
    
    template<typename T>
    std::vector<T> Image<T>::LecteurImageRAW(const std::string& fichier, size_t Largeur, size_t Hauteur, bool bigEndian) {
        static_assert(std::is_integral<T>::value, "T doit être un type entier");
    
        std::ifstream ifs(fichier, std::ios::binary);
        std::vector<T> image(Largeur * Hauteur);
    
        if (!ifs) {
            std::cerr << "Erreur ouverture RAW " << sizeof(T)*8 << " bits.\n";
            return image;
        }
    
        for (size_t i = 0; i < image.size(); ++i) {
            uint8_t bytes[sizeof(T)];
            ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
            T val = 0;
            if (bigEndian) {
                for (size_t b = 0; b < sizeof(T); ++b)
                    val = (val << 8) | bytes[b];
            } else {
                for (size_t b = 0; b < sizeof(T); ++b)
                    val |= (static_cast<T>(bytes[b]) << (8 * b));
            }
            image[i] = val;
        }
    
        return image;
    }
    
    template<typename T>
    void Image<T>::printImage(const std::vector<T>& image, size_t nbCols, size_t nblignes) const {
        for (size_t y = 0; y < nblignes; ++y) {
            for (size_t x = 0; x < nbCols; ++x) {
                std::cout << std::setw(4) << int(image[y * _Largeur + x]) << " ";
            }
            std::cout << std::endl;
        }
    }
    
    // Conversion de type avec dynamique
    template<typename SrcType, typename DstType>
    std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjuster) {
        std::vector<DstType> ImageConverter(image.size());
    
        SrcType minVal = *std::min_element(image.begin(), image.end());
        SrcType maxVal = *std::max_element(image.begin(), image.end());
    
        for (size_t i = 0; i < image.size(); ++i) {
            if (adjuster) {
                ImageConverter[i] = static_cast<DstType>(
                    ((image[i] - minVal) / static_cast<double>(maxVal - minVal)) * std::numeric_limits<DstType>::max()
                );
            } else {
                ImageConverter[i] = static_cast<DstType>(image[i]);
            }
        }
    
        return ImageConverter;
    }
    
    template<typename T>
    T& Image<T>::operator()(size_t x, size_t y) {
        return _pixel[y * _Largeur + x];
    }
    
    template<typename T>
    const T& Image<T>::operator()(size_t x, size_t y) const {
        return _pixel[y * _Largeur + x];
    }

    class ImageRGB : public Image<unsigned char>{

        public :
        
        ImageRGB(const std::vector<unsigned char>& pixelrgb, size_t Largeur, size_t Hauteur);
        ImageRGB(const std::vector<unsigned char>& ImageGris, size_t Largeur, size_t Hauteur, const std::vector<unsigned char>& lut);
            
        const std::vector<unsigned char>& getPixelRGB() const;
        void sauvegraderPPM(const std::string& fichier) const;
        std::vector<unsigned char> ChargerLUT(const std::string& fichier);
        
        template <typename T>
        std::vector<T> LectureImageRawRGB(const std::string& fichier, size_t Largeur, size_t Hauteur, size_t cannaux, bool bigEndian = false) ;
        
        template <typename T>
        std::vector<T> convertRGB_Gris(const std::vector<uint8_t>& rgbImage, size_t Largeur, size_t Hauteur);
        private: 
        std::vector<unsigned char> _rgbPixel;
        
        };
        
        ImageRGB::ImageRGB(const std::vector<unsigned char>& rgbPixel, size_t Largeur, size_t Hauteur)
            : Image<unsigned char>(Largeur, Hauteur), _rgbPixel(rgbPixel) {}
        
            ImageRGB::ImageRGB(const std::vector<unsigned char>& ImageGris, size_t Largeur, size_t Hauteur, const std::vector<unsigned char>& lut)
            : Image<unsigned char>(Largeur, Hauteur), _rgbPixel(Largeur * Hauteur * 3)
        {
            if (lut.size() != 256 * 3) {
                throw std::runtime_error("LUT invalide. Elle doit contenir exactement 256x3 valeurs.");
            }
        
            for (size_t i = 0; i <ImageGris.size(); ++i) {
                unsigned char intensity = ImageGris[i];
                size_t lutIndex = intensity * 3;
        
                _rgbPixel[3 * i + 0] = lut[lutIndex + 0]; // R
                _rgbPixel[3 * i + 1] = lut[lutIndex + 1]; // G
                _rgbPixel[3 * i + 2] = lut[lutIndex + 2]; // B
            }
        }
        const std::vector<unsigned char>& ImageRGB::getPixelRGB() const {
            return _rgbPixel;
        }
        
        
        
        void ImageRGB::sauvegraderPPM(const std::string& fichier) const {
            std::ofstream file(fichier, std::ios::binary);
            if (!file) {
                std::cerr << "Erreur : impossible de créer le fichier " << fichier << std::endl;
                return;
            }
        
            file << "P6\n" << getLargeur() << " " << getHauteur()<< "\n255\n";
            file.write(reinterpret_cast<const char*>(_rgbPixel.data()), getLargeur() * getHauteur() * 3);
            file.close();
        }
        
        
        std::vector<unsigned char> ChargerLUT(const std::string& fichier) {
            std::vector<unsigned char> lut(256 * 3);
            std::ifstream file(fichier, std::ios::binary);
            if (!file) {
                std::cerr << "Erreur lecture LUT binaire.\n";
                return lut;
            }
            file.read(reinterpret_cast<char*>(lut.data()), lut.size());
            return lut;
        }
        
        
        template <typename T>
        std::vector<T> LectureImageRawRGB(const std::string& fichier, size_t Largeur, size_t Hauteur, size_t cannaux, bool bigEndian = false) {
            static_assert(std::is_integral<T>::value, "T doit être un type entier");
        
            std::ifstream testFile(fichier);
            if (!testFile) {
                std::cerr << "Le fichier n'existe pas ou le chemin est incorrect : " << fichier << '\n';
            }
        
            std::ifstream ifs(fichier, std::ios::binary);
            std::vector<T> image(Largeur * Hauteur * cannaux);
        
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
        
        std::vector<uint8_t> convertRGB_Gris(const std::vector<uint8_t>& rgbImage, size_t Largeur, size_t Hauteur) {
            std::vector<uint8_t> ImageGris(Largeur * Hauteur);
            for (size_t i = 0; i < Largeur * Hauteur; ++i) {
                uint8_t r = rgbImage[i * 3 + 0];
                uint8_t g = rgbImage[i * 3 + 1];
                uint8_t b = rgbImage[i * 3 + 2];
                ImageGris[i] = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
            }
            return ImageGris;
        }
}

namespace v2_0 {

}