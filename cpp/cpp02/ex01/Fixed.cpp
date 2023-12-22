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
	setRawBits(_old.rawBit);
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed( void ) : rawBit(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int num ) : rawBit(num << fractionalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : rawBit((int)roundf(num * (1 << fractionalBit)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)rawBit / (1 << fractionalBit); 
}

int Fixed::toInt(void) const
{
	return rawBit >> fractionalBit;
}
