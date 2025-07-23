#pragma once

class Size {
private:
    unsigned int s_width;
    unsigned int s_height;
public:
    Size();
    Size(unsigned int s_width, unsigned int s_height);
    void set_width(unsigned int s_width);
    void set_height(unsigned int s_height);
    unsigned int get_width() const;
    unsigned int get_height() const;
    bool operator==(const Size& other) const;
    bool operator<(const Size& other) const;
    bool operator<=(const Size& other) const;
    bool operator>(const Size& other) const;
    bool operator>=(const Size& other) const;

};
