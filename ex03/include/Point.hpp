#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();
        Point& operator=(const Point& other);
        Fixed getX() const;
        Fixed getY() const;
};


float compute_distance(Point p1, Point p2);
bool bsp( Point const a, Point const b, Point const c, Point const point); 


#endif