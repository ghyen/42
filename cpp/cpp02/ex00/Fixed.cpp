#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBit;
}

void Fixed::setRawBits( int const newRaw )
{
	rawBit = newRaw;
}

Fixed::Fixed(const Fixed &_old)
{
	std::cout << "Copy constructor called" << std::endl;
	//setRawBits(_old.getRawBits());
	*this = _old;
}

Fixed &Fixed::operator=(const Fixed &_old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(_old.getRawBits());
	return *this;
}

Fixed::Fixed( void ) : rawBit(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
