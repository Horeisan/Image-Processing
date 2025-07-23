#include <iostream>
#include "Image.h"
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"
using namespace std;

int main() {
    // 1. Creează imaginea principală
    Image img = Image::ones(5, 5);  // imagine 5x5 plină cu 255

    // 2. Pune pătrat negru în centru
    img.at(2, 2) = 0;
    img.at(2, 1) = 0;
    img.at(2, 3) = 0;
    img.at(1, 2) = 0;
    img.at(3, 2) = 0;

    // 3. Creează un ROI: 3x3 din colțul (1,1)
    Rectangle roiRect(Point(1, 1), Size(3, 3));
    Image roiImg;

    if (img.getROI(roiImg, roiRect)) {
        cout << "ROI extras cu succes:\n";
        cout << roiImg;

        // 4. Salvează imaginile
        img.save("original.pgm");
        roiImg.save("roi.pgm");
    } else {
        cout << "ROI invalid!\n";
    }

    return 0;
}
