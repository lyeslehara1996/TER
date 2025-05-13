#ifndef Addition_HPP
#define Addition_HPP

#include "Processing.hpp"

namespace v2_0 {

template<typename T>
class AdditionScalar : public Processing1<T> {
public:
    AdditionScalar(T scalar) : _scalar(scalar) {}

    void Process(const Image<T>& input, bool inPlace) override {
        Image<T>* target = inPlace ? const_cast<Image<T>*>(&input) : this->output.get();
        size_t width = input.getWidth();
        size_t height = input.getHeigth();

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                (*target)(x, y) = input(x, y) + _scalar;
            }
        }
    }

private:
    T _scalar;
};

template<typename T>
void additionScalar(const Image<T>& input, Image<T>& output, T scalar) {
    size_t width = input.getWidth();
    size_t height = input.getHeigth();

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            output(x, y) = input(x, y) + scalar;
        }
    }
}

template<typename T>
class Addition : public Processing2<T> {
public:
    void Process(const Image<T>& input1, const Image<T>& input2, bool inPlace) override {
        Image<T>* target = inPlace ? const_cast<Image<T>*>(&input1) : this->output.get();
        size_t width = input1.getWidth();
        size_t height = input1.getHeigth();

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                (*target)(x, y) = input1(x, y) + input2(x, y);
            }
        }
    }
};

template<typename T>
void addition(const Image<T>& input1, const Image<T>& input2, Image<T>& output) {
    size_t width = input1.getWidth();
    size_t height = input1.getHeigth();

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            output(x, y) = input1(x, y) + input2(x, y);
        }
    }
}

}  // namespace v2_0

#endif