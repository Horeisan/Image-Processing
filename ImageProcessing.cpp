#include "ImageProcessing.h"
#include <cmath>
void ImageProcessing::process(Image& src, Image& dst) {

}

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

ImageConvolution::ImageConvolution() {
    this->BlueKernel= {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
}
ImageConvolution::ImageConvolution(std::vector<std::vector<int>> BlueKernel) {

        this->BlueKernel = BlueKernel;

}

void ImageConvolution::blur(Image &src, Image &dst, const std::vector<std::vector<int>> &BlueKernel) { //we work only with 3*3 matrices
        Image* padding = new Image(src.width()+2,src.height()+2);
        for (int i = 0; i < src.height();i++) {
            for (int j= 0; j < src.width();j++){
                padding->at(j+1,i+1) = src.at(j,i);
            }
        }
    for (int i = 1; i < padding->height()-1; i++) {
        for (int j= 1; j < padding->width()-1; j++) {
            int final_value = 0;

            for (int krows = 0; krows<3; krows++) {
                for (int kcolumns = 0; kcolumns<3; kcolumns++) {
                    int pi = i + krows -1;
                    int pj = j + kcolumns -1;

                    final_value += padding->at(pj, pi) * BlueKernel[krows][kcolumns];
                }
            }
       final_value/=9.0;
       if (final_value < 0) final_value = 0;
       if (final_value > 255) final_value = 255;

       dst.at(j - 1, i - 1) = static_cast<unsigned char>(final_value);
        }
    }
    delete padding;
}
void ImageConvolution::gaussian_blur(Image &src, Image &dst, const std::vector<std::vector<int>> &BlueKernel) { //we work only with 3*3 matrices
    Image* padding = new Image(src.width()+2,src.height()+2);
    for (int i = 0; i < src.height();i++) {
        for (int j= 0; j < src.width();j++){
            padding->at(j+1,i+1) = src.at(j,i);
        }
    }
    for (int i = 1; i < padding->height()-1; i++) {
        for (int j= 1; j < padding->width()-1; j++) {
            int final_value = 0;

            for (int krows = 0; krows<3; krows++) {
                for (int kcolumns = 0; kcolumns<3; kcolumns++) {
                    int pi = i + krows -1;
                    int pj = j + kcolumns -1;

                    final_value += padding->at(pj, pi) * BlueKernel[krows][kcolumns];
                }
            }
            final_value/=16.0;
            if (final_value < 0) final_value = 0;
            if (final_value > 255) final_value = 255;

            dst.at(j - 1, i - 1) = static_cast<unsigned char>(final_value);
        }
    }
    delete padding;
}
