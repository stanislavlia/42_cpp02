#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
        //Need to overload <<        

        
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
};

#endif