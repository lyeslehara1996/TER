#ifndef TEMPLATE_ADDITION_H
#define TEMPLATE_ADDITION_H

#include <vector>           
#include <iostream>      
#include "./Image.h"
#include "./processing2.h"


namespace v2_0 {
    // Addition de deux images
    template<typename T>
    class Addition : public Processing2<T> {
    public:
    //constructeur 
        Addition(v1_1::Image<T>& input1, v1_1::Image<T>& input2, bool inPlace = false);

        //methode process de la class processing2 (qui est virtuelle) doit etre implementer 
        void Process() override;

        // Méthode statique utilitaire pour addition sans créer d'objet
        static v1_1::Image<T> addition(const v1_1::Image<T>& imageInput1, const v1_1::Image<T>& imageInput2);
    };


}

#endif