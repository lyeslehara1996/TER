
#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <vector>           //Fournit la classe std::vector, un tableau dynamique (taille ajustable automatiquement) 
#include <iostream>         //Permet l’entrée/sortie via la console.  //Fournit std::cout, std::cin, std::endl
#include <fstream>          //  Sert à faire de l’entrée/sortie sur fichiers. // Fournit std::ifstream (lecture) et std::ofstream (écriture).
#include <math.h>           // Fournit les fonctions mathématiques classiques (sin, cos, sqrt, etc.)
#include <cstdint>          // Fournit les types d'entiers à taille fixe, uint8_t (8 bits), int16_t (16 bits) 
#include <limits>           // Fournit des infos sur les valeurs extrêmes des types (min, max, epsilon)
#include <iomanip>          //Permet de formater l'affichage (alignement, précision, )
#include <algorithm>            //Fournit des algorithmes standard std::sort, std::min_element, std::max, std::copy
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace v1_0 {

    template <typename T>
    std::vector<T> allocationImage(size_t largeur, size_t hauteur) {
        return std::vector<T>(largeur * hauteur);
    }

    // Image blanche
    template <typename T>
    std::vector<T> ImageBlanche(size_t largeur, size_t hauteur) { // size_t : est un type entier comme nt mais non signé elle accepte pas des valeurs négatives 
        return std::vector<T>(largeur * hauteur, std::numeric_limits<T>::max()); // etourne la plus grande valeur possible que peut prendre un type numérique T 
        //                                                                        //  exemple :  Max int: 2147483647 ,  Max unsigned char: 255
    }

    // Mire sinusoïdale
    template <typename T>
    std::vector<T> SinusoidalImage(size_t largeur, size_t hauteur, double frequence) {
        std::vector<T> image(largeur * hauteur); //Allocation de l'image

//On parcourt l’image ligne par ligne, pixel par pixel
        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                double valeur = std::sin(2 * M_PI * frequence * x / largeur); //C’est pour normaliser la position x entre 0 et 1 si x= 0 et largeur 100 => x/largeur 0.0 , si x= 50 donc x/largeur = 0.5, 
                double Valnormaliser = (valeur + 1.0) * 0.5; // normaliser en 0 et 1 car le Le sinus donne des valeurs entre -1 et 1 
                                                              //mais on veut pas de négative donc En ajoutant 1, on obtient : 0 à 2
                                                              //En multipliant par 0.5, on obtient : 0 à 1  
                image[y * largeur + x] = static_cast<T>(Valnormaliser * std::numeric_limits<T>::max()); // on transforme notre valeur entre 0 et 1 en une valeur réelle de pixel.
            }                                                                                           // exemple 0.2 * 255 = 51 , 1 =255 , 0.5 =
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
        //sortie vers un fichier ( file stream)
        //Par défaut, C++ écrit en mode texte. Pour ne pas perdre d'information lors de l'interpretation 
        //Les octets peuvent être modifiés automatiquement (ex : \n devient \r\n sous Windows)
        std::ofstream ofs(fichier, std::ios::binary);//Spécifie qu’on écrit en mode binaire (pas texte)

          //P5 en tete de fichier PGM (en niveau de gris )dans le fichier binaire et dans le fichier text c'est P2
        //donc le fichier PGM contient ces information : en_tete = P6 ou P2 les dimension de l image(fichier) hauteur et largeur 
        ofs << "P5\n" << largeur << " " << hauteur << "\n255\n";

        //changement de type de pointeur, sans modifier les données. car std::ofstream::write() attend un const char* mais on const uint8_t* Donc  uint8_t* → char* 
        ofs.write(reinterpret_cast<const char*>(image.data()), image.size());
    }
   
    template <typename T>
    std::vector<T> RGBImage(size_t largeur, size_t hauteur, T R, T G, T B) {
        static_assert(std::is_integral<T>::value, "createRGBImage requiert un type entier");
    
        std::vector<T> imageRGB(largeur * hauteur * 3);
        for (size_t i = 0; i < largeur * hauteur; ++i) {
            imageRGB[i * 3 + 0] = R;
            imageRGB[i * 3 + 1] = G;
            imageRGB[i * 3 + 2] = B;
        }
        return imageRGB;
    }
    
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
    /*
    la lecture / écriture de fichiers images au format brut (.raw). 
    A la lecture,il faudra prendre en compte à la fois le codage big endian, 
     et le codage little endian (le plus répandu pour les images codées sur plusieurs octets). 
    */
    
    //Fichier brut, sans en-tête, sans information de dimensions, juste des données brutes //L’ordinateur ne peut pas deviner la taille ou les canaux : tu dois la spécifier toi-même
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

    template<typename T>
    void ecrireFichierRaw(const std::vector<T>& image, const std::string& filename) {
        std::ofstream out(filename, std::ios::binary);
        out.write(reinterpret_cast<const char*>(image.data()), image.size() * sizeof(T)); //image.data() => donne un pointeur vers les données brutes du vecteur
                                                                                                     //Le fichier ne sait écrire que des octets (char), donc on doit changer le type du pointeur
                                                                                                     //  (T*) en const char* avec reinterpret_cast, pour pouvoir écrire les données brutes dans un fichier binaire (RAW).
                                                                                                     //// Les données ne changent pas, seule la façon de les interpréter change.
        out.close();
    }

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
std::vector<DstType> convertImage(const std::vector<SrcType>& image, bool adjustDynamics) { //On va ré-étaler la plage de valeurs de l’image source pour utiliser toute la plage possible de la destination.
                                                                                            //prends toute la plage utile des valeurs en uint16_t et on les "étales" sur toute la plage disponible en uint8_t (de 0 à 255)
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

namespace v1_1{

    template<typename T>
    class Image {
    public:
    Image(int largeur, int hauteur);
    Image();

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

    static Image<T> lireImageRAW(const std::string& fichier, size_t largeur, size_t hauteur, bool bigEndian = false);
   

    template<typename Dst>
    Image<Dst> convertirImage(bool ajuster = false) const;

    T& operator()(int x, int y);
    const T& operator()(int x, int y) const;

protected:
    int _largeur, _hauteur;
    std::vector<T> _image;
    };
    
    // Implémentations
    template<typename T>
    Image<T>::Image() : _largeur(0), _hauteur(0) {}
    template<typename T>
    Image<T>::Image(int largeur, int hauteur) : _largeur(largeur), _hauteur(hauteur), _image(largeur * hauteur) {}
   
   
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
                (*this)(x, y) = estBlanc ? std::numeric_limits<T>::max() : 0;  //(*this) désigne l’instance courante de la classe (l’objet sur lequel on est en train de travailler).
            }                                                                   //Grâce à la surcharge de l’opérateur (), écrire (*this)(x,y) revient à accéder au pixel en (x,y) 
        }
       
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

    template<typename T>
    void Image<T>::printImage() const {
        for (size_t y = 0; y < _hauteur; ++y) {
            for (size_t x = 0; x < _largeur; ++x) {
                std::cout << std::setw(4) << static_cast<int>(_image[y * _largeur + x]) << " ";
            }
            std::cout << std::endl;
        }
    }
    
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
        //Surcgarge de constructeur 
        ImageRGB(const Image<uint8_t>& rgbImage, int largeur, int hauteur); //creer des images RGB simple 
        ImageRGB(const Image<uint8_t>& imageGris,  size_t Largeur, size_t Hauteur,const std::vector<uint8_t>& lut); //Convertir des images RGB en niveau de gris on appliquant LUT

            
        const std::vector<uint8_t>& getImageRGB() const;
        void sauvegarderPPM(const std::string& fichier) const;


        static std::vector<uint8_t> chargerLUT(const std::string& fichier);


        static Image<uint8_t> convertRGB_Gris(const std::vector<uint8_t>& imageRGB, int largeur, int hauteur);


        static Image<uint8_t> lectureImageRawRGB(const std::string& fichier, size_t largeur, size_t hauteur, bool bigEndian = false);

       
   
        private: 
        std::vector<uint8_t> _ImageRGB;
        
        };
        
   
ImageRGB::ImageRGB(const Image<uint8_t>& rgbImage, int largeur, int hauteur)
: Image<uint8_t>(largeur, hauteur * 3), _ImageRGB(rgbImage.getData()) {} // *3 pour les composantes : Rouge, Vert, Bleu.

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
namespace v2_0 {
/*
Main
 │
 ▼
Addition<T>::addition(img1, img2)
 └───► crée objet Addition<T> add(...)
       │
       ├──► add.Update()
       │     └──► this->Process()   (polymorphisme)
       │            └──► Addition<T>::Process()  // vrai traitement
       │

      */
#include "FFT.hpp"
    // Processing1 : pour une seule image en entrée

    //class abstract contient une methode virtuelle qui sera implementer dans des class fille  
    // utilisée pour définir une interface commune que toutes les classes dérivées doivent implémenter.
    template<typename T>
    class Processing1 {
    public:
        Processing1(v1_1::Image<T>& input, bool inPlace = false);

        virtual void Process() = 0; //methode virtuelle, cette classe ne contient pas d'omplementation /
                                    ///Par contre toute classe herite de cette class dois obligatoirement implementer cette methode 
        void Update();

        v1_1::Image<T>& getOutput();

    protected:
        v1_1::Image<T>& imageInput_;
        v1_1::Image<T> imageOutput_;
        bool inPlace_;  //inPlace_ indique si le traitement doit écraser l'image d'entrée ou non
    };

    // Processing2 : pour deux images en entrée
    template<typename T>
    class Processing2 {
    public: //encapsulation (publique, private, protected), gère la sécurité d'accés au données(attributs et methodes)

    //Constructeur
        Processing2(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace = false);
//Methodes 
        virtual void Process() = 0; 

        void Update();

        v1_1::Image<T>& getOutput();

    protected:
    //attributs
        v1_1::Image<T>& imageInput1_;
        v1_1::Image<T>& imageInput2_;
        v1_1::Image<T> imageOutput_;
        bool inPlace_; 
    };

    // Addition avec un scalaire
    template<typename T>
    class AdditionScalar : public Processing1<T> {
    public:
        AdditionScalar(v1_1::Image<T>& input, T valScalar, bool inPlace = false);

        void Process() override;
        static v1_1::Image<T> additionScalar(const v1_1::Image<T>& input, T valScalar);
    private:
        T valScalar_;
    };



    // Addition de deux images
    template<typename T>
    class Addition : public Processing2<T> {
    public:
    //constructeur 
        Addition(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace = false);

        //methode process de la class processing2 (qui est virtuelle) doit etre implementer 
        void Process() override;

        // Méthode statique utilitaire pour addition sans créer d'objet
        static v1_1::Image<T> addition(const v1_1::Image<T>& imageInput1, const v1_1::Image<T>& imageInput2);
    };

 
    // ----------------- Implémentations -----------------

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
 // AdditionScalar
template<typename T>
AdditionScalar<T>::AdditionScalar(v1_1::Image<T>& input, T valScalar, bool inPlace)
    : Processing1<T>(input, inPlace), valScalar_(valScalar) {}

template<typename T>
void AdditionScalar<T>::Process() {
    size_t largeur = this->imageInput_.getlargeur();
    size_t hauteur = this->imageInput_.gethauteur();
    v1_1::Image<T>& imageSortie = this->inPlace_ ? this->imageInput_ : this->imageOutput_;

    for (size_t y = 0; y < hauteur; ++y) {
        for (size_t x = 0; x < largeur; ++x) {
            T val = this->imageInput_(x, y) + valScalar_;

            // Saturation (valeur maximale selon le type T)
            if (std::numeric_limits<T>::is_integer) {
                val = std::min<T>(val, std::numeric_limits<T>::max());
            }

            imageSortie(x, y) = val;
        }
    }
}
    // Fonction libre additionScalar
    template<typename T>
   v1_1::Image<T> AdditionScalar<T>::additionScalar(const v1_1::Image<T>& input, T valScalar) {
        size_t largeur = input.getlargeur();
        size_t hauteur = input.gethauteur();
        v1_1::Image<T> output(largeur, hauteur);

        for (size_t y = 0; y < hauteur; ++y) {
            for (size_t x = 0; x < largeur; ++x) {
                output(x, y) = input(x, y) + valScalar;
            }
        }

        return output;
    }


    // la class Égalisation d'histogramme
template<typename T>
class egalisationHistogram : public Processing1<T> {   
public:
    egalisationHistogram(v1_1::Image<T>& input, bool inPlace = false);

    void Process() override;

    // Génère une image d'histogramme depuis l'entrée originale
    v1_1::Image<uint8_t> getHistogramImage();


    // 5. Recalculer histogramme après égalisation
   void compterHistogram(const v1_1::Image<T>& image);
private:
    std::vector<int> histogramImage_;  // pour getHistogramImage()
};

// egalisationHistogram
//Améliorer le contraste d’une image en répartissant de manière plus uniforme les niveaux de gris (valeurs de pixels entre 0 et 255).
//Une image sombre aura des pixels concentrés dans les bas niveaux de gris (0-50).
//L’égalisation d’histogramme étale ces valeurs sur toute la plage [0, 255], ce qui améliore la visibilité des détails.

//Quand on regarde une image, ses pixels ont des intensités (par exemple de 0 à 255). Mais ces intensités ne sont pas toujours bien réparties : par exemple, elles peuvent être concentrées dans une petite plage (image sombre ou claire).

//L’égalisation d’histogramme est une méthode pour étaler ou redistribuer ces intensités de manière plus uniforme sur toute la plage possible (0 à 255). Cela améliore le contraste de l’image.
template<typename T>
egalisationHistogram<T>::egalisationHistogram(v1_1::Image<T>& input, bool inPlace)
    : Processing1<T>(input, inPlace) {}


    template<typename T>
void egalisationHistogram<T>::compterHistogram(const v1_1::Image<T>& image) {
    histogramImage_ = std::vector<int>(256, 0);
    for (auto val : image.getData()) {
        histogramImage_[val]++;
    }
}


    template<typename T>
void egalisationHistogram<T>::Process() {
    static_assert(std::is_same<T, uint8_t>::value, "egalisation d'Histogram ne supporte que uint8_t");

    size_t w = this->imageInput_.getlargeur();
    size_t h = this->imageInput_.gethauteur();
    size_t total = w * h;

    v1_1::Image<T>& output = this->inPlace_ ? this->imageInput_ : this->imageOutput_;
    output = v1_1::Image<T>(w, h);

    // 1. Histogramme d'entrée
        // 1. Histogramme
    //te donne combien de fois chaque intensité apparaît dans l’image.
    histogramImage_ = std::vector<int>(256, 0);
    for (auto val : this->imageInput_.getData()) {
        histogramImage_[val]++;
    }

    // 2. CDF
    
    // 2. CDF  La CDF donne, pour chaque niveau i, le nombre total de pixels de valeur ≤ i.
    //Elle sert à transformer les anciennes valeurs vers de nouvelles valeurs étalées.
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



template<typename T>
v1_1::Image<uint8_t> egalisationHistogram<T>::getHistogramImage() {
    const int histlargeur = 256;
    const int histhauteur = 100;

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

// La class Convolutuion 

template<typename T>
class Convolution : public Processing1<T> {
public:
    Convolution( v1_1::Image<T>& image, const v1_1::Image<float>& noyau, bool inPlace = false);

    void Process() override;

    static v1_1::Image<float> createMoyenneur(int taille);
    static v1_1::Image<float> createGaussien(int taille, float sigma);
    static v1_1::Image<float> createExponentiel(int taille, float lambda);

private:
    v1_1::Image<float> noyau_;
};

// Constructeur
template<typename T>
Convolution<T>::Convolution( v1_1::Image<T>& image, const v1_1::Image<float>& noyau, bool inPlace)
    : Processing1<T>(image, inPlace), noyau_(noyau) {}

// Processus de convolution
template<typename T>
void Convolution<T>::Process() {
    int L = this->imageInput_.getlargeur();
    int H = this->imageInput_.gethauteur();
    int nL = noyau_.getlargeur();
    int nH = noyau_.gethauteur();
    int dx = nL / 2;
    int dy = nH / 2;

    v1_1::Image<T>& out = this->inPlace_ ? this->imageInput_ : this->imageOutput_;
    if (!this->inPlace_) {
        this->imageOutput_ = v1_1::Image<T>(L, H);  // allouer explicitement
    }
    
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < L; ++x) {
            float sum = 0.0f;
            for (int j = 0; j < nH; ++j) {
                for (int i = 0; i < nL; ++i) {
                    int ix = x + i - dx;
                    int iy = y + j - dy;

                    // Gestion manuelle des bords (mirroring simple ici)
                    if (ix < 0) ix = 0;
                    if (ix >= L) ix = L - 1;
                    if (iy < 0) iy = 0;
                    if (iy >= H) iy = H - 1;

                    sum += this->imageInput_(ix, iy) * noyau_(i, j);
                }
            }

            // Clamp manuel entre 0 et 255
            if (sum < 0.0f) sum = 0.0f;
            else if (sum > 255.0f) sum = 255.0f;

            out(x, y) = static_cast<T>(sum);
        }
    }
}

//Moyenneur
template<typename T>
v1_1::Image<float> Convolution<T>::createMoyenneur(int taille) {
    v1_1::Image<float> noyau(taille, taille);
    float val = 1.0f / (taille * taille);
    for (int y = 0; y < taille; ++y)
        for (int x = 0; x < taille; ++x)
            noyau(x, y) = val;
    return noyau;
}

//Gaussien 
template<typename T>
v1_1::Image<float> Convolution<T>::createGaussien(int taille, float sigma) {
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
//Exponentiel 

template<typename T>
v1_1::Image<float> Convolution<T>::createExponentiel(int taille, float lambda) {
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

//class 

template<typename T>
class FiltrageFrequenciel : public Processing2<T> {
public:
    FiltrageFrequenciel(v1_1::Image<T>& image, v1_1::Image<T>& filtre);
    void Process() override;
    static v1_1::Image<T> creerFiltreButterworth(int largeur, int hauteur, float d0, int ordre);
};

template<typename T>
FiltrageFrequenciel<T>::FiltrageFrequenciel(v1_1::Image<T>& image, v1_1::Image<T>& filtre)
    : Processing2<T>(image, filtre, false) {}

template<typename T>
void FiltrageFrequenciel<T>::Process() {
    size_t w = this->imageInput1_.getlargeur();
    size_t h = this->imageInput1_.gethauteur();

    // 1. Initialiser les parties réelle et imaginaire avec centrage
    v1_1::Image<T> realIn = this->imageInput1_;
    v1_1::Image<T> imagIn(w, h);

    for (size_t y = 0; y < h; ++y)
        for (size_t x = 0; x < w; ++x) {
            realIn(x, y) *= ((x + y) % 2 == 0) ? 1 : -1;  // centrage
            imagIn(x, y) = 0;
        }

    // 2. FFT directe
    v1_1::Image<T> realF(w, h), imagF(w, h);
    directFFT(realIn, imagIn, realF, imagF);

    // 3. Appliquer le filtre fréquentiel normalisé
    for (size_t y = 0; y < h; ++y)
        for (size_t x = 0; x < w; ++x) {
            float H = static_cast<float>(this->imageInput2_(x, y)) / 255.0f;  // [0,1]
            realF(x, y) = static_cast<T>(realF(x, y) * H);
            imagF(x, y) = static_cast<T>(imagF(x, y) * H);
        }

    // 4. FFT inverse
    v1_1::Image<T> realOut(w, h), imagOut(w, h);
    inverseFFT(realF, imagF, realOut, imagOut);

    // 5. Décentrage de Fourier
    for (size_t y = 0; y < h; ++y)
        for (size_t x = 0; x < w; ++x)
            realOut(x, y) *= ((x + y) % 2 == 0) ? 1 : -1;

    // 6. Stocker le résultat, clamp entre 0 et 255
    this->imageOutput_ = v1_1::Image<T>(w, h);
    for (size_t y = 0; y < h; ++y)
        for (size_t x = 0; x < w; ++x) {
            float val = static_cast<float>(realOut(x, y));
            val = std::max(0.0f, std::min(255.0f, val));
            this->imageOutput_(x, y) = static_cast<T>(val);
        }
}

template<typename T>
v1_1::Image<T> FiltrageFrequenciel<T>::creerFiltreButterworth(int width, int height, float d0, int ordre) {
    v1_1::Image<T> filtre(width, height);
    int cx = width / 2;
    int cy = height / 2;

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            float dx = x - cx;
            float dy = y - cy;
            float d = std::sqrt(dx * dx + dy * dy);
            float H = 1.0f / (1.0f + std::pow(d / d0, 2 * ordre));
            filtre(x, y) = static_cast<T>(H * 255.0f);  // dans [0,255]
        }

    return filtre;
}
    

}
#endif