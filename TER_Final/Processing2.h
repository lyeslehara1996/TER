#ifndef TEMPLATE_PROCESSING2_H
#define TEMPLATE_PROCESSING2_H

#include <vector>           
#include <iostream>      
#include "./Image.h"



namespace v2_0 {
template<typename T>
class Processing2 {
public: 
//Constructeur
    Processing2(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace = false);
//Methodes 
    virtual void Process() = 0; 

    void Update();

    v1_1::Image<T>& getOutput();

protected:
//attributs
   v1_1::Image<T>& imageInput1_;
    v1_1::Image<T>& imageInput2_;
    v1_1::Image<T> imageOutput_;
    bool inPlace_; 
};


}
#endif