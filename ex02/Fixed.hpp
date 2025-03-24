#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
# include <iomanip>



class Fixed 
{
    private :
                int value;
                static const int FractionalBits = 8;
            
    public :
                Fixed();
                Fixed(const int _integer);
                Fixed(const float number);
                Fixed(const Fixed &Value);
                Fixed& operator=(const Fixed& other);
                bool operator>(const Fixed& other) const;
                bool operator<(const Fixed& other) const;
                bool operator>=(const Fixed& other) const;
                bool operator<=(const Fixed& other) const;
                bool operator==(const Fixed& other) const;
                bool operator!=(const Fixed& other) const;
                Fixed operator+(const Fixed& other);
                Fixed operator-(const Fixed& other);
                Fixed operator*(const Fixed& other);
                Fixed operator/(const Fixed& other);
                Fixed operator++(int);
                Fixed operator++();
                Fixed operator--(int);
                Fixed operator--();
                ~Fixed();
                int getRawBits( void ) const;
                void setRawBits( int const raw ); 
                float toFloat( void ) const; 
                int toInt( void ) const;
                static Fixed& min(Fixed& r1, Fixed& r2);
                static const Fixed& min(const Fixed& n1, const Fixed& n2);
                static Fixed& max(Fixed& r1, Fixed& r2);
                static const Fixed& max(const Fixed& n1, const Fixed& n2);  
};

std::ostream & operator<<( std::ostream & o, const Fixed& f);

#endif