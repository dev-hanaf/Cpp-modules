#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed
{
    private:
        int fixedPointNumber;
        static const int fractionalBits = 8;
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


        bool operator==(const Fixed &obj);
        bool operator!=(const Fixed &obj);
        bool operator>=(const Fixed &obj);
        bool operator<=(const Fixed &obj);
        bool operator>(const Fixed &obj);
        bool operator<(const Fixed &obj);

        Fixed operator*(const Fixed &obj);
        Fixed operator/(const Fixed &obj);
        Fixed operator+(const Fixed &obj);
        Fixed operator-(const Fixed &obj);

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed&		min(Fixed& x, Fixed& y);
		static Fixed&		max(Fixed& x, Fixed& y);
		static const Fixed&	min(const Fixed& x, const Fixed& y);
		static const Fixed&	max(const Fixed& x, const Fixed& y);

};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);