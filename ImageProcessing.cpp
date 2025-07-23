#include "ImageProcessing.h"
BrightnessConstrast::BrightnessConstrast() {
    this->alpha = 1;
    this->beta = 0;
}
BrightnessConstrast::BrightnessConstrast(float alpha, float beta) {
    this->alpha = alpha;
    this->beta = beta;
}

void BrightnessConstrast::process(Image &src, Image &dst) {
    if (src.height() == dst.height() && src.width() == dst.width()) {
        unsigned char pixel;
        for (int i = 0; i < src.height(); i++) {
             for (int j = 0 ; j < src.width(); j++) {
                pixel = src.at(j,i);
                 float value = alpha * pixel + beta;
                 if (value < 0) value = 0;
                 if (value > 255) value = 255;
                 dst.at(j, i) = static_cast<unsigned char>(value);

             }

        }
    }


}
