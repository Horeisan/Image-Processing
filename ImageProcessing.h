#pragma once
#include "Image.h"

class ImageProcessing {
public:
    virtual void process( Image& src, Image& dst) = 0;
    virtual ~ImageProcessing();
};

class BrightnessConstrast : public ImageProcessing {
private:
    float alpha;
    float beta;
public:
    BrightnessConstrast();
    BrightnessConstrast(float alpha, float beta);
    void process( Image &src, Image &dst) override;
};