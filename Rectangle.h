#pragma once
#include "Point.h"
#include "Size.h"
class Rectangle {
private:
    Point topleft;
    Size size;
public:
    Rectangle();
    Rectangle(Point topleft, Size size);
    Rectangle(int x, int y , int width , int height);
    Point getTopLeft() const;
    Size getSize() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setTopLeft(const Point& p);
    void setSize(const Size& s);
    void setWidth(int w);
    void setHeight(int h);
    Rectangle operator&(const Rectangle& other) const;
    Rectangle operator|(const Rectangle& other) const;
};