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

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
	
	Fixed &operator=(const Fixed &ref);
	bool operator>(const Fixed &ref)const;
	bool operator<(const Fixed &ref)const;
	bool operator>=(const Fixed &ref)const;
	bool operator<=(const Fixed &ref)const;
	bool operator==(const Fixed &ref)const;
	bool operator!=(const Fixed &ref)const;

	Fixed operator+(const Fixed &ref)const;
	Fixed operator-(const Fixed &ref)const;
	Fixed operator*(const Fixed &ref)const;
	Fixed operator/(const Fixed &ref)const;

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++(void);
	Fixed &operator--(void);

    Fixed(const Fixed &ref);
	Fixed( void );
	Fixed( const int num );
	Fixed( const float num );
    ~Fixed( void );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
