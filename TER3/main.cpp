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
    std::string imageRGB = "imageRGB/";

    
    int choix_namespace = -1;

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
    auto ImageBlanche = v1_0::ImageBlanche<uint8_t>(Largeur, Hauteur);
    v1_0::sauvegarderPGM(ImageBlanche, Largeur, Hauteur, imagePGM + "ImageBlanche.pgm");

    // 2.  sinusoïdale
    auto sinusImage = v1_0::SinusoidalImage<uint16_t>(Largeur, Hauteur, 8.0); 
    // savePGM16(sinusImage, Largeur, Hauteur, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    v1_0::ecrireFichierRaw(sinusImage, ImageRaw + "sinus_image.raw");
    // 3. Damier
    auto DamierImage = v1_0::ImageDamier<uint8_t>(Largeur, Hauteur, 32); 
    v1_0::sauvegarderPGM(DamierImage, Largeur, Hauteur, imagePGM + "DamierImage.pgm");

    //4.image en couleur RGB
    auto rgbImage = v1_0::RGBImage<uint8_t>(Largeur, Hauteur, 255, 128, 64);
    v1_0::sauvegarderPPM(rgbImage, Largeur, Hauteur, imagePGM + "rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    v1_0::printImage(DamierImage, 4, 3);

    auto sinusImage_BE = v1_0::lireImageRAW<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
    auto sinusImage_LE = v1_0::lireImageRAW<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
     
    auto sinusImage_BE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
    v1_0::sauvegarderPGM(sinusImage_BE_converte, Largeur, Hauteur, imagePGM + "sinusImage_BE_converte.pgm");
    auto sinusImage_LE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
    v1_0::sauvegarderPGM(sinusImage_LE_converte, Largeur, Hauteur, imagePGM + "sinusImage_LE_converte.pgm");
 
   
    // 1. Lecture de fichiers RAW (8 bits)
    //Lecture de fichiers RAW (8 bits) avec 1 canal (Niveau de gris) 

    auto imageXR__femoral_BE = v1_0::lireImageRAW<uint8_t>(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512,false); // Big Endian
    auto imageXR__femoral_LE = v1_0::lireImageRAW<uint8_t>(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, true); // Big Endian
    

    
    auto IRM_RGB_crane_RGB_BE = v1_0::lectureImageRawRGB<uint8_t>(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256,3,false); // Big Endian
    auto IRM_RGB_crane_RGB_LE = v1_0::lectureImageRawRGB<uint8_t>(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, 3,true); // Big Endian
    
    //convertir en niveau de gris 
    auto IRM_RGB_crane_BE = v1_0::convertRGB_Gris(IRM_RGB_crane_RGB_BE, 256,256);
    auto IRM_RGB_crane_LE = v1_0::convertRGB_Gris(IRM_RGB_crane_RGB_LE, 256,256);

    
    
    
    
    // 2. Sauvegarde des fichiers RAW 8 bits en images PGM en niveaux de gris
    v1_0::sauvegarderPGM(imageXR__femoral_BE, 512, 512, imagePGM+"XR_8_bits_512x512_femoral_BE.pgm");
    v1_0::sauvegarderPGM(imageXR__femoral_LE, 512, 512, imagePGM+"XR_8_bits_512x512_femoral_LE.pgm");
    
     v1_0::sauvegarderPGM(IRM_RGB_crane_BE, 256, 256, imagePGM+"IRM_RGB_crane_BE.pgm");
     v1_0::sauvegarderPGM(IRM_RGB_crane_LE, 256, 256, imagePGM+"IRM_RGB_crane_LE.pgm");
  
   //changement de la dynamique de lUT

    auto lut1 = v1_0::chargerLUT(lutPath + "000-gray.lut");
    auto lut2 = v1_0::chargerLUT(lutPath + "001-fire.lut");
    auto lut3 = v1_0::chargerLUT(lutPath + "002-spectrum.lut");

   //  // 4. Application de la LUT sur les images
   // image 1 => imageXR__femoral_BE

    auto imageXR__femoral_BE_RGB_1 = v1_0::applLUT(imageXR__femoral_BE, lut1);
    auto imageXR__femoral_BE_RGB_2 = v1_0::applLUT(imageXR__femoral_BE, lut2);
    auto imageXR__femoral_BE_RGB_3 = v1_0::applLUT(imageXR__femoral_BE, lut3);

    auto IRM_RGB_crane_BE_RGB1 = v1_0::applLUT(IRM_RGB_crane_BE, lut1);
    auto IRM_RGB_crane_BE_RGB2 = v1_0::applLUT(IRM_RGB_crane_BE, lut2);
    auto IRM_RGB_crane_LE_RGB1 = v1_0::applLUT(IRM_RGB_crane_LE, lut1);
    auto IRM_RGB_crane_LE_RGB2 = v1_0::applLUT(IRM_RGB_crane_LE, lut2);
     
     
    //  // 5. Sauvegarde des images en couleur
    //  savePPM(imageXR__femoral_BE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_LE.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_RGB_1, 512, 512,  imageRGB+"imageXR__femoral_BE_RGB_1.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_RGB_2, 512, 512,  imageRGB+"imageXR__femoral_BE_RGB_2.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_BE_RGB_3, 512, 512,  imageRGB+"imageXR__femoral_BE_RGB_3.ppm");


    //  // 5. Sauvegarde des images en couleur
    v1_0::sauvegarderPPM(IRM_RGB_crane_BE_RGB1, 256, 256,  imageRGB+"IRM_RGB_crane_BE_RGB1.ppm");
    v1_0::sauvegarderPPM(IRM_RGB_crane_BE_RGB2, 256, 256,  imageRGB+"IRM_RGB_crane_BE_RGB2.ppm");
    v1_0::sauvegarderPPM(IRM_RGB_crane_LE_RGB1, 256, 256,  imageRGB+"IRM_RGB_crane_LE_RGB1.ppm");
    v1_0::sauvegarderPPM(IRM_RGB_crane_LE_RGB2, 256, 256,  imageRGB+"IRM_RGB_crane_LE_RGB2.ppm");
     
break;
}

case 2:{
    std::cout << "Namespace 1.1 sélectionné\n";



// Générer images de test
v1_1::Image<uint8_t> imageBlanche(256, 256);
imageBlanche.creerImageBlache();
imageBlanche.ecrireFichierRaw("ImageBlanche.raw");
imageBlanche.sauvegarderPGM( imagePGM+"ImageBlanche.pgm");

v1_1::Image<uint8_t> imageDamier(256, 256);
imageDamier.creerDamier(64);
imageDamier.ecrireFichierRaw( "ImageDamier.raw");
imageDamier.sauvegarderPGM( imagePGM+"ImageDamier.pgm");

v1_1::Image<uint8_t> imageSinus(256, 256);
imageSinus.creerSinusoidale(25);
imageSinus.ecrireFichierRaw( "ImageSinus.raw");
imageSinus.sauvegarderPGM(imagePGM+"ImageSinus.pgm");


  // Lire images RAW correctement
  auto XR_femoral_BE = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, false);
  auto XR_femoral_LE = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, true);
 
  auto TDM_16_bits_BE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, false);
  auto TDM_16_bits_LE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, true);

  auto TDM_16__crane_converte_BE = TDM_16_bits_BE.convertirImage< uint8_t>( true);
  auto TDM_16__crane_converte_LE = TDM_16_bits_BE.convertirImage< uint8_t>( true);

  //ImgaeRGB

    auto IRM_RGB_crane_BE = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, false);
    auto IRM_RGB_crane_LE = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, true);
   
    auto IRM_RGB_crane_BEGris_BE = v1_1::convertRGB_Gris(IRM_RGB_crane_BE, 256, 256);
    auto IRM_RGB_crane_BEGris_LE = v1_1::convertRGB_Gris(IRM_RGB_crane_BE, 256, 256);
 

  XR_femoral_BE.sauvegarderPGM( imagePGM+"XR_femoral_BE.pgm");
  XR_femoral_LE.sauvegarderPGM( imagePGM+"XR_femoral_LE.pgm");
  
  TDM_16__crane_converte_BE.sauvegarderPGM( imagePGM+"TDM_16_bits_BE.pgm");
  TDM_16__crane_converte_LE.sauvegarderPGM( imagePGM+"TDM_16_bits_LE.pgm");

  IRM_RGB_crane_BEGris_BE.sauvegarderPGM( imagePGM+"IRM_RGB_8_bits_engris_BE.pgm");
  IRM_RGB_crane_BEGris_LE.sauvegarderPGM( imagePGM+"IRM_RGB_8_bits_engris_LE.pgm");

  // Charger LUT
  auto lut11 = v1_1::ImageRGB::chargerLUT(lutPath + "000-gray.lut");
  auto lut12 = v1_1::ImageRGB::chargerLUT(lutPath + "001-fire.lut");

  // Appliquer LUT
  v1_1::ImageRGB XR_femoral_BE_LUT_11(XR_femoral_BE, 512, 512, lut11);
  
  v1_1::ImageRGB TDM_16__crane_converte_LE_11(TDM_16__crane_converte_LE, 512, 512, lut11);
  v1_1::ImageRGB TDM_16__crane_converte_BE_11(TDM_16__crane_converte_BE, 512, 512, lut11);
  
  v1_1::ImageRGB TDM_16__crane_converte_LE_12(TDM_16__crane_converte_LE, 512, 512, lut12);
  v1_1::ImageRGB TDM_16__crane_converte_BE_12(TDM_16__crane_converte_BE, 512, 512, lut12);
  

  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT_BE(IRM_RGB_crane_BEGris_BE, 256, 256, lut11);
  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT_LE(IRM_RGB_crane_BEGris_LE, 256, 256, lut11);

  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT1_BE(IRM_RGB_crane_BEGris_BE, 256, 256, lut12);
  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT1_LE(IRM_RGB_crane_BEGris_LE, 256, 256, lut12);


  // Sauvegarder en .ppm
  XR_femoral_BE_LUT_11.sauvegarderPPM( imageRGB+ "XR_femoral_BE_LUT_11.ppm");

  TDM_16__crane_converte_LE_11.sauvegarderPPM( imageRGB+ " TDM_16__crane_converte_LE_1.ppm");
  TDM_16__crane_converte_BE_11.sauvegarderPPM( imageRGB+ " TDM_16__crane_converte_BE_1.ppm");

  TDM_16__crane_converte_LE_12.sauvegarderPPM( imageRGB+ " TDM_16__crane_converte_LE_2.ppm");
  TDM_16__crane_converte_BE_12.sauvegarderPPM( imageRGB+ " TDM_16__crane_converte_BE_2.ppm");

  IRM_RGB_crane_BEGris_LUT_BE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT1_BE.ppm");
  IRM_RGB_crane_BEGris_LUT_LE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT1_LE.ppm");

  IRM_RGB_crane_BEGris_LUT1_BE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT2_BE_2.ppm");
  IRM_RGB_crane_BEGris_LUT1_LE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT2_LE_2.ppm");



        
break;
}

case 3: {
std::cout << "Namespace 2.0 sélectionné\n";

v1_1::Image<uint8_t> imageBlanche(256, 256);
imageBlanche.creerImageBlache();

v1_1::Image<uint8_t> imageSinus(256, 256);
imageSinus.creerSinusoidale(25);


v1_1::Image<uint8_t> imageDamier(256, 256);
imageDamier.creerDamier(64);
  // Crée résultat
  v1_1::Image<uint8_t> result1(256, 256);

  result1 = v2_0::Addition<uint8_t>::addition(imageSinus, imageDamier);

result1.sauvegarderPGM("result1.pgm");
break; 
}


case 0:
return 0;
break;

default: 
std::cout << "Choix invalide, veuillez taper 0, 1 ou 2.\n";



}
   
}
