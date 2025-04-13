#include <vector>
#include <iostream>
#include <cstdint>
#include "namespace.hpp"


int main(){
    
    using namespace v1_0;
    const size_t width = 256;
    const size_t height = 256;

    //la Reponse a la première question 

    // 1. Création image blanche
    auto whiteImage = createWhiteImage<uint8_t>(width, height);
    savePGM(whiteImage, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\whiteImage.pgm");

    // 2.  sinusoïdale
    auto sinusImage = createSinusoidalImage<uint16_t>(width, height, 8.0); 
    savePGM16(sinusImage, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    writeRawImage(sinusImage, "sinus_image.raw");
    // 3. Damier
    auto checkerboardImage = createCheckerboardImage<uint8_t>(width, height, 32); 
    savePGM(checkerboardImage, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\checkerboardImage.pgm");

    //4.image en couleur RGB
    auto rgbImage = createRGBImage<uint8_t>(width, height, 255, 128, 64);
    savePPM(rgbImage, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    printImage(checkerboardImage, 4, 3);



    //La réponse à la deuxième question :
    
       // 5. Lecture de fichiers RAW (8 bits)
       auto imageLE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw", 256, 256, false); // Little Endian
      // savePGM(imageLE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\XR_8_bits_512x512_coeur.pgm");
   
       auto imageBE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw", 256, 256, true); // Big Endian
      // savePGM(imageBE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\XR_8_bits_512x512_coeur_BE.pgm");
      
      auto image_craneLE = readRawImageWithChannels<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256, 3 ,false); // Big Endian
      auto image_craneBE = readRawImageWithChannels<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256, 3 ,true); // Big Endian
    
          savePPM(image_craneLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_RGB_8_bits_256x256_crane_BE.pgm");
       savePPM(image_craneBE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_RGB_8_bits_256x256_crane_Bl.pgm");
      
     
     auto converted = convertImage<uint16_t, uint8_t>(sinusImage, true);
       savePGM(converted, width, height, "converted_sinus_image.pgm");
       auto converted2 = convertImage<uint16_t, uint8_t>(imageLE, true);
       savePGM(converted2, width, height, "IRM_16_bits_256x256_coeurLE.pgm");
       auto converted3 = convertImage<uint16_t, uint8_t>(imageBE, true);
       savePGM(converted3, width, height, "IRM_16_bits_256x256_coeurBE.pgm");

       
       auto lut = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\005-random.lut");
       auto coloredimageLE = applyLUT(converted2, lut);
       auto coloredimageBE = applyLUT(converted3, lut);
       auto coloredsinus = applyLUT(converted, lut);

       savePPM(coloredimageLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_LE.ppm");
       savePPM(coloredimageBE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_BE.ppm");
       savePPM(coloredsinus, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coloredsinus.ppm");

    return 0;

}