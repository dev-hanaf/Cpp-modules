#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointNumber = num * (1 << this->fractionalBits);
}


Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointNumber = roundf(num * (1 << this->fractionalBits));

}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->fixedPointNumber = obj.fixedPointNumber;
    *this = obj;
}


Fixed & Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->fixedPointNumber = obj.fixedPointNumber;
    }
    return *this;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointNumber;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointNumber = raw;
}


float Fixed::toFloat() const
{
    return (float)(this->fixedPointNumber) / (1 << this->fractionalBits);
}

int Fixed::toInt() const
{
    return this->fixedPointNumber / (1 << this->fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}
