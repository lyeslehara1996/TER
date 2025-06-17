#ifndef TEMPLATE_CONVOLUTION_H
#define TEMPLATE_CONVOLUTION_H

#include <vector>           
#include <iostream>      
#include "./Image.h"
#include "./processing1.h"
namespace v2_0 {

    template<typename T>
    class Convolution : public v2_0::Processing1<T> {
        public:
        Convolution( v1_1::Image<T>& image, const v1_1::Image<float>& noyau, bool inPlace = false);
        
        void Process() override;
        
        static v1_1::Image<float> creerMoyenneur(int taille);
        static v1_1::Image<float> creerGaussien(int taille, float sigma);
        static v1_1::Image<float> creerExponentiel(int taille, float lambda);

        
        private:
        v1_1::Image<float> noyau_;
    };
}
#endif