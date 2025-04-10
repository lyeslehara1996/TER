#include <vector>
#include <iostream>
#include <cstdint>
#include "namespace.hpp"


int main(){
    
    using namespace v1_0;
    const size_t width = 256;
    const size_t height = 256;


    // 1. Allocation d'une image
    std::vector<uint8_t> image = allocationImage<uint8_t>(width, height);
    std::cout << "Image allouée (" << width << "x" << height << ")\n";

    // 2. Création image blanche
    auto whiteImage = createWhiteImage(image, uint8_t(255));
    savePGM(whiteImage, width, height, "whiteImage.pgm");
    // 3. Mire sinusoïdale
    auto sinusImage16 = createSinusoidalImage<uint16_t>(width, height, 0.1, 65535);
   
   
    // 4. Damier
    auto checkerboard = createCheckerboardImage<uint8_t>(width, height, 32, 0, 255);
    savePGM(checkerboard, width, height, "imagedamier.pgm");
   

}