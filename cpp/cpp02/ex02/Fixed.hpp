#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed( void );
        Fixed( const Fixed &other );
        Fixed &operator=(const Fixed &other);
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed ( const int n );
        Fixed ( const float f );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>( const Fixed &other ) const;
        bool operator<( const Fixed &other ) const;
        bool operator>=( const Fixed &other ) const;
        bool operator<=( const Fixed &other ) const;
        bool operator==( const Fixed &other ) const;
        bool operator!=( const Fixed &other ) const;

        Fixed operator+( const Fixed &other ) const;
        Fixed operator-( const Fixed &other ) const;
        Fixed operator*( const Fixed &other ) const;
        Fixed operator/( const Fixed &other ) const;

        Fixed &operator++( void );
        Fixed  operator++( int );
        Fixed &operator--( void );
        Fixed  operator--( int );

        static Fixed       &min( Fixed &a, Fixed &b );
        static const Fixed &min( const Fixed &a, const Fixed &b );
        static Fixed       &max( Fixed &a, Fixed &b );
        static const Fixed &max( const Fixed &a, const Fixed &b );

    private:
                     int _raw;
        static const int _rawBits = 8;
};
std::ostream &operator<<( std::ostream &out, const Fixed &fixed );
#endif