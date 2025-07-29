#include "Image.h"
#include "ImageProcessing.h"
#include <iostream>
using namespace std;
int main() {
    Image src;
    if (src.load("balloons_ascii.pgm") != true) {
        cout<<"The image could'n be opened";

    }

    Image dst(src.width(), src.height());
    GammaCorrection gammaProcessor(3.0f);
    gammaProcessor.process(src, dst);

    if (dst.save("gamma.pgm") != true) {
        cout<< "Error saving the image!" <<endl;

    }

    return 0;
}