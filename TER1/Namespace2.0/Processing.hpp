#ifndef Processing_HPP
#define Processing_HPP

#include "../Namespace V1.1/Image.hpp"
#include "../Namespace V1.1/ImageRGB.hpp"
#include <memory>

namespace v2_0 {
template<typename T>
class Processing1 {
public:
virtual void Process(const Image<T>& input, bool inPlace) = 0;

// Méthode qui déclenche le traitement
void Update(const Image<T>& input, bool inPlace = false) ;

// Accès à l'image de sortie
const Image<T>& getOutput() const ;


protected:
std::unique_ptr<Image<T>> output;

};

template<typename T>
class Processing2 {
public:
    // Méthode virtuelle pure à implémenter par les classes dérivées
    virtual void Process(const Image<T>& input1, const Image<T>& input2, bool inPlace) = 0;

    // Méthode qui déclenche le traitement
    void Update(const Image<T>& input1, const Image<T>& input2, bool inPlace = false) ;
    // Accès à l'image de sortie
    const Image<T>& getOutput() const ;

protected:
    std::unique_ptr<Image<T>> output;
};


template<typename T>
    void Processing1<T>::Update(const v1_1::Image<T>& input, bool inPlace) {
        if (!inPlace) {
            output = std::make_unique<v1_1::Image<T>>(input.getWidth(), input.getHeigth());
        }
        Process(input, inPlace);
    }
    
    template<typename T>
    const v1_1::Image<T>& Processing1<T>::getOutput() const {
        return *output;
    }
    
    
    template<typename T>
    void Processing2<T>::Update(const v1_1::Image<T>& input1, const v1_1::Image<T>& input2, bool inPlace) {
        if (!inPlace) {
            output = std::make_unique<v1_1::Image<T>>(input1.getWidth(), input1.getHeigth());
        }
        Process(input1, input2, inPlace);
    }
    
    template<typename T>
    const v1_1::Image<T>& Processing2<T>::getOutput() const {
        return *output;
    }
}

#endif