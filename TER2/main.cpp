#include <iostream>
#include <vector>
#include <string>
#include "namespace.hpp"
#include <filesystem>//

namespace fs = std::filesystem; 
struct RawImageInfo {
  std::string fichier;
  size_t largeur;
  size_t hauteur;
  int cannaux;    // 1 ou 3
  bool bigEndian;  // true = BE, false = LE
  bool estUint16;   // true = uint16, false = uint8
};

int main(){
    
  try {




    std::string ImageRaw= "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\images_RAW\\images\\" ;
    std::string imagePGM= "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imagePGM\\" ;
    std::string lutPath = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\LUT\\LUT\\";
    std::string imageRGBPath = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imageRGB\\";

  

std::vector<std::string> lutFilenames  = {
 
        "000-gray.lut",
        "001-fire.lut", 
        "002-spectrum.lut", 
        "003-ice.lut", 
        "004-phase.lut",   
        "5_ramps.lut",   
        "6_reserved_colors.lut",  
        "6_shades.lut",   
        "16_colors.lut",  
        "16_equal.lut",  
        "16_ramps.lut", 
        "20_colors.lut",
        "32_colors.lut",  
        "amber.lut",  
        "auxctq.lut", 
        "blue_orange_icb.lut",  
        "blue_orange.lut",   
        "brain.lut",  
        "brgbcmyw.lut",   
        "brown.lut",  
        "cells.lut",  
        "cequal.lut",  
        "cmy-cyan.lut",
        "cmy-magneta.lut",  
        "cmy-yellow.lut", 
        "cmy.lut",  
        "cold.lut",  
        "cool.lut",  
        "cti_ras.lut",  
        "edges.lut", 
        "ether.lut", 
        "fire-ncsa.lut",  
        "gem-16.lut",
        "gem-256.lut",  
        "gold.lut",  
        "GreenFire.lut", 
        "grey.lut",  
        "gyr_centre.lut",  
        "haze.lut", 
        "heart.lut",  
        "HiLo.lut",  
        "HotGreen.lut",  
        "HotRed.lut",  
        "hsatl1.lut",  
        "hsatl2.lut",  
        "hsatv1.lut", 
        "hue_ramps_08.lut", 
        "hue_ramps_16.lut", 
        "hue.lut", 
        "iman.lut",
        "invert_gray.lut",
            };

std::vector<RawImageInfo> images = {
 
  { "IRM_5_labels_8_bits_256x256_crane.raw", 256, 256, 1, false, false},  // Little Endian, uint8
  { "IRM_5_labels_8_bits_256x256_crane.raw", 256, 256, 1, true, false},  // Little Endian, uint8
  
  { "IRM_8_bits_256x256_coeur.raw", 256, 256, 1, false, false},           // Little Endian, uint16
  { "IRM_8_bits_256x256_coeur.raw", 256, 256, 1, true, false},           // Little Endian, uint16
 
  { "IRM_16_bits_256x256_coeur.raw", 256, 256, 1, false, true},
  { "IRM_16_bits_256x256_coeur.raw", 256, 256, 1, true, true},
 
  { "IRM_16_bits_256x256_crane.raw", 256, 256, 1, false, true},
  { "IRM_16_bits_256x256_crane.raw", 256, 256, 1, true, true},
 
  { "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, 3, false, false},
  { "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, 3, true, false},
 
  { "TDM_8_bits_512x512_thorax.raw", 512, 512, 1, false, false},
  { "TDM_8_bits_512x512_thorax.raw", 512, 512, 1, true, false},
  
  
  { "TDM_16_bits_512x512_crane.raw", 512, 512, 1, false, true},
  { "TDM_16_bits_512x512_crane.raw", 512, 512, 1, true, true},
    
  { "XR_8_bits_512x512_femoral.raw", 512, 512, 1, false, false},
  { "XR_8_bits_512x512_femoral.raw", 512, 512, 1, true, false},

  { "Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, 3, false, false},
  { "Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, 3, true, false},

  { "US_8_bits_128x128_coeur.raw", 128, 128, 1, false, false},
  { "US_8_bits_128x128_coeur.raw", 128, 128, 1, true, false},

 
 
};

 
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
    auto imageBlanche = v1_0::ImageBlanche<uint8_t>(256, 256);
    v1_0::sauvegarderPGM(imageBlanche, 256, 256, imagePGM + "imageBlanche.pgm");

    // 2.  sinusoïdale
    auto sinusImage = v1_0::SinusoidalImage<uint16_t>(256, 256, 8.0); 
    // v1_0::sauvegarderPGM16(sinusImage, largeur, hauteur, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    v1_0::ecrireFichierRaw(sinusImage, ImageRaw + "sinus_image.raw");
    // 3. Damier
    auto imageDamier = v1_0::ImageDamier<uint8_t>(256, 256, 32); 
    v1_0::sauvegarderPGM(imageDamier, 256, 256, imagePGM + "imageDamier.pgm");

    //4.image en couleur RGB
    auto rgbImage = v1_0::RGBImage<uint8_t>(256, 256, 255, 128, 64);
    v1_0::sauvegarderPPM(rgbImage, 256, 256, imagePGM + "rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    v1_0::printImage(imageDamier, 4, 3);

    auto sinusImage_BE = v1_0::lireImageRAW<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
    auto sinusImage_LE = v1_0::lireImageRAW<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
     
    auto sinusImage_BE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
    v1_0::sauvegarderPGM(sinusImage_BE_converte, 256, 256, imagePGM + "sinusImage_BE_converte.pgm");

    auto sinusImage_LE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
    v1_0::sauvegarderPGM(sinusImage_LE_converte, 256, 256, imagePGM + "isinusImage_BE_converte.pgm");
 
    //  Charger toutes les LUTs
    std::vector<std::string> Nomluts;
    std::vector<decltype(v1_1::ImageRGB::chargerLUT(""))> luts;
    
    for (const auto& filename : lutFilenames) {
        std::string fullPath = lutPath + filename;
    
        if (!fs::exists(fullPath)) {
            std::cerr << "Erreur : Le fichier LUT n'existe pas : " << fullPath << std::endl;
            continue;  // Passe au suivant si fichier introuvable
        }
    
        auto lut = v1_1::ImageRGB::chargerLUT(fullPath);
    
        // Extraire le nom sans extension ni chemin (ex: "sepia")
        size_t lastSlash = fullPath.find_last_of("\\/");
        size_t lastDot = fullPath.find_last_of('.');
        std::string nomlut = fullPath.substr(lastSlash + 1, lastDot - lastSlash - 1);
    
        Nomluts.push_back(nomlut);
        luts.push_back(lut);
    
        std::cout << "LUT chargée avec succès : " << nomlut << std::endl;
    }

 //  Appliquer chaque LUT sur chaque image
 for (const auto& img : images) {
  std::string imagePath = ImageRaw + img.fichier;
  std::string imageBaseNom = img.fichier.substr(0, img.fichier.find_last_of('.'));

  std::cout << "Traitement de : " << img.fichier << std::endl;

  std::string Dossier = imageRGBPath + imageBaseNom; 
  if (!fs::exists(Dossier)) {
      fs::create_directory(Dossier);
  }

  // ----- Cas 1 : Image RGB (channels == 3)
  if (img.cannaux == 3) {
    // Lire l'image RGB brute
    auto imageRGB = v1_0::lectureImageRawRGB<uint8_t>(imagePath, img.largeur, img.hauteur, img.cannaux, img.bigEndian);

    // Convertir en niveaux de gris
    auto imageGris = v1_0::convertRGB_Gris (imageRGB, img.largeur, img.hauteur);

    // Appliquer toutes les LUTs dessus
    for (size_t j = 0; j < luts.size(); ++j) {
        auto RGBImage = v1_0::applLUT(imageGris, luts[j]);
        std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
        v1_0::sauvegarderPPM(RGBImage, img.largeur, img.hauteur, lien_fichier);
    }
}

  // ----- Cas 2 : Image scalaire (1 canal)
  if (img.estUint16) {
      auto image16 = v1_0::lireImageRAW<uint16_t>(imagePath, img.largeur, img.hauteur, img.bigEndian);
      bool adjustDynamics = true;
      auto image = v1_0::convertImage<uint16_t, uint8_t>(image16, adjustDynamics);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto RGBImage = v1_0::applLUT(image, luts[j]);
          std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
          v1_0::sauvegarderPPM(RGBImage, img.largeur, img.hauteur, lien_fichier);
      }

  } else { // uint8
      auto image = v1_0::lireImageRAW<uint8_t>(imagePath, img.largeur, img.hauteur, img.bigEndian);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto RGBImage = v1_0::applLUT(image, luts[j]);
          std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
          v1_0::sauvegarderPPM(RGBImage, img.largeur, img.hauteur, lien_fichier);
      }
  }
}

std::cout << " Traitement terminé !" << std::endl;

break;
}

case 2 :{
  std::string ImageRaw= "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\images_RAW\\images\\" ;
  std::string imagePGM= "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imagePGM\\" ;
  std::string lutPath = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\LUT\\LUT\\";
  std::string imageRGBPath = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imageRGB\\";
 
// Générer images de test
v1_1::Image<uint8_t> imageBlanche(256, 256);
imageBlanche.creerImageBlanche();
imageBlanche.ecrireFichierRaw("ImageBlanche.raw");
imageBlanche.sauvegarderPGM( imagePGM+"ImageBlanche.pgm");


  v1_1::Image<uint8_t> imageDamier(256, 256);
  imageDamier.creerDamier(10);
  imageDamier.ecrireFichierRaw( ImageRaw+"ImageDamier.raw");
  imageDamier.sauvegarderPGM( imagePGM+"ImageDamier.pgm");

  v1_1::Image<uint8_t> imageSinus(256, 256);
  imageSinus.creerSinusoidale(25);
  imageSinus.ecrireFichierRaw( ImageRaw+"ImageSinus.raw");
  imageSinus.sauvegarderPGM(imagePGM+"ImageSinus.pgm");

   //  Charger toutes les LUTs
   std::vector<std::string> Nomluts;
   std::vector<decltype(v1_1::ImageRGB::chargerLUT(""))> luts;
   
   for (const auto& filename : lutFilenames) {
       std::string fullPath = lutPath + filename;
   
       if (!fs::exists(fullPath)) {
           std::cerr << "Erreur : Le fichier LUT n'existe pas : " << fullPath << std::endl;
           continue;  // Passe au suivant si fichier introuvable
       }
   
       auto lut = v1_1::ImageRGB::chargerLUT(fullPath);
   
       // Extraire le nom sans extension ni chemin (ex: "sepia")
       size_t lastSlash = fullPath.find_last_of("\\/");
       size_t lastDot = fullPath.find_last_of('.');
       std::string nomlut = fullPath.substr(lastSlash + 1, lastDot - lastSlash - 1);
   
       Nomluts.push_back(nomlut);
       luts.push_back(lut);
   
       std::cout << "LUT chargée avec succès : " << nomlut << std::endl;
   }


  for (const auto& img : images) {
    std::string path = ImageRaw + img.fichier;
    std::string nomBase = img.fichier.substr(0, img.fichier.find_last_of('.'));
    std::string dossier = imageRGBPath + nomBase;

    if (!fs::exists(dossier)) fs::create_directory(dossier);

    if (img.cannaux == 3) {
        auto imgRGB = v1_1::lectureImageRawRGB(path, img.largeur, img.hauteur, img.bigEndian);
        auto imgGris = v1_1::convertRGB_Gris(imgRGB, img.largeur, img.hauteur);
        for (size_t i = 0; i < luts.size(); ++i) {
            v1_1::ImageRGB imgLut(imgGris, img.largeur, img.hauteur, luts[i]);
            std::string fichier = nomBase + "_RGB_LUT_" + Nomluts[i] + ".ppm";
            imgLut.sauvegarderPPM(dossier + "/" + fichier);
        }
    } else {
        if (img.estUint16) {
            auto img16 = v1_1::Image<uint16_t>::lireImageRAW(path, img.largeur, img.hauteur, img.bigEndian);
            auto img8 = img16.convertirImage<uint8_t>(true);
            for (size_t i = 0; i < luts.size(); ++i) {
                v1_1::ImageRGB imgLut(img8, img.largeur, img.hauteur, luts[i]);
                std::string fichier = nomBase + "_16bit_LUT_" + Nomluts[i] + ".ppm";
                imgLut.sauvegarderPPM(dossier + "/" + fichier);
            }
        } else {
            auto img8 = v1_1::Image<uint8_t>::lireImageRAW(path, img.largeur, img.hauteur, img.bigEndian);
            for (size_t i = 0; i < luts.size(); ++i) {
                v1_1::ImageRGB imgLut(img8, img.largeur, img.hauteur, luts[i]);
                std::string fichier = nomBase + "_8bit_LUT_" + Nomluts[i] + ".ppm";
                imgLut.sauvegarderPPM(dossier + "/" + fichier);
            }
        }
    }
}

  std::cout << "Sauvegarde terminée avec succès.\n";
  break;
}

case 3: {
std::cout << "Namespace 2.0 sélectionné\n";
break; 
}


case 0:
return 0;
break;

default: 
std::cout << "Choix invalide, veuillez taper 0, 1 ou 2.\n";



}

   } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
        return 1;
    }
}