#ifndef IMAGE_H
#define IMAGE_H

#include <vector>           
#include <iostream>      
#include "./Image.h"
namespace v1_1 {

    class ImageRGB : public  v1_1::Image<uint8_t>{
        
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
}
    #endif