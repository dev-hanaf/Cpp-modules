#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const Point&);
        Point(float const x, float const y);
        Point &operator=(const Point &);
        ~Point();

        Fixed const getX() const;
        Fixed const getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);