#include <iostream>
#include <vector>
#include <string>
#include "namespace.hpp"
#include <filesystem>//

namespace fs = std::filesystem; 
struct RawImageInfo {
  std::string fichier;
  size_t Largeur;
  size_t Hauteur;
  int cannaux;    // 1 ou 3
  bool bigEndian;  // true = BE, false = LE
  bool estUint16;   // true = uint16, false = uint8
};

int main(){
    
  try {

    const size_t Largeur = 256;
    const size_t Hauteur = 256;


    std::string ImageRaw= "./TER2/images_RAW/" ;
    std::string imagePGM= "./TER2/imagePGM/" ;
    std::string lutPath = "./TER2/LUT/";
    std::string imageRGBPath = "./TER2/imageRGB/";

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

 
int choix_namespace = -1;
while (true) {
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
    auto imageBlanche = v1_0::ImageBlanche<uint8_t>(Largeur, Hauteur);
    v1_0::sauvegarderPGM(imageBlanche, Largeur, Hauteur, imagePGM + "imageBlanche.pgm");

    // 2.  sinusoïdale
    auto sinusImage = v1_0::SinusoidalImage<uint16_t>(Largeur, Hauteur, 8.0); 
    // v1_0::sauvegarderPGM16(sinusImage, Largeur, Hauteur, "C:\\Users\\lylehara\\Downloads\\TER\\imagesPGM\\sinusImage.pgm");
    v1_0::EcritureImageRaw(sinusImage, ImageRaw + "sinus_image.raw");
    // 3. Damier
    auto imageDamier = v1_0::ImageDamier<uint8_t>(Largeur, Hauteur, 32); 
    v1_0::sauvegarderPGM(imageDamier, Largeur, Hauteur, imagePGM + "imageDamier.pgm");

    //4.image en couleur RGB
    auto rgbImage = v1_0::RGBImage<uint8_t>(Largeur, Hauteur, 255, 128, 64);
    v1_0::sauvegarderPPM(rgbImage, Largeur, Hauteur, imagePGM + "rgbImage.ppm");
   
    //afficher la matrice de l'image a la console 
    v1_0::printImage(imageDamier, 4, 3);

    auto sinusImage_BE = v1_0::LecteurImageRAW<uint16_t>(ImageRaw + "sinus_image.raw", 256, 256, false); // Little Endian
    auto sinusImage_LE = v1_0::LecteurImageRAW<uint16_t>(ImageRaw +"sinus_image.raw", 256, 256, true); // Big Endian
     
    auto sinusImage_BE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_BE, true);
    v1_0::sauvegarderPGM(sinusImage_BE_converte, Largeur, Hauteur, imagePGM + "sinusImage_BE_converte.pgm");
     
    auto sinusImage_LE_converte = v1_0::convertImage<uint16_t, uint8_t>(sinusImage_LE, true);
    v1_0::sauvegarderPGM(sinusImage_LE_converte, Largeur, Hauteur, imagePGM + "isinusImage_BE_converte.pgm");
 
    //  Charger toutes les LUTs
    std::vector<std::string> Nomluts;
    std::vector<decltype(v1_0::ChargerLUT(""))> luts;
    for (const auto& lutPath : lutPaths) {
        auto lut = v1_0::ChargerLUT(lutPath);
        // Extraire le nom de la LUT sans chemin ni extension
        size_t lastSlash = lutPath.find_last_of("\\/");
        size_t lastDot = lutPath.find_last_of('.');
        std::string nomlut = lutPath.substr(lastSlash + 1, lastDot - lastSlash - 1);
        Nomluts.push_back(nomlut);
        luts.push_back(lut);
        std::cout << "LUT chargée avec succée : " << nomlut << std::endl;
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
    auto imageRGB = v1_0::LectureImageRawRGB<uint8_t>(imagePath, img.Largeur, img.Hauteur, img.cannaux, img.bigEndian);

    // Convertir en niveaux de gris
    auto imageGris = v1_0::convertRGBenGris(imageRGB, img.Largeur, img.Hauteur);

    // Appliquer toutes les LUTs dessus
    for (size_t j = 0; j < luts.size(); ++j) {
        auto RGBImage = v1_0::applLUT(imageGris, luts[j]);
        std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
        v1_0::sauvegarderPPM(RGBImage, img.Largeur, img.Hauteur, lien_fichier);
    }
}

  // ----- Cas 2 : Image scalaire (1 canal)
  if (img.estUint16) {
      auto image16 = v1_0::LecteurImageRAW<uint16_t>(imagePath, img.Largeur, img.Hauteur, img.bigEndian);
      bool adjustDynamics = true;
      auto image = v1_0::convertImage<uint16_t, uint8_t>(image16, adjustDynamics);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto RGBImage = v1_0::applLUT(image, luts[j]);
          std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
          v1_0::sauvegarderPPM(RGBImage, img.Largeur, img.Hauteur, lien_fichier);
      }

  } else { // uint8
      auto image = v1_0::LecteurImageRAW<uint8_t>(imagePath, img.Largeur, img.Hauteur, img.bigEndian);

      for (size_t j = 0; j < luts.size(); ++j) {
          auto RGBImage = v1_0::applLUT(image, luts[j]);
          std::string lien_fichier = Dossier + "/" + imageBaseNom + (img.bigEndian ? "_BE" : "_LE") + "_with_" + Nomluts[j] + ".ppm";
          v1_0::sauvegarderPPM(RGBImage, img.Largeur, img.Hauteur, lien_fichier);
      }
  }
}

std::cout << " Traitement terminé !" << std::endl;

break;
}

case 2 :{
  std::string svgrdImageRaw = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\images_RAW\\";
  std::string ImageRaw = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\images_RAW\\images\\";
  std::string imagePGM = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imagePGM\\";
  std::string imageRGB = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\imageRGB\\";
  std::string lutPath = "C:\\Users\\lylehara\\Downloads\\TER\\TER2\\LUT\\LUT\\";

  size_t Largeur = 256, Hauteur = 256;

  // Générer images de test
  v1_1::Image<uint8_t> imageBlanche(Largeur, Hauteur);
  imageBlanche.creerImageBlache();
  imageBlanche.ecrireFichierRaw(svgrdImageRaw+"ImageBlanche.raw");
  imageBlanche.sauvegarderPGM( imagePGM+ "ImageBlanche.pgm");

  v1_1::Image<uint8_t> imageDamier(Largeur, Hauteur);
  imageDamier.creerDamier(64);
  imageDamier.ecrireFichierRaw( svgrdImageRaw+"ImageDamier.raw");
  imageDamier.sauvegarderPGM( imagePGM+"ImageDamier.pgm");

  v1_1::Image<uint8_t> imageSinus(Largeur, Hauteur);
  imageSinus.creerSinusoidale(25);
  imageSinus.ecrireFichierRaw( svgrdImageRaw+"ImageSinus.raw");
  imageSinus.sauvegarderPGM(imagePGM+"ImageSinus.pgm");

   //  Charger toutes les LUTs
   std::vector<std::string> Nomluts;
   std::vector<decltype(v1_0::ChargerLUT(""))> luts;
   for (const auto& lutPath : lutPaths) {
       auto lut = v1_1::ImageRGB::chargerLUT(lutPath);
       // Extraire le nom de la LUT sans chemin ni extension
       size_t lastSlash = lutPath.find_last_of("\\/");
       size_t lastDot = lutPath.find_last_of('.');
       std::string nomlut = lutPath.substr(lastSlash + 1, lastDot - lastSlash - 1);
       Nomluts.push_back(nomlut);
       luts.push_back(lut);
       std::cout << "LUT chargée avec succée : " << nomlut << std::endl;
   }



  // Lire images RAW correctement
  auto XR_femoral_BE = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, false);
  auto XR_femoral_LE = v1_1::Image<uint8_t>::lireImageRAW(ImageRaw + "XR_8_bits_512x512_femoral.raw", 512, 512, true);
 
  auto TDM_16_bits_BE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, false);
  auto TDM_16_bits_LE = v1_1::Image<uint16_t>::lireImageRAW(ImageRaw + "TDM_16_bits_512x512_crane.raw", 512, 512, true);

  auto TDM_16__crane_converted_BE = TDM_16_bits_BE.convertirImage< uint8_t>( true);
  auto TDM_16__crane_converted_LE = TDM_16_bits_BE.convertirImage< uint8_t>( true);

  //ImgaeRGB

    auto IRM_RGB_crane_BE = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, false);
    auto IRM_RGB_crane_LE = v1_1::lectureImageRawRGB(ImageRaw + "IRM_RGB_8_bits_256x256_crane.raw", 256, 256, true);
   
    auto IRM_RGB_crane_BEGris_BE = v1_1::convertRGB_Gris(IRM_RGB_crane_BE, 256, 256);
    auto IRM_RGB_crane_BEGris_LE = v1_1::convertRGB_Gris(IRM_RGB_crane_BE, 256, 256);
 

  XR_femoral_BE.sauvegarderPGM( imagePGM+"XR_femoral_BE.pgm");
  XR_femoral_LE.sauvegarderPGM( imagePGM+"XR_femoral_LE.pgm");
  
  TDM_16__crane_converted_BE.sauvegarderPGM( imagePGM+"TDM_16_bits_BE.pgm");
  TDM_16__crane_converted_LE.sauvegarderPGM( imagePGM+"TDM_16_bits_LE.pgm");

  IRM_RGB_crane_BEGris_BE.sauvegarderPGM( imagePGM+"IRM_RGB_8_bits_engris_BE.pgm");
  IRM_RGB_crane_BEGris_LE.sauvegarderPGM( imagePGM+"IRM_RGB_8_bits_engris_LE.pgm");

  // Charger LUT
  auto lut11 = v1_1::ImageRGB::chargerLUT(lutPath + "000-gray.lut");
  auto lut12 = v1_1::ImageRGB::chargerLUT(lutPath + "001-fire.lut");

  // Appliquer LUT
  v1_1::ImageRGB XR_femoral_BE_LUT_11(XR_femoral_BE, 512, 512, lut11);
  
  v1_1::ImageRGB TDM_16__crane_converted_LE_11(TDM_16__crane_converted_LE, 512, 512, lut11);
  v1_1::ImageRGB TDM_16__crane_converted_BE_11(TDM_16__crane_converted_BE, 512, 512, lut11);
  
  v1_1::ImageRGB TDM_16__crane_converted_LE_12(TDM_16__crane_converted_LE, 512, 512, lut12);
  v1_1::ImageRGB TDM_16__crane_converted_BE_12(TDM_16__crane_converted_BE, 512, 512, lut12);
  

  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT_BE(IRM_RGB_crane_BEGris_BE, 256, 256, lut11);
  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT_LE(IRM_RGB_crane_BEGris_LE, 256, 256, lut11);

  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT1_BE(IRM_RGB_crane_BEGris_BE, 256, 256, lut12);
  v1_1::ImageRGB IRM_RGB_crane_BEGris_LUT1_LE(IRM_RGB_crane_BEGris_LE, 256, 256, lut12);


  // Sauvegarder en .ppm
  XR_femoral_BE_LUT_11.sauvegarderPPM( imageRGB+ "XR_femoral_BE_LUT_11.ppm");

  TDM_16__crane_converted_LE_11.sauvegarderPPM( imageRGB+ " TDM_16__crane_converted_LE_1.ppm");
  TDM_16__crane_converted_BE_11.sauvegarderPPM( imageRGB+ " TDM_16__crane_converted_BE_1.ppm");

  TDM_16__crane_converted_LE_12.sauvegarderPPM( imageRGB+ " TDM_16__crane_converted_LE_2.ppm");
  TDM_16__crane_converted_BE_12.sauvegarderPPM( imageRGB+ " TDM_16__crane_converted_BE_2.ppm");

  IRM_RGB_crane_BEGris_LUT_BE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT1_BE.ppm");
  IRM_RGB_crane_BEGris_LUT_LE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT1_LE.ppm");

  IRM_RGB_crane_BEGris_LUT1_BE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT2_BE_2.ppm");
  IRM_RGB_crane_BEGris_LUT1_LE.sauvegarderPPM( imageRGB+ " IRM_RGB_8_bits_LUT2_LE_2.ppm");





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
}
   } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
        return 1;
    }
}