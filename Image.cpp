#include "Image.h"
#include <iostream>
#include <fstream>

Image::Image() { // default constructor
    m_width = 0;
    m_height = 0;
    m_data = nullptr;
}
Image::Image(unsigned int w, unsigned int h) { // parametrized constructor
    this->m_width = w;
    this->m_height = h;
    m_data = new unsigned char *[m_height];
    for (int i = 0; i < m_height; i++)
    {
            m_data[i] = new unsigned char[m_width]{0};
    }

}
Image::Image(const Image &other) {  // copy constructor
    this -> m_width = other.width();
    this -> m_height = other.height();
    m_data = new unsigned char *[m_height];
    for (int i = 0; i < m_height; i++)
    {
        m_data[i] = new unsigned char[m_width]{0};
    }
    for (int i = 0 ; i < m_height; i++)
        {
            for (int j =0 ; j< m_width; j++) {
                m_data[i][j] = other.m_data[i][j];
            }

        }

}

Image& Image::operator=(const Image &other) {   //assignment operator
    if (this != &other) {
        for (int i = 0; i < m_height; i++)
            delete[] m_data[i];
        delete[] m_data;

        m_width = other.m_width;
        m_height = other.m_height;
        m_data = new unsigned char*[m_height];
        for (int i = 0; i < m_height; i++) {
            m_data[i] = new unsigned char[m_width];
            for (int j = 0; j < m_width; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}

Image :: ~Image() {
    // Destructor
    for (int i = 0; i < m_height; i++) {
        delete[] m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;

    m_width = 0;
    m_height = 0;
}

Image Image::operator+(const Image &i) {    // Adding pixels
    Image new_image;
    if (this->m_height == i.m_height && new_image.m_width == this->m_width + i.m_width) {
        m_data = new unsigned char*[m_height];
        for (int k = 0; k < m_height; k++) {
            m_data[k] = new unsigned char[m_width];
            for (int j = 0; j < m_width; j++) {
                m_data[k][j] = i.m_data[k][j]+this->m_data[k][j];
            }
        }

    }
    return new_image;
}
Image Image::operator-(const Image &i) { // Subtracting pixels
    Image new_image;

    if (this->m_height == i.m_height && new_image.m_width == this->m_width + i.m_width) {
        m_data = new unsigned char*[m_height];
        for (int k = 0; k < m_height; k++) {
            m_data[k] = new unsigned char[m_width];
            for (int j = 0; j < m_width; j++) {
                new_image.m_data[k][j] = i.m_data[k][j]-this->m_data[k][j];
            }
        }
    }
    return new_image;
}
Image Image::operator*(double s) {   // Multiplying the pixels with unsigned char value
    Image new_image;

    m_data = new unsigned char*[m_height];
        for (int k = 0; k < m_height; k++) {
            m_data[k] = new unsigned char[m_width];
            for (int j = 0; j < m_width; j++) {
                new_image.m_data[k][j] = static_cast<unsigned char>(this->m_data[k][j] * s);
            }
        }

    return new_image;
}

bool Image::isEmpty() const { // Checking if it's empty
    if ( this->m_width == 0 && m_height == 0 && m_data == nullptr)
        return true;
    return false;

}

std::ostream& operator<<(std::ostream& os, const Image& dt) { //overloading << operator
    os<<"Height = " << dt.m_height <<"Width = "<<dt.m_width<<"\n";
    for ( int i = 0; i < dt.m_height; i++) {
        for ( int j = 0; j < dt.m_width; j++) {
            os<< static_cast<unsigned char>(dt.m_data[i][j]) << " ";
        }
        os<<"\n";
    }
    return os;
}

unsigned int Image::width() const {
    return this->m_width;
}
unsigned int Image:: height() const
{
    return this->m_height;
}
Image Image::zeros(unsigned int w, unsigned int h) {
    return Image(w, h);
}
void Image::fill(unsigned char val) {
    for (unsigned int i = 0; i < m_height; i++)
        for (unsigned int j = 0; j < m_width; j++)
            m_data[i][j] = val;
}

Image Image::ones(unsigned int w, unsigned int h) { //you can create black img
    Image img(w, h);
    img.fill(255);
    return img;
}

void Image::release() {
    if (m_data != nullptr) {
        for (unsigned int i = 0; i < m_height; i++) {
            delete[] m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
    }
    m_width = 0;
    m_height = 0;
}

unsigned char& Image :: at(unsigned int x, unsigned int y) {
    return this->m_data[y][x];
}

unsigned char& Image::at(Point pt) {
    return m_data[pt.getY()][pt.getX()];
}

unsigned char* Image::row(int y) {
    return m_data[y];
}
bool Image::getROI(Image& roiImg, Rectangle roiRect) {
    unsigned int x = roiRect.getTopLeft().getX();
    unsigned int y = roiRect.getTopLeft().getY();
    unsigned int roiWidth = roiRect.getWidth();
    unsigned int roiHeight = roiRect.getHeight();

    if (x + roiWidth > m_width || y + roiHeight > m_height)
        return false;

    roiImg = Image(roiWidth, roiHeight);
    for (unsigned int i = 0; i < roiHeight; i++) {
        for (unsigned int j = 0; j < roiWidth; j++) {
            roiImg.at(j, i) = this->at(x + j, y + i);
        }
    }

    return true;
}
//getting cropped image
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    Rectangle roiRect(Point(x, y), Size(width, height));
    return getROI(roiImg, roiRect);
}

std::istream& operator>>(std::istream& is, Image& dt) {
    std::string magic;
    is >> magic;
    if (magic != "P2") {
        is.setstate(std::ios::failbit);
        return is;
    }

    unsigned int width, height, maxVal;
    is >> width >> height >> maxVal;

    dt.release();

    dt.m_width = width;
    dt.m_height = height;
    dt.m_data = new unsigned char*[height];
    for (unsigned int i = 0; i < height; i++)
        dt.m_data[i] = new unsigned char[width];

    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            int val;
            is >>val;
            dt.m_data[i][j] = static_cast<unsigned char>(val);
        }
    }

    return is;
}

bool Image::load(std::string imagePath) {
    std::ifstream is(imagePath);
    if (!is.is_open())
        return false;

    std::string magic;
    is >> magic;
    if (magic != "P2")
        return false;

    unsigned int width, height, maxVal;
    is >> width >> height >> maxVal;

    release();

    m_width = width;
    m_height = height;
    m_data = new unsigned char*[m_height];
    for (unsigned int i = 0; i < m_height; i++)
        m_data[i] = new unsigned char[m_width];

    for (unsigned int i = 0; i < m_height; i++) {
        for (unsigned int j = 0; j < m_width; j++) {
             int val;
             is >> val;
             m_data[i][j] = static_cast<unsigned char>(val);
        }
    }

    return true;
}

bool Image::save(std::string imagePath) const {
    std::ofstream os(imagePath);
    if (!os.is_open())
        return false;

    os <<"P2\n";
    os << m_width << " " << m_height << "\n";
    os <<"255\n";

    for (unsigned int i = 0; i < m_height; i++) {
        for (unsigned int j = 0; j < m_width; j++) {
            os << static_cast<int>(m_data[i][j])<< " ";
        }
        os <<"\n";
    }

    return true;
}



