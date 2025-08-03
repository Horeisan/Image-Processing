#pragma once
#include "Image.h"
#include <vector>

class ImageProcessing {
public:
    virtual void process( Image& src, Image& dst);
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

class ImageConvolution : public ImageProcessing {
private:
    std::vector<std::vector<int>> BlueKernel;
public:
    ImageConvolution();
    ImageConvolution(std::vector<std::vector<int>> BlueKernel);
    void blur( Image& src, Image& dst, const std::vector<std::vector<int>> &BlueKernel);
    void gaussian_blur( Image& src, Image& dst, const std::vector<std::vector<int>> &BlueKernel);



};