#include "Fixed.hpp"

int main( void ) {
Fixed a(10);
Fixed b( a );
Fixed c;
Fixed d((float) 1.8);
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.toInt() << std::endl;
std::cout << d.toFloat() << std::endl;

return 0;
}

// int main()
// {
//     int a = 100;

//     //BYteshifts examples
//     std::cout << (a >> 4) << std::endl;
//     std::cout << (a << 2) << std::endl;
//     std::cout << (a >> 1) << std::endl;
// }

