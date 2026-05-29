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