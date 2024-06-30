#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _num_value;
        static const int _num_frac_bits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(const Fixed& other);

        Fixed& operator=(const Fixed& other);
        //we allow member func from another class to acess out data
        friend std::ostream& operator<<(std::ostream& o, const Fixed& num);


        //arithmetic ops
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        //Increment & Decrement ops
        Fixed operator++();//for prefix
        Fixed operator--();
        Fixed operator++(int);//for postfix
        Fixed operator--(int);


        //Comparison OPS
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);
        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);

        //min and max (static - because we want to acess the funcs outside of object)
        static Fixed& min(Fixed& num1, Fixed& num2);
        static Fixed& max(Fixed& num1, Fixed& num2);
        static const Fixed& min(const Fixed& num1, const Fixed& num2);
        static const Fixed& max(const Fixed& num1, const Fixed& num2);
        
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
};

#endif