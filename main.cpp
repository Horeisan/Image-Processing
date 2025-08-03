#include "Image.h"
#include "ImageProcessing.h"
#include <iostream>
using namespace std;
int main() {
    Image src;
    if (src.load("balloons_ascii.pgm") != true) {
        cout<<"The image couldn't be opened";

    }

    Image dst(src.width(), src.height());
    GammaCorrection gammaProcessor(3.0f);
    gammaProcessor.process(src, dst);

    if (dst.save("gamma.pgm") != true) {
        cout<< "Error saving the image!" <<endl;

    }

    Image src2;
    if (src2.load("balloons_ascii.pgm") != true) {
        cout<<"The image couldn't be opened";

    }
    Image dst2(src2.width(),src2.height());
    std::vector<std::vector<int>> my_vector ={
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    ImageConvolution blurr(my_vector);
    blurr.blur(src2, dst2, my_vector);

    if (dst2.save("convulsion.pgm") != true) {
        cout<< "Error saving the image!" <<endl;

    }
    Image src3;
    if (src3.load("balloons_ascii.pgm") != true) {
        cout<<"The image couldn't be opened";

    }
    Image dst3(src3.width(),src3.height());
    std::vector<std::vector<int>> my_vector2 ={
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };

    ImageConvolution blurr2(my_vector);
    blurr2.gaussian_blur(src3, dst3, my_vector2);

    if (dst3.save("gaussian_convulsion.pgm") != true) {
        cout<< "Error saving the image!" <<endl;
    }
    cout<<"Image opened";
    return 0;
}