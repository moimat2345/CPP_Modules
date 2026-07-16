#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "SetRawBits function called\n";
	this->_value = raw;
}

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed( int const raw )
{
	std::cout << "Int constructor called\n";
	this->_value = raw << this->_fractionalBits;
}

Fixed::Fixed( float const raw )
{
	std::cout << "Float constructor called\n";
	this->_value = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called\n";
	if ( this != &rhs )
		this->_value = rhs._value;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

float Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_value >> this->_fractionalBits;
}


Fixed Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++( void )
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--( void )
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}


Fixed Fixed::operator>( Fixed const & rhs ) const
{
	return this->_value > rhs._value;
}

Fixed Fixed::operator<( Fixed const & rhs ) const
{
	return this->_value < rhs._value;
}

Fixed Fixed::operator>=( Fixed const & rhs ) const
{
	return this->_value >= rhs._value;
}

Fixed Fixed::operator<=( Fixed const & rhs ) const
{
	return this->_value <= rhs._value;
}

Fixed Fixed::operator==( Fixed const & rhs ) const
{
	return this->_value == rhs._value;
}

Fixed Fixed::operator!=( Fixed const & rhs ) const
{
	return this->_value != rhs._value;
}


Fixed & Fixed::min( Fixed &a, Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return b;
}

Fixed const & Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return b;
}

Fixed & Fixed::max( Fixed &a, Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return b;
}

Fixed const & Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return b;
}