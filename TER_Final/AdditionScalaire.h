#ifndef TEMPLATE_ADDITIONSCALAIRE_H
#define TEMPLATE_ADDITIONSCALAIRE_H

#include <vector>           
#include <iostream>      
#include "./Image.h"
#include "./processing1.h"

namespace v2_0 {

    // Addition avec un scalaire
    template<typename T>
    class AdditionScalaire : public v2_0::Processing1<T> {
        public:
        AdditionScalaire(v1_1::Image<T>& input, T valScalaire, bool inPlace = false);
        
        void Process() override;
        static v1_1::Image<T> additionScalaire(const v1_1::Image<T>& input, T valScalaire);
        private:
        T valScalaire_;
    };
    
    
}
#endif