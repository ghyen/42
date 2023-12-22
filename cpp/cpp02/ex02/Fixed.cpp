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

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	//setRawBits(ref.getRawBits());
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(ref.rawBit);
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

bool Fixed::operator>(const Fixed& fixed) const
{
	return rawBit > fixed.rawBit;
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return rawBit < fixed.rawBit;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return rawBit >= fixed.rawBit;
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return rawBit <= fixed.rawBit;
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return rawBit == fixed.rawBit;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return rawBit != fixed.rawBit;
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
	rawBit++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);
	rawBit++;
	return res;
}

Fixed& Fixed::operator--()
{
	rawBit--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed res(*this);
	rawBit++;
	return res;
}
Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1 <= f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return f1 <= f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1 >= f2 ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return f1 >= f2 ? f1 : f2;
}
