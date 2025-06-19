#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include "namespace.hpp"


int main(){
  try {
    const size_t Largeur = 256;
    const size_t Hauteur = 256;

    v1_1::Image<uint8_t> Image8(Largeur, Hauteur);
    v1_1::Image<uint16_t > image16(Largeur, Hauteur);
    


    std::string ImageRaw= "images RAW/images/" ;
    std::string imagePGM= "imagePGM/" ;
    std::string lutPath = "LUT/LUT/";
    std::string imageRGB = "imageRGB/";

    
    int choix_namespace = -1;

    std::cout << "====== MENU ======\n";
    std::cout << "1. Namespace v1_0\n";
    std::cout << "2. Namespace v1_1\n";
    std::cout << "3. Namespace v2_0\n";
    std::cout << "0. Quitter\n";
    std::cout << "Votre choix : ";
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
    
    auto sinusImage_BE = v1_0::lireImageRAW<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
    auto sinusImage_LE = v1_0::lireImageRAW<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
    
    auto sinusImage_BE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
    v1_0::sauvegarderPGM(sinusImage_BE_converte, Largeur, Hauteur, imagePGM + "sinusImage_BE_converte.pgm");
    auto sinusImage_LE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
    v1_0::sauvegarderPGM(sinusImage_LE_converte, Largeur, Hauteur, imagePGM + "sinusImage_LE_converte.pgm");
    
    
    // 1. Lecture de fichiers RAW (8 bits)
    //Lecture de fichiers RAW (8 bits) avec 1 canal (Niveau de gris) 
    
    auto TDM__crane_LE = v1_0::lireImageRAW<uint16_t>(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512,true); // Big Endian
    auto TDM__crane_BE = v1_0::lireImageRAW<uint16_t>(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512,false); // Big Endian
    
    auto imageXR__femoral = v1_0::lireImageRAW<uint8_t>(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512); // Big Endian
    
    auto IRM_coeur = v1_0::lireImageRAW<uint8_t>(ImageRaw + "IRM_8_bits_256x256_coeur.raw", 256, 256); // Big Endian
    
    auto IRM_RGB_crane_RGB = v1_0::lectureImageRawRGB<uint8_t>(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256,3); // Big Endian
   
    //convertir en niveau de gris 
    auto IRM_RGB_crane = v1_0::convertRGB_Gris(IRM_RGB_crane_RGB, 256,256);

    //Covertir en uint8_t

    auto TDM__crane_LE_converte = v1_0::convertImage<uint16_t, uint8_t>(TDM__crane_LE, true);
    auto TDM__crane_BE_converte = v1_0::convertImage<uint16_t, uint8_t>(TDM__crane_BE, true);
    v1_0::sauvegarderPGM(TDM__crane_LE_converte, 512, 512, imagePGM + "TDM__crane_LE_converte.pgm");
    v1_0::sauvegarderPGM(TDM__crane_BE_converte, 512, 512, imagePGM + "TDM__crane_BE_converte.pgm");
    
    
    
    // 2. Sauvegarde des fichiers RAW 8 bits en images PGM en niveaux de gris
    v1_0::sauvegarderPGM(imageXR__femoral, 512, 512, imagePGM+"XR_8_bits_512x512_femoral_BE.pgm");
    v1_0::sauvegarderPGM(IRM_coeur, 256, 256, imagePGM+"IRM_8_bits_256x256_coeur.pgm");
    
     v1_0::sauvegarderPGM(IRM_RGB_crane, 256, 256, imagePGM+"IRM_RGB_crane_BE.pgm");
  
   //changement de la dynamique de lUT

    auto lut1 = v1_0::chargerLUT(lutPath + "000-gray.lut");
    auto lut2 = v1_0::chargerLUT(lutPath + "001-fire.lut");
    auto lut3 = v1_0::chargerLUT(lutPath + "002-spectrum.lut");

   //  // 4. Application de la LUT sur les images
   // image 1 => imageXR__femoral_BE

    auto imageXR__femoral_RGB_1 = v1_0::applLUT(imageXR__femoral, lut1);
    auto imageXR__femoral_RGB_2 = v1_0::applLUT(imageXR__femoral, lut2);
    auto imageXR__femoral_RGB_3 = v1_0::applLUT(imageXR__femoral, lut3);

    auto IRM_coeur_RGB_1 = v1_0::applLUT(IRM_coeur, lut1);
    auto IRM_coeur_RGB_2 = v1_0::applLUT(IRM_coeur, lut2);
    auto IRM_coeur_RGB_3 = v1_0::applLUT(IRM_coeur, lut3);

    auto IRM_RGB_crane_RGB1 = v1_0::applLUT(IRM_RGB_crane, lut1);
    auto IRM_RGB_crane_RGB2 = v1_0::applLUT(IRM_RGB_crane, lut2);
     
     
    //  // 5. Sauvegarde des images en couleur
    //  savePPM(imageXR__femoral_BE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_LE.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_RGB_1, 512, 512,  imageRGB+"imageXR__femoral_RGB_1.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_RGB_2, 512, 512,  imageRGB+"imageXR__femoral_RGB_2.ppm");
    v1_0::sauvegarderPPM(imageXR__femoral_RGB_3, 512, 512,  imageRGB+"imageXR__femoral_RGB_3.ppm");

    v1_0::sauvegarderPPM(IRM_coeur_RGB_1, 512, 512,  imageRGB+"IRM_coeur_RGB_1.ppm");
    v1_0::sauvegarderPPM(IRM_coeur_RGB_2, 512, 512,  imageRGB+"IRM_coeur_RGB_2.ppm");
    v1_0::sauvegarderPPM(IRM_coeur_RGB_3, 512, 512,  imageRGB+"IRM_coeur_RGB_3.ppm");


    //  // 5. Sauvegarde des images en couleur
    v1_0::sauvegarderPPM(IRM_RGB_crane_RGB1, 256, 256,  imageRGB+"IRM_RGB_crane_RGB1.ppm");
    v1_0::sauvegarderPPM(IRM_RGB_crane_RGB2, 256, 256,  imageRGB+"IRM_RGB_crane_RGB2.ppm");
     
break;
}

case 2:{
    std::cout << "Namespace 1.1 sélectionné\n";
// Générer images de test (uint8_t, pas besoin d’endianess)
v1_1::Image<uint8_t> imageBlanche(256, 256);
imageBlanche.creerImageBlache();
imageBlanche.ecrireFichierRaw("ImageBlanche.raw");
imageBlanche.sauvegarderPGM(imagePGM + "ImageBlanche.pgm");

v1_1::Image<uint8_t> imageDamier(256, 256);
imageDamier.creerDamier(64);
imageDamier.ecrireFichierRaw("ImageDamier.raw");
imageDamier.sauvegarderPGM(imagePGM + "ImageDamier.pgm");

v1_1::Image<uint8_t> imageSinus(256, 256);
imageSinus.creerSinusoidale(25);
imageSinus.ecrireFichierRaw("ImageSinus.raw");
imageSinus.sauvegarderPGM(imagePGM + "ImageSinus.pgm");

// Lire images RAW correctement

// uint8_t : pas de paramètre endian (inutile)
auto XR_femoral = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512);
auto IRM_coeur = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "IRM_8_bits_256x256_coeur.raw", 256, 256);

// uint16_t : gérer endianess explicitement (false=BE, true=LE)
auto TDM_16_bits_LE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, false);
auto TDM_16_bits_BE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, true);

// Conversion 16 bits -> 8 bits : 
// **On choisit une seule conversion** car uint8_t n'a pas d'endianness
auto TDM_16_crane_converte = TDM_16_bits_LE.convertirImage<uint8_t>(false);

// Images RGB 8 bits par composante (pas d’impact endianess normalement, mais méthode attend bool)
auto IRM_RGB_crane = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, false);

// Conversion en niveaux de gris (pas de différence d’endianness pour uint8_t)
auto IRM_RGB_crane_Gris = v1_1::convertRGB_Gris(IRM_RGB_crane, 256, 256);

// Sauvegarder PGM (niveau de gris)
XR_femoral.sauvegarderPGM(imagePGM + "XR_femoral.pgm");
IRM_coeur.sauvegarderPGM(imagePGM + "IRM_coeur.pgm");
TDM_16_crane_converte.sauvegarderPGM(imagePGM + "TDM_16_crane_converte.pgm");  // Une seule version 8 bits

IRM_RGB_crane_Gris.sauvegarderPGM(imagePGM + "IRM_RGB_8_bits_engris.pgm");

// Charger LUTs
auto lut11 = v1_1::ImageRGB::chargerLUT(lutPath + "16_Color_Ramps.lut");
auto lut12 = v1_1::ImageRGB::chargerLUT(lutPath + "16-color.lut");

// Appliquer LUT sur images 8 bits (une seule version 16->8 bits convertie)
v1_1::ImageRGB XR_femoral_LUT_11(XR_femoral, 512, 512, lut11);
v1_1::ImageRGB XR_femoral_LUT_12(XR_femoral, 512, 512, lut12);

v1_1::ImageRGB IRM_coeur_LUT_11(IRM_coeur, 256, 256, lut11);
v1_1::ImageRGB IRM_coeur_LUT_12(IRM_coeur, 256, 256, lut12);


v1_1::ImageRGB TDM_16_crane_converte_LUT_11(TDM_16_crane_converte, 512, 512, lut11);
v1_1::ImageRGB TDM_16_crane_converte_LUT_12(TDM_16_crane_converte, 512, 512, lut12);

v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT(IRM_RGB_crane_Gris, 256, 256, lut11);

v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT2(IRM_RGB_crane_Gris, 256, 256, lut12);

// Sauvegarder en PPM
XR_femoral_LUT_11.sauvegarderPPM(imageRGB + "XR_femoral_LUT_11.ppm");
XR_femoral_LUT_12.sauvegarderPPM(imageRGB + "XR_femoral_LUT_12.ppm");

IRM_coeur_LUT_11.sauvegarderPPM(imageRGB + "IRM_coeur_LUT_11.ppm");
IRM_coeur_LUT_12.sauvegarderPPM(imageRGB + "IRM_coeur_LUT_12.ppm");


TDM_16_crane_converte_LUT_11.sauvegarderPPM(imageRGB + "TDM_16_crane_converte_LUT_11.ppm");
TDM_16_crane_converte_LUT_12.sauvegarderPPM(imageRGB + "TDM_16_crane_converte_LUT_12.ppm");

IRM_RGB_crane_BEGris_LUT.sauvegarderPPM(imageRGB + "IRM_RGB_8_bits_LUT1.ppm");

IRM_RGB_crane_BEGris_LUT2.sauvegarderPPM(imageRGB + "IRM_RGB_8_bits_LUT2.ppm");

        
break;
}

case 3: {
std::cout << "Namespace 2.0 sélectionné\n";

// Générer images de test (uint8_t, pas besoin d’endianess)
v1_1::Image<uint8_t> imageBlanche(256, 256);
imageBlanche.creerImageBlache();
imageBlanche.ecrireFichierRaw("ImageBlanche.raw");
imageBlanche.sauvegarderPGM(imagePGM + "ImageBlanche.pgm");

v1_1::Image<uint8_t> imageDamier(256, 256);
imageDamier.creerDamier(30);
imageDamier.ecrireFichierRaw("ImageDamier.raw");
imageDamier.sauvegarderPGM(imagePGM + "ImageDamier.pgm");

v1_1::Image<uint8_t> imageSinus(256, 256);
imageSinus.creerSinusoidale(6);
imageSinus.ecrireFichierRaw("ImageSinus.raw");
imageSinus.sauvegarderPGM(imagePGM + "ImageSinus.pgm");

// Lire images RAW correctement

// uint8_t : pas de paramètre endian (inutile)
auto XR_femoral = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512);
auto thorax = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "TDM_8_bits_512x512_thorax.raw", 512, 512);
auto IRM_coeur = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "IRM_8_bits_256x256_coeur.raw", 256, 256);

// uint16_t : gérer endianess explicitement (false=BE, true=LE)
auto TDM_16_bits_BE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, false);
auto TDM_16_bits_LE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, true);

// Conversion 16 bits -> 8 bits : 
// **On choisit une seule conversion** car uint8_t n'a pas d'endianness
auto TDM_16_crane_converte = TDM_16_bits_LE.convertirImage<uint8_t>(false);

// Images RGB 8 bits par composante (pas d’impact endianess normalement, mais méthode attend bool)
auto IRM_RGB_crane = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, false);

// Conversion en niveaux de gris (pas de différence d’endianness pour uint8_t)
auto IRM_RGB_crane_Gris = v1_1::convertRGB_Gris(IRM_RGB_crane, 256, 256);

// Sauvegarder PGM (niveau de gris)
thorax.sauvegarderPGM(imagePGM + "thorax.pgm");
XR_femoral.sauvegarderPGM(imagePGM + "XR_femoral.pgm");
IRM_coeur.sauvegarderPGM(imagePGM + "IRM_coeur.pgm");
TDM_16_crane_converte.sauvegarderPGM(imagePGM + "TDM_16_crane_converte.pgm");  // Une seule version 8 bits

IRM_RGB_crane_Gris.sauvegarderPGM(imagePGM + "IRM_RGB_8_bits_engris.pgm");

// Charger LUTs
auto lut11 = v1_1::ImageRGB::chargerLUT(lutPath + "16_Color_Ramps.lut");
auto lut12 = v1_1::ImageRGB::chargerLUT(lutPath + "16-color.lut");

// Appliquer LUT sur images 8 bits (une seule version 16->8 bits convertie)
v1_1::ImageRGB XR_femoral_LUT_11(XR_femoral, 512, 512, lut11);
v1_1::ImageRGB XR_femoral_LUT_12(XR_femoral, 512, 512, lut12);

v1_1::ImageRGB thorax_LUT_11(thorax, 512, 512, lut11);
v1_1::ImageRGB thorax_LUT_12(thorax, 512, 512, lut12);

v1_1::ImageRGB IRM_coeur_LUT_11(IRM_coeur, 256, 256, lut11);
v1_1::ImageRGB IRM_coeur_LUT_12(IRM_coeur, 256, 256, lut12);


v1_1::ImageRGB TDM_16_crane_converte_LUT_11(TDM_16_crane_converte, 512, 512, lut11);
v1_1::ImageRGB TDM_16_crane_converte_LUT_12(TDM_16_crane_converte, 512, 512, lut12);

v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT(IRM_RGB_crane_Gris, 256, 256, lut11);

v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT2(IRM_RGB_crane_Gris, 256, 256, lut12);

// Sauvegarder en PPM
thorax_LUT_11.sauvegarderPPM(imageRGB + "thorax_LUT_11.ppm");
thorax_LUT_12.sauvegarderPPM(imageRGB + "thorax_LUT_12.ppm");

XR_femoral_LUT_11.sauvegarderPPM(imageRGB + "XR_femoral_LUT_11.ppm");
XR_femoral_LUT_12.sauvegarderPPM(imageRGB + "XR_femoral_LUT_12.ppm");

IRM_coeur_LUT_11.sauvegarderPPM(imageRGB + "IRM_coeur_LUT_11.ppm");
IRM_coeur_LUT_12.sauvegarderPPM(imageRGB + "IRM_coeur_LUT_12.ppm");


TDM_16_crane_converte_LUT_11.sauvegarderPPM(imageRGB + "TDM_16_crane_converte_LUT_11.ppm");
TDM_16_crane_converte_LUT_12.sauvegarderPPM(imageRGB + "TDM_16_crane_converte_LUT_12.ppm");

IRM_RGB_crane_BEGris_LUT.sauvegarderPPM(imageRGB + "IRM_RGB_8_bits_LUT1.ppm");

IRM_RGB_crane_BEGris_LUT2.sauvegarderPPM(imageRGB + "IRM_RGB_8_bits_LUT2.ppm");

//Adiition de deux image 
v1_1::Image<uint8_t> additionResult0 = v2_0::AdditionScalaire<uint8_t>::additionScalaire(XR_femoral, 150);

additionResult0.sauvegarderPGM("ScalarXR_femoral.pgm");


v1_1::Image<uint8_t> additionResult1 = v2_0::Addition<uint8_t>::addition(XR_femoral, TDM_16_crane_converte);
additionResult1.sauvegarderPGM("TDM_16_crane_converte+XR_femoral.pgm");


v1_1::Image<uint8_t> additionResult2 = v2_0::Addition<uint8_t>::addition(imageDamier, imageSinus);
additionResult2.sauvegarderPGM("imageDamier+imageSinus.pgm");

v1_1::Image<uint8_t> additionResult3 = v2_0::Addition<uint8_t>::addition(IRM_coeur, XR_femoral);
additionResult3.sauvegarderPGM("IRM_coeur+XR_femoral.pgm");


// 3. Appliquer égalisation histogramme sur imageDamier
// On crée une copie temporaire pour analyser l'image sans l'altérer
v2_0::egalisationHistogram<uint8_t> histSinusAvant(imageSinus);

histSinusAvant.compterHistogram(imageSinus); // Histogramme AVANT
auto histoSinusAvant = histSinusAvant.getHistogramImage();
histoSinusAvant.sauvegarderPGM(imagePGM + "histoSinusAvant.pgm");

v2_0::egalisationHistogram<uint8_t> histXR_femoralAvant(XR_femoral);

histXR_femoralAvant.compterHistogram(XR_femoral); // Histogramme AVANT
auto histoXR_femoralAvant = histXR_femoralAvant.getHistogramImage();
histoXR_femoralAvant.sauvegarderPGM(imagePGM + "histoXR_femoralAvant.pgm");


// 2. Appliquer l’égalisation d’histogramme

v2_0::egalisationHistogram<uint8_t> histogaramme1(imageSinus);
histogaramme1.Update();  // égalisation exécutée

v2_0::egalisationHistogram<uint8_t> histogaramme2(XR_femoral);
histogaramme2.Update();  // égalisation exécutée


// 3. Sauvegarder les images égalisées

auto imageEgalisée = histogaramme1.getOutput();
imageEgalisée.sauvegarderPGM(imagePGM + "imageSinusEgalisée.pgm");

auto imageEgalisée2 = histogaramme2.getOutput();
imageEgalisée2.sauvegarderPGM(imagePGM + "image_XR_femoralEgalisée.pgm");


// 4. Générer histogramme APRÈS égalisation

// Le calcul d'histogramme est automatiquement refait dans `Process()`
auto histoSinusApres = histogaramme1.getHistogramImage();
histoSinusApres.sauvegarderPGM(imagePGM + "histoSinusApres.pgm");

auto histoXR_femoralAprés = histogaramme2.getHistogramImage();
histoXR_femoralAprés.sauvegarderPGM(imagePGM + "histoXR_femoralAprés.pgm");


//Convolution 

v1_1::Image<uint8_t> IRM_coeurMoyenneur = IRM_coeur;
v1_1::Image<uint8_t> IRM_coeurMoyenneurGaussien = IRM_coeur;
v1_1::Image<uint8_t> IRM_coeurMoyenneurExpo = IRM_coeur;

/*
Pour un petit noyau (ex : 3×3), choisis λ ou σ petits car tu n’as pas beaucoup de voisins.
Pour un noyau plus grand (5×5, 7×7, 11×11…), choisis λ ou σ un peu plus grands pour que l’effet se ressente sur la taille du noyau.
En général :

𝜎≈taille du noyau/6
Pour l'exponentiel, on peut prendre :
𝜆≈3/(taille du noyau/2)

*/
auto moyenneur = v2_0::Convolution<uint8_t>::creerMoyenneur(10);
auto gaussien = v2_0::Convolution<uint8_t>::creerGaussien(3, 1.0f);
auto expo =v2_0:: Convolution<uint8_t>::creerExponentiel(5, 0.8f);


v2_0::Convolution<uint8_t> filtreMoyenneur(IRM_coeurMoyenneur, moyenneur, false);
v2_0::Convolution<uint8_t> filtreGaussien(IRM_coeurMoyenneurGaussien, gaussien, false);
v2_0::Convolution<uint8_t> filtreExpo(IRM_coeurMoyenneurExpo, expo, false);

filtreGaussien.Process();
filtreMoyenneur.Process();
filtreExpo.Process();

auto output = filtreGaussien.getOutput();
auto outputImage = filtreMoyenneur.getOutput();
auto outputImage2 = filtreExpo.getOutput();

output.sauvegarderPGM("image_filtrée_gaussien.pgm");
outputImage.sauvegarderPGM("image_filtrée_moyeneur.pgm");
outputImage2.sauvegarderPGM("image_filtrée_expo.pgm");

v1_1::Image<uint8_t> imageEgalisée2Moyenneur = imageEgalisée2;
v1_1::Image<uint8_t> imageEgalisée2Gaussien = imageEgalisée2;
v1_1::Image<uint8_t> imageEgalisée2Expo = imageEgalisée2;

//Il applique le même poids à tous les pixels du noyau. Il fait une moyenne simple.
auto moyenneur2 = v2_0::Convolution<uint8_t>::creerMoyenneur(5);
//Petit sigma (ex : σ = 0.5) : flou léger, presque pas visible.
//Grand sigma (ex : σ = 2.0 ou plus) : flou plus fort, l’image devient plus floue, les détails disparaissent.
auto gaussien2 = v2_0::Convolution<uint8_t>::creerGaussien(7, 0.5f);
//Petit lambda (ex : λ = 0.2) : noyau large, donc flou plus fort (mais un peu moins doux que gaussien).
//noyau très concentré → flou très léger, presque comme un filtre moyen 3x3.
auto expo2 =v2_0:: Convolution<uint8_t>::creerExponentiel(3, 0.8f);


v2_0::Convolution<uint8_t> filtreMoyenneur2(imageEgalisée2Moyenneur, moyenneur, false);
v2_0::Convolution<uint8_t> filtreGaussien2(imageEgalisée2Gaussien, gaussien, false);
v2_0::Convolution<uint8_t> filtreExpo2(imageEgalisée2Expo, expo, false);

filtreGaussien2.Process();
filtreMoyenneur2.Process();
filtreExpo2.Process();

auto output2 = filtreGaussien2.getOutput();
auto outputImage22 = filtreMoyenneur2.getOutput();
auto outputImage32 = filtreExpo2.getOutput();

output2.sauvegarderPGM("imageEgalisée2Moyenneur.pgm");
outputImage22.sauvegarderPGM("imageEgalisée2Gaussien.pgm");
outputImage32.sauvegarderPGM("imageEgalisée2Expo.pgm");

// Créer l'image et le filtre

//    // Créer un filtre Butterworth
//     auto filtre = v2_0::FiltrageFrequenciel<uint8_t>::creerFiltreButterworth(XR_femoral.getlargeur(), XR_femoral.gethauteur(), 50.0f, 2);

//    v2_0::FiltrageFrequenciel<unsigned char> filtreur(XR_femoral, filtre);
//    filtreur.Update();
   
//    v1_1::Image<unsigned char> resultat = filtreur.getOutput();
//    resultat.sauvegarderPGM("image_filtrée.pgm");


// auto filtreIdealPB =v2_0::FiltrageFrequenciel<uint8_t>::creerFiltreIdeal(512, 512, 50.0f, false); // passe-bas
// auto filtreIdealPH = v2_0::FiltrageFrequenciel<uint8_t>::creerFiltreIdeal(512, 512, 50.0f, true);  // passe-haut

// v2_0::FiltrageFrequenciel<uint8_t> proc(XR_femoral, filtreIdealPH);
// v2_0::FiltrageFrequenciel<uint8_t> proc2(XR_femoral, filtreIdealPB);
// proc.Update();
// proc2.Update();
// v1_1::Image<unsigned char> result = proc.getOutput();
// v1_1::Image<unsigned char> result2 = proc2.getOutput();
// result.sauvegarderPGM("image_filtrée_idéal.pgm");
// result2.sauvegarderPGM("image_filtrée_idéal2.pgm");


// v1_1::Image<uint8_t> contours = v2_0::GradientMagnitude<uint8_t>::detecterContoursSobel(result2);

// contours.sauvegarderPGM("image_contours_sobel.pgm");

break; 
}


case 0:
return 0;
break;

default: 
std::cout << "Choix invalide, veuillez taper 0, 1 ou 2.\n";



}
   
} catch (const std::exception& ex) {
  std::cerr << "Exception attrapée : " << ex.what() << std::endl;
  return 1;
}
return 0;
}