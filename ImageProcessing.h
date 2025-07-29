#pragma once
#include "Image.h"

class ImageProcessing {
public:
    virtual void process( Image& src, Image& dst) = 0;
    virtual ~ImageProcessing() = default;
};

class BrightnessContrast : public ImageProcessing {
private:
    float alpha;
    float beta;
public:
    BrightnessContrast();
    BrightnessContrast(float alpha, float beta);
    void process( Image &src, Image &dst) override;
};
class GammaCorrection : public ImageProcessing {
private:
    float gamma;
public:
    GammaCorrection();
    GammaCorrection(float gamma);
    void process( Image &src, Image &dst) override;
};
