#include "Size.h"
Size::Size() {
    this->s_height = 0;
    this->s_width = 0;
}
Size::Size(unsigned int s_width, unsigned int s_height) {
    this->s_width = s_width;
    this->s_height = s_height;
}
unsigned int Size::get_height() const {
    return this->s_height;
}
unsigned int Size::get_width() const {
    return this->s_width;
}
void Size::set_height(unsigned int s_height) {
    this->s_height = s_height;
}
void Size::set_width(unsigned int s_width) {
    this->s_width = s_width;
}
bool Size::operator>(const Size &other) const {
    return this->s_width*this->s_height > other.s_width*other.s_height;
}
bool Size::operator==(const Size &other) const {
    return this->s_width * this->s_height == other.s_width * other.s_height;
}

bool Size::operator<(const Size &other) const {
    return this->s_width * this->s_height < other.s_width * other.s_height;
}

bool Size::operator<=(const Size &other) const {
    return this->s_width * this->s_height <= other.s_width * other.s_height;
}

bool Size::operator>=(const Size &other) const {
    return this->s_width * this->s_height >= other.s_width * other.s_height;
}
