#ifndef KERNELS_HPP
#define KERNELS_HPP

#include "../Namespace V1.1/Image.hpp"
#include <cmath>

namespace v2_0 {

inline v1_1::Image<float> createMeanKernel(int size = 3) {
    v1_1::Image<float> kernel(size, size);
    float value = 1.0f / (size * size);
    for (int y = 0; y < size; ++y)
        for (int x = 0; x < size; ++x)
            kernel(x, y) = value;
    return kernel;
}

inline v1_1::Image<float> createGaussianKernel(int size = 3, float sigma = 1.0f) {
    v1_1::Image<float> kernel(size, size);
    int center = size / 2;
    float sum = 0.0f;

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            int dx = x - center;
            int dy = y - center;
            float value = std::exp(-(dx * dx + dy * dy) / (2 * sigma * sigma));
            kernel(x, y) = value;
            sum += value;
        }
    }

    for (int y = 0; y < size; ++y)
        for (int x = 0; x < size; ++x)
            kernel(x, y) /= sum;

    return kernel;
}

inline v1_1::Image<float> createExponentialKernel(int size = 3) {
    v1_1::Image<float> kernel(size, size);
    int center = size / 2;
    float sum = 0.0f;

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            int dx = x - center;
            int dy = y - center;
            float value = std::exp(-std::sqrt(dx * dx + dy * dy));
            kernel(x, y) = value;
            sum += value;
        }
    }

    for (int y = 0; y < size; ++y)
        for (int x = 0; x < size; ++x)
            kernel(x, y) /= sum;

    return kernel;
}

} // namespace v2_0

#endif
