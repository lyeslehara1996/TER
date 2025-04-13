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


    // 1. Lecture de fichiers RAW (8 bits)
    //Lecture de fichiers RAW (8 bits) avec 1 canal (Niveau de gris) 

    auto imageIRM_5__craneBE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw", 256, 256, false); // Little Endian
    auto imageIRM_5__craneLE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw", 256, 256, true); // Little Endian
   
    auto imageIRM__coeurBE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw", 256, 256, false); // Little Endian
    auto imageIRM__coeurLE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw", 256, 256, true); // Little Endian
   
    auto imageShepp_Logan_phantom_1_BE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, false); // Little Endian
    auto imageShepp_Logan_phantom_1_LE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, true); // Big Endian
   
    auto imageShepp_Logan_sinogram_2_BE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw", 256, 263, false); // Big Endian
    auto imageShepp_Logan_sinogram_2_LE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw", 256, 263, true); // Big Endian
   
    auto imageTDM__thorax_BE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_8_bits_512x512_thorax.raw", 512, 512, false); // Big Endian
    auto imageTDM__thorax_LE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_8_bits_512x512_thorax.raw", 512, 512, true); // Big Endian
    
    auto imageUS__coeur_BE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\US_8_bits_128x128_coeur.raw", 128, 128, false); // Big Endian
    auto imageUS__coeur_LE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\US_8_bits_128x128_coeur.raw", 128, 128, true); // Big Endian
    
    auto imageXR__femoral_BE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\XR_8_bits_512x512_femoral.raw", 512, 512, false); // Big Endian
    auto imageXR__femoral_LE = readRawImage<uint8_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\XR_8_bits_512x512_femoral.raw", 512, 512, true); // Big Endian
    
    // 1.2. Lecture de fichiers RAW (8 bits) avec 3 canaux (RGB)
    auto image_craneBE = readRawImageWithChannels<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256, 3 ,false); // Big Endian
    auto image_craneLE = readRawImageWithChannels<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256, 3 ,true); // Big Endian
  


    // 2. Sauvegarde des fichiers RAW 8 bits en images PGM en niveaux de gris
    savePGM(imageIRM_5__craneLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_5_labels_8_bits_256x256_crane_BE.pgm");
    savePGM(imageIRM_5__craneBE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_5_labels_8_bits_256x256_crane_LE.pgm");
   
    savePGM(imageIRM__coeurLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_8_bits_256x256_coeur_BE.pgm");
    savePGM(imageIRM__coeurBE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_8_bits_256x256_coeur_LE.pgm");
   
    savePGM(imageShepp_Logan_phantom_1_LE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_phantom_8_bits_256x256_BE.pgm");
    savePGM(imageShepp_Logan_phantom_1_BE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_phantom_8_bits_256x256_LE.pgm");
   
    savePGM(imageShepp_Logan_sinogram_2_BE, 256, 263, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_8_bits_256x363_BE.pgm");
    savePGM(imageShepp_Logan_sinogram_2_LE, 256, 263, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_8_bits_256x363_LE.pgm");
   
    savePGM(imageTDM__thorax_BE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\TDM_8_bits_512x512_thorax_BE.pgm");
    savePGM(imageTDM__thorax_BE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\TDM_8_bits_512x512_thorax_LE.pgm");
   
    savePGM(imageUS__coeur_BE, 128, 128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\US_8_bits_128x128_coeur_BE.pgm");
    savePGM(imageUS__coeur_LE, 128, 128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\US_8_bits_128x128_coeur_LE.pgm");
    
    savePGM(imageXR__femoral_BE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\XR_8_bits_512x512_femoral_BE.pgm");
    savePGM(imageXR__femoral_LE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\XR_8_bits_512x512_femoral_LE.pgm");
    
    // 2.2 Sauvegarde des fichiers raw 8 bit en  images PPM en rgb
    savePPM(image_craneBE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_RGB_8_bits_256x256_crane_BE.pgm");
    savePPM(image_craneLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_RGB_8_bits_256x256_crane_LE.pgm");
    

    // 3. Lecture de fichiers RAW (16 bits)
      auto imageIRM__coeur_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw", 256, 256, false); // Little Endian
      auto imageIRM__coeur_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_coeur.raw", 256, 256, true); // Big Endian
      
      auto imageIRM__crane_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw", 256, 256, false); // Little Endian
      auto imageIRM__crane_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw", 256, 256, true); // Big Endian
    
      auto imageShepp_Logan_sinogram_3_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw", 64, 128, false); // Big Endian
     auto imageShepp_Logan_sinogram_3_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw", 64, 128, true); // Big Endian
     
     auto imageShepp_Logan_sinogram_4_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw", 256, 363, false); // Big Endian
     auto imageShepp_Logan_sinogram_4_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw", 256, 363, true); // Big Endian
     
     auto imageShepp_Logan_sinogram_5_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw", 256, 512, false); // Big Endian
     auto imageShepp_Logan_sinogram_5_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw", 256, 512, true); // Big Endian
     
     auto imageTDM__crane_BE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_16_bits_512x512_crane.raw", 512, 512, false); // Big Endian
     auto imageTDM__crane_LE = readRawImage<uint16_t>("C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_16_bits_512x512_crane.raw", 512, 512, true); // Big Endian
    \
     // Conversion de l'image 16 bits en 8 bits
     auto converted = convertImage<uint16_t, uint8_t>(sinusImage, true);
     savePGM(converted, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGMconverted_sinus_image.pgm");

       auto imageIRM__coeur_BE_converted = convertImage<uint16_t, uint8_t>(imageIRM__coeur_BE, true);
       auto imageIRM__coeur_LE_converted = convertImage<uint16_t, uint8_t>(imageIRM__coeur_LE, true);
       savePGM(imageIRM__coeur_BE_converted, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageIRM__coeur_BE.pgm");
       savePGM(imageIRM__coeur_LE_converted, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageIRM__coeur_LE.pgm");
     
       auto imageIRM__crane_BE_converted = convertImage<uint16_t, uint8_t>(imageIRM__crane_BE, true);
       auto imageIRM__crane_LE_converted = convertImage<uint16_t, uint8_t>(imageIRM__crane_LE, true);
       savePGM(imageIRM__crane_BE_converted, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageIRM__crane_BE.pgm");
       savePGM(imageIRM__crane_LE_converted, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageIRM__crane_LE.pgm");
     
       auto imageShepp_Logan_sinogram_3_BE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_3_BE, true);
       auto imageShepp_Logan_sinogram_3_LE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_3_LE, true);
       savePGM(imageShepp_Logan_sinogram_3_BE_converted, 64, 128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_3_BE.pgm");
       savePGM(imageShepp_Logan_sinogram_3_LE_converted, 64, 128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_3_LE.pgm");
     
       auto imageShepp_Logan_sinogram_4_BE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_4_BE, true);
       auto imageShepp_Logan_sinogram_4_LE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_4_LE, true);
       savePGM(imageShepp_Logan_sinogram_4_BE_converted, 256, 363, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_4_BE.pgm");
       savePGM(imageShepp_Logan_sinogram_4_LE_converted, 256, 363, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_4_LE.pgm");
     
       auto imageShepp_Logan_sinogram_5_BE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_5_BE, true);
       auto imageShepp_Logan_sinogram_5_LE_converted = convertImage<uint16_t, uint8_t>(imageShepp_Logan_sinogram_5_LE, true);
       savePGM(imageShepp_Logan_sinogram_5_BE_converted, 256, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_5_BE.pgm");
       savePGM(imageShepp_Logan_sinogram_5_LE_converted, 256, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageShepp_Logan_sinogram_5_LE.pgm");
     
       auto imageTDM__crane_BE_converted = convertImage<uint16_t, uint8_t>(imageTDM__crane_BE, true);
       auto imageTDM__crane_LE_converted = convertImage<uint16_t, uint8_t>(imageTDM__crane_LE, true);
       savePGM(imageTDM__crane_BE_converted, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageTDM__crane_BE.pgm");
       savePGM(imageTDM__crane_LE_converted, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imagesPGM\\imageTDM__crane_LE.pgm");

       //changement de la dynamique de lUT

        auto lut1 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\000-gray.lut");
        auto lut2 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\001-fire.lut");
        auto lut3 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\002-spectrum.lut");
        auto lut4 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\003-ice.lut");
        auto lut5 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\004-phase.lut");
        auto lut6 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\5_ramps.lut");
        auto lut7 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\6_reserved_colors.lut");
        auto lut8 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\6_shades.lut");
        auto lut9 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\16_colors.lut");
        auto lut11 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\16_equal.lut");
        auto lut12 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\16_ramps.lut");
        auto lut13 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\20_colors.lut");
        auto lut14 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\32_colors.lut");
        auto lut15 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\amber.lut");
        auto lut16 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\auxctq.lut");
        auto lut17 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\blue_orange_icb.lut");
        auto lut18 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\blue_orange.lut");
        auto lut19 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brain.lut");
        auto lut21 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brgbcmyw.lut");
        auto lut22 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brown.lut");
        auto lut23 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cells.lut");
        auto lut24 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cequal.lut");
        auto lut25 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cmy-cyan.lut");
        auto lut26 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cmy-magneta.lut");
        auto lut27 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cmy-yellow.lut");
        auto lut28 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cmy.lut");
        auto lut29 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cold.lut");
        auto lut31 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cool.lut");
        auto lut32 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\cti_ras.lut");
        auto lut33 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\edges.lut");
        auto lut34 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\ether.lut");
        auto lut35 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\fire-ncsa.lut");
        auto lut36 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\gem-16.lut");
        auto lut37 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\gem-256.lut");
        auto lut38 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\gold.lut");
        auto lut39 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\GreenFire.lut");
        auto lut41 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\grey.lut");
        auto lut42 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\gyr_centre.lut");
        auto lut43 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\haze.lut");
        auto lut44 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\heart.lut");
        auto lut45 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\HiLo.lut");
        auto lut46 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\HotGreen.lut");
        auto lut47 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\HotRed.lut");
        auto lut48 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hsatl1.lut");
        auto lut49 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hsatl2.lut");
        auto lut51 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hsatv1.lut");
        auto lut52 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hue_ramps_08.lut");
        auto lut53 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hue_ramps_16.lut");
        auto lut54 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\hue.lut");
        auto lut55 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\iman.lut");
        auto lut56 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\invert_gray.lut");
        auto lut57 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\isocontour.lut");
        auto lut58 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\log_down.lut");
        auto lut59 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\log_up.lut");
        auto lut61 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\mixed.lut");
        auto lut62 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\neon-blue.lut");
        auto lut63 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\neon-green.lut");
        auto lut64 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\neon-magenta.lut");
        auto lut65 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\neon-red.lut");
        auto lut66 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\nih-image-fire1.lut");
        auto lut67 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\nih-image-fire2.lut");
        auto lut68 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\pastel.lut");
        auto lut69 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\RangeIndicator.lut");
        auto lut71 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\red-blue.lut");
        auto lut72 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\rgb-green.lut");
        auto lut73 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\rgb-red.lut");
        auto lut74 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\royal.lut");
        auto lut75 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\sepia.lut");
        auto lut76 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\siemens.lut");
        auto lut77 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\smart.lut");
        auto lut78 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\split_blackblue_redwhite.lut");
        auto lut79 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\split_blackwhite_ge.lut");
        auto lut81 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\split_blackwhite_warmmetal.lut");
        auto lut82= loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\split_bluered_warmmetal.lut");
        auto lut83 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\system_lut.lut");
        auto lut84 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\thal_16.lut");
        auto lut85 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\thal_256.lut");
        auto lut86 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\thallium.lut");
        auto lut87 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\topography.lut");
        auto lut88 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\unionjack.lut");
        auto lut89 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\vivid.lut");
        auto lut90 = loadLUTBinary("C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\warhol.lut");
        // auto lut = loadLUTBinary("");
      
      //  // 4. Application de la LUT sur les images
        auto imageXR__femoral_BE_colored_1 = applyLUT(imageXR__femoral_BE, lut1);
        auto imageXR__femoral_BE_colored_2 = applyLUT(imageXR__femoral_BE, lut2);
        auto imageXR__femoral_BE_colored_3 = applyLUT(imageXR__femoral_BE, lut3);
        auto imageXR__femoral_BE_colored_4 = applyLUT(imageXR__femoral_BE, lut4);
        auto imageXR__femoral_BE_colored_5 = applyLUT(imageXR__femoral_BE, lut5);
        auto imageXR__femoral_BE_colored_6 = applyLUT(imageXR__femoral_BE, lut6);
        auto imageXR__femoral_BE_colored_7 = applyLUT(imageXR__femoral_BE, lut7);
        auto imageXR__femoral_BE_colored_8 = applyLUT(imageXR__femoral_BE, lut8);
        auto imageXR__femoral_BE_colored_9 = applyLUT(imageXR__femoral_BE, lut9);
        auto imageXR__femoral_BE_colored_10 = applyLUT(imageXR__femoral_BE, lut11);
        auto imageXR__femoral_BE_colored_11 = applyLUT(imageXR__femoral_BE, lut12);
        auto imageXR__femoral_BE_colored_12 = applyLUT(imageXR__femoral_BE, lut13);
        auto imageXR__femoral_BE_colored_13 = applyLUT(imageXR__femoral_BE, lut14);
        auto imageXR__femoral_BE_colored_14 = applyLUT(imageXR__femoral_BE, lut15);
        auto imageXR__femoral_BE_colored_15 = applyLUT(imageXR__femoral_BE, lut16);
        auto imageXR__femoral_BE_colored_16 = applyLUT(imageXR__femoral_BE, lut17);
        auto imageXR__femoral_BE_colored_17 = applyLUT(imageXR__femoral_BE, lut18);
        auto imageXR__femoral_BE_colored_18 = applyLUT(imageXR__femoral_BE, lut19);
        auto imageXR__femoral_BE_colored_19 = applyLUT(imageXR__femoral_BE, lut21);
        auto imageXR__femoral_BE_colored_20 = applyLUT(imageXR__femoral_BE, lut22);
        auto imageXR__femoral_BE_colored_21 = applyLUT(imageXR__femoral_BE, lut23);
        auto imageXR__femoral_BE_colored_22 = applyLUT(imageXR__femoral_BE, lut24);
        auto imageXR__femoral_BE_colored_23 = applyLUT(imageXR__femoral_BE, lut25);
        auto imageXR__femoral_BE_colored_24 = applyLUT(imageXR__femoral_BE, lut26);
        auto imageXR__femoral_BE_colored_25 = applyLUT(imageXR__femoral_BE, lut27);
        auto imageXR__femoral_BE_colored_26 = applyLUT(imageXR__femoral_BE, lut28);
        auto imageXR__femoral_BE_colored_27 = applyLUT(imageXR__femoral_BE, lut29);
        auto imageXR__femoral_BE_colored_28 = applyLUT(imageXR__femoral_BE, lut31);
        auto imageXR__femoral_BE_colored_29 = applyLUT(imageXR__femoral_BE, lut32);
        auto imageXR__femoral_BE_colored_30 = applyLUT(imageXR__femoral_BE, lut33);
        auto imageXR__femoral_BE_colored_31 = applyLUT(imageXR__femoral_BE, lut34);
        auto imageXR__femoral_BE_colored_32 = applyLUT(imageXR__femoral_BE, lut35);
        auto imageXR__femoral_BE_colored_33 = applyLUT(imageXR__femoral_BE, lut36);
        auto imageXR__femoral_BE_colored_34 = applyLUT(imageXR__femoral_BE, lut37);
        auto imageXR__femoral_BE_colored_35 = applyLUT(imageXR__femoral_BE, lut38);
        auto imageXR__femoral_BE_colored_36 = applyLUT(imageXR__femoral_BE, lut39);
        auto imageXR__femoral_BE_colored_37 = applyLUT(imageXR__femoral_BE, lut41);
        auto imageXR__femoral_BE_colored_38 = applyLUT(imageXR__femoral_BE, lut42);
        auto imageXR__femoral_BE_colored_39 = applyLUT(imageXR__femoral_BE, lut43);
        auto imageXR__femoral_BE_colored_40 = applyLUT(imageXR__femoral_BE, lut44);
        auto imageXR__femoral_BE_colored_41 = applyLUT(imageXR__femoral_BE, lut45);
        auto imageXR__femoral_BE_colored_42 = applyLUT(imageXR__femoral_BE, lut46);
        auto imageXR__femoral_BE_colored_43 = applyLUT(imageXR__femoral_BE, lut47);
        auto imageXR__femoral_BE_colored_44 = applyLUT(imageXR__femoral_BE, lut48);
        auto imageXR__femoral_BE_colored_45 = applyLUT(imageXR__femoral_BE, lut49);
        auto imageXR__femoral_BE_colored_46 = applyLUT(imageXR__femoral_BE, lut51);
        auto imageXR__femoral_BE_colored_47 = applyLUT(imageXR__femoral_BE, lut52);
        auto imageXR__femoral_BE_colored_48 = applyLUT(imageXR__femoral_BE, lut53);
        auto imageXR__femoral_BE_colored_49 = applyLUT(imageXR__femoral_BE, lut54);
        auto imageXR__femoral_BE_colored_50 = applyLUT(imageXR__femoral_BE, lut55);
        auto imageXR__femoral_BE_colored_51 = applyLUT(imageXR__femoral_BE, lut56);
        auto imageXR__femoral_BE_colored_52 = applyLUT(imageXR__femoral_BE, lut57);
        auto imageXR__femoral_BE_colored_53 = applyLUT(imageXR__femoral_BE, lut58);
        auto imageXR__femoral_BE_colored_54 = applyLUT(imageXR__femoral_BE, lut59);
        auto imageXR__femoral_BE_colored_55 = applyLUT(imageXR__femoral_BE, lut61);
        auto imageXR__femoral_BE_colored_56 = applyLUT(imageXR__femoral_BE, lut62);
        auto imageXR__femoral_BE_colored_57 = applyLUT(imageXR__femoral_BE, lut63);
        auto imageXR__femoral_BE_colored_58 = applyLUT(imageXR__femoral_BE, lut64);
        auto imageXR__femoral_BE_colored_59 = applyLUT(imageXR__femoral_BE, lut65);
        auto imageXR__femoral_BE_colored_60 = applyLUT(imageXR__femoral_BE, lut66);
        auto imageXR__femoral_BE_colored_61 = applyLUT(imageXR__femoral_BE, lut67);
        auto imageXR__femoral_BE_colored_62 = applyLUT(imageXR__femoral_BE, lut68);
        auto imageXR__femoral_BE_colored_63 = applyLUT(imageXR__femoral_BE, lut69);
        auto imageXR__femoral_BE_colored_64 = applyLUT(imageXR__femoral_BE, lut71);
        auto imageXR__femoral_BE_colored_65 = applyLUT(imageXR__femoral_BE, lut72);
        auto imageXR__femoral_BE_colored_66 = applyLUT(imageXR__femoral_BE, lut73);
        auto imageXR__femoral_BE_colored_67 = applyLUT(imageXR__femoral_BE, lut74);
        auto imageXR__femoral_BE_colored_68 = applyLUT(imageXR__femoral_BE, lut75);
        auto imageXR__femoral_BE_colored_69 = applyLUT(imageXR__femoral_BE, lut76);
        auto imageXR__femoral_BE_colored_70 = applyLUT(imageXR__femoral_BE, lut77);
        auto imageXR__femoral_BE_colored_71 = applyLUT(imageXR__femoral_BE, lut78);
        auto imageXR__femoral_BE_colored_72 = applyLUT(imageXR__femoral_BE, lut79);
        auto imageXR__femoral_BE_colored_73 = applyLUT(imageXR__femoral_BE, lut81);
        auto imageXR__femoral_BE_colored_74 = applyLUT(imageXR__femoral_BE, lut82);
        auto imageXR__femoral_BE_colored_75 = applyLUT(imageXR__femoral_BE, lut83);
        auto imageXR__femoral_BE_colored_76 = applyLUT(imageXR__femoral_BE, lut84);
        auto imageXR__femoral_BE_colored_77 = applyLUT(imageXR__femoral_BE, lut85);
        auto imageXR__femoral_BE_colored_78 = applyLUT(imageXR__femoral_BE, lut86);
        auto imageXR__femoral_BE_colored_79 = applyLUT(imageXR__femoral_BE, lut87);
        auto imageXR__femoral_BE_colored_80 = applyLUT(imageXR__femoral_BE, lut88);
        auto imageXR__femoral_BE_colored_81 = applyLUT(imageXR__femoral_BE, lut89);
        auto imageXR__femoral_BE_colored_82 = applyLUT(imageXR__femoral_BE, lut90);

      //  // 5. Sauvegarde des images en couleur
      //  savePPM(imageXR__femoral_BE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\coeur_LE.ppm");
        savePPM(imageXR__femoral_BE_colored_1, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_1.ppm");
        savePPM(imageXR__femoral_BE_colored_2, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_2.ppm");
        savePPM(imageXR__femoral_BE_colored_3, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_3.ppm");
        savePPM(imageXR__femoral_BE_colored_4, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_4.ppm");
        savePPM(imageXR__femoral_BE_colored_5, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_5.ppm");
        savePPM(imageXR__femoral_BE_colored_6, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_6.ppm");
        savePPM(imageXR__femoral_BE_colored_7, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_7.ppm");
        savePPM(imageXR__femoral_BE_colored_8, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_8.ppm");
        savePPM(imageXR__femoral_BE_colored_9, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_9.ppm");
        savePPM(imageXR__femoral_BE_colored_10, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_10.ppm");
        savePPM(imageXR__femoral_BE_colored_11, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_11.ppm"); 
        savePPM(imageXR__femoral_BE_colored_12, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_12.ppm");
        savePPM(imageXR__femoral_BE_colored_13, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_13.ppm");
        savePPM(imageXR__femoral_BE_colored_14, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_14.ppm");
        savePPM(imageXR__femoral_BE_colored_15, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_15.ppm");
        savePPM(imageXR__femoral_BE_colored_16, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_16.ppm");
        savePPM(imageXR__femoral_BE_colored_17, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_17.ppm");
        savePPM(imageXR__femoral_BE_colored_18, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_18.ppm");
        savePPM(imageXR__femoral_BE_colored_19, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_19.ppm");
        savePPM(imageXR__femoral_BE_colored_20, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_20.ppm");
        savePPM(imageXR__femoral_BE_colored_21, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_21.ppm");
        savePPM(imageXR__femoral_BE_colored_22, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_22.ppm");
        savePPM(imageXR__femoral_BE_colored_23, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_23.ppm");
        savePPM(imageXR__femoral_BE_colored_24, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_24.ppm");
        savePPM(imageXR__femoral_BE_colored_25, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_25.ppm");
        savePPM(imageXR__femoral_BE_colored_26, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_26.ppm");
        savePPM(imageXR__femoral_BE_colored_27, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_27.ppm");
        savePPM(imageXR__femoral_BE_colored_28, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_28.ppm");
        savePPM(imageXR__femoral_BE_colored_29, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_29.ppm");
        savePPM(imageXR__femoral_BE_colored_30, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_30.ppm");
        savePPM(imageXR__femoral_BE_colored_31, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_31.ppm");
        savePPM(imageXR__femoral_BE_colored_32, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_32.ppm");
        savePPM(imageXR__femoral_BE_colored_33, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_33.ppm");
        savePPM(imageXR__femoral_BE_colored_34, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_34.ppm");
        savePPM(imageXR__femoral_BE_colored_35, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_35.ppm");
        savePPM(imageXR__femoral_BE_colored_36, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_36.ppm");
        savePPM(imageXR__femoral_BE_colored_37, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_37.ppm");
        savePPM(imageXR__femoral_BE_colored_38, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_38.ppm");
        savePPM(imageXR__femoral_BE_colored_39, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_39.ppm");
        savePPM(imageXR__femoral_BE_colored_40, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_40.ppm");
        savePPM(imageXR__femoral_BE_colored_41, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_41.ppm");
        savePPM(imageXR__femoral_BE_colored_42, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_42.ppm");
        savePPM(imageXR__femoral_BE_colored_43, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_43.ppm");
        savePPM(imageXR__femoral_BE_colored_44, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_44.ppm");
        savePPM(imageXR__femoral_BE_colored_45, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_45.ppm");
        savePPM(imageXR__femoral_BE_colored_46, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_46.ppm");
        savePPM(imageXR__femoral_BE_colored_47, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_47.ppm");
        savePPM(imageXR__femoral_BE_colored_48, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_48.ppm");
        savePPM(imageXR__femoral_BE_colored_49, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_49.ppm");
        savePPM(imageXR__femoral_BE_colored_50, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_50.ppm");
        savePPM(imageXR__femoral_BE_colored_51, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_51.ppm");
        savePPM(imageXR__femoral_BE_colored_52, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_52.ppm");
        savePPM(imageXR__femoral_BE_colored_53, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_53.ppm");
        savePPM(imageXR__femoral_BE_colored_54, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_54.ppm");
        savePPM(imageXR__femoral_BE_colored_55, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_55.ppm");
        savePPM(imageXR__femoral_BE_colored_56, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_56.ppm");
        savePPM(imageXR__femoral_BE_colored_57, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_57.ppm");
        savePPM(imageXR__femoral_BE_colored_58, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_58.ppm");
        savePPM(imageXR__femoral_BE_colored_59, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_59.ppm");
        savePPM(imageXR__femoral_BE_colored_60, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_60.ppm");
        savePPM(imageXR__femoral_BE_colored_61, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_61.ppm");
        savePPM(imageXR__femoral_BE_colored_62, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_62.ppm");
        savePPM(imageXR__femoral_BE_colored_63, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_63.ppm");
        savePPM(imageXR__femoral_BE_colored_64, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_64.ppm");
        savePPM(imageXR__femoral_BE_colored_65, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_65.ppm");
        savePPM(imageXR__femoral_BE_colored_66, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_66.ppm");
        savePPM(imageXR__femoral_BE_colored_67, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_67.ppm");
        savePPM(imageXR__femoral_BE_colored_68, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_68.ppm");
        savePPM(imageXR__femoral_BE_colored_69, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_69.ppm");
        savePPM(imageXR__femoral_BE_colored_70, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_70.ppm");
        savePPM(imageXR__femoral_BE_colored_71, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_71.ppm");
        savePPM(imageXR__femoral_BE_colored_72, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_72.ppm");
        savePPM(imageXR__femoral_BE_colored_73, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_73.ppm");
        savePPM(imageXR__femoral_BE_colored_74, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_74.ppm");
        savePPM(imageXR__femoral_BE_colored_75, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_75.ppm");
        savePPM(imageXR__femoral_BE_colored_76, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_76.ppm");
        savePPM(imageXR__femoral_BE_colored_77, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_77.ppm");
        savePPM(imageXR__femoral_BE_colored_78, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_78.ppm");
        savePPM(imageXR__femoral_BE_colored_79, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_79.ppm");
        savePPM(imageXR__femoral_BE_colored_80, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_80.ppm");
        savePPM(imageXR__femoral_BE_colored_81, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_81.ppm");
        savePPM(imageXR__femoral_BE_colored_82, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageXR__femoral_BE_colored_82.ppm");
          
    return 0;

}