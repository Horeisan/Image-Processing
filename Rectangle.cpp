#include "Rectangle.h"
#include <cmath>
using namespace std;

Rectangle::Rectangle() {
    this->topleft.setX(0);
    this->topleft.setY(0);
    this->size.set_height(0);
    this->size.set_width(0);
}
Rectangle::Rectangle(Point topleft, Size size) {
    this->topleft = topleft;
    this->size = size;
}
Rectangle::Rectangle(int x, int y, int width, int height) {
    this->topleft.setX(x);
    this->topleft.setY(y);
    this->size.set_height(width);
    this->size.set_width(height);
}


Point Rectangle::getTopLeft() const {
    return this->topleft;
}

Size Rectangle::getSize() const {
    return this->size;
}

void Rectangle::setTopLeft(const Point& p) {
    this->topleft = p;
}

void Rectangle::setSize(const Size& s) {
    this->size = s;
}

void Rectangle::setWidth(int w) {
    this->size.set_width(w);
}

void Rectangle::setHeight(int h) {
    this->size.set_height(h);
}
unsigned int Rectangle:: getWidth() const {
    return this->size.get_width();
}
unsigned int Rectangle:: getHeight() const
{
    return this->size.get_height();

}

Rectangle Rectangle::operator&(const Rectangle& other) const {
    int x1 = max(this->topleft.getX(), other.topleft.getX());
    int y1 = max(this->topleft.getY(), other.topleft.getY());
    int x2 = min(this->topleft.getX() + this->getWidth(), other.topleft.getX() + other.getWidth());
    int y2 = min(this->topleft.getY() + this->getHeight(), other.topleft.getY() + other.getHeight());

    if (x2 <= x1 || y2 <= y1) {
        
        return Rectangle(x1, y1, 0, 0);
    }
    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}

Rectangle Rectangle::operator|(const Rectangle& other) const {
    int x1 = min(this->topleft.getX(), other.topleft.getX());
    int y1 = min(this->topleft.getY(), other.topleft.getY());
    int x2 = max(this->topleft.getX() + this->getWidth(), other.topleft.getX() + other.getWidth());
    int y2 = max(this->topleft.getY() + this->getHeight(), other.topleft.getY() + other.getHeight());

    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}


