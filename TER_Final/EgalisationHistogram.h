#ifndef TEMPLATE_EGALISATIONHISTOGRAM_H
#define TEMPLATE_EGALISATIONHISTOGRAM_H

#include <vector>           
#include <iostream>      
#include "./Image.h"
#include "./processing1.h"


namespace v2_0{
template<typename T>
class egalisationHistogram : public v2_0::Processing1<T> {   
public:
    egalisationHistogram(v1_1::Image<T>& input, bool inPlace = false);

    void Process() override;

    // Génère une image d'histogramme depuis l'entrée originale
    v1_1::Image<uint8_t> getHistogramImage();


    // 5. Recalculer histogramme après égalisation
   void compterHistogram(const v1_1::Image<T>& image);
private:
    std::vector<int> histogramImage_;  // pour getHistogramImage()
};
}
#endif