#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point x(float(0), float(0));
    Point y(float(0), float(1));
    Point z(float(1), float(0));


    std::cout << bsp(x, y, z, Point(float(0), float(-0.2))) << std::endl;

    return 0;

}