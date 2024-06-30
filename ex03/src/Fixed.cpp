#include "Fixed.hpp"

Fixed::Fixed() : _num_value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
};

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;

    //shift value to left by 8 bits
    this->_num_value = (val << this->_num_frac_bits);

};

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;

    //multiply arg by 2 ** 8 and round it to nearest int
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
    //move rawbits value to the right by numfracbits
    return (this->_num_value >> this->_num_frac_bits); 
};


float Fixed::toFloat() const 
{
    //cast rawbits value and 2 ** 8 to float and divide to get a float num
    return static_cast<float>(this->_num_value) / static_cast<float>(1 << this->_num_frac_bits);
};


//==============ARITHMETIC OPERATORS====================
Fixed Fixed::operator+(const Fixed& other)
{
    float curr_float = this->toFloat();
    float other_float = other.toFloat();

    Fixed result(curr_float + other_float);

    return result;
}

Fixed Fixed::operator-(const Fixed& other)
{
    float curr_float = this->toFloat();
    float other_float = other.toFloat();

    Fixed result(curr_float - other_float);

    return result;
}

Fixed Fixed::operator*(const Fixed& other)
{
    float curr_float = this->toFloat();
    float other_float = other.toFloat();

    Fixed result(curr_float * other_float);

    return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
    float curr_float = this->toFloat();
    float other_float = other.toFloat();

    Fixed result(curr_float / other_float);

    return result;
}

//==============INCREMENTAL OPERATORS====================
Fixed Fixed::operator++()
{
    ++(this->_num_value);
    return *this;
};

Fixed Fixed::operator--()
{
    --(this->_num_value);
    return *this;
};

Fixed Fixed::operator++(int)
{
    ++(this->_num_value);
    return *this;
};

Fixed Fixed::operator--(int)
{
    --(this->_num_value);
    return *this;
};

//=============COMPARISON OPERATIONS==============
bool Fixed::operator==(const Fixed& other)
{
    return (bool)(this->_num_value == other.getRawBits());
};

bool Fixed::operator!=(const Fixed& other)
{
    return (bool)(this->_num_value != other.getRawBits());
};

bool Fixed::operator>(const Fixed& other)
{
    return (bool)(this->_num_value > other.getRawBits());
};

bool Fixed::operator<(const Fixed& other)
{
    return (bool)(this->_num_value < other.getRawBits());
};

bool Fixed::operator>=(const Fixed& other)
{
    return (bool)(this->_num_value >= other.getRawBits());
};

bool Fixed::operator<=(const Fixed& other)
{
    return (bool)(this->_num_value <= other.getRawBits());
};


//==============MIN & MAX funcs=====================
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1.getRawBits() >= num2.getRawBits())
        return num1;
    return num2;
};

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if (num1.getRawBits() >= num2.getRawBits())
        return num1;
    return num2;
};

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1.getRawBits() <= num2.getRawBits())
        return num1;
    return num2;
};

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1.getRawBits() <= num2.getRawBits())
        return num1;
    return num2;
};