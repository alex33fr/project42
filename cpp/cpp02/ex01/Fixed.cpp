#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed &other ) : _raw(other._raw)
{
    std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}
void Fixed::setRawBits( int const raw ){ this->_raw = raw; }

Fixed &Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &other)
        return (*this);
    this->_raw = other._raw;
    return (*this);
}

Fixed::Fixed( const int n ) : _raw(n << _rawBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _raw(roundf(f * (1 << _rawBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    float   raw = static_cast<float>(_raw);
    float   scale = static_cast<float>(1 << _rawBits);
    float   result = raw / scale;

    return (result);
}

int Fixed::toInt( void ) const
{
    int result = _raw >> _rawBits;

    return (result);
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed )
{
    out << fixed.toFloat();
    return ( out );
}
