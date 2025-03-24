#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &Value)
{
    value = Value.value;
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        value = other.value;
    }
    return *this;
}

void Fixed :: setRawBits( int const raw )
{
    value = raw;
}
int Fixed :: getRawBits( void ) const
{
     std::cout << "getRawBits member function called" << std::endl;
     return value;
}

Fixed ::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed :: Fixed(const int _integer)
{
    std::cout << "Int constructor called" << std::endl;
    value = _integer * (1 << FractionalBits);
}

Fixed:: Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    value = number * (1 << FractionalBits);
}
float Fixed:: toFloat( void ) const
{
    return((float)value / (1 << FractionalBits));
}

int Fixed:: toInt( void ) const
{
    return(value >>FractionalBits);

}

std::ostream & operator<<( std::ostream & o, const Fixed& f) {
    o << f.toFloat();
    return o;
}

bool Fixed ::operator<(const Fixed& other) const
{
    return(value < other.value);
}

bool Fixed ::operator>(const Fixed& other) const
{
    return(value > other.value);
}

bool Fixed ::operator>=(const Fixed& other) const
{
    return(value >= other.value);
}

bool Fixed ::operator<=(const Fixed& other) const
{
    return(value <= other.value);
}

bool Fixed ::operator==(const Fixed& other) const
{
    return(value == other.value);
}

bool Fixed ::operator!=(const Fixed& other) const
{
    return(value != other.value);
}

Fixed Fixed:: operator+(const Fixed& other)
{
    return Fixed(this->value + other.value);
}

Fixed Fixed:: operator-(const Fixed& other)
{
    return Fixed(this->value - other.value);
}

Fixed Fixed::operator*(const Fixed& other) {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) {
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::min(Fixed& r1, Fixed& r2)
{
    return((r1 < r2) ? r1 : r2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
    return((n1 < n2) ? n1 : n2);
}

Fixed& Fixed::max(Fixed& r1, Fixed& r2)
{
    return((r1 > r2) ? r1 : r2);
}

const Fixed& Fixed::max(const Fixed& n1,const Fixed& n2)
{
    return((n1 > n2) ? n1 : n2);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    value++;
    return(*this);
}

Fixed& Fixed::operator++()
{
    ++value;
    return(*this);
}