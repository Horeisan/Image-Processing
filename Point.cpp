#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
int Point::getX() const {
    return this->x;
}
int Point::getY() const {
    return this->y;
}
void Point::setX(int x) {
    this->x = x;
}
void Point::setY(int y) {
    this->y = y;
}
bool Point::operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return this->x != other.x || this->y != other.y;
}
Point Point::operator+(const Point &other)  {
    this->x = this->x+other.x;
    this->y = this->y+other.y;
    return *this;
}

Point Point::operator-(const Point &other)  {
    this->x = this->x-other.x;
    this->y = this->y-other.y;
    return *this;
}


