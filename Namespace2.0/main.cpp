
#include<iostream>
#include "../Namespace V1.1/Image.hpp"
#include "./Processing.hpp"
#include "./Addition.hpp"
#include "./Equalization.hpp"
#include "./Karnel.hpp"  // en plus de Convolution.hpp
#include "Convolution.hpp"
using namespace v1_1;
using namespace v2_0;
int main(){
    const size_t width = 256;
    const size_t height = 256;
    std::string filenameImagePGM = "C:\\Users\\lylehara\\Downloads\\TER\\Namespace V1.1\\ImagePGM\\";
    std::string filenameimages_RAW = "C:\\Users\\lylehara\\Downloads\\TER\\images_RAW\\images\\";
    std::string lutPath = "C:\\Users\\lylehara\\Downloads\\TER\\LUT\\LUT\\"; 
    std::string filenameImagePPM = "C:\\Users\\lylehara\\Downloads\\TER\\Namespace V1.1\\ImagePPM\\";

    auto meanKernel = v2_0::createMeanKernel(3);
    auto gaussKernel = v2_0::createGaussianKernel(3, 1.0f);
    auto expKernel = v2_0::createExponentialKernel(3);
    // Crée tes images
    v1_1::Image<uint8_t> Image8(width, height);
    // Génère les données
    auto sinusData = Image8.createSinusoidalImage(10.0);
    auto checkerboardData = Image8.createCheckerboardImage(32);
    
    auto IRM_8__coeur_BE=  Image8.readRawImage(filenameimages_RAW + "IRM_8_bits_256x256_coeur.raw",  256,  256,false);
    auto IRM_8__coeur_LE=  Image8.readRawImage(filenameimages_RAW + "IRM_8_bits_256x256_coeur.raw",  256,  256,true);
    
    auto imageShepp_Logan_phantom_1_BE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_phantom_8_bits_256x256.raw",  256,  256,false);
    auto imageShepp_Logan_phantom_1_LE=  Image8.readRawImage(filenameimages_RAW + "Shepp_Logan_phantom_8_bits_256x256.raw",  256,  256,true);
   
    // Crée des vraies Image<T> avec ces données
    v1_1::Image<uint8_t> imageSinus(width, height);
    imageSinus.setData(sinusData);
    
    v1_1::Image<uint8_t> IRM_8__coeur_1(width, height);
    IRM_8__coeur_1.setData(IRM_8__coeur_BE);
    
    v1_1::Image<uint8_t> IRM_8__coeur_2(width, height);
    IRM_8__coeur_2.setData(IRM_8__coeur_LE);
    
    v1_1::Image<uint8_t> IRM_5_labels__crane_1(width, height);
    IRM_5_labels__crane_1.setData(imageShepp_Logan_phantom_1_BE);
    
    v1_1::Image<uint8_t> IRM_5_labels__crane_2(width, height);
    IRM_5_labels__crane_2.setData(imageShepp_Logan_phantom_1_LE);
    
    v1_1::Image<uint8_t> imageCheckerboard(width, height);
    imageCheckerboard.setData(checkerboardData);
    
    // Crée résultat
    v1_1::Image<uint8_t> result1(width, height);
    v1_1::Image<uint8_t> result2(width, height);
    v1_1::Image<uint8_t> result3(width, height);
    v1_1::Image<uint8_t> result4(width, height);
    // v1_1::Image<uint8_t> histImage(width, height);

    // Utilisation fonctionnelle (sans classes)
    v2_0::addition(IRM_8__coeur_1, IRM_5_labels__crane_1, result1);
    v2_0::addition(IRM_8__coeur_1, IRM_5_labels__crane_2, result2);
    v2_0::addition(IRM_8__coeur_2, IRM_5_labels__crane_1, result3);
    v2_0::addition(IRM_8__coeur_2, IRM_5_labels__crane_2, result4);
    //v2_0::additionScalar(imageSinus, result2, static_cast<uint8_t>(50));
    
    // Utilisation orientée objet (avec classes)
    v2_0::Addition<uint8_t> additionProcessor;
    additionProcessor.Update(IRM_8__coeur_1, IRM_5_labels__crane_1);
    result1 = additionProcessor.getOutput();
    
    v2_0::Addition<uint8_t> additionProcessor2;
    additionProcessor2.Update(IRM_8__coeur_1, IRM_5_labels__crane_2);
    result2 = additionProcessor.getOutput();
    
    v2_0::Addition<uint8_t> additionProcessor3;
    additionProcessor3.Update(IRM_8__coeur_2, IRM_5_labels__crane_1);
    result3 = additionProcessor.getOutput();
    
    v2_0::Addition<uint8_t> additionProcessor4;
    additionProcessor4.Update(IRM_8__coeur_2, IRM_5_labels__crane_2);
    result4 = additionProcessor.getOutput();
    
    // v2_0::AdditionScalar<uint8_t> scalarProcessor(50);
    // scalarProcessor.Update(imageSinus);
    // result2 = scalarProcessor.getOutput();
    
    result1.savePGM(result1.getData(), result1.getWidth(), result1.getHeigth(), "result1.pgm");
    result2.savePGM(result2.getData(), result2.getWidth(), result2.getHeigth(), "result2.pgm");
    result3.savePGM(result3.getData(), result3.getWidth(), result3.getHeigth(), "result3.pgm");
    result4.savePGM(result4.getData(), result4.getWidth(), result4.getHeigth(), "result4.pgm");
   
   
   // Création de l'histogramme avant égalisation
auto histImageBefore = v2_0::generateHistogramImage(result1);
histImageBefore.savePGM(histImageBefore.getData(), histImageBefore.getWidth(), histImageBefore.getHeigth(), "hist_before.pgm");

// Égalisation de l'histogramme
v1_1::Image<uint8_t> equalizedImage(width, height);
v2_0::histogramEqualization(result1, equalizedImage);
equalizedImage.savePGM(equalizedImage.getData(), equalizedImage.getWidth(), equalizedImage.getHeigth(), "equalized.pgm");

// Création de l'histogramme après égalisation
auto histImageAfter = v2_0::generateHistogramImage(equalizedImage);
histImageAfter.savePGM(histImageAfter.getData(), histImageAfter.getWidth(), histImageAfter.getHeigth(), "hist_after.pgm");


Convolution<uint8_t> convolutionProcessor;
v1_1::Image<uint8_t> filteredImage(width, height);

// Test avec le filtre moyenneur
convolutionProcessor.Process(IRM_8__coeur_1, meanKernel, false);

filteredImage = convolutionProcessor.getOutput();
filteredImage.savePGM(filteredImage.getData(), filteredImage.getWidth(), filteredImage.getHeigth(), "filtered_mean.pgm");

// Test avec gaussien
convolutionProcessor.Process(IRM_8__coeur_1, gaussKernel, false);

filteredImage = convolutionProcessor.getOutput();
filteredImage.savePGM(filteredImage.getData(), filteredImage.getWidth(), filteredImage.getHeigth(), "filtered_gaussian.pgm");

// Test avec exponentiel
convolutionProcessor.Update(IRM_8__coeur_1, expKernel);
convolutionProcessor.Process(IRM_8__coeur_1, expKernel, false);
filteredImage = convolutionProcessor.getOutput();
filteredImage.savePGM(filteredImage.getData(), filteredImage.getWidth(), filteredImage.getHeigth(), "filtered_exponential.pgm");




    return 0;
}