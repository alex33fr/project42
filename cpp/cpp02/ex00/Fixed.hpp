#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    public:
        Fixed( void );
        Fixed( const Fixed &other );
        Fixed &operator=(const Fixed &other);
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
                     int _raw;
        static const int _rawBits = 8;
};

#endif