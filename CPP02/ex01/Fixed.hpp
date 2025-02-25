#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed
{
    private:
        int fixedPointNumber;
        static const int fractionalBits;
    public:
        Fixed();
        Fixed(const int);
        Fixed(const float);
        Fixed(const Fixed&);
        Fixed &operator=(const Fixed&);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);