#include "Fixed.hpp"

Fixed::Fixed() : _num_value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) : _num_value(other.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_num_value = other._num_value;
    
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