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
    
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& num);


#endif
