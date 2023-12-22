#pragma once
#include <iostream>

class Fixed {
private:
	int rawBit;
	static const int fractionalBit = 8;

public:
	float toFloat( void ) const;
	int toInt( void ) const;
    int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed &operator=(const Fixed &_old);
    Fixed(const Fixed &_old);
	Fixed( void );
	Fixed( const int num );
	Fixed( const float num );
    ~Fixed( void );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
