#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int _num_value;
        static const int _num_frac_bits;
    
    public:
        Fixed();
        Fixed(Fixed& other);
        Fixed& operator=(Fixed& other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif