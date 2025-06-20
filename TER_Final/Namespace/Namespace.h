#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <cstddef>
#include <vector>           
#include <iostream>      
#include <fstream>       
#include <math.h>         
#include <cstdint>      
#include <limits>      
#include <iomanip>          
#include <algorithm>    
#include <filesystem>
#include "./Image.h"
#include "./ImageRGB.h"
#include "./Processing1.h"
#include "./Processing2.h"
#include "./Addition.h"
#include "./AdditionScalaire.h"
#include "./EgalisationHistogram.h"
#include "./Convolution.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


namespace v1_0{
    // Alloue une image avec largeur * hauteur pixels
    template <typename T>
    std::vector<T> allocationImage(size_t largeur, size_t hauteur) {
        return std::vector<T>(largeur * hauteur);
    }

    // Image blanche
    template <typename T>
    std::vector<T> ImageBlanche(size_t largeur, size_t hauteur) { 
        return std::vector<T>(largeur * hauteur, std::numeric_limits<T>::max()); 
        //                                                                       
    }

    // Mire sinusoïdale
    template <typename T>
    std::vector<T> SinusoidalImage(size_t largeur, size_t hauteur, double frequence) {
        std::vector<T> image(largeur * hauteur); //Allocation de l'image

        //On parcourt l’image ligne par ligne, pixel par pixel
        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                double valeur = std::sin(2 * M_PI * frequence * x / largeur); 
                double Valnormaliser = (valeur + 1.0) * 0.5; 
                                                                                                     
                image[y * largeur + x] = static_cast<T>(Valnormaliser * std::numeric_limits<T>::max()); 
            }                                                                                           
        }
        return image;
    }

    // Damier
    template <typename T>
    std::vector<T> ImageDamier(size_t largeur, size_t hauteur, size_t tailleCase) {
        std::vector<T> image(largeur * hauteur);

        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                bool estBlanc = ((x / tailleCase) % 2 == (y / tailleCase) % 2); //si l'indice x / taille de la case modulo 2 == a l'indice y / taille de case  modulo 2 donc la case est blanc 
                image[y * largeur + x] = estBlanc ? std::numeric_limits<T>::max() : 0;
            }
        }
        return image;
    }

    // Sauvegarde en PGM sauvegarde une image en niveaux de gris
    void sauvegarderPGM(const std::vector<uint8_t>& image, size_t largeur, size_t hauteur, const std::string& fichier) { 
        std::ofstream ofs(fichier, std::ios::binary);//Spécifie qu’on écrit en mode binaire (pas texte)
          //P5 en tete de fichier PGM (en niveau de gris )
        ofs << "P5\n" << largeur << " " << hauteur << "\n255\n";
         ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
   
    template <typename T>
    std::vector<T> RGBImage(size_t largeur, size_t hauteur, T R, T G, T B) {
        static_assert(std::is_integral<T>::value, "creerRGBImage requiert un type entier");
    
        std::vector<T> imageRGB(largeur * hauteur * 3);
        for (size_t i = 0; i < largeur * hauteur; ++i) {
            imageRGB[i * 3 + 0] = R;
            imageRGB[i * 3 + 1] = G;
            imageRGB[i * 3 + 2] = B;
        }
        return imageRGB;
    }
     // en ppm et pgm pour visualiser avec notre QT
    //pas de template car déja en uint_8 a cause des LUT
    void sauvegarderPPM(const std::vector<uint8_t>& image, int largeur, int hauteur, const std::string& fichier) {
        std::ofstream file(fichier, std::ios::binary);
        if (!file) {
            std::cerr << "Erreur : impossible de créer le fichier " << fichier << std::endl;
            return;
        }
        // Écrire l'en-tête du fichier PPM
        file << "P6\n" << largeur << " " << hauteur << "\n255\n";
        // Écrire les données de l'image (R, G, B)
        file.write(reinterpret_cast<const char*>(image.data()), largeur * hauteur * 3);
    
        file.close();
    }

    void printImage(const std::vector<uint8_t>& image, size_t largeur, size_t hauteur) {
        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                std::cout << std::setw(4) << static_cast<int>(image[y * largeur + x]) << " ";
            }
            std::cout << '\n';
        }
    }


    // La réponse à la deuxième question 
   
    // Lecture d'une image RAW mono canal
    template<typename T>
std::vector<T> lireImageRAW(const std::string& nomFichier, int largeur, int hauteur, bool bigEndian = false) {
    std::ifstream in(nomFichier, std::ios::binary);
    if (!in) throw std::runtime_error("Erreur d'ouverture du fichier : " + nomFichier);

    std::vector<T> img(largeur * hauteur);  // img.size() == nbPixels
           //reinterpret_cast<char*> → C++ veut des char* pour lire des octets
    in.read(reinterpret_cast<char*>(img.data()), img.size() * sizeof(T));  // Lecture des octets
                                                                                        ////nbPixels * sizeof(T) → taille totale des données à lire en octets // Si T = uint8_t → lecture de 1 octet par pixel, Si T = uint16_t → lecture de 2 octets par pixel


    // Inversion d’endianess si besoin (pour les types > 1 octet)
    if (bigEndian && sizeof(T) > 1) {
        for (T& pixel : img) {
            uint8_t* ptr = reinterpret_cast<uint8_t*>(&pixel);//on transforme cette adresse en tableau d’octets
            std::reverse(ptr, ptr + sizeof(T));
        }
    }

    in.close();
    return img;
}
 // Ecriture d'une image RAW mono canal
    template<typename T>
    void ecrireFichierRaw(const std::vector<T>& image, const std::string& filename) {
        std::ofstream out(filename, std::ios::binary);
        out.write(reinterpret_cast<const char*>(image.data()), image.size() * sizeof(T)); 
                                                                                              
        out.close();
    }

    //Chargement du fichier LUT
std::vector<uint8_t> chargerLUT(const std::string& fichier) {
    std::vector<uint8_t> lut(256 * 3);
    std::ifstream file(fichier, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur de lecture du fichier LUT\n";
        return lut;
    }
    file.read(reinterpret_cast<char*>(lut.data()), lut.size());
    return lut;
}


    // Lit une image RGB et convertit en niveaux de gris
std::vector<uint8_t> convertRGB_Gris(const std::vector<uint8_t>& rgbImage, size_t largeur, size_t hauteur) {
    std::vector<uint8_t> imageGris(largeur * hauteur);
    for (size_t i = 0; i < largeur * hauteur; ++i) {
        uint8_t r = rgbImage[i * 3 + 0];
        uint8_t g = rgbImage[i * 3 + 1];
        uint8_t b = rgbImage[i * 3 + 2];
        imageGris[i] = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
    }
    return imageGris;
}

//Appliquer le lut
std::vector<uint8_t> applLUT(const std::vector<uint8_t>& imageGris, const std::vector<uint8_t>& lut) {
    if (lut.size() % 3 != 0) {
        throw std::runtime_error("LUT doit contenir un multiple de 3 valeurs RGB.");
    }

    size_t numColors = lut.size() / 3;
    std::vector<uint8_t> imageRGB(imageGris.size() * 3);

    for (size_t i = 0; i < imageGris.size(); ++i) {
        uint8_t intensity = imageGris[i];

        if (intensity >= numColors) {
            throw std::runtime_error("le niveau de gris dépasse la plage de valeurs supportée par la LUT");
        }

        size_t lutIndex = intensity * 3;

        imageRGB[3 * i + 0] = lut[lutIndex + 0]; // R
        imageRGB[3 * i + 1] = lut[lutIndex + 1]; // G
        imageRGB[3 * i + 2] = lut[lutIndex + 2]; // B
    }

    return imageRGB;
}


// Conversion de l'image
template<typename SrcType, typename DstType>
std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjustDynamics) {  

    std::vector<DstType> imageCnvert(image.size());

    SrcType minVal = *std::min_element(image.begin(), image.end());
    SrcType maxVal = *std::max_element(image.begin(), image.end());

    for (size_t i = 0; i < image.size(); ++i) {
        if (adjustDynamics) {
            imageCnvert[i] = static_cast<DstType>(
                ((image[i] - minVal) / static_cast<double>(maxVal - minVal)) * std::numeric_limits<DstType>::max()
            );
        } else {
            imageCnvert[i] = static_cast<DstType>(image[i]);
        }
    }

    return imageCnvert;
}

//Lecteur de fichier raw pour les images RGB 
template <typename T>
std::vector<T> lectureImageRawRGB(const std::string& fichier, size_t largeur, size_t hauteur, size_t canaux, bool bigEndian = false) {
    static_assert(std::is_integral<T>::value, "T doit être un type entier");

    std::ifstream ifs(fichier, std::ios::binary);
    if (!ifs) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << fichier << '\n';
        return {};
    }

    size_t taille = largeur * hauteur * canaux;
    std::vector<T> image(taille);

    for (size_t i = 0; i < taille; ++i) {
        uint8_t octets[sizeof(T)];
        ifs.read(reinterpret_cast<char*>(octets), sizeof(T));

        if (ifs.gcount() != sizeof(T)) {
            std::cerr << "Erreur : données incomplètes dans le fichier.\n";
            return {};
        }

        T valeur = 0;
        if (bigEndian) {
            for (size_t j = 0; j < sizeof(T); ++j) {
                valeur = (valeur << 8) | octets[j];
            }
        } else {
            for (size_t j = 0; j < sizeof(T); ++j) {
                valeur |= (static_cast<T>(octets[j]) << (8 * j));
            }
        }

        image[i] = valeur;
    }

    return image;
}
}


//Bibliothèque namespace v1.1
namespace v1_1{

 
    
    // Implémentations des methodes des class 
       // Constructeurs
    template<typename T>
    Image<T>::Image() : _largeur(0), _hauteur(0) {}
    template<typename T>
    Image<T>::Image(int largeur, int hauteur) : _largeur(largeur), _hauteur(hauteur), _image(largeur * hauteur) {}
   
   
    template<typename T>
    void Image<T>::creerImageBlache() {
        std::fill(_image.begin(), _image.end(), std::numeric_limits<T>::max());
    }

//methodes recupérer la langeur et la largeur et data (pixel)
    template<typename T>
    int Image<T>::getlargeur() const { return _largeur; }
    
    template<typename T>
    int Image<T>::gethauteur() const { return _hauteur; }
    
    template<typename T>
    const std::vector<T>& Image<T>::getData() const { return _image; }
    
    template<typename T>
    void Image<T>::setData(const std::vector<T>& image) {
        _image = image;}
    
    


      // Méthodes de création d'image
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
        for (size_t y = 0; y < _hauteur; ++y) {
            for (size_t x = 0; x < _largeur; ++x) {
                bool estBlanc = ((x / tailleCase) % 2 == (y / tailleCase) % 2);
                (*this)(x, y) = estBlanc ? std::numeric_limits<T>::max() : 0;  
            }                                                                  
        }
       
    }
    //methdoes sauvegarde 
    template<typename T>
    void Image<T>::sauvegarderPGM( const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs << "P5\n" << _largeur << " " << _hauteur << "\n255\n";
        ofs.write(reinterpret_cast<const char*>(_image.data()), _image.size());
    }
    // Lecture/écriture RAW
    template<typename T>
    void Image<T>::ecrireFichierRaw(const std::string& fichier) const {
        std::ofstream ofs(fichier, std::ios::binary);
        ofs.write(reinterpret_cast<const char*>(_image.data()), _image.size() * sizeof(T));
        ofs.close();
    }
 
    template<typename T>
    Image<T> Image<T>::lireImageRAW(const std::string& fichier, size_t largeur, size_t hauteur, bool bigEndian) {
        Image<T> img(largeur, hauteur);
        std::ifstream in(fichier, std::ios::binary);
        if (!in) {
            throw std::runtime_error("Erreur ouverture fichier : " + fichier);
        }
    
        in.read(reinterpret_cast<char*>(img._image.data()), largeur * hauteur * sizeof(T));
        if (!in) {
            throw std::runtime_error("Erreur de lecture : " + fichier);
        }
    
        if (bigEndian && sizeof(T) > 1) {
            for (T& px : img._image) {
                uint8_t* ptr = reinterpret_cast<uint8_t*>(&px);
                std::reverse(ptr, ptr + sizeof(T));
            }
        }
    
        return img;
    }
//print image dans la console 
    template<typename T>
    void Image<T>::printImage() const {
        for (size_t y = 0; y < _hauteur; ++y) {
            for (size_t x = 0; x < _largeur; ++x) {
                std::cout << std::setw(4) << static_cast<int>(_image[y * _largeur + x]) << " ";
            }
            std::cout << std::endl;
        }
    }
    //convert image d'un type à un autre 
    template<typename T>
    template<typename Dst>
    Image<Dst> Image<T>::convertirImage(bool ajuster) const {
        Image<Dst> dst(_largeur, _hauteur);  // Nouvelle image destination
        const std::vector<T>& srcPixels = this->getData();  // Pixels source
    
        std::vector<Dst> dstPixels(srcPixels.size());
    
        T minVal = *std::min_element(srcPixels.begin(), srcPixels.end());
        T maxVal = *std::max_element(srcPixels.begin(), srcPixels.end());
    
        for (size_t i = 0; i < srcPixels.size(); ++i) {
            if (ajuster && maxVal != minVal) {
                float echelle = static_cast<float>(srcPixels[i] - minVal) / (maxVal - minVal);
                dstPixels[i] = static_cast<Dst>(echelle * std::numeric_limits<Dst>::max());
            } else {
                dstPixels[i] = static_cast<Dst>(srcPixels[i]);
            }
        }
    
        dst.setData(dstPixels);
        return dst;
    }

      //surcharge operateur
    template<typename T>
    T& Image<T>::operator()(int x, int y) {
        return _image[y * _largeur + x];
    }
      //surcharge operateur
    template<typename T>
    const T& Image<T>::operator()(int x, int y) const {
        return _image[y * _largeur + x];
    }

   //implémentation de methodes de la class RB// Lecture/écriture RGB
   //surcharge de constructeur 
       ///1er constructeur , conversion d umage gris en RGB
ImageRGB::ImageRGB(const Image<uint8_t>& rgbImage, int largeur, int hauteur)
: Image<uint8_t>(largeur, hauteur * 3), _ImageRGB(rgbImage.getData()) {} // *3 pour les composantes : Rouge, Vert, Bleu.
   ///2em constructeur , recoit un fichier et creer une image RGB
ImageRGB::ImageRGB(const Image<uint8_t>& imageGris, size_t Largeur, size_t Hauteur, const std::vector<uint8_t>& lut)
: Image<uint8_t>(Largeur, Hauteur), _ImageRGB(Largeur * Hauteur * 3) //Converti une image uint8_t de niveau de gris on image RGB contient trois cannaux R,G,B 
{
    if (lut.size() != 256 * 3) {
        throw std::runtime_error("LUT invalide. Elle doit contenir exactement 256x3 valeurs.");
    }

    const auto& data = imageGris.getData();
    for (size_t i = 0; i < data.size(); ++i) { //parcourir chaque pixel de l'image RGB 
        uint8_t intensity = data[i]; //recupérer la valeur de pixel 0-255
        int lutIndex = intensity * 3; //calculer index LUT si par exemple lutIndex = 6 
        _ImageRGB[3 * i + 0] = lut[lutIndex + 0]; // R  6
        _ImageRGB[3 * i + 1] = lut[lutIndex + 1]; // G  7 
        _ImageRGB[3 * i + 2] = lut[lutIndex + 2]; // B  8
    }
}
//sauvegrade en PPM 
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

        
//charger le fichier LUT 
     // methode static car pas nécessaire de creer d'objet et aussi on utilise aucune attribut 
        std::vector<uint8_t> ImageRGB::chargerLUT(const std::string& fichier) {
            std::vector<uint8_t> lut(256 * 3);
            std::ifstream ifs(fichier, std::ios::binary);
            if (!ifs) {
                throw std::runtime_error("Impossible d'ouvrir le fichier LUT : " + fichier);
            }
            ifs.read(reinterpret_cast<char*>(lut.data()), lut.size());
            if (!ifs) {
                throw std::runtime_error("Erreur de lecture de la LUT : " + fichier);
            }
            return lut;
        }
        //lecture image RAW a 3 cannaux 
             // methode static car pas nécessaire de creer d'objet et aussi on utilise aucune attribut 
        Image<uint8_t> lectureImageRawRGB(const std::string& fichier, size_t largeur, size_t hauteur, bool bigEndian = false) {
            const size_t canaux = 3;
            std::vector<uint8_t> donnee(largeur * hauteur * canaux);
        
            std::ifstream in(fichier, std::ios::binary);
            if (!in) {
                throw std::runtime_error("Erreur ouverture fichier : " + fichier);
            }
        
            in.read(reinterpret_cast<char*>(donnee.data()), donnee.size());
            if (!in) {
                throw std::runtime_error("Erreur de lecture : " + fichier);
            }
        
            // Pas besoin d'inverser l'endianess pour du uint8_t
            // Mais s’il y avait des uint16_t, oui
        
            Image<uint8_t> imageRGB(largeur * 3, hauteur); 
            imageRGB.setData(donnee);
        
            return imageRGB;
        }
        
        //convert image RGB en niveau de gris 
           // methode static car pas nécessaire de creer d'objet et aussi on utilise aucune attribut 
     // Fonction utilitaire pour lire une image RGB et la convertir en niveaux de gris
        Image<uint8_t> convertRGB_Gris(const Image<uint8_t>& imgRGB, int largeur, int hauteur) {
            const std::vector<uint8_t>& rgbData = imgRGB.getData(); // ou autre méthode d’accès
            std::vector<uint8_t> grayData(largeur * hauteur);
        
            for (int i = 0; i < largeur * hauteur; ++i) {
                uint8_t r = rgbData[i * 3 + 0];
                uint8_t g = rgbData[i * 3 + 1];
                uint8_t b = rgbData[i * 3 + 2];
                grayData[i] = static_cast<uint8_t>(0.299f * r + 0.587f * g + 0.114f * b);
            }
        
            Image<uint8_t> imgGris(largeur, hauteur);
            imgGris.setData(grayData);
            return imgGris;
        }
}


//Namespace v2_0
 namespace v2_0 {

 //implementation     

 // Processing1
        template<typename T>
        Processing1<T>::Processing1(v1_1::Image<T>& input, bool inPlace)
            : imageInput_(input), inPlace_(inPlace), imageOutput_(input.getlargeur(), input.gethauteur()) {}
    
        template<typename T>
        void Processing1<T>::Update() {
            Process();
        }
    
        template<typename T>
        v1_1::Image<T>& Processing1<T>::getOutput() {
            return inPlace_ ? imageInput_ : imageOutput_;
        }
    
// Processing2

        template<typename T>
        Processing2<T>::Processing2(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace)
            : imageInput1_(input1), imageInput2_(input2), inPlace_(inPlace),
              imageOutput_(input1.getlargeur(), input1.gethauteur()) {}
    
        template<typename T>
        void Processing2<T>::Update() {
            Process();
        }
    
        template<typename T>
        v1_1::Image<T>& Processing2<T>::getOutput() {
            return inPlace_ ? imageInput1_ : imageOutput_;
        }
    
        // Addition
        template<typename T>
        Addition<T>::Addition(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace)
            : Processing2<T>(input1, input2, inPlace) {}
    
            template<typename T>
            void Addition<T>::Process() {
                size_t largeur1 = this->imageInput1_.getlargeur();
                size_t hauteur1 = this->imageInput1_.gethauteur();
                size_t largeur2 = this->imageInput2_.getlargeur();
                size_t hauteur2 = this->imageInput2_.gethauteur();
            
                size_t largeurFinale = std::max(largeur1, largeur2);
                size_t hauteurFinale = std::max(hauteur1, hauteur2);
            
                v1_1::Image<T> imageTemp(largeurFinale, hauteurFinale);
            
                for (size_t y = 0; y < hauteurFinale; ++y) {
                    for (size_t x = 0; x < largeurFinale; ++x) {
                        T val1 = (x < largeur1 && y < hauteur1) ? this->imageInput1_(x, y) : 0;
                        T val2 = (x < largeur2 && y < hauteur2) ? this->imageInput2_(x, y) : 0;
            
                        imageTemp(x, y) = val1 + val2;
                    }
                }
            
                if (this->inPlace_) {
                    this->imageInput1_ = std::move(imageTemp);
                } else {
                    this->imageOutput_ = std::move(imageTemp);
                }
            }
            
    
         // Méthode statique addition
              // methode static car pas nécessaire de creer d'objet et aussi on utilise aucune attribut 
      template<typename T>
      v1_1::Image<T> Addition<T>::addition(const v1_1::Image<T>& image1, const v1_1::Image<T>& image2) {
          // Création de copies modifiables
          v1_1::Image<T> imgRef1 = image1;
          v1_1::Image<T> imgRef2 = image2;
      
          // Création de l'opération sans passer de type (car comportement unique : étendre avec zéros)
          Addition<T> add(imgRef1, imgRef2, false);
          add.Update();
      
          return add.getOutput();
      }
     // AdditionScalaire
     //Constructeur 
    template<typename T>
    AdditionScalaire<T>::AdditionScalaire(v1_1::Image<T>& input, T valScalaire, bool inPlace)
        : Processing1<T>(input, inPlace), valScalaire_(valScalaire) {}
    
        //methode process()
    template<typename T>
    void AdditionScalaire<T>::Process() {
        size_t largeur = this->imageInput_.getlargeur();
        size_t hauteur = this->imageInput_.gethauteur();
        v1_1::Image<T>& imageSortie = this->inPlace_ ? this->imageInput_ : this->imageOutput_;
    
        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                T val = this->imageInput_(x, y) + valScalaire_;
    
                // Saturation (valeur maximale selon le type T)
                if (std::numeric_limits<T>::is_integer) {
                    val = std::min<T>(val, std::numeric_limits<T>::max());
                }
    
                imageSortie(x, y) = val;
            }
        }
    }
        // Fonction libre additionScalaire
             // methode static car pas nécessaire de creer d'objet et aussi on utilise aucune attribut 
        template<typename T>
       v1_1::Image<T> AdditionScalaire<T>::additionScalaire(const v1_1::Image<T>& input, T valScalaire) {
            size_t largeur = input.getlargeur();
            size_t hauteur = input.gethauteur();
            v1_1::Image<T> output(largeur, hauteur);
    
            for (size_t y = 0; y < hauteur; ++y) {
                for (size_t x = 0; x < largeur; ++x) {
                    output(x, y) = input(x, y) + valScalaire;
                }
            }
    
            return output;
        }
    
    
//Implémentation des methode de l'égalisation d'histogramme 
      template<typename T>
    egalisationHistogram<T>::egalisationHistogram(v1_1::Image<T>& input, bool inPlace)
        : Processing1<T>(input, inPlace) {}
    
    //méthode compter d'histogramme 
        template<typename T>
    void egalisationHistogram<T>::compterHistogram(const v1_1::Image<T>& image) {
        histogramImage_ = std::vector<int>(256, 0);
        for (auto val : image.getData()) {
            histogramImage_[val]++;
        }
    }
    //methode process pour le traitement d'histogramme 
        template<typename T>
    void egalisationHistogram<T>::Process() {
        static_assert(std::is_same<T, uint8_t>::value, "egalisation d'Histogram ne supporte que uint8_t");
    
        size_t w = this->imageInput_.getlargeur();
        size_t h = this->imageInput_.gethauteur();
        size_t total = w * h;
    
        v1_1::Image<T>& output = this->inPlace_ ? this->imageInput_ : this->imageOutput_;
        output = v1_1::Image<T>(w, h);
    
        // 1. Histogramme d'entrée
        histogramImage_ = std::vector<int>(256, 0);
        for (auto val : this->imageInput_.getData()) {
            histogramImage_[val]++;
        }
        // 2. CDF
        std::vector<int> cdf(256);
        cdf[0] = histogramImage_[0];
        for (int i = 1; i < 256; ++i)
            cdf[i] = cdf[i - 1] + histogramImage_[i];
    
        // 3. LUT
        std::vector<uint8_t> lut(256);
        for (int i = 0; i < 256; ++i)
            lut[i] = static_cast<uint8_t>(255.0 * cdf[i] / total);

        // 4. Appliquer LUT
        for (size_t y = 0; y < h; ++y)
            for (size_t x = 0; x < w; ++x)
                output(x, y) = lut[this->imageInput_(x, y)];
    
        // 5. Recalculer histogramme après égalisation
        compterHistogram(output);
    }
    
    
    //Methode getHistogramme affiche l'histogramme 
    template<typename T>
    v1_1::Image<uint8_t> egalisationHistogram<T>::getHistogramImage() {
         int histlargeur = 256;
         int histhauteur = 100;
    
        v1_1::Image<uint8_t> histImage(histlargeur, histhauteur);
    
        // Fond blanc
        for (int y = 0; y < histhauteur; ++y)
            for (int x = 0; x < histlargeur; ++x)
                histImage(x, y) = 255;
    
        if (histogramImage_.empty())
            return histImage;
    
        // Trouver le max pour normalisation
        int maxVal = *std::max_element(histogramImage_.begin(), histogramImage_.end());
        if (maxVal == 0) return histImage;
    
        // Tracer les barres noires (histogramme)
        for (int x = 0; x < histlargeur; ++x) {
            int barreHauteur = static_cast<int>((histogramImage_[x] / static_cast<float>(maxVal)) * histhauteur);
    
            // Dessiner de bas en haut
            for (int y = histhauteur - 1; y >= histhauteur - barreHauteur; --y) {
                histImage(x, y) = 0;  // noir
            }
        }
    
        return histImage;
    }
    
 
//Implémentation des méthodes de convolution 
// Constructeur
template<typename T>
Convolution<T>::Convolution( v1_1::Image<T>& image, const v1_1::Image<float>& noyau, bool inPlace)
    : Processing1<T>(image, inPlace), noyau_(noyau) {}
//Methode process() pour le calcul de convolution 
// Processus de convolution
template<typename T>
void Convolution<T>::Process() {
    //Récupère la largeur (L) et la hauteur (H) de l’image d’entrée.
    int L = this->imageInput_.getlargeur();
    int H = this->imageInput_.gethauteur();

    //Récupère les dimensions du noyau de convolution.
    int nL = noyau_.getlargeur();
    int nH = noyau_.gethauteur();

    //Calcule le décalage nécessaire pour centrer le noyau autour du pixel courant.
    int dx = nL / 2;
    int dy = nH / 2;

    v1_1::Image<T>& out = this->inPlace_ ? this->imageInput_ : this->imageOutput_;
    if (!this->inPlace_) {
        this->imageOutput_ = v1_1::Image<T>(L, H);  // allouer explicitement
    }
    
    //Parcourt chaque pixel (x, y) de l’image.
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < L; ++x) {
           // Initialise la somme pondérée pour ce pixel.
            float sum = 0.0f;
            //Parcourt chaque poids du noyau (i, j).
            for (int j = 0; j < nH; ++j) {
                for (int i = 0; i < nL; ++i) {
                    //Position dans l’image source correspondant à la position (i, j) dans le noyau centré sur (x, y).
                    int ix = x + i - dx;
                    int iy = y + j - dy;
                    //Gestion des bords : si ix ou iy sortent de l’image, on réplique la bordure (padding par duplication).
                    if (ix < 0) ix = 0;
                    if (ix >= L) ix = L - 1;
                    if (iy < 0) iy = 0;
                    if (iy >= H) iy = H - 1;
                   // Ajoute à la somme pondérée la valeur du pixel multipliée par le poids du noyau correspondant.
                    sum += this->imageInput_(ix, iy) * noyau_(i, j);
                }
            }
           //on limite la valeur du pixel calculé à la plage [0, 255].
            if (sum < 0.0f) sum = 0.0f;
            else if (sum > 255.0f) sum = 255.0f;

            //On écrit la valeur finale dans l’image de sortie (ou entrée si in-place).
            out(x, y) = static_cast<T>(sum);
        }
    }}


    // creation du filtre Moyenneur
    template<typename T>
    v1_1::Image<float> Convolution<T>::creerMoyenneur(int taille) {
        v1_1::Image<float> noyau(taille, taille);
        float val = 1.0f / (taille * taille);
        for (int y = 0; y < taille; ++y)
            for (int x = 0; x < taille; ++x)
                noyau(x, y) = val;
        return noyau;
    }
    
    //creation du filtre Gaussien 
    template<typename T>
    v1_1::Image<float> Convolution<T>::creerGaussien(int taille, float sigma) {
        v1_1::Image<float> noyau(taille, taille);
        int c = taille / 2;
        float sum = 0.0f;
    
        for (int y = 0; y < taille; ++y) {
            for (int x = 0; x < taille; ++x) {
                float dx = x - c;
                float dy = y - c;
                float val = std::exp(-(dx * dx + dy * dy) / (2 * sigma * sigma));
                noyau(x, y) = val;
                sum += val;
            }
        }
    
        for (int y = 0; y < taille; ++y)
            for (int x = 0; x < taille; ++x)
                noyau(x, y) /= sum;
    
        return noyau;
    }
    // creation du filtre Exponentiel 
    
    template<typename T>
    v1_1::Image<float> Convolution<T>::creerExponentiel(int taille, float lambda) {
        v1_1::Image<float> noyau(taille, taille);
        int c = taille / 2;
        float sum = 0.0f;
    
        for (int y = 0; y < taille; ++y) {
            for (int x = 0; x < taille; ++x) {
                float dx = std::abs(x - c);
                float dy = std::abs(y - c);
                float val = std::exp(-lambda * (dx + dy));
                noyau(x, y) = val;
                sum += val;
            }
        }
    
        for (int y = 0; y < taille; ++y)
            for (int x = 0; x < taille; ++x)
                noyau(x, y) /= sum;
    
        return noyau;
    }

    
    
}


#endif