#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0){}

Fixed::Fixed(const int num)
{
    this->fixedPointNumber = num * (1 << this->fractionalBits);
}


Fixed::Fixed(const float num)
{

    this->fixedPointNumber = roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}


Fixed & Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
    {
        this->fixedPointNumber = obj.fixedPointNumber;
    }
    return *this;
}


Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointNumber;
}

void Fixed::setRawBits(const int raw)
{
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




bool Fixed::operator==(const Fixed &obj)
{
    return (getRawBits() == obj.getRawBits());
}
bool Fixed::operator!=(const Fixed &obj)
{
    return (getRawBits() != obj.getRawBits());

}
bool Fixed::operator>=(const Fixed &obj)
{
    return (getRawBits() >= obj.getRawBits());

}
bool Fixed::operator<=(const Fixed &obj)
{
    return (getRawBits() <= obj.getRawBits());
}
bool Fixed::operator>(const Fixed &obj)
{
    return (getRawBits() > obj.getRawBits());
}
bool Fixed::operator<(const Fixed &obj)
{
    return (getRawBits() < obj.getRawBits());
}


Fixed	Fixed::operator+(const Fixed&obj)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + obj.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed&obj)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - obj.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed&obj)
{
	Fixed	result;
	result.setRawBits((this->fixedPointNumber* obj.fixedPointNumber) / (1<<fractionalBits));   
	return (result);
}

Fixed	Fixed::operator/(const Fixed&obj)
{
	if (obj.getRawBits() == 0)
		return Fixed();
    float i = (float)this->fixedPointNumber / (float)obj.fixedPointNumber;
    this->fixedPointNumber = i * 256;
	return (*this);
}

Fixed &Fixed::operator++()
{
    this->fixedPointNumber++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->fixedPointNumber++;
    return old;
}

Fixed &Fixed::operator--()
{
    this->fixedPointNumber--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->fixedPointNumber--;
    return old;
}


Fixed&		Fixed::min(Fixed& x, Fixed& y)
{
    if (x.getRawBits() < y.getRawBits())
        return x;
    return  y;
}

const Fixed&		Fixed::min(const Fixed& x, const Fixed& y)
{
    if (x.getRawBits() < y.getRawBits())
        return x;
    return  y;
}

Fixed&		Fixed::max(Fixed& x, Fixed& y)
{
    if (x.getRawBits() > y.getRawBits())
        return x;
    return  y;
}

const Fixed&		Fixed::max(const Fixed& x, const Fixed& y)
{
    if (x.getRawBits() > y.getRawBits())
        return x;
    return  y;
}