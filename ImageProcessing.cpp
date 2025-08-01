#include "ImageProcessing.h"
#include <cmath>

BrightnessContrast::BrightnessContrast() {
    this->alpha = 1;
    this->beta = 0;
}
BrightnessContrast::BrightnessContrast(float alpha, float beta) {
    this->alpha = alpha;
    this->beta = beta;
}

void BrightnessContrast::process(Image &src, Image &dst) {   // we applying the formula for the brightness
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
GammaCorrection::GammaCorrection() {
    this ->gamma = 1;
}
GammaCorrection::GammaCorrection(float gamma) {
    this -> gamma = gamma;
}
void GammaCorrection:: process( Image &src, Image &dst) {           // We applying the formula the formula for GammaCorrection
    if (src.height() == dst.height() && src.width() == dst.width()) {
        for (int i = 0; i < src.height(); i++) {
            for (int j = 0 ; j < src.width(); j++) {
                float value = static_cast<float>(src.at(j,i)) /255.f;
                float converted_to_float = pow(value,this->gamma);
                float result = static_cast<int>(converted_to_float* 255.f);
                if (result < 0) result = 0;
                else if (result > 255) result = 255;
                dst.at(j, i) = static_cast<unsigned char>(result);
            }
        }
    }
}

