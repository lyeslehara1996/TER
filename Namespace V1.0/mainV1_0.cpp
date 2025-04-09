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
    writeRawImage8(whiteImage, "white.raw");

    // 3. Mire sinusoïdale
    auto sinusImage16 = createSinusoidalImage<uint16_t>(width, height, 0.1, 65535);
    writeRawImage(sinusImage16, "sinus16.raw", false);

    // 4. Damier
    auto checkerboard = createCheckerboardImage<uint8_t>(width, height, 32, 0, 255);
    writeRawImage8(checkerboard, "checker.raw");
    


      // 1. Lecture d’image 16 bits avec endianness
      auto Ellipse_3LE = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_3_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto Ellipse_3E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_3_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto Ellipse_4LE = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_4_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto Ellipse_4E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_4_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 3 Lecture d’image 16 bits avec endianness
      auto Ellipse_5LE = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_5_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto Ellipse_5E = readRawImage<uint8_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Ellipse_5_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 4. Lecture d’image 16 bits avec endianness
      auto IRM_5LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw)", width, height, false); // little endian
      auto IRM_5E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_5_labels_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 5. Lecture d’image 16 bits avec endianness
      auto IRM_8LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw)", width, height, false); // little endian
      auto IRM_8E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_8_bits_256x256_coeur.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 6. Lecture d’image 16 bits avec endianness
      auto IRM_16_canneLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw)", width, height, false); // little endian
      auto IRM_16_canneE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_16_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      

      // 7. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\IRM_RGB_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      
      // 8. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_phantom_8LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height, false); // little endian
      auto Shepp_Logan_phantom_8E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 9. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_sinogram_8_2LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_8_2E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 10. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_sinogram_16_3LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_3E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_64x128.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 11. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_sinogram_16_4LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_4E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 12. Lecture d’image 16 bits avec endianness
      auto Shepp_Logan_sinogram_16_5LE = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw)", width, height, false); // little endian
      auto Shepp_Logan_sinogram_16_5E = readRawImage<uint16_t>(R"(C:\\Users\\lylehara\\Downloads\TER\\images_RAW\\images\\Shepp_Logan_sinogram_16_bits_256x512.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // . Conversion vers 8 bits
      // auto Ellipse_3_8 = convertImage<uint16_t, uint8_t>(Ellipse_3LE, 65535, 255);
      // writeRawImage8(Ellipse_3_8, "Ellipse_3LE.raw");
  
      // auto Ellipse_4LE_8 = convertImage<uint16_t, uint8_t>(Ellipse_4LE, 65535, 255);
      // writeRawImage8(Ellipse_4LE_8, "Ellipse_4LE_8.raw");
  
      // auto Ellipse_5LE_8 = convertImage<uint16_t, uint8_t>(Ellipse_5LE, 65535, 255);
      // writeRawImage8(Ellipse_5LE_8, "Ellipse_5LE_8.raw");
  
      auto IRM_5LE_8 = convertImage<uint16_t, uint8_t>(IRM_5LE, 65535, 255);
      writeRawImage8(IRM_5LE_8, "IRM_5LE.raw");
  
      auto IRM_8LE_8 = convertImage<uint16_t, uint8_t>(IRM_8LE, 65535, 255);
      writeRawImage8(IRM_8LE_8, "IRM_8LE.raw");
  
      auto IRM_16_canneLE_8 = convertImage<uint16_t, uint8_t>(IRM_16_canneLE, 65535, 255);
      writeRawImage8(IRM_16_canneLE_8, "IRM_16_canneLE.raw");
  
      auto imageCoeurLE_8 = convertImage<uint16_t, uint8_t>(imageCoeurLE, 65535, 255);
      writeRawImage8(imageCoeurLE_8, "imageCoeurLE.raw");
  
      auto Shepp_Logan_phantom_8LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_phantom_8LE, 65535, 255);
      writeRawImage8(Shepp_Logan_phantom_8LE_8, "Shepp_Logan_phantom_8LE.raw");
  
      auto Shepp_Logan_sinogram_8_2LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_8_2LE, 65535, 255);
      writeRawImage8(Shepp_Logan_sinogram_8_2LE_8, "Shepp_Logan_sinogram_8_2LE.raw");
  
      auto Shepp_Logan_sinogram_16_3LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_3LE, 65535, 255);
      writeRawImage8(Shepp_Logan_sinogram_16_3LE_8, "Shepp_Logan_sinogram_16_3LE.raw");
  
      auto Shepp_Logan_sinogram_16_4LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_4LE, 65535, 255);
      writeRawImage8(Shepp_Logan_sinogram_16_4LE_8, "Shepp_Logan_sinogram_16_4LE.raw");
  
      auto Shepp_Logan_sinogram_16_5LE_8 = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_5LE, 65535, 255);
      writeRawImage8(Shepp_Logan_sinogram_16_5LE_8, "Shepp_Logan_sinogram_16_5LE.raw");
  
      savePGM(Ellipse_3LE, width, height, "Ellipse_3LE.pgm");
      savePGM(Ellipse_4LE, width, height, "Ellipse_4LE.pgm");
      savePGM(Ellipse_5LE, width, height, "Ellipse_5LE.pgm");
      savePGM(IRM_5LE_8, width, height, "IRM_5LE_8.pgm");
      savePGM(IRM_8LE_8, width, height, "IRM_8LE_8.pgm");
      savePGM(imageCoeurLE_8, width, height, "imageCoeurLE_8.pgm");
      savePGM(Shepp_Logan_phantom_8LE_8, width, height, "Shepp_Logan_phantom_8LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_8_2LE_8, width, height, "Shepp_Logan_sinogram_8_2LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_3LE_8, width, height, "Shepp_Logan_sinogram_16_3LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_4LE_8, width, height, "Shepp_Logan_sinogram_16_4LE_8.pgm");
      savePGM(Shepp_Logan_sinogram_16_5LE_8, width, height, "Shepp_Logan_sinogram_16_5LE_8.pgm");
      // 7. Application LUT binaire
    //   auto lut = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\BlackOnWhite.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImage = applyLUT(imageCoeur8, lut);
    //   savePPM(colorImage, width, height, "imageCoeur8color_from_lut.ppm");
  
    //   auto lutsinogram = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brown.lut)"); // Assurez-vous que ce fichier existe
    //   auto colorImagesinogram = applyLUT(sinogram8, lutsinogram);
    //   savePPM(colorImagesinogram, width, height, "sinogram8color_from_lut.ppm");
  

      // 8. Sauvegarde d’images PGM
      std::cout << "Tous les traitements sont terminés.\n";
  
      return 0;
}
