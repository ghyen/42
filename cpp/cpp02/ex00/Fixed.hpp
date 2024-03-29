#pragma once
#include <iostream>

class Fixed {
private:
	int rawBit;
	static const int fractionalBit = 8;

public:
    int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed &operator=(const Fixed &_old);
    Fixed(const Fixed &_old);
	Fixed( void );
    ~Fixed( void );
};
