#include "Fixed.hpp"

Fixed::Fixed() : _num_value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;

    //important part
    *this = other;
};

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;

    //shift value to lefy by 8 bits
    this->_num_value = (val << this->_num_frac_bits);

};

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;

    //shift value to left by 8 bits and round
    this->_num_value = roundf(val * (1 << this->_num_frac_bits));

};



Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_num_value = other.getRawBits();
    
    return *this;
};

std::ostream& operator<<(std::ostream& o, const Fixed& num)
{
    o << num.toFloat();
    return o;
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

int Fixed::toInt() const
{   
    return (this->_num_value >> this->_num_frac_bits); 
};


float Fixed::toFloat() const 
{
    return static_cast<float>(this->_num_value) 
                                / static_cast<float>(1 << this->_num_frac_bits);
};
