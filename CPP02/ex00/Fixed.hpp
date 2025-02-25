#pragma once

#include <iostream>

class Fixed
{
    private:
        int fixedPointNumber;
        static const int fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed&);
        Fixed &operator=(const Fixed&);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};