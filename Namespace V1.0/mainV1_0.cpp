#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <type_traits>


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
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_3_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_3_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_4_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_4_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_5_labels_8_bits_256x256.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Ellipse_5_labels_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 4. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_5_labels_8_bits_256x256_crane.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_5_labels_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_8_bits_256x256_coeur.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_8_bits_256x256_coeur.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_16_bits_256x256_crane.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_16_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_16_bits_256x256_crane.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_16_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 1. Lecture d’image 16 bits avec endianness
      auto imageCoeurLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_RGB_8_bits_256x256_crane.raw)", width, height, false); // little endian
      auto imageCoeurE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\IRM_RGB_8_bits_256x256_crane.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      
      // 2. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_phantom_8_bits_256x256.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_8_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_64x128.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_64x128.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_256x363.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_256x363.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 2. Lecture d’image 16 bits avec endianness
      auto sinogramLE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_256x512.raw)", width, height, false); // little endian
      auto sinogramE = readRawImage<uint16_t>(R"(C:\Users\lylehara\Downloads\TER\images_RAW\images\Shepp_Logan_sinogram_16_bits_256x512.raw)", width, height, true);  // big endian
      std::cout << "Lecture des images 16 bits avec endianness faite.\n";
      
      // 6. Conversion vers 8 bits
      auto imageCoeur8 = convertImage<uint16_t, uint8_t>(imageCoeurLE, 65535, 255);
      writeRawImage8(imageCoeur8, "imageCoeur8.raw");
  
      auto sinogram8 = convertImage<uint16_t, uint8_t>(sinogramLE, 65535, 255);
      writeRawImage8(sinogram8, "imageCoeur8.raw");
  
      // 7. Application LUT binaire
      auto lut = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\NucMed_Image_LUTs\\BlackOnWhite.lut)"); // Assurez-vous que ce fichier existe
      auto colorImage = applyLUT(imageCoeur8, lut);
      savePPM(colorImage, width, height, "imageCoeur8color_from_lut.ppm");
  
      auto lutsinogram = loadLUTBinary(R"(C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\brown.lut)"); // Assurez-vous que ce fichier existe
      auto colorImagesinogram = applyLUT(sinogram8, lutsinogram);
      savePPM(colorImagesinogram, width, height, "sinogram8color_from_lut.ppm");
  
      // 8. Sauvegarde d’images PGM
      savePGM(imageCoeur8, width, height, "imageCoeur8.pgm");
      savePGM(sinogram8, width, height, "sinogram8.pgm");
  
      std::cout << "Tous les traitements sont terminés.\n";
  
      return 0;
}
