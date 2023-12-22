# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int val;
	static const int fractionalBit;

public:
    int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed &operator=(const Fixed &_old);
    Fixed(const Fixed &_old);
	Fixed( void );
    ~Fixed( void );
};

#endif
