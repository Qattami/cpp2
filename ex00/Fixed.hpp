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
                Fixed(const Fixed &Value);
                Fixed& operator=(const Fixed& other);
                ~Fixed();
                int getRawBits( void ) const;
                void setRawBits( int const raw );    
};

#endif