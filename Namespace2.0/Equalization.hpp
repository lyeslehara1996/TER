#ifndef EQUALIZATION_HPP
#define EQUALIZATION_HPP

#include "../Namespace V1.1/Image.hpp"
#include <vector>
#include <algorithm>
#include <cstdint>

namespace v2_0 {

template<typename T>
void histogramEqualization(const v1_1::Image<T>& input, v1_1::Image<T>& output) {
    size_t width = input.getWidth();
    size_t height = input.getHeigth();
    size_t totalPixels = width * height;

    // Calcul histogramme
    std::vector<int> histogram(256, 0);
    for (size_t y = 0; y < height; ++y)
        for (size_t x = 0; x < width; ++x)
            histogram[input(x, y)]++;

    // Calcul de la fonction de distribution cumulée (CDF)
    std::vector<int> cdf(256, 0);
    cdf[0] = histogram[0];
    for (size_t i = 1; i < 256; ++i)
        cdf[i] = cdf[i - 1] + histogram[i];

    // Trouver le premier pixel non nul dans la CDF (utile si image sombre)
    int cdf_min = *std::find_if(cdf.begin(), cdf.end(), [](int v) { return v > 0; });

    // Égalisation de l'histogramme
    std::vector<uint8_t> equalizedLUT(256);
    for (int i = 0; i < 256; ++i)
        equalizedLUT[i] = static_cast<uint8_t>(std::round(((cdf[i] - cdf_min) * 255.0) / (totalPixels - cdf_min)));

    // Appliquer la LUT
    for (size_t y = 0; y < height; ++y)
        for (size_t x = 0; x < width; ++x)
            output(x, y) = equalizedLUT[input(x, y)];
}

template<typename T>
v1_1::Image<T> generateHistogramImage(const v1_1::Image<T>& input) {
    const int histWidth = 256;
    const int histHeight = 100;
    v1_1::Image<T> histImage(histWidth, histHeight);

    // Calcul histogramme
    std::vector<int> histogram(256, 0);
    size_t width = input.getWidth();
    size_t height = input.getHeigth();

    for (size_t y = 0; y < height; ++y)
        for (size_t x = 0; x < width; ++x)
            histogram[input(x, y)]++;

    // Normaliser pour rentrer dans l’image
    int maxVal = *std::max_element(histogram.begin(), histogram.end());

    for (int x = 0; x < histWidth; ++x) {
        int barHeight = static_cast<int>((histogram[x] / static_cast<float>(maxVal)) * histHeight);
        for (int y = histHeight - 1; y >= histHeight - barHeight; --y) {
            histImage(x, y) = 255;
        }
    }

    return histImage;
}

} // namespace v2_0

#endif
