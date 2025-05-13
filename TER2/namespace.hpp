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
    std::vector<T> allocationImage(int width, int height) {
        return std::vector<T>(width * height);
    }

    // Image blanche
    template <typename T>
    std::vector<T> ImageBlanche(int width, int height) {
        return std::vector<T>(width * height, std::numeric_limits<T>::max());
    }

    // Mire sinusoïdale
    template <typename T>
    std::vector<T> SinusoidalImage(int width, int height, double frequence) {
        std::vector<T> image(width * height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                double valeur = std::sin(2 * M_PI * frequence * x / width);
                double Valnormaliser = (valeur + 1.0) * 0.5; // normaliser en 0 et 1 
                image[y * width + x] = static_cast<T>(Valnormaliser * std::numeric_limits<T>::max());
            }
        }
        return image;
    }

    // Damier
    template <typename T>
    std::vector<T> ImageDamier(int width, int height, int tailleCase) {
        std::vector<T> image(width * height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool isWhite = ((x / tailleCase) % 2 == (y / tailleCase) % 2);
                image[y * width + x] = isWhite ? std::numeric_limits<T>::max() : 0;
            }
        }
        return image;
    }

    // Sauvegarde en PGM (grayscale)
    void sauvegarderPGM(const std::vector<uint8_t>& image, int width, int height, const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P5\n" << width << " " << height << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
   
    template <typename T>
    std::vector<T> RGBImage(int width, int height, T R, T G, T B) {
        static_assert(std::is_integral<T>::value, "createRGBImage requiert un type entier");
    
        std::vector<T> imageRGB(width * height * 3);
        for (int i = 0; i < width * height; ++i) {
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

    void printImage(const std::vector<uint8_t>& image, int width, int height) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
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
std::vector<T> LecteurImageRAW(const std::string& filename, int width, int height, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value, "T doit être un type entier");

    std::ifstream ifs(filename, std::ios::binary);
    std::vector<T> image(width * height);

    if (!ifs) {
        std::cerr << "Erreur ouverture RAW " << sizeof(T)*8 << " bits.\n";
        return image;
    }

    for (int i = 0; i < image.size(); ++i) {
        uint8_t bytes[sizeof(T)];
        ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
        T value = 0;
        if (bigEndian) {
            for (int b = 0; b < sizeof(T); ++b)
                value = (value << 8) | bytes[b];
        } else {
            for (int b = 0; b < sizeof(T); ++b)
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
            for (int b = 0; b < sizeof(T); ++b)
                bytes[sizeof(T) - 1 - b] = (val >> (8 * b)) & 0xFF;
        } else {
            for (int b = 0; b < sizeof(T); ++b)
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



std::vector<uint8_t> convertRGBenGris(const std::vector<uint8_t>& rgbImage, int width, int height) {
    std::vector<uint8_t> grayImage(width * height);
    for (int i = 0; i < width * height; ++i) {
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

    int numColors = lut.size() / 3;
    std::vector<unsigned char> coloredImage(grayImage.size() * 3);

    for (int i = 0; i < grayImage.size(); ++i) {
        unsigned char intensity = grayImage[i];

        if (intensity >= numColors) {
            throw std::runtime_error("le niveau de gris dépasse la plage de valeurs supportée par la LUT");
        }

        int lutIndex = intensity * 3;

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

    for (int i = 0; i < image.size(); ++i) {
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
std::vector<T> LectureImageRawRGB(const std::string& fichier, int width, int height, int cannaux, bool bigEndian = false) {
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

    for (int i = 0; i < image.size(); ++i) {
        uint8_t bytes[sizeof(T)];
        ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
        T value = 0;
        if (bigEndian) {
            for (int b = 0; b < sizeof(T); ++b)
                value = (value << 8) | bytes[b];
        } else {
            for (int b = 0; b < sizeof(T); ++b)
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
    Image(int largeur, int hauteur);

    int getlargeur() const;
    int gethauteur() const;

    const std::vector<T>& getData() const;
    void setData(const std::vector<T>& image);

    void creerImageBlache();
    void creerSinusoidale(double frequence);
    void creerDamier(int tailleCase);

    void sauvegarderPGM(const std::string& fichier) const;
    void ecrireFichierRaw(const std::string& fichier) const;

    void printImage() const;

    void lireImageRAW(const std::string& fichier, bool bigEndian = false);


    template<typename Dst>
    Image<Dst> convertirImage(bool ajuster = false) const;

    T& operator()(int x, int y);
    const T& operator()(int x, int y) const;

private:
    int _largeur, _hauteur;
    std::vector<T> _image;
    };
    
    // Implémentations
    
    template<typename T>
    void Image<T>::creerImageBlache() {
        std::fill(_image.begin(), _image.end(), std::numeric_limits<T>::max());
    }


    template<typename T>
    int Image<T>::getlargeur() const { return _largeur; }
    
    template<typename T>
    int Image<T>::gethauteur() const { return _hauteur; }
    
    template<typename T>
    const std::vector<T>& Image<T>::getData() const { return _image; }
    
    template<typename T>
    void Image<T>::setData(const std::vector<T>& image) {
        _image = image;}
    
    


    
    template<typename T>
    void Image<T>::creerSinusoidale(double frequence) {
        for (size_t y = 0; y < _hauteur; ++y) {
            for (size_t x = 0; x < _largeur; ++x) {
                double val = std::sin(2 * M_PI * frequence * x / _largeur);
                double norm = (val + 1.0) * 0.5;
                (*this)(x, y) = static_cast<T>(norm * std::numeric_limits<T>::max());
            }
        }
      
    }
    
    template<typename T>
    void Image<T>::creerDamier(int tailleCase) {
        for (int y = 0; y < _hauteur; ++y) {
            for (int x = 0; x < _largeur; ++x) {
                bool estBlanc = ((x / tailleCase) % 2 == (y / tailleCase) % 2);
                (*this)(x, y) = estBlanc ? std::numeric_limits<T>::max() : 0;
            }
        }
        return _image;
    }
    
    template<typename T>
    void Image<T>::sauvegarderPGM( const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs << "P5\n" << _largeur << " " << _hauteur << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(_image.data()), _image.size());
    }
    
    template<typename T>
    void Image<T>::ecrireFichierRaw(const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs.write(reinterpret_cast<const char*>(_image.data()), _image.size() * sizeof(T));
        ofs.close();
    }
    
    template<typename T>
    void Image<T>::lireImageRAW(const std::string& fichier, bool bigEndian) {
        static_assert(std::is_integral<T>::value, "T doit être un type entier");
    
        std::ifstream ifs(fichier, std::ios::binary);
        if (!ifs) {
            std::cerr << "Erreur : impossible d’ouvrir le fichier " << fichier << '\n';
            return;
        }
    
        _image.resize(_largeur * _hauteur);
    
        for (size_t i = 0; i < _image.size(); ++i) {
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
            _image[i] = val;
        }
    }


    template<typename T>
    void Image<T>::printImage() const {
        for (size_t y = 0; y < _hauteur; ++y) {
            for (size_t x = 0; x < _largeur; ++x) {
                std::cout << std::setw(4) << static_cast<int>(_image[y * _largeur + x]) << " ";
            }
            std::cout << std::endl;
        }
    }
    
 template<typename DstType>
 Image<DstType> Image<T>::convertirImage(bool ajuster) const {
    Image<DstType> dst(_Largeur, _Hauteur);  // Utilise les bons noms de membres
    const std::vector<T>& srcPixels = this->getData();

    std::vector<DstType> dstPixels(srcPixels.size());

    T minVal = *std::min_element(srcPixels.begin(), srcPixels.end());
    T maxVal = *std::max_element(srcPixels.begin(), srcPixels.end());

    for (size_t i = 0; i < srcPixels.size(); ++i) {
        if (ajuster && maxVal != minVal) {
            float echelle = static_cast<float>(srcPixels[i] - minVal) / (maxVal - minVal);
            dstPixels[i] = static_cast<DstType>(echelle * std::numeric_limits<DstType>::max());
        } else {
            dstPixels[i] = static_cast<DstType>(srcPixels[i]);
        }
    }

    dst.setData(dstPixels);
    return dst;
}


    
    template<typename T>
    T& Image<T>::operator()(int x, int y) {
        return _image[y * _largeur + x];
    }
    
    template<typename T>
    const T& Image<T>::operator()(int x, int y) const {
        return _image[y * _largeur + x];
    }

    class ImageRGB : public  Image<uint8_t>{

        public :
        
        ImageRGB(const std::vector<uint8_t>& rgbPixel, int largeur, int hauteur);
        ImageRGB(const std::vector<uint8_t>& imageGris, int largeur, int hauteur, const std::vector<uint8_t>& lut);

            
        const std::vector<uint8_t>& getImageRGB() const;
        void sauvegarderPPM(const std::string& fichier) const;


       static  std::vector<uint8_t> chargerLUT(const std::string& fichier);
        
       static std::vector<uint8_t> convertirEnGris(const std::vector<uint8_t>& imageRGB, size_t largeur, size_t hauteur);
       
       template <typename T>
       std::vector<T> lectureImageRawRGB(const std::string& fichier, size_t largeur, size_t hauteur, size_t canaux, bool bigEndian = false);
         
   
        private: 
        std::vector<uint8_t> _ImageRGB
        
        };
        
   
        ImageRGB::ImageRGB(const std::vector<uint8_t>& ImageRGB, int largeur, int hauteur)
        : Image<uint8_t>(largeur, hauteur * 3), _ImageRGB(ImageRGB) {}

        ImageRGB::ImageRGB(const std::vector<uint8_t>& imageGris, int largeur, int hauteur, const std::vector<uint8_t>& lut)
        : Image<uint8_t>(largeur, hauteur * 3), _ImageRGB(largeur * hauteur * 3)
        {
        if (lut.size() != 256 * 3) {
            throw std::runtime_error("LUT invalide. Elle doit contenir exactement 256x3 valeurs.");
        }

        for (size_t i = 0; i < imageGris.size(); ++i) {
            uint8_t intensity = imageGris[i];
            int lutIndex = intensity * 3;

            _ImageRGB[3 * i + 0] = lut[lutIndex + 0]; // R
            _ImageRGB[3 * i + 1] = lut[lutIndex + 1]; // G
            _ImageRGB[3 * i + 2] = lut[lutIndex + 2]; // B
        }
        }
        
        
        void ImageRGB::sauvegarderPPM(const std::string& fichier) const {
            std::ofstream file(fichier, std::ios::binary);
            if (!file) {
                std::cerr << "Erreur : impossible de créer le fichier " << fichier << std::endl;
                return;
            }
        
            file << "P6\n" << getlargeur() << " " << gethauteur()<< "\n255\n";
            file.write(reinterpret_cast<const char*>(_ImageRGB.data()), getlargeur() * gethauteur() * 3);
            file.close();
        }
        
        
        std::vector<uint8_t> ImageRGB::chargerLUT(const std::string& fichier) {
            std::vector<uint8_t> lut(256 * 3);
            std::ifstream file(fichier, std::ios::binary);
            if (!file) {
                std::cerr << "Erreur lecture LUT binaire.\n";
                return lut;
            }
            file.read(reinterpret_cast<char*>(lut.data()), lut.size());
            return lut;
        }
        
        
        template <typename T>
        std::vector<T> ImageRGB::lectureImageRawRGB(const std::string& fichier, size_t largeur, size_t hauteur, size_t canaux, bool bigEndian = false) {
            static_assert(std::is_integral<T>::value, "T doit être un type entier");
        
            std::ifstream testFile(fichier);
            if (!testFile) {
                std::cerr << "Le fichier n'existe pas ou le chemin est incorrect : " << fichier << '\n';
            }
        
            std::ifstream ifs(fichier, std::ios::binary);
            std::vector<T> image(largeur * hauteur * canaux);
        
            if (!ifs) {
                std::cerr << "Erreur ouverture RAW " << sizeof(T) * 8 << " bits.\n";
                return image;
            }
        
            for (int i = 0; i < image.size(); ++i) {
                uint8_t bytes[sizeof(T)];
                ifs.read(reinterpret_cast<char*>(bytes), sizeof(T));
                T value = 0;
                if (bigEndian) {
                    for (int b = 0; b < sizeof(T); ++b)
                        value = (value << 8) | bytes[b];
                } else {
                    for (int b = 0; b < sizeof(T); ++b)
                        value |= (static_cast<T>(bytes[b]) << (8 * b));
                }
                image[i] = value;
            }
        
            return image;
        }
        
        std::vector<uint8_t> convertRGB_Gris(const std::vector<uint8_t>& rgbImage, int largeur, int hauteur) {
            std::vector<uint8_t> ImageGris(largeur * hauteur);
            for (int i = 0; i < largeur * hauteur; ++i) {
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