#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <type_traits>
#include "Namespace.hpp"

int main() {

    using namespace v1_0;

    const size_t width = 256;
    const size_t height = 256;


    // 1. Allocation d'une image
    std::vector<uint8_t> image = allocationImage<uint8_t>(width, height);
    std::cout << "Image allouée (" << width << "x" << height << ")\n";

    // 2. Création image blanche
    auto whiteImage = createWhiteImage(image, uint8_t(255));
    writePGMImage8(whiteImage, "white.raw",255,255);

    // 3. Mire sinusoïdale
    auto sinusImage16 = createSinusoidalImage<uint16_t>(width, height, 0.1, 65535);
    writeRawImage(sinusImage16, "sinus16.raw", false);

    // 4. Damier
    auto checkerboard = createCheckerboardImage<uint8_t>(width, height, 32, 0, 255);
    writePGMImage8(checkerboard, "checker.raw",255,255);
    


      // 1. Lecture d’image 16 bits avec endianness
      auto Ellipse_3LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_3_labels_8_bits_256x256.raw)", width, height); // little endian
  //    auto Ellipse_3E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_3_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto Ellipse_4LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_4_labels_8_bits_256x256.raw)", width, height); // little endian
   //   auto Ellipse_4E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_4_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 3 Lecture d’image 16 bits avec endianness
      auto Ellipse_5LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_5_labels_8_bits_256x256.raw)", width, height); // little endian
     // auto Ellipse_5E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_5_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 4. Lecture d’image 16 bits avec endianness
      auto IRM_5LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw)", width, height); // little endian
      //auto IRM_5E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 5. Lecture d’image 16 bits avec endianness
      auto IRM_8LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw)", width, height); // little endian
     // auto IRM_8E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 6. Lecture d’image 16 bits avec endianness
      //auto IRM_16_canneLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw)", width, height, false); // little endian
      auto IRM_16_canneE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      

      // 7. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256); // little endian
      //auto imageCoeurE = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      
      // 8. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_phantom_8LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height); // little endian
      //auto Shepp_Logan_phantom_8E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 9. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_sinogram_8_2LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", 256, 363); // little endian
      //auto Shepp_Logan_sinogram_8_2E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 10. Lecture d’image 16 bits avec endianness
      //auto Shepp_Logan_sinogram_16_3LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_3E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw)", 64, 128, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 11. Lecture d’image 16 bits avec endianness
      //auto Shepp_Logan_sinogram_16_4LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_4E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw)", 256, 363, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 12. Lecture d’image 16 bits avec endianness
      //auto Shepp_Logan_sinogram_16_5LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_5E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw)", 256, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      
      // 12. Lecture d’image 16 bits avec endianness
      auto thoraxLE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_8_bits_512x512_thorax.raw)", 512, 512); // little endian
      //auto thoraxE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_8_bits_512x512_thorax.raw)", 512, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 12. Lecture d’image 16 bits avec endianness
      //auto craneLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_16_bits_512x512_crane.raw)", width, height, false); // little endian
      auto craneE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\TDM_16_bits_512x512_crane.raw)", 512, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 12. Lecture d’image 16 bits avec endianness
      auto coeur_LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\US_8_bits_128x128_coeur.raw)", 128, 128); // little endian
     // auto coeur_E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\US_8_bits_128x128_coeur.raw)", 256, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 12. Lecture d’image 16 bits avec endianness
      auto femoral_LE = readRawImage8bit<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\XR_8_bits_512x512_femoral.raw)", 512, 512); // little endian
     // auto femoral_E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\XR_8_bits_512x512_femoral.raw)", 256, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      auto _crane_LE = readRawImage8bit<uint8_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_RGB_8_bits_256x256_crane.raw)", 256, 256); // little endian
     // auto femoral_E = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_RGB_8_bits_256x256_crane.raw.raw)", 256, 512, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
//Conversion vers 8 bits

  
      auto IRM_16_canneLE_8 = convertImage<uint16_t, uint8_t>(IRM_16_canneE, 65535, 255);
      writePGMImage8(IRM_16_canneLE_8, "IRM_16_canneLE.raw",255,255);
  

  
      auto Shepp_Logan_sinogram_16_3LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_3E, 65535, 255);
      writePGMImage8(Shepp_Logan_sinogram_16_3LE_8, "Shepp_Logan_sinogram_16_3LE.raw",64,128);
  
      auto Shepp_Logan_sinogram_16_4LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_4E, 65535, 255);
      writePGMImage8(Shepp_Logan_sinogram_16_4LE_8, "Shepp_Logan_sinogram_16_4LE.raw",256,363);
  
      auto Shepp_Logan_sinogram_16_5LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_5E, 65535, 255);
      writePGMImage8(Shepp_Logan_sinogram_16_5LE_8, "Shepp_Logan_sinogram_16_5LE.raw",256,512);
  
      auto craneE_8 = convertImage<uint16_t, uint8_t>(craneE, 65535, 255);
      writePGMImage8(craneE_8, "craneE.raw",512,512);
  
      savePGM(Ellipse_3LE, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Ellipse_3LE.pgm");
      savePGM(Ellipse_4LE, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Ellipse_4LE.pgm");
      savePGM(Ellipse_5LE, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Ellipse_5LE.pgm");
      savePGM(IRM_5LE, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_5LE_8.pgm");
      savePGM(IRM_8LE, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\IRM_8LE_8.pgm");
      savePGM(imageCoeurLE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\imageCoeurLE_8.pgm");
      savePGM(Shepp_Logan_phantom_8LE, 256,256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_phantom_8LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_8_2LE, 256,363, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_8_2LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_3LE_8,64,128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_16_3LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_4LE_8, 256, 363, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_16_4LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_5LE_8, 256 , 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\Shepp_Logan_sinogram_16_5LE_8.pgm");
      savePGM(thoraxLE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\thoraxLE.pgm");
      savePGM(craneE_8, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\craneE_8.pgm");
      savePGM(coeur_LE, 128, 128, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\coeur_LE.pgm");
      savePGM(femoral_LE, 512, 512, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\femoral_LE.pgm");
      savePGM(_crane_LE, 256, 256, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\_crane_LE.pgm");


      // 7. Application LUT binaire
      auto lut1 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\5percent.lut)"); // Assurez-vous que ce fichier existe
      auto lut2 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\6_Reserved_Colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut3 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\8_Grays.lut)"); // Assurez-vous que ce fichier existe
      auto lut4 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\8color.lut)"); // Assurez-vous que ce fichier existe
      auto lut5 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\10_Percent.lut)"); // Assurez-vous que ce fichier existe
      auto lut6 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\12_Colors.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(imageCoeur8, lut);
      auto lut7 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\16_Color_Ramps.lut)"); // Assurez-vous que ce fichier existe
      auto lut8 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\16_color.lut)"); // Assurez-vous que ce fichier existe
      auto lut9 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\20_Colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut10 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\LUT\\LUT\\NucMed_Image_LUTs\\32_Colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut11 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\LUT\\LUT\\NucMed_Image_LUTs\\A_Squared.lut)"); // Assurez-vous que ce fichier existe
      auto lut12 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Amber.lut)"); // Assurez-vous que ce fichier existe
      
      
      auto lut13 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\BlackOnWhite.lut)"); // Assurez-vous que ce fichier existe
      auto lut14 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Blue_Green_Red.lut)"); // Assurez-vous que ce fichier existe
      auto lut15 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\blue_orange_icb.lut)"); // Assurez-vous que ce fichier existe
      auto lut16 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\blue_orange.lut)"); // Assurez-vous que ce fichier existe
      auto lut17 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Blue_Red_Yellow.lut)"); // Assurez-vous que ce fichier existe
      auto lut18 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Blue_Red.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
      auto lut19 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Blue-Orange.lut)"); // Assurez-vous que ce fichier existe
      auto lut20 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\blue.lut)"); // Assurez-vous que ce fichier existe
      auto lut21 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Brain.lut)"); // Assurez-vous que ce fichier existe
      auto lut22 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Brown_Body.lut)"); // Assurez-vous que ce fichier existe
      auto lut23 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Bullseye.lut)"); // Assurez-vous que ce fichier existe
      auto lut24 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\CEqual.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
      auto lut25 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Ceretec.lut)"); // Assurez-vous que ce fichier existe
      auto lut26 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\colder.lut)"); // Assurez-vous que ce fichier existe
      auto lut27 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\cool.lut)"); // Assurez-vous que ce fichier existe
      auto lut28 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\CTI_RAS.lut)"); // Assurez-vous que ce fichier existe
      auto lut29 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Cyclic.lut)"); // Assurez-vous que ce fichier existe
      auto lut30 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Edges.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut31 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Fire-1.lut)"); // Assurez-vous que ce fichier existe
            auto lut32 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Fire-2.lut)"); // Assurez-vous que ce fichier existe
            auto lut33 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\ge-16.lut)"); // Assurez-vous que ce fichier existe
            auto lut34 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\ge-256.lut)"); // Assurez-vous que ce fichier existe
            auto lut35 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\GE.lut)"); // Assurez-vous que ce fichier existe
            auto lut36 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\GEM-16.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut37 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\GEM-256.lut)"); // Assurez-vous que ce fichier existe
            auto lut38 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Gold.lut)"); // Assurez-vous que ce fichier existe
            auto lut39 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\gray.lut)"); // Assurez-vous que ce fichier existe
            auto lut40 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Grayscale.lut)"); // Assurez-vous que ce fichier existe
            auto lut41 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Green_Table.lut)"); // Assurez-vous que ce fichier existe
            auto lut42 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Green.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut43 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Grey.lut)"); // Assurez-vous que ce fichier existe
            auto lut44 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Heart.lut)"); // Assurez-vous que ce fichier existe
            auto lut45 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Heart.lut)"); // Assurez-vous que ce fichier existe
            auto lut46 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\Hot_Iron.lut)"); // Assurez-vous que ce fichier existe
            auto lut47 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\hot.lut)"); // Assurez-vous que ce fichier existe
            auto lut48 = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\hotter.lut)"); // Assurez-vous que ce fichier existe
   


            // 7. Application LUT binaire
      auto lut1_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\000-gray.lut)"); // Assurez-vous que ce fichier existe
      auto lut2_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\001-fire.lut)"); // Assurez-vous que ce fichier existe
      auto lut3_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\002-spectrum.lut)"); // Assurez-vous que ce fichier existe
      auto lut4_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\003-ice.lut)"); // Assurez-vous que ce fichier existe
      auto lut5_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\004-phase.lut)"); // Assurez-vous que ce fichier existe
      auto lut6_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\5_ramps.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(imageCoeur8, lut);
      auto lut7_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\005-random.lut)"); // Assurez-vous que ce fichier existe
      auto lut8_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\6_reserved_colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut9_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\6_shades.lut)"); // Assurez-vous que ce fichier existe
      auto lut10_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\16_colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut11_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\16_equal.lut)"); // Assurez-vous que ce fichier existe
      auto lut12_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\16_ramps.lut)"); // Assurez-vous que ce fichier existe
      
      
      auto lut13_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\20_colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut14_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\32_colors.lut)"); // Assurez-vous que ce fichier existe
      auto lut15_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\amber.lut)"); // Assurez-vous que ce fichier existe
      auto lut16_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\auxctq.lut)"); // Assurez-vous que ce fichier existe
      auto lut17_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\blue_orange_icb.lut)"); // Assurez-vous que ce fichier existe
      auto lut18_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\brain.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
      auto lut19_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\brgbcmyw.lut)"); // Assurez-vous que ce fichier existe
      auto lut20_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\brown.lut)"); // Assurez-vous que ce fichier existe
      auto lut21_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cells.lut)"); // Assurez-vous que ce fichier existe
      auto lut22_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cequal.lut)"); // Assurez-vous que ce fichier existe
      auto lut23_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cmy-cyan.lut)"); // Assurez-vous que ce fichier existe
      auto lut24_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cmy-magneta.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
      auto lut25_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cmy-yellow.lut)"); // Assurez-vous que ce fichier existe
      auto lut26_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cmy.lut)"); // Assurez-vous que ce fichier existe
      auto lut27_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cold.lut)"); // Assurez-vous que ce fichier existe
      auto lut28_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cool.lut)"); // Assurez-vous que ce fichier existe
      auto lut29_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\cti_ras.lut)"); // Assurez-vous que ce fichier existe
      auto lut30_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\edges.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut31_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\ether.lut)"); // Assurez-vous que ce fichier existe
            auto lut32_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\fire-ncsa.lut)"); // Assurez-vous que ce fichier existe
            auto lut33_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\gem-16.lut)"); // Assurez-vous que ce fichier existe
            auto lut34_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\gem-256.lut)"); // Assurez-vous que ce fichier existe
            auto lut35_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\gold.lut)"); // Assurez-vous que ce fichier existe
            auto lut36_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\GreenFire.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut37_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\grey.lut)"); // Assurez-vous que ce fichier existe
            auto lut38_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\gyr_centre.lut)"); // Assurez-vous que ce fichier existe
            auto lut39_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\haze.lut)"); // Assurez-vous que ce fichier existe
            auto lut40_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\heart.lut)"); // Assurez-vous que ce fichier existe
            auto lut41_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\HiLo.lut)"); // Assurez-vous que ce fichier existe
            auto lut42_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\HotGreen.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(Shepp_Logan_phantom_8LE_8, lut1);
            auto lut43_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\hsatl1.lut)"); // Assurez-vous que ce fichier existe
            auto lut44_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\hsatl2.lut)"); // Assurez-vous que ce fichier existe
            auto lut45_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\hue_ramps_08.lut)"); // Assurez-vous que ce fichier existe
            auto lut46_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\hue_ramps_16.lut)"); // Assurez-vous que ce fichier existe
            auto lut47_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\hue.lut)"); // Assurez-vous que ce fichier existe
            auto lut48_2 = loadLUTBinary(R"(C:\Users\lylehara\Downloads\TER\LUT\LUT\iman.lut)"); // Assurez-vous que ce fichier existe



      auto colorImage1 = applyLUT(Shepp_Logan_phantom_8LE, lut1);
      auto colorImage2 = applyLUT(Shepp_Logan_phantom_8LE, lut2);
      auto colorImage3 = applyLUT(Shepp_Logan_phantom_8LE, lut3);
      auto colorImage4 = applyLUT(Shepp_Logan_phantom_8LE, lut4);
      auto colorImage5 = applyLUT(Shepp_Logan_phantom_8LE, lut5);
      auto colorImage6 = applyLUT(Shepp_Logan_phantom_8LE, lut6);
      auto colorImage7 = applyLUT(Shepp_Logan_phantom_8LE, lut7);
      auto colorImage8 = applyLUT(Shepp_Logan_phantom_8LE, lut8);
      auto colorImage9 = applyLUT(Shepp_Logan_phantom_8LE, lut9);
      auto colorImage10 = applyLUT(Shepp_Logan_phantom_8LE, lut11);
      auto colorImage11 = applyLUT(Shepp_Logan_phantom_8LE, lut12);
      auto colorImage12 = applyLUT(Shepp_Logan_phantom_8LE, lut13);
      auto colorImage13 = applyLUT(Shepp_Logan_phantom_8LE, lut14);
      auto colorImage14 = applyLUT(Shepp_Logan_phantom_8LE, lut15);
      auto colorImage15 = applyLUT(Shepp_Logan_phantom_8LE, lut16);
      auto colorImage16 = applyLUT(Shepp_Logan_phantom_8LE, lut17);
      auto colorImage17 = applyLUT(Shepp_Logan_phantom_8LE, lut18);
      auto colorImage18 = applyLUT(Shepp_Logan_phantom_8LE, lut19);
      auto colorImage19 = applyLUT(Shepp_Logan_phantom_8LE, lut20);
      auto colorImage20 = applyLUT(Shepp_Logan_phantom_8LE, lut21);
      auto colorImage21 = applyLUT(Shepp_Logan_phantom_8LE, lut22);
      auto colorImage22 = applyLUT(Shepp_Logan_phantom_8LE, lut23);
      auto colorImage23 = applyLUT(Shepp_Logan_phantom_8LE, lut24);
      auto colorImage24 = applyLUT(Shepp_Logan_phantom_8LE, lut25);
      auto colorImage25 = applyLUT(Shepp_Logan_phantom_8LE, lut26);
      auto colorImage26 = applyLUT(Shepp_Logan_phantom_8LE, lut27);
      auto colorImage27 = applyLUT(Shepp_Logan_phantom_8LE, lut28);
      auto colorImage28 = applyLUT(Shepp_Logan_phantom_8LE, lut29);
      auto colorImage29 = applyLUT(Shepp_Logan_phantom_8LE, lut30);
      auto colorImage30 = applyLUT(Shepp_Logan_phantom_8LE, lut31);
      auto colorImage31 = applyLUT(Shepp_Logan_phantom_8LE, lut32);
      auto colorImage32 = applyLUT(Shepp_Logan_phantom_8LE, lut33);
      auto colorImage33 = applyLUT(Shepp_Logan_phantom_8LE, lut34);
      auto colorImage34 = applyLUT(Shepp_Logan_phantom_8LE, lut35);
      auto colorImage35 = applyLUT(Shepp_Logan_phantom_8LE, lut36);
      auto colorImage36 = applyLUT(Shepp_Logan_phantom_8LE, lut37);
      auto colorImage37 = applyLUT(Shepp_Logan_phantom_8LE, lut38);
      auto colorImage38 = applyLUT(Shepp_Logan_phantom_8LE, lut39);
      auto colorImage39 = applyLUT(Shepp_Logan_phantom_8LE, lut40);
      auto colorImage40 = applyLUT(Shepp_Logan_phantom_8LE, lut41);
      auto colorImage41 = applyLUT(Shepp_Logan_phantom_8LE, lut42);
      auto colorImage42 = applyLUT(Shepp_Logan_phantom_8LE, lut43);
      auto colorImage43 = applyLUT(Shepp_Logan_phantom_8LE, lut44);
      auto colorImage44 = applyLUT(Shepp_Logan_phantom_8LE, lut45);
      auto colorImage45 = applyLUT(Shepp_Logan_phantom_8LE, lut46);
      auto colorImage46 = applyLUT(Shepp_Logan_phantom_8LE, lut47);
      auto colorImage47 = applyLUT(Shepp_Logan_phantom_8LE, lut48);
    
    //image coeurs 

    auto imageCoeurLE1 = applyLUT(imageCoeurLE, lut1);
    auto imageCoeurLE2 = applyLUT(imageCoeurLE, lut2);
    auto imageCoeurLE3 = applyLUT(imageCoeurLE, lut3);
    auto imageCoeurLE4 = applyLUT(imageCoeurLE, lut4);
    auto imageCoeurLE5 = applyLUT(imageCoeurLE, lut5);
    auto imageCoeurLE6 = applyLUT(imageCoeurLE, lut6);
    auto imageCoeurLE7 = applyLUT(imageCoeurLE, lut7);
    auto imageCoeurLE8 = applyLUT(imageCoeurLE, lut8);
    auto imageCoeurLE9 = applyLUT(imageCoeurLE, lut9);
    auto imageCoeurLE10 = applyLUT(imageCoeurLE, lut11);
    auto imageCoeurLE11 = applyLUT(imageCoeurLE, lut12);
    auto imageCoeurLE12 = applyLUT(imageCoeurLE, lut13);
    auto imageCoeurLE13 = applyLUT(imageCoeurLE, lut14);
    auto imageCoeurLE14 = applyLUT(imageCoeurLE, lut15);
    auto imageCoeurLE15 = applyLUT(imageCoeurLE, lut16);
    auto imageCoeurLE16 = applyLUT(imageCoeurLE, lut17);
    auto imageCoeurLE17 = applyLUT(imageCoeurLE, lut18);
    auto imageCoeurLE18 = applyLUT(imageCoeurLE, lut19);
    auto imageCoeurLE19 = applyLUT(imageCoeurLE, lut20);
    auto imageCoeurLE20 = applyLUT(imageCoeurLE, lut21);
    auto imageCoeurLE21 = applyLUT(imageCoeurLE, lut22);
    auto imageCoeurLE22 = applyLUT(imageCoeurLE, lut23);
    auto imageCoeurLE23 = applyLUT(imageCoeurLE, lut24);
    auto imageCoeurLE24 = applyLUT(imageCoeurLE, lut25);
    auto imageCoeurLE25 = applyLUT(imageCoeurLE, lut26);
    auto imageCoeurLE26 = applyLUT(imageCoeurLE, lut27);
    auto imageCoeurLE27 = applyLUT(imageCoeurLE, lut28);
    auto imageCoeurLE28 = applyLUT(imageCoeurLE, lut29);
    auto imageCoeurLE29 = applyLUT(imageCoeurLE, lut30);
    auto imageCoeurLE30 = applyLUT(imageCoeurLE, lut31);
    auto imageCoeurLE31 = applyLUT(imageCoeurLE, lut32);
    auto imageCoeurLE32 = applyLUT(imageCoeurLE, lut33);
    auto imageCoeurLE33 = applyLUT(imageCoeurLE, lut34);
    auto imageCoeurLE34 = applyLUT(imageCoeurLE, lut35);
    auto imageCoeurLE35 = applyLUT(imageCoeurLE, lut36);
    auto imageCoeurLE36 = applyLUT(imageCoeurLE, lut37);
    auto imageCoeurLE37 = applyLUT(imageCoeurLE, lut38);
    auto imageCoeurLE38 = applyLUT(imageCoeurLE, lut39);
    auto imageCoeurLE39 = applyLUT(imageCoeurLE, lut40);
    auto imageCoeurLE40 = applyLUT(imageCoeurLE, lut41);
    auto imageCoeurLE41 = applyLUT(imageCoeurLE, lut42);
    auto imageCoeurLE42 = applyLUT(imageCoeurLE, lut43);
    auto imageCoeurLE43 = applyLUT(imageCoeurLE, lut44);
    auto imageCoeurLE44 = applyLUT(imageCoeurLE, lut45);
    auto imageCoeurLE45 = applyLUT(imageCoeurLE, lut46);
    auto imageCoeurLE46 = applyLUT(imageCoeurLE, lut47);
    auto imageCoeurLE47 = applyLUT(imageCoeurLE, lut48);
//image 3

auto IRM_8LE1 = applyLUT(IRM_8LE, lut1);
auto IRM_8LE2 = applyLUT(IRM_8LE, lut2);
auto IRM_8LE3 = applyLUT(IRM_8LE, lut3);
auto IRM_8LE4 = applyLUT(IRM_8LE, lut4);
auto IRM_8LE5 = applyLUT(IRM_8LE, lut5);
auto IRM_8LE6 = applyLUT(IRM_8LE, lut6);
auto IRM_8LE7 = applyLUT(IRM_8LE, lut7);
auto IRM_8LE8 = applyLUT(IRM_8LE, lut8);
auto IRM_8LE9 = applyLUT(IRM_8LE, lut9);
auto IRM_8LE10 = applyLUT(IRM_8LE, lut11);
auto IRM_8LE11 = applyLUT(IRM_8LE, lut12);
auto IRM_8LE12 = applyLUT(IRM_8LE, lut13);
auto IRM_8LE13 = applyLUT(IRM_8LE, lut14);
auto IRM_8LE14 = applyLUT(IRM_8LE, lut15);
auto IRM_8LE15 = applyLUT(IRM_8LE, lut16);
auto IRM_8LE16 = applyLUT(IRM_8LE, lut17);
auto IRM_8LE17 = applyLUT(IRM_8LE, lut18);
auto IRM_8LE18 = applyLUT(IRM_8LE, lut19);
auto IRM_8LE19 = applyLUT(IRM_8LE, lut20);
auto IRM_8LE20 = applyLUT(IRM_8LE, lut21);
auto IRM_8LE21 = applyLUT(IRM_8LE, lut22);
auto IRM_8LE22 = applyLUT(IRM_8LE, lut23);
auto IRM_8LE23 = applyLUT(IRM_8LE, lut24);
auto IRM_8LE24 = applyLUT(IRM_8LE, lut25);
auto IRM_8LE25 = applyLUT(IRM_8LE, lut26);
auto IRM_8LE26 = applyLUT(IRM_8LE, lut27);
auto IRM_8LE27 = applyLUT(IRM_8LE, lut28);
auto IRM_8LE28 = applyLUT(IRM_8LE, lut29);
auto IRM_8LE29 = applyLUT(IRM_8LE, lut30);
auto IRM_8LE30 = applyLUT(IRM_8LE, lut31);
auto IRM_8LE31 = applyLUT(IRM_8LE, lut32);
auto IRM_8LE32 = applyLUT(IRM_8LE, lut33);
auto IRM_8LE33 = applyLUT(IRM_8LE, lut34);
auto IRM_8LE34 = applyLUT(IRM_8LE, lut35);
auto IRM_8LE35 = applyLUT(IRM_8LE, lut36);
auto IRM_8LE36 = applyLUT(IRM_8LE, lut37);
auto IRM_8LE37 = applyLUT(IRM_8LE, lut38);
auto IRM_8LE38 = applyLUT(IRM_8LE, lut39);
auto IRM_8LE39 = applyLUT(IRM_8LE, lut40);
auto IRM_8LE40 = applyLUT(IRM_8LE, lut41);
auto IRM_8LE41 = applyLUT(IRM_8LE, lut42);
auto IRM_8LE42 = applyLUT(IRM_8LE, lut43);
auto IRM_8LE43 = applyLUT(IRM_8LE, lut44);
auto IRM_8LE44 = applyLUT(IRM_8LE, lut45);
auto IRM_8LE45 = applyLUT(IRM_8LE, lut46);
auto IRM_8LE46 = applyLUT(IRM_8LE, lut47);
auto IRM_8LE47 = applyLUT(IRM_8LE, lut48);

//save image 1

      savePPM(colorImage1, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage1_from_lut.ppm");
      savePPM(colorImage2, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage2_from_lut.ppm");
      savePPM(colorImage3, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage3_from_lut.ppm");
      savePPM(colorImage4, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage4_from_lut.ppm");
      savePPM(colorImage5, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage5_from_lut.ppm");
      savePPM(colorImage6, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage6_from_lut.ppm");
      savePPM(colorImage7, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage7_from_lut.ppm");
      savePPM(colorImage8, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage8_from_lut.ppm");
      savePPM(colorImage9, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage10_from_lut.ppm");
      savePPM(colorImage10, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage11_from_lut.ppm");
      savePPM(colorImage11, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage12_from_lut.ppm");
      savePPM(colorImage12, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage13_from_lut.ppm");
      savePPM(colorImage13, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage14_from_lut.ppm");
      savePPM(colorImage14, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage15_from_lut.ppm");
      savePPM(colorImage15, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage16_from_lut.ppm");
      savePPM(colorImage16, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage17_from_lut.ppm");
      savePPM(colorImage17, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage18_from_lut.ppm");
      savePPM(colorImage18, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage19_from_lut.ppm");
      savePPM(colorImage19, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage20_from_lut.ppm");
      savePPM(colorImage20, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage21_from_lut.ppm");
      savePPM(colorImage22, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage22_from_lut.ppm");
      savePPM(colorImage23, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage23_from_lut.ppm");
      savePPM(colorImage24, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage24_from_lut.ppm");
      savePPM(colorImage25, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage25_from_lut.ppm");
      savePPM(colorImage26, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage26_from_lut.ppm");
      savePPM(colorImage27, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage27_from_lut.ppm");
      savePPM(colorImage28, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage28_from_lut.ppm");
      savePPM(colorImage29, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage29_from_lut.ppm");
      savePPM(colorImage30, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage30_from_lut.ppm");
      savePPM(colorImage31, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage31_from_lut.ppm");
      savePPM(colorImage32, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage32_from_lut.ppm");
      savePPM(colorImage33, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage33_from_lut.ppm");
      savePPM(colorImage34, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage34_from_lut.ppm");
      savePPM(colorImage35, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage35_from_lut.ppm");
      savePPM(colorImage36, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage36_from_lut.ppm");
      savePPM(colorImage37, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage37_from_lut.ppm");
      savePPM(colorImage38, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage38_from_lut.ppm");
      savePPM(colorImage39, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage39_from_lut.ppm");
      savePPM(colorImage40, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage40_from_lut.ppm");
      savePPM(colorImage41, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage41_from_lut.ppm");
      savePPM(colorImage42, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage42_from_lut.ppm");
      savePPM(colorImage43, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage43_from_lut.ppm");
      savePPM(colorImage44, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage44_from_lut.ppm");
      savePPM(colorImage45, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage45_from_lut.ppm");
      savePPM(colorImage46, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage46_from_lut.ppm");
      savePPM(colorImage47, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\colorImage47_from_lut.ppm");
  

      //save image 2 

      savePPM(imageCoeurLE1, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE1_from_lut.ppm");
      savePPM(imageCoeurLE2, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE2_from_lut.ppm");
      savePPM(imageCoeurLE3, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE3_from_lut.ppm");
      savePPM(imageCoeurLE4, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE4_from_lut.ppm");
      savePPM(imageCoeurLE5, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE5_from_lut.ppm");
      savePPM(imageCoeurLE6, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE6_from_lut.ppm");
      savePPM(imageCoeurLE7, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE7_from_lut.ppm");
      savePPM(imageCoeurLE8, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE8_from_lut.ppm");
      savePPM(imageCoeurLE9, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE10_from_lut.ppm");
      savePPM(imageCoeurLE10, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE11_from_lut.ppm");
      savePPM(imageCoeurLE11, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE12_from_lut.ppm");
      savePPM(imageCoeurLE12, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE13_from_lut.ppm");
      savePPM(imageCoeurLE13, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE14_from_lut.ppm");
      savePPM(imageCoeurLE14, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE15_from_lut.ppm");
      savePPM(imageCoeurLE15, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE16_from_lut.ppm");
      savePPM(imageCoeurLE16, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE17_from_lut.ppm");
      savePPM(imageCoeurLE17, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE18_from_lut.ppm");
      savePPM(imageCoeurLE18, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE19_from_lut.ppm");
      savePPM(imageCoeurLE19, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE20_from_lut.ppm");
      savePPM(imageCoeurLE20, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE21_from_lut.ppm");
      savePPM(imageCoeurLE22, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE22_from_lut.ppm");
      savePPM(imageCoeurLE23, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE23_from_lut.ppm");
      savePPM(imageCoeurLE24, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE24_from_lut.ppm");
      savePPM(imageCoeurLE25, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE25_from_lut.ppm");
      savePPM(imageCoeurLE26, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE26_from_lut.ppm");
      savePPM(imageCoeurLE27, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE27_from_lut.ppm");
      savePPM(imageCoeurLE28, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE28_from_lut.ppm");
      savePPM(imageCoeurLE29, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE29_from_lut.ppm");
      savePPM(imageCoeurLE30, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE30_from_lut.ppm");
      savePPM(imageCoeurLE31, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE31_from_lut.ppm");
      savePPM(imageCoeurLE32, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE32_from_lut.ppm");
      savePPM(imageCoeurLE33, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE33_from_lut.ppm");
      savePPM(imageCoeurLE34, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE34_from_lut.ppm");
      savePPM(imageCoeurLE35, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE35_from_lut.ppm");
      savePPM(imageCoeurLE36, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE36_from_lut.ppm");
      savePPM(imageCoeurLE37, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE37_from_lut.ppm");
      savePPM(imageCoeurLE38, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE38_from_lut.ppm");
      savePPM(imageCoeurLE39, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE39_from_lut.ppm");
      savePPM(imageCoeurLE40, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE40_from_lut.ppm");
      savePPM(imageCoeurLE41, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE41_from_lut.ppm");
      savePPM(imageCoeurLE42, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE42_from_lut.ppm");
      savePPM(imageCoeurLE43, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE43_from_lut.ppm");
      savePPM(imageCoeurLE44, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE44_from_lut.ppm");
      savePPM(imageCoeurLE45, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE45_from_lut.ppm");
      savePPM(imageCoeurLE46, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\imageCoeurLE46_from_lut.ppm");
    
//save image 2 

savePPM(IRM_8LE1, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE1_from_lut.ppm");
savePPM(IRM_8LE2, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE2_from_lut.ppm");
savePPM(IRM_8LE3, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE3_from_lut.ppm");
savePPM(IRM_8LE4, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE4_from_lut.ppm");
savePPM(IRM_8LE5, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE5_from_lut.ppm");
savePPM(IRM_8LE6, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE6_from_lut.ppm");
savePPM(IRM_8LE7, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE7_from_lut.ppm");
savePPM(IRM_8LE8, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE8_from_lut.ppm");
savePPM(IRM_8LE9, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE10_from_lut.ppm");
savePPM(IRM_8LE10, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE11_from_lut.ppm");
savePPM(IRM_8LE11, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE12_from_lut.ppm");
savePPM(IRM_8LE12, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE13_from_lut.ppm");
savePPM(IRM_8LE13, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE14_from_lut.ppm");
savePPM(IRM_8LE14, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE15_from_lut.ppm");
savePPM(IRM_8LE15, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE16_from_lut.ppm");
savePPM(IRM_8LE16, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE17_from_lut.ppm");
savePPM(IRM_8LE17, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE18_from_lut.ppm");
savePPM(IRM_8LE18, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE19_from_lut.ppm");
savePPM(IRM_8LE19, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE20_from_lut.ppm");
savePPM(IRM_8LE20, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE21_from_lut.ppm");
savePPM(IRM_8LE22, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE22_from_lut.ppm");
savePPM(IRM_8LE23, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE23_from_lut.ppm");
savePPM(IRM_8LE24, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE24_from_lut.ppm");
savePPM(IRM_8LE25, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE25_from_lut.ppm");
savePPM(IRM_8LE26, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE26_from_lut.ppm");
savePPM(IRM_8LE27, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE27_from_lut.ppm");
savePPM(IRM_8LE28, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE28_from_lut.ppm");
savePPM(IRM_8LE29, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE29_from_lut.ppm");
savePPM(IRM_8LE30, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE30_from_lut.ppm");
savePPM(IRM_8LE31, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE31_from_lut.ppm");
savePPM(IRM_8LE32, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE32_from_lut.ppm");
savePPM(IRM_8LE33, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE33_from_lut.ppm");
savePPM(IRM_8LE34, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE34_from_lut.ppm");
savePPM(IRM_8LE35, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE35_from_lut.ppm");
savePPM(IRM_8LE36, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE36_from_lut.ppm");
savePPM(IRM_8LE37, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE37_from_lut.ppm");
savePPM(IRM_8LE38, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE38_from_lut.ppm");
savePPM(IRM_8LE39, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE39_from_lut.ppm");
savePPM(IRM_8LE40, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE40_from_lut.ppm");
savePPM(IRM_8LE41, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE41_from_lut.ppm");
savePPM(IRM_8LE42, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE42_from_lut.ppm");
savePPM(IRM_8LE43, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE43_from_lut.ppm");
savePPM(IRM_8LE44, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE44_from_lut.ppm");
savePPM(IRM_8LE45, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE45_from_lut.ppm");
savePPM(IRM_8LE46, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesColors\\IRM_8LE46_from_lut.ppm");




      
    //   auto lutsinogram = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brown.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImagesinogram = applyLUT(sinogram8, lutsinogram);
    //   savePPM(colorImagesinogram, width, height, "sinogram8color_from_lut.ppm");
  

      // 8. Sauvegarde d’images PGM
      std::cout << "Tous les traitements sont terminés.\n";
  
      return 0;
}
