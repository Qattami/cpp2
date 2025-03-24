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
                ~Fixed();
                int getRawBits( void ) const;
                void setRawBits( int const raw ); 
                float toFloat( void ) const; 
                int toInt( void ) const;  
};

std::ostream & operator<<( std::ostream & o, const Fixed& f);

#endif