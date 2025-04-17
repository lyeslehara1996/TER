#include "Image.hpp"
#include "ImageRGB.hpp"
#include <cstdint>
#include <string>


int main() {
    using namespace v1_1;
    const size_t width = 256;
    const size_t height = 256;
    //question 1
    std::string filenameImagePGM = "C:\\Users\\lylehara\\Downloads\\TER\\Namespace V1.1\\ImagePGM\\";
    std::string filenameimages_RAW = "C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\";
    std::string lutPath = "C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\"; 
    std::string filenameImagePPM = "C:\\Users\\lylehara\\Downloads\\TER\\Namespace V1.1\\ImagePPM\\";




    Image<uint8_t> Image8(width, height);
    Image<uint16_t > image16(width, height);
    


//image blanche 
    auto imagewhite = Image8.createWhiteImage();
    Image8.savePGM(imagewhite, width,height,filenameImagePGM + "whiteImage.pgm");

//image damier
    auto imageCheckerboard = Image8.createCheckerboardImage(32);
    Image8.savePGM(imageCheckerboard,width,height,filenameImagePGM + "checkerboard.pgm");

//image sinusoidale 
    auto imageSinus= Image8.createSinusoidalImage(10.0);
    Image8.savePGM(imageSinus,width,height,filenameImagePGM+"sinusoidal.pgm");

    //print image dans console 
   // Image8.printImage(imageSinus,50, 50);

    //lecture fichier image .raw 8bits 
    auto Ellipse_labels_1_BE=  Image8.readRawImage(filenameimages_RAW + "Ellipse_3_labels_8_bits_256x256.raw",  256,  256,false);
    auto Ellipse_labels_1_LE=  Image8.readRawImage(filenameimages_RAW + "Ellipse_3_labels_8_bits_256x256.raw",  256,  256,true);
   
    
    auto IRM_5_labels__crane_BE=  Image8.readRawImage(filenameimages_RAW + "IRM_5_labels_8_bits_256x256_crane.raw",  256,  256,false);
    auto IRM_5_labels__crane_LE=  Image8.readRawImage(filenameimages_RAW + "IRM_5_labels_8_bits_256x256_crane.raw",  256,  256,true);
    
    auto IRM_8__coeur_BE=  Image8.readRawImage(filenameimages_RAW + "IRM_8_bits_256x256_coeur.raw",  256,  256,false);
    auto IRM_8__coeur_LE=  Image8.readRawImage(filenameimages_RAW + "IRM_8_bits_256x256_coeur.raw",  256,  256,true);
    
    auto imageShepp_Logan_phantom_1_BE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_phantom_8_bits_256x256.raw",  256,  256,false);
    auto imageShepp_Logan_phantom_1_LE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_phantom_8_bits_256x256.raw",  256,  256,true);
   
    auto Shepp_Logan_phantom_2_BE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_8_bits_256x363.raw",  256,  363,false);
    auto Shepp_Logan_phantom_2_LE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_8_bits_256x363.raw",  256,  363,true);
   
    auto TDM_thorax_BE=  Image8.readRawImage(filenameimages_RAW + "TDM_8_bits_512x512_thorax.raw",  512,  512,false);
    auto TDM_thorax_LE=  Image8.readRawImage(filenameimages_RAW + "TDM_8_bits_512x512_thorax.raw",  512,  512,true);
   
    auto US_coeur_BE=  Image8.readRawImage(filenameimages_RAW + "US_8_bits_128x128_coeur.raw",  128,  128,false);
    auto US_coeur_LE=  Image8.readRawImage(filenameimages_RAW + "US_8_bits_128x128_coeur.raw",  128,  128,true);
   
    auto XR_femoral_BE=  Image8.readRawImage(filenameimages_RAW + "XR_8_bits_512x512_femoral.raw",  512,  512,false);
    auto XR_femoral_LE=  Image8.readRawImage(filenameimages_RAW + "XR_8_bits_512x512_femoral.raw",  512,  512,true);
   
    //lecteur image RGB
    auto IRM_RGB_crane_BE = readRawImageRGB<uint8_t>(filenameimages_RAW + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, 3, false);
    auto IRM_RGB_crane_LE = readRawImageRGB<uint8_t>(filenameimages_RAW + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, 3, true);

 

    //sauvegarder image 8bit en  .pgm 
    Image8.savePGM(Ellipse_labels_1_BE,  256,  256, filenameImagePGM + "Ellipse_3_labels_8_bits_256x256_BE.pgm");
    Image8.savePGM(Ellipse_labels_1_LE,  256,  256, filenameImagePGM + "Ellipse_3_labels_8_bits_256x256_LE.pgm");
    
    Image8.savePGM(IRM_5_labels__crane_BE,  256,  256, filenameImagePGM + "IRM_5_labels_8_bits_256x256_crane_BE.pgm");
    Image8.savePGM(IRM_5_labels__crane_LE,  256,  256, filenameImagePGM + "IRM_5_labels_8_bits_256x256_crane_LE.pgm");
    
    Image8.savePGM(IRM_8__coeur_BE,  256,  256, filenameImagePGM + "IRM_8_bits_256x256_coeur_BE.pgm");
    Image8.savePGM(IRM_8__coeur_LE,  256,  256, filenameImagePGM + "IRM_8_bits_256x256_coeur.pgm");
    
    Image8.savePGM(imageShepp_Logan_phantom_1_BE,  256,  256, filenameImagePGM + "Shepp_Logan_phantom_8_bits_256x256_BE.pgm");
    Image8.savePGM(imageShepp_Logan_phantom_1_BE,  256,  256, filenameImagePGM + "Shepp_Logan_phantom_8_bits_256x256_LE.pgm");
    
    Image8.savePGM(Shepp_Logan_phantom_2_BE,  256,  363, filenameImagePGM + "Shepp_Logan_phantom_8_bits_256x256_BE.pgm");
    Image8.savePGM(Shepp_Logan_phantom_2_LE,  256,  363, filenameImagePGM + "Shepp_Logan_phantom_8_bits_256x256_LE.pgm");
    
    Image8.savePGM(TDM_thorax_BE,  512,  512, filenameImagePGM + "Shepp_Logan_sinogram_8_bits_256x363_BE.pgm");
    Image8.savePGM(TDM_thorax_LE,  512,  512, filenameImagePGM + "Shepp_Logan_sinogram_8_bits_256x363_LE.pgm");
   
    Image8.savePGM(US_coeur_BE,  128,  128, filenameImagePGM + "US_8_bits_128x128_coeur_BE.pgm");
    Image8.savePGM(US_coeur_LE,  128,  128, filenameImagePGM + "US_8_bits_128x128_coeur_LE.pgm");
    
    Image8.savePGM(XR_femoral_BE,  512,  512, filenameImagePGM + "XR_8_bits_512x512_femoral.pgm");
    Image8.savePGM(XR_femoral_LE,  512,  512, filenameImagePGM + "XR_8_bits_512x512_femoral.pgm");
    
    //sauvegarder image ppm 

    ImageRGB IRM_RGB_crane_BE_RGB(IRM_RGB_crane_BE, 256, 256); // Constructeur avec données RGB
    IRM_RGB_crane_BE_RGB.savePPM(filenameImagePPM + "IRM_RGB_8_bits_256x256_crane_BE.ppm");
    
    ImageRGB IRM_RGB_crane_LE_RGB(IRM_RGB_crane_LE, 256, 256);
    IRM_RGB_crane_LE_RGB.savePPM(filenameImagePPM + "IRM_RGB_8_bits_256x256_crane_LE.ppm");

    
    std::vector<uint8_t> IRM_RGB_crane_BE_grayscale = convertRGBToGrayscale(IRM_RGB_crane_BE_RGB.getRGBData(), IRM_RGB_crane_BE_RGB.getWidth(),IRM_RGB_crane_BE_RGB.getHeigth()); 
    std::vector<uint8_t> IRM_RGB_crane_LE_grayscale = convertRGBToGrayscale(IRM_RGB_crane_LE_RGB.getRGBData(), IRM_RGB_crane_LE_RGB.getWidth(),IRM_RGB_crane_LE_RGB.getHeigth()); 
   
    Image<unsigned char> IRM_RGB_crane_BE_imageGrayscale(IRM_RGB_crane_BE_RGB.getWidth(), IRM_RGB_crane_BE_RGB.getHeigth());
    Image<unsigned char> IRM_RGB_crane_LE_imageGrayscale(IRM_RGB_crane_LE_RGB.getWidth(), IRM_RGB_crane_LE_RGB.getHeigth());
    IRM_RGB_crane_BE_imageGrayscale.setData(IRM_RGB_crane_BE_grayscale);
    IRM_RGB_crane_LE_imageGrayscale.setData(IRM_RGB_crane_LE_grayscale);
    IRM_RGB_crane_LE_imageGrayscale.savePGM(IRM_RGB_crane_BE_grayscale,256,256,filenameImagePGM + "IRM_RGB_crane_BE_grayscale.pgm");
    IRM_RGB_crane_LE_imageGrayscale.savePGM(IRM_RGB_crane_LE_grayscale,256,256,filenameImagePGM + "IRM_RGB_crane_LE_grayscale.pgm");
    

//lecture image .raw de 16 bit
    auto IRM_16__coeur_BE = image16.readRawImage(filenameimages_RAW + "IRM_16_bits_256x256_coeur.raw", 256, 256, false);
    auto IRM_16__coeur_LE = image16.readRawImage(filenameimages_RAW + "IRM_16_bits_256x256_coeur.raw", 256, 256, true);
  
    auto IRM_16__crane_BE = image16.readRawImage(filenameimages_RAW + "IRM_16_bits_256x256_crane.raw", 256, 256, false);
    auto IRM_16__crane_LE = image16.readRawImage(filenameimages_RAW + "IRM_16_bits_256x256_crane.raw", 256, 256, true);
  
    auto TDM_16__crane_BE = image16.readRawImage(filenameimages_RAW + "TDM_16_bits_512x512_crane.raw", 512, 512, false);
    auto TDM_16__crane_LE = image16.readRawImage(filenameimages_RAW + "TDM_16_bits_512x512_crane.raw", 512, 512, true);
  
    auto Shepp_Logan_sinogram_16_1__BE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_64x128.raw", 64, 128, false);
    auto Shepp_Logan_sinogram_16_1__LE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_64x128.raw", 64, 128, true);
   
    auto Shepp_Logan_sinogram_16_2__BE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_256x363.raw", 256, 363, false);
    auto Shepp_Logan_sinogram_16_2__LE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_256x363.raw", 256, 363, true);
    
    auto Shepp_Logan_sinogram_16_3__BE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_256x512.raw", 256, 512, false);
    auto Shepp_Logan_sinogram_16_3__LE = image16.readRawImage(filenameimages_RAW + "Shepp_Logan_sinogram_16_bits_256x512.raw", 256, 512, true);



    //convertir image 16bits a 8bit 
    auto IRM_16__coeur_converted_BE = convertImage<uint16_t, uint8_t>(IRM_16__coeur_BE, true);
    auto IRM_16__coeur_converted_LE = convertImage<uint16_t, uint8_t>(IRM_16__coeur_LE, true);
  
    auto IRM_16__crane_converted_BE = convertImage<uint16_t, uint8_t>(IRM_16__crane_BE, true);
    auto IRM_16__crane_converted_LE = convertImage<uint16_t, uint8_t>(IRM_16__crane_LE, true);
  
    auto TDM_16__crane_converted_BE = convertImage<uint16_t, uint8_t>(TDM_16__crane_BE, true);
    auto TDM_16__crane_converted_LE = convertImage<uint16_t, uint8_t>(TDM_16__crane_LE, true);
  
    auto Shepp_Logan_sinogram_16_1_converted_BE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_1__BE, true);
    auto Shepp_Logan_sinogram_16_1_converted_LE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_1__LE, true);
  
    auto Shepp_Logan_sinogram_16_2_converted_BE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_2__BE, true);
    auto Shepp_Logan_sinogram_16_2_converted_LE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_2__LE, true);
  
    auto Shepp_Logan_sinogram_16_3_converted_BE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_3__BE, true);
    auto Shepp_Logan_sinogram_16_3_converted_LE = convertImage<uint16_t, uint8_t>(Shepp_Logan_sinogram_16_3__BE, true);
  
    
    //sauvegarder image converti en .pgm
    image16.savePGM(IRM_16__coeur_converted_BE,  256,  256, filenameImagePGM + "IRM_16__coeur_converted_converted_BE.pgm");
    image16.savePGM(IRM_16__coeur_converted_LE,  256,  256, filenameImagePGM + "IRM_16__coeur_converted_converted_LE.pgm");
   
    image16.savePGM(IRM_16__crane_converted_BE,  256,  256, filenameImagePGM + "IRM_16__crane_converted_converted_BE.pgm");
    image16.savePGM(IRM_16__crane_converted_LE,  256,  256, filenameImagePGM + "IRM_16__crane_converted_converted_LE.pgm");
   
    image16.savePGM(TDM_16__crane_converted_BE,  512, 512, filenameImagePGM + "TDM_16__crane_converted_converted_BE.pgm");
    image16.savePGM(TDM_16__crane_converted_LE,  512, 512, filenameImagePGM + "TDM_16__crane_converted_converted_LE.pgm");
   
    image16.savePGM(Shepp_Logan_sinogram_16_1_converted_BE,  64, 128, filenameImagePGM + "Shepp_Logan_sinogram_16_1_converted_converted_BE.pgm");
    image16.savePGM(Shepp_Logan_sinogram_16_1_converted_LE,  64, 128, filenameImagePGM + "Shepp_Logan_sinogram_16_1_converted_converted_LE.pgm");
   
    image16.savePGM(Shepp_Logan_sinogram_16_2_converted_BE,  256, 363, filenameImagePGM + "Shepp_Logan_sinogram_16_2_converted_converted_BE.pgm");
    image16.savePGM(Shepp_Logan_sinogram_16_2_converted_LE,  256, 363, filenameImagePGM + "Shepp_Logan_sinogram_16_2_converted_converted_LE.pgm");
   
    image16.savePGM(Shepp_Logan_sinogram_16_3_converted_BE,  256, 512, filenameImagePGM + "Shepp_Logan_sinogram_16_3_converted_converted_BE.pgm");
    image16.savePGM(Shepp_Logan_sinogram_16_3_converted_LE,  256, 512, filenameImagePGM + "Shepp_Logan_sinogram_16_3_converted_converted_LE.pgm");
   

    // charger LUT
        auto lut1 = loadLUTBinary(lutPath + "000-gray.lut");
        auto lut2 = loadLUTBinary(lutPath + "001-fire.lut");
        auto lut3 = loadLUTBinary(lutPath + "002-spectrum.lut");
        auto lut4 = loadLUTBinary(lutPath + "003-ice.lut");
        auto lut5 = loadLUTBinary(lutPath + "004-phase.lut");
        auto lut6 = loadLUTBinary(lutPath + "5_ramps.lut");
        auto lut7 = loadLUTBinary(lutPath + "6_reserved_colors.lut");
        auto lut8 = loadLUTBinary(lutPath + "6_shades.lut");
        auto lut9 = loadLUTBinary(lutPath + "16_colors.lut");


    //appliquer LUT
        ImageRGB XR_femoral_BE_LUT_1 (XR_femoral_BE, 512, 512, lut1);
        ImageRGB XR_femoral_BE_LUT_2 (XR_femoral_BE, 512, 512, lut2);
        ImageRGB XR_femoral_BE_LUT_3 (XR_femoral_BE, 512, 512, lut3);
        ImageRGB XR_femoral_BE_LUT_4 (XR_femoral_BE, 512, 512, lut4);
        ImageRGB XR_femoral_BE_LUT_5 (XR_femoral_BE, 512, 512, lut5);
        ImageRGB XR_femoral_BE_LUT_6 (XR_femoral_BE, 512, 512, lut6);
        ImageRGB XR_femoral_BE_LUT_7 (XR_femoral_BE, 512, 512, lut7);
        ImageRGB XR_femoral_BE_LUT_8 (XR_femoral_BE, 512, 512, lut8);
        ImageRGB XR_femoral_BE_LUT_9 (XR_femoral_BE, 512, 512, lut9);
        
        ImageRGB IRM_RGB_crane_BE_LUT_1 (IRM_RGB_crane_BE_grayscale, 256, 256, lut1);
        ImageRGB IRM_RGB_crane_BE_LUT_2 (IRM_RGB_crane_BE_grayscale, 256, 256, lut2);
        ImageRGB IRM_RGB_crane_BE_LUT_3 (IRM_RGB_crane_BE_grayscale, 256, 256, lut3);
        ImageRGB IRM_RGB_crane_BE_LUT_4 (IRM_RGB_crane_BE_grayscale, 256, 256, lut4);
        ImageRGB IRM_RGB_crane_BE_LUT_5 (IRM_RGB_crane_BE_grayscale, 256, 256, lut5);
        ImageRGB IRM_RGB_crane_BE_LUT_6 (IRM_RGB_crane_BE_grayscale, 256, 256, lut6);
        ImageRGB IRM_RGB_crane_BE_LUT_7 (IRM_RGB_crane_BE_grayscale, 256, 256, lut7);
        ImageRGB IRM_RGB_crane_BE_LUT_8 (IRM_RGB_crane_BE_grayscale, 256, 256, lut8);
        ImageRGB IRM_RGB_crane_BE_LUT_9 (IRM_RGB_crane_BE_grayscale, 256, 256, lut9);
        
    
     // Sauvegarde l image en format .PPM
     XR_femoral_BE_LUT_1.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_1.ppm");
     XR_femoral_BE_LUT_2.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_2.ppm");
     XR_femoral_BE_LUT_3.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_3.ppm");
     XR_femoral_BE_LUT_4.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_4.ppm");
     XR_femoral_BE_LUT_5.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_5.ppm");
     XR_femoral_BE_LUT_6.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_6.ppm");
     XR_femoral_BE_LUT_7.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_7.ppm");
     XR_femoral_BE_LUT_8.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_8.ppm");
     XR_femoral_BE_LUT_9.savePPM(filenameImagePPM + "XR_femoral_BE_LUT_9.ppm");
   
   
     IRM_RGB_crane_BE_LUT_1.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_1.ppm");
     IRM_RGB_crane_BE_LUT_2.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_2.ppm");
     IRM_RGB_crane_BE_LUT_3.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_3.ppm");
     IRM_RGB_crane_BE_LUT_4.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_4.ppm");
     IRM_RGB_crane_BE_LUT_5.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_5.ppm");
     IRM_RGB_crane_BE_LUT_6.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_6.ppm");
     IRM_RGB_crane_BE_LUT_7.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_7.ppm");
     IRM_RGB_crane_BE_LUT_8.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_8.ppm");
     IRM_RGB_crane_BE_LUT_9.savePPM(filenameImagePPM + "IRM_RGB_crane_BE_LUT_9.ppm");
}