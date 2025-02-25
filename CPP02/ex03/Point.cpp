#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0){}

Point::Point(float const x, float const y) : x(x), y(y){}


Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point & Point::operator=(const Point &obj)
{
    if (this != &obj)
    {
        new (this) Point(obj.getX().toFloat(), obj.getY().toFloat());
    }
    
    return *this;
}

Fixed const Point::getX() const
{
    return  this->x;
}

Fixed const Point::getY() const
{
    return  this->y;
}

Point::~Point(){}
