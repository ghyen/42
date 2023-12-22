#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return val;
}
void Fixed::setRawBits( int const raw )
{
	val = raw;
}
Fixed::Fixed(const Fixed &_old)
{
	std::cout << "Copy constructor called" << std::endl;
	this->val = _old.val;
}
Fixed &Fixed::operator=(const Fixed &_old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = _old.val;
	return *this;
}
Fixed::Fixed( void ) : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
