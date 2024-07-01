#include "Point.hpp"

//collection of possible solutions - https://www.quora.com/How-do-I-check-whether-a-given-point-lies-inside-a-triangle-whose-coordinates-are-given

Point::Point() : _x(0), _y(0)
{
};

Point::Point(const float x, const float y): _x(x), _y(y)
{
};

Point::Point(const Point& other): _x(other.getX()), _y(other.getY())
{
};

Point::~Point()
{
    
};


Fixed Point::getX() const
{
    return (_x);
};

Fixed Point::getY() const
{
    return (_y);
};

