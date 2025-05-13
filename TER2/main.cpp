#include <iostream>
#include <vector>
#include <string>
#include "namespace.hpp"
#include <filesystem>//

namespace fs = std::filesystem; 
using namespace v1_0;
struct RawImageInfo {
  std::string filename;
  size_t width;
  size_t height;
  int channels;    // 1 ou 3
  bool bigEndian;  // true = BE, false = LE
  bool isUint16;   // true = uint16, false = uint8
};

int main(){
    
    const size_t width = 256;
    const size_t height = 256;
    std::string ImageRaw= "images_Raw\\images\\" ;
    std::string imagePGM= "imagePGM/" ;
    std::string lutPath = "LUT/LUT/";
    std::string imageColoredPath = "imageColored/";

    std::vector<std::string> lutPaths = {
 
        "LUT\\LUT\\000-gray.lut",   "LUT\\LUT\\001-fire.lut",   "LUT\\LUT\\002-spectrum.lut",   "LUT\\LUT\\003-ice.lut",   "LUT\\LUT\\004-phase.lut",   "LUT\\LUT\\5_ramps.lut",   "LUT\\LUT\\6_reserved_colors.lut",   "LUT\\LUT\\6_shades.lut",   "LUT\\LUT\\16_colors.lut",   "LUT\\LUT\\16_equal.lut",   "LUT\\LUT\\16_ramps.lut",   "LUT\\LUT\\20_colors.lut",   "LUT\\LUT\\32_colors.lut",   "LUT\\LUT\\amber.lut",   "LUT\\LUT\\auxctq.lut",   "LUT\\LUT\\blue_orange_icb.lut",   "LUT\\LUT\\blue_orange.lut",   "LUT\\LUT\\brain.lut",   "LUT\\LUT\\brgbcmyw.lut",   "LUT\\LUT\\brown.lut",   "LUT\\LUT\\cells.lut",   "LUT\\LUT\\cequal.lut",   "LUT\\LUT\\cmy-cyan.lut",  "LUT\\LUT\\cmy-magneta.lut",  "LUT\\LUT\\cmy-yellow.lut",  "LUT\\LUT\\cmy.lut",  "LUT\\LUT\\cold.lut",  "LUT\\LUT\\cool.lut",  "LUT\\LUT\\cti_ras.lut",  "LUT\\LUT\\edges.lut",  "LUT\\LUT\\ether.lut",  "LUT\\LUT\\fire-ncsa.lut",  "LUT\\LUT\\gem-16.lut",  "LUT\\LUT\\gem-256.lut",  "LUT\\LUT\\gold.lut",  "LUT\\LUT\\GreenFire.lut",  "LUT\\LUT\\grey.lut",  "LUT\\LUT\\gyr_centre.lut",  "LUT\\LUT\\haze.lut",  "LUT\\LUT\\heart.lut",  "LUT\\LUT\\HiLo.lut",  "LUT\\LUT\\HotGreen.lut",  "LUT\\LUT\\HotRed.lut",  "LUT\\LUT\\hsatl1.lut",  "LUT\\LUT\\hsatl2.lut",  "LUT\\LUT\\hsatv1.lut", "LUT\\LUT\\hue_ramps_08.lut", "LUT\\LUT\\hue_ramps_16.lut", "LUT\\LUT\\hue.lut", "LUT\\LUT\\iman.lut", "LUT\\LUT\\invert_gray.lut", "LUT\\LUT\\isocontour.lut", "LUT\\LUT\\log_down.lut", "LUT\\LUT\\log_up.lut", "LUT\\LUT\\mixed.lut", "LUT\\LUT\\neon-blue.lut", "LUT\\LUT\\neon-green.lut", "LUT\\LUT\\neon-magenta.lut", "LUT\\LUT\\neon-red.lut", "LUT\\LUT\\nih-image-fire1.lut", "LUT\\LUT\\nih-image-fire2.lut", "LUT\\LUT\\pastel.lut", "LUT\\LUT\\RangeIndicator.lut", "LUT\\LUT\\red-blue.lut", "LUT\\LUT\\rgb-green.lut", "LUT\\LUT\\rgb-red.lut", "LUT\\LUT\\royal.lut", "LUT\\LUT\\sepia.lut", "LUT\\LUT\\siemens.lut", "LUT\\LUT\\smart.lut", "LUT\\LUT\\split_blackblue_redwhite.lut", "LUT\\LUT\\split_blackwhite_ge.lut",  "LUT\\LUT\\split_blackwhite_warmmetal.lut",  "UT\\LUT\\split_bluered_warmmetal.lut",  "LUT\\LUT\\system_lut.lut",  "LUT\\LUT\\thal_16.lut",  "LUT\\LUT\\thal_256.lut",  "LUT\\LUT\\thallium.lut",  "LUT\\LUT\\topography.lut",  "LUT\\LUT\\unionjack.lut",  "LUT\\LUT\\vivid.lut",  "LUT\\LUT\\warhol.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\5percent.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\6_Reserved_Colors.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\8_Grays.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\8color.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\10_Percent.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\12_Colors.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\16_Color_Ramps.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\16_color.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\16-color.lut",  "LUT\\LUT\\NucMed_Image_LUTs\\A_Squared.lut",   "LUT\\LUT\\Amber.lut",     "LUT\\LUT\\Auxctq.lut",     "LUT\\LUT\\BlackOnWhite.lut",     "LUT\\LUT\\Blue_Green_Red.lut",     "LUT\\LUT\\Blue_Green.lut",     "LUT\\LUT\\blue_orange_icb.lut",     "LUT\\LUT\\blue_orange.lut",     "LUT\\LUT\\Blue_Red_Yellow.lut",     "LUT\\LUT\\Blue_Red.lut",     "LUT\\LUT\\Blue-Orange.lut",     "LUT\\LUT\\blue.lut",     "LUT\\LUT\\Brain.lut",     "LUT\\LUT\\Brown_Body.lut",     "LUT\\LUT\\Bullseye.lut",     "LUT\\LUT\\CEqual.lut",     "LUT\\LUT\\Ceretec.lut",     "LUT\\LUT\\colder.lut",     "LUT\\LUT\\cool.lut",     "LUT\\LUT\\CTI_RAS.lut",     "LUT\\LUT\\Cyclic.lut",     "LUT\\LUT\\Edges.lut", "LUT\\LUT\\Fire-1.lut", "LUT\\LUT\\Fire-2.lut", "LUT\\LUT\\ge-16.lut", "LUT\\LUT\\GE.lut", "LUT\\LUT\\GEM-16.lut", "LUT\\LUT\\GEM-256.lut", "LUT\\LUT\\Gold.lut", "LUT\\LUT\\gray.lut", "LUT\\LUT\\Grayscale.lut", "LUT\\LUT\\Green_Table.lut", "LUT\\LUT\\Grey.lut", "LUT\\LUT\\Heart.lut", "LUT\\LUT\\Hot_Iron.lut", "LUT\\LUT\\hot.lut", "LUT\\LUT\\hotter.lut", "LUT\\LUT\\Ice.lut", "LUT\\LUT\\Icon.bin", "LUT\\LUT\\Invert_Grayscale.lut", "LUT\\LUT\\Invert_Grey.lut", "LUT\\LUT\\Isocontour.lut", "LUT\\LUT\\linear.lut", "LUT\\LUT\\Log_Down.lut", "LUT\\LUT\\Log_Up.lut", "LUT\\LUT\\Magenta.lut", "LUT\\LUT\\MMC.lut", "LUT\\LUT\\multi.lut", "LUT\\LUT\\PIXEF.lut", "LUT\\LUT\\PIXRED.lut", "LUT\\LUT\\prism.lut", "LUT\\LUT\\Rainbow.lut","LUT\\LUT\\Red.lut","LUT\\LUT\\Royal.lut","LUT\\LUT\\S_Pet.lut","LUT\\LUT\\Siemens.lut","LUT\\LUT\\smart.lut","LUT\\LUT\\Sopha.lut","LUT\\LUT\\Spectrum.lut","LUT\\LUT\\Split_BlackBlue_RedWhite.lut","LUT\\LUT\\Split_BlackWhite_GE.lut","LUT\\LUT\\Split_BlackWhite_WarmMetal.lut","LUT\\LUT\\Split_BlueRed_WarmMetal.lut","LUT\\LUT\\StarsAndStripes.lut","LUT\\LUT\\step4.lut","LUT\\LUT\\step5.lut","LUT\\LUT\\step10.lut","LUT\\LUT\\step20.lut","LUT\\LUT\\System_LUT.lut","LUT\\LUT\\Thal_16.lut","LUT\\LUT\\Thal_256.lut","LUT\\LUT\\Thal_Map.lut","LUT\\LUT\\Thallium.lut","LUT\\LUT\\Thermal-SP.lut","LUT\\LUT\\Thermal.lut","LUT\\LUT\\UCLA_NIH.lut","LUT\\LUT\\Warm_Metal.lut","LUT\\LUT\\warm.lut","LUT\\LUT\\White_Blue_Green_Red.lut","LUT\\LUT\\Yellow_WFG.lut"
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
 
  { "Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, 3, false, false},
  { "Shepp_Logan_phantom_8_bits_256x256.raw", 256, 256, 3, true, false},
 
  { "TDM_8_bits_512x512_thorax.raw", 512, 512, 1, false, false},
  { "TDM_8_bits_512x512_thorax.raw", 512, 512, 1, true, false},
  
 
  { "TDM_16_bits_512x512_crane.raw", 512, 512, 1, false, true},
  { "TDM_16_bits_512x512_crane.raw", 512, 512, 1, true, true},
  
 
  { "US_8_bits_128x128_coeur.raw", 128, 128, 1, false, false},
  { "US_8_bits_128x128_coeur.raw", 128, 128, 1, true, false},
 
  { "XR_8_bits_512x512_femoral.raw", 512, 512, 1, false, false},
  { "XR_8_bits_512x512_femoral.raw", 512, 512, 1, true, false},
 
 
};


    //la Reponse a la première question 

    // 1. Création image blanche
    auto whiteImage = ImageBlanche<uint8_t>(width, height);
    savePGM(whiteImage, width, height, imagePGM + "whiteImage.pgm");

    // 2.  sinusoïdale
    auto sinusImage = SinusoidalImage<uint16_t>(width, height, 8.0); 
    // savePGM16(sinusImage, width, height, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    writeRawImage(sinusImage, ImageRaw + "sinus_image.raw");
    // 3. Damier
    auto checkerboardImage = ImageDamier<uint8_t>(width, height, 32); 
    savePGM(checkerboardImage, width, height, imagePGM + "checkerboardImage.pgm");

    //4.image en couleur RGB
    auto rgbImage = RGBImage<uint8_t>(width, height, 255, 128, 64);
    savePPM(rgbImage, width, height, imagePGM + "rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    printImage(checkerboardImage, 4, 3);

    auto sinusImage_BE = readRawImage<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
      auto sinusImage_LE = readRawImage<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
     
      auto sinusImage_BE_converted = convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
      savePGM(sinusImage_BE_converted, width, height, imagePGM + "sinusImage_BE_converted.pgm");
      auto sinusImage_LE_converted = convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
      savePGM(sinusImage_LE_converted, width, height, imagePGM + "isinusImage_BE_converted.pgm");
 
    //  Charger toutes les LUTs
    std::vector<std::string> lutNames;
    std::vector<decltype(loadLUT(""))> luts;
    for (const auto& lutPath : lutPaths) {
        auto lut = loadLUT(lutPath);
        // Extraire le nom de la LUT sans chemin ni extension
        size_t lastSlash = lutPath.find_last_of("\\/");
        size_t lastDot = lutPath.find_last_of('.');
        std::string name = lutPath.substr(lastSlash + 1, lastDot - lastSlash - 1);
        lutNames.push_back(name);
        luts.push_back(lut);
        std::cout << "LUT chargée : " << name << std::endl;
    }

 //  Appliquer chaque LUT sur chaque image
 for (const auto& img : images) {
  std::string imagePath = ImageRaw + img.filename;
  std::string imageBaseName = img.filename.substr(0, img.filename.find_last_of('.'));

  std::cout << "Traitement de : " << img.filename << std::endl;

  std::string outputDir = imageColoredPath + imageBaseName; 
  if (!fs::exists(outputDir)) {
      fs::create_directory(outputDir);
  }

  // ----- Cas 1 : Image RGB (channels == 3)
  if (img.channels == 3) {
    // Lire l'image RGB brute
    auto imageRGB = readRawImageRGB<uint8_t>(imagePath, img.width, img.height, img.channels, img.bigEndian);

    // Convertir en niveaux de gris
    auto imageGray = convertRGBToGrayscale(imageRGB, img.width, img.height);

    // Appliquer toutes les LUTs dessus
    for (size_t j = 0; j < luts.size(); ++j) {
        auto coloredImage = applyLUT(imageGray, luts[j]);
        std::string outPath = outputDir + "/" + imageBaseName + (img.bigEndian ? "_BE" : "_LE") + "_with_" + lutNames[j] + ".ppm";
        savePPM(coloredImage, img.width, img.height, outPath);
    }
}
  // ----- Cas 2 : Image scalaire (1 canal)
  if (img.isUint16) {
      auto image16 = readRawImage<uint16_t>(imagePath, img.width, img.height, img.bigEndian);
      bool adjustDynamics = true;
      auto image = convertImage<uint16_t, uint8_t>(image16, adjustDynamics);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto coloredImage = applyLUT(image, luts[j]);
          std::string outPath = outputDir + "/" + imageBaseName + (img.bigEndian ? "_BE" : "_LE") + "_with_" + lutNames[j] + ".ppm";
          savePPM(coloredImage, img.width, img.height, outPath);
      }

  } else { // uint8
      auto image = readRawImage<uint8_t>(imagePath, img.width, img.height, img.bigEndian);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto coloredImage = applyLUT(image, luts[j]);
          std::string outPath = outputDir + "/" + imageBaseName + (img.bigEndian ? "_BE" : "_LE") + "_with_" + lutNames[j] + ".ppm";
          savePPM(coloredImage, img.width, img.height, outPath);
      }
  }
}

std::cout << " Traitement terminé !" << std::endl;

}