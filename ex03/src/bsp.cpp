#include "Point.hpp"

Fixed abs(const Fixed val)
{
    if (val.toFloat() < 0)
    {  
        return Fixed(val.toFloat() * -1);
    }
    return val;
};


//Using Heron's formula to find area
Fixed triangle_area(Point const a, Point const b, Point const c)
{
    return abs( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
};


bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed   abcArea = abs(triangle_area( a, b, c ));
    Fixed   pabArea = abs(triangle_area( point, a, b ));
    Fixed   pbcArea = abs(triangle_area( point, b, c ));
    Fixed   pcaArea = abs(triangle_area( point, c, a ));


    if (pabArea == 0 || pcaArea == 0 || pbcArea == 0)//it means that we are on the edge
        return false;

    //compare composed areas with original one
    return  ( abcArea == pabArea + pbcArea + pcaArea );
}