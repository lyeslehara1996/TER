#ifndef TEMPLATE_PROCESSING1_H
#define TEMPLATE_PROCESSING1_H

#include <vector>           
#include <iostream>      
#include "./Image.h"


namespace v2_0 {

    template<typename T>
    class Processing1 {
public:
Processing1(v1_1::Image<T>& input, bool inPlace = false);

virtual void Process() = 0; 

void Update();

v1_1::Image<T>& getOutput();

protected:
v1_1::Image<T>& imageInput_;
v1_1::Image<T> imageOutput_;
bool inPlace_;  
};

}
#endif