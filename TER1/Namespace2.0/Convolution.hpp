#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP

#include "Processing.hpp"
#include <cmath>
#include <iostream>

namespace v2_0 {

template<typename T>
class Convolution : public Processing2<T> {
public:
    // Implémentation de la méthode Process avec noms d’arguments
    void Process(const v1_1::Image<T>& input, const v1_1::Image<T>& kernelAsImage, bool inPlace) override {
        // Cast du kernel vers float (si on suppose que l’utilisateur passe un Image<float> via un cast)
        const v1_1::Image<float>& kernel = reinterpret_cast<const v1_1::Image<float>&>(kernelAsImage);

        size_t width = input.getWidth();
        size_t height = input.getHeigth();

        int kWidth = kernel.getWidth();
        int kHeight = kernel.getHeigth();
        int kCenterX = kWidth / 2;
        int kCenterY = kHeight / 2;

        v1_1::Image<T>* target = inPlace ? const_cast<v1_1::Image<T>*>(&input) : this->output.get();

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                float sum = 0.0f;

                for (int j = 0; j < kHeight; ++j) {
                    for (int i = 0; i < kWidth; ++i) {
                        int x_img = static_cast<int>(x) + i - kCenterX;
                        int y_img = static_cast<int>(y) + j - kCenterY;

                        if (x_img >= 0 && x_img < static_cast<int>(width) &&
                            y_img >= 0 && y_img < static_cast<int>(height)) {
                            sum += kernel(i, j) * input(x_img, y_img);
                        }
                    }
                }

                int value = static_cast<int>(std::round(sum));
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                (*target)(x, y) = static_cast<T>(value);
            }
        }
    }
};

} // namespace v2_0

#endif
