#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include "namespace.hpp"



int main(){
    size_t width = 256;   // Largeur de l'image
    size_t height = 256;  // Hauteur de l'image

    auto Allocimg =   v1_0::allocationImage<uint8_t>(width,height);


    //utilisation d'un seul vecteur 
    auto imgBlanche = v1_0::createWhiteImage<uint8_t>(Allocimg, 255);
    
    std::cout << "Contenu de l'image blanche :\n";
    v1_0::printImage(imgBlanche,width,height);

    std::string filename = "imgBlanche.pgm";
  v1_0::savePGM(imgBlanche, width, height,filename);
  std::cout << "Image blanche enregistrée sous '" << filename << "'.\n";

  //image RGP
  auto imgRGB = v1_0::createRGBImage(width, height, 51, 102, 255);
  std::string rgbFilename = "imgBleue.ppm";
  v1_0::savePPM(imgRGB, width, height, rgbFilename);
  std::cout << "Image RGB bleue enregistrée sous '" << rgbFilename << "'.\n";

    // Création de la mire sinusoïdale
  auto imgSinusoidale = v1_0::allocationImage<uint8_t>(width, height);
  v1_0::createSinusoidalImage(imgSinusoidale, width, height, 0.1, 255);  // fréquence 0.1
  std::string SinusoidaleFilename = "imgSinusoidale.pgm";
  v1_0::savePGM(imgSinusoidale, width, height, SinusoidaleFilename);
  std::cout << "Image Sinusoidale enregistrée sous '" << SinusoidaleFilename << "'.\n";
 // Création du damier
 auto imgDamier = v1_0::allocationImage<uint8_t>(width, height);
 v1_0::createCheckerboardImage(imgDamier, width, height, 16, 0, 255);  // carrés de 16 pixels
 std::string damierFilename = "imgDamier.pgm";
 v1_0::savePGM(imgDamier, width, height, damierFilename);
 std::cout << "Image en damier enregistrée sous '" << damierFilename << "'.\n";


  // Enregistrement RAW
  std::string rawFilename = "imgBlanche.raw";
  v1_0::writeRawImage8(imgBlanche, rawFilename);
  std::cout << "Image blanche enregistrée au format RAW sous '" << rawFilename << "'.\n";

  // Lecture RAW
  auto imageLue = v1_0::readRawImage16(rawFilename, width, height);
  std::cout << "Image RAW relue depuis '" << rawFilename << "'.\n";

  // Vérification (optionnelle) : enregistrer en PGM après lecture RAW
  v1_0::savePGM(imageLue, width, height, "imageLueDepuisRAW.pgm");
  std::cout << "Image RAW relue sauvegardée au format PGM.\n";

// Conversion uint16_t -> uint8_t avec dynamique
std::vector<uint16_t> img16bits(width * height, 60000); // exemple 16 bits
auto img8bits = v1_0::convertImage<uint16_t, uint8_t>(img16bits, 65535, 255);
v1_0::savePGM(img8bits, width, height, "converted8bits.pgm");

// LUT : application de fausses couleurs
auto lut = v1_0::loadLUTBinary("LUT\\LUT\\16_equal.lut");  // ou loadLUTText("LUT.txt");
auto colorized = v1_0::applyLUT(img8bits, lut);
v1_0::savePPM(colorized, width, height, "colorized.ppm");

auto imgGris = v1_0::createWhiteImage<uint8_t>(v1_0::allocationImage<uint8_t>(256, 256), 127); // Image grise

auto lutt = v1_0::loadLUTBinary("Auxctq.lut"); // ou loadLUTText("palette.txt");

auto imgCouleur = v1_0::applyLUT(imgGris, lutt); // Image en fausses couleurs

v1_0::savePPM(imgCouleur, 256, 256, "imgFaussesCouleurs.ppm");

    return 0;
}