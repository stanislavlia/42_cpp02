#include "Fixed.hpp"

Fixed::Fixed() : _num_value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_num_value = other._num_value;

    //important part
    *this = other;
};

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    this->_num_value = val;
};



Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_num_value = other.getRawBits();
    
    return *this;
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{   
    std::cout << "getRawBits() member function called" << std::endl;
    return (this->_num_value);
};

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits() member function called" << std::endl;
    this->_num_value = raw;
};

// Fixed::Fixed() {
//     std::cout << "Default constructor called" << std::endl;
//     this->_num_value = 0;
// }

// Fixed::Fixed( const Fixed &rhs ) {
//     std::cout << "Copy constructor called" << std::endl;
//     this->setRawBits(rhs.getRawBits());
//     // *this = rhs;
// }

// Fixed& Fixed::operator=( const Fixed &rhs ) {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &rhs)
//         this->_num_value = rhs.getRawBits();
//     return *this;
// }

// Fixed::~Fixed() {
//     std::cout << "Destructor called" << std::endl;
// }

// int Fixed::getRawBits( void ) const {
//     std::cout << "getRawBits member function called" << std::endl;
//     return this->_num_value;
// }

// void    Fixed::setRawBits( int const raw ) {
//     this->_num_value = raw;
// }