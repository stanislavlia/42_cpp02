#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point x(float(0), float(0));
    Point y(float(0), float(10));
    Point z(float(10), float(0));


    
    std::cout <<"Expected 0; Given " << bsp(x, y, z, Point(float(0), float(-1))) << std::endl;
    std::cout <<"Expected 1; Given " << bsp(x, y, z, Point(float(1), float(0.5))) << std::endl;
    std::cout <<"Expected 1; Given " << bsp(x, y, z, Point(float(2), float(2))) << std::endl;
    std::cout << "Expected 0; Given " <<  bsp(x, y, z, Point(float(2), float(-2))) << std::endl;
    std::cout << "Expected 0; Given "  <<  bsp(x, y, z, Point(float(10), float(10))) << std::endl;

    std::cout << "Expected 0; Given "<< bsp(x, y, z, Point(float(0), float(0))) << std::endl;
    std::cout << "Expected 0; Given "  <<  bsp(x, y, z, Point(float(8), float(0))) << std::endl;
    std::cout << "Expected 0; Given "<< bsp(x, y, z, Point(float(0), float(9.9))) << std::endl;
    std::cout << "Expected 1; Given "<< bsp(x, y, z, Point(float(0.1), float(3.3))) << std::endl;
    
    return 0;

}