#include <iostream>
#include <vector>
#include <string>
#include "namespace.hpp"


int main(){
    
    const size_t Largeur = 256;
    const size_t Hauteur = 256;

    v1_1::Image<uint8_t> Image8(Largeur, Hauteur);
    v1_1::Image<uint16_t > image16(Largeur, Hauteur);
    


    std::string ImageRaw= "images_Raw\\images\\" ;
    std::string imagePGM= "imagePGM/" ;
    std::string lutPath = "LUT/LUT/";
    std::string imageRGBdPath = "imageColored/";

    
    int choix_namespace = -1;
while (true) {
    std::cout << "Tapez 1 pour utiliser le namespace v1_0\n";
    std::cout << "Tapez 2 pour utiliser le namespace v1_1\n";
    std::cout << "Tapez 3 pour utiliser le namespace v1_1\n";
    std::cout << "Tapez 0 pour quitter\n";
    std::cin >> choix_namespace;

switch (choix_namespace) {
case 1:{
    std::cout << "Namespace 1.0 sélectionné\n";

   //la Reponse a la première question 

    // 1. Création image blanche
    auto whiteImage = v1_0::ImageBlanche<uint8_t>(Largeur, Hauteur);
    v1_0::sauvegarderPGM(whiteImage, Largeur, Hauteur, imagePGM + "whiteImage.pgm");

    // 2.  sinusoïdale
    auto sinusImage = v1_0::SinusoidalImage<uint16_t>(Largeur, Hauteur, 8.0); 
    // savePGM16(sinusImage, Largeur, Hauteur, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    v1_0::EcritureImageRaw(sinusImage, ImageRaw + "sinus_image.raw");
    // 3. Damier
    auto checkerboardImage = v1_0::ImageDamier<uint8_t>(Largeur, Hauteur, 32); 
    v1_0::sauvegarderPGM(checkerboardImage, Largeur, Hauteur, imagePGM + "checkerboardImage.pgm");

    //4.image en couleur RGB
    auto rgbImage = v1_0::RGBImage<uint8_t>(Largeur, Hauteur, 255, 128, 64);
    v1_0::sauvegarderPPM(rgbImage, Largeur, Hauteur, imagePGM + "rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    v1_0::printImage(checkerboardImage, 4, 3);

    auto sinusImage_BE = v1_0::LecteurImageRAW<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
    auto sinusImage_LE = v1_0::LecteurImageRAW<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
     
    auto sinusImage_BE_converted = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
    v1_0::sauvegarderPGM(sinusImage_BE_converted, Largeur, Hauteur, imagePGM + "sinusImage_BE_converted.pgm");
    auto sinusImage_LE_converted = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
    v1_0::sauvegarderPGM(sinusImage_LE_converted, Largeur, Hauteur, imagePGM + "isinusImage_BE_converted.pgm");
 
   
    // 1. Lecture de fichiers RAW (8 bits)
    //Lecture de fichiers RAW (8 bits) avec 1 canal (Niveau de gris) 

    auto imageXR__femoral_BE = v1_0::LectureImageRawRGB<uint8_t>(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, 1,false); // Big Endian
    auto imageXR__femoral_LE = v1_0::LectureImageRawRGB<uint8_t>(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512,1, true); // Big Endian
    
   // 2. Sauvegarde des fichiers RAW 8 bits en images PGM en niveaux de gris
    v1_0::sauvegarderPGM(imageXR__femoral_BE, 512, 512, imagePGM+"XR_8_bits_512x512_femoral_BE.pgm");
    v1_0::sauvegarderPGM(imageXR__femoral_LE, 512, 512, imagePGM+"XR_8_bits_512x512_femoral_LE.pgm");
   
  
   //changement de la dynamique de lUT

    auto lut1 = v1_0::ChargerLUT(lutPath + "000-gray.lut");
    auto lut2 = v1_0::ChargerLUT(lutPath + "001-fire.lut");
    auto lut3 = v1_0::ChargerLUT(lutPath + "002-spectrum.lut");

   //  // 4. Application de la LUT sur les images
   // image 1 => imageXR__femoral_BE

    auto imageXR__femoral_BE_colored_1 = v1_0::applLUT(imageXR__femoral_BE, lut1);
    auto imageXR__femoral_BE_colored_2 = v1_0::applLUT(imageXR__femoral_BE, lut2);
    auto imageXR__femoral_BE_colored_3 = v1_0::applLUT(imageXR__femoral_BE, lut3);
     
     
    //  // 5. Sauvegarde des images en couleur
    //  savePPM(imageXR__femoral_BE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_LE.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_colored_1, 512, 512,  imageRGBdPath+"imageXR__femoral_BE_colored_1.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_colored_2, 512, 512,  imageRGBdPath+"imageXR__femoral_BE_colored_2.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_colored_3, 512, 512,  imageRGBdPath+"imageXR__femoral_BE_colored_3.ppm");
     
break;
}

case 2:{
    std::cout << "Namespace 1.1 sélectionné\n";

//image blanche 
auto ImageBlanche = Image8.creerImageBlache();
Image8.sauvegarderPGM(ImageBlanche, Largeur,Hauteur,imagePGM + "ImageBlanche.pgm");

//image damier
auto ImageDamier = Image8.creerImageDamier(32);
Image8.sauvegarderPGM(ImageDamier,Largeur,Hauteur,imagePGM + "damier.pgm");

//image sinusoidale 
auto imageSinus= Image8.creerImageSinusoidal(10.0);
Image8.sauvegarderPGM(imageSinus,Largeur,Hauteur,imagePGM+"sinusoidal.pgm");


//lecture fichier image .raw 8bits 
auto XR_femoral_BE=  Image8.LecteurImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw",  512,  512,false);
auto XR_femoral_LE=  Image8.LecteurImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw",  512,  512,true);
   
 
Image8.sauvegarderPGM(XR_femoral_BE,  512,  512, imagePGM + "Shepp_Logan_sinogram_8_bits_256x363_BE.pgm");
Image8.sauvegarderPGM(XR_femoral_LE,  512,  512, imagePGM + "Shepp_Logan_sinogram_8_bits_256x363_LE.pgm");

// charger LUT
auto lut11 = v1_1::ChargerLUT(lutPath + "000-gray.lut");
auto lut12 = v1_1::ChargerLUT(lutPath + "001-fire.lut");

 
//appliquer LUT
v1_1::ImageRGB XR_femoral_BE_LUT_1 (XR_femoral_BE, 512, 512, lut11);
v1_1::ImageRGB XR_femoral_BE_LUT_2 (XR_femoral_BE, 512, 512, lut12);
     
// Sauvegarde l image en format .PPM
XR_femoral_BE_LUT_1.sauvegraderPPM(imageRGBdPath + "XR_femoral_BE_LUT_1.ppm");
XR_femoral_BE_LUT_2.sauvegraderPPM(imageRGBdPath + "XR_femoral_BE_LUT_2.ppm");
        
break;
}

case 3: 
std::cout << "Namespace 2.0 sélectionné\n";
break; 

case 0:
return 0;
break;

default: 
std::cout << "Choix invalide, veuillez taper 0, 1 ou 2.\n";



}
   
}
}