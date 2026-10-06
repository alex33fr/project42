#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed &other ) : _raw(other._raw)
{
    std::cout << "Copy constructor called" << std::endl;
};
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