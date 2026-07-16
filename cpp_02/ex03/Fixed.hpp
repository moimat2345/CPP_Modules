/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:02:49 by matnusko          #+#    #+#             */
/*   Updated: 2026/07/16 17:48:55 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( int const raw );
	Fixed( float const raw );
	~Fixed( void );
	Fixed &operator=( Fixed const & rhs );

	Fixed operator+( Fixed const & rhs ) const;
	Fixed operator-( Fixed const & rhs ) const;
	Fixed operator*( Fixed const & rhs ) const;
	Fixed operator/( Fixed const & rhs ) const;
	
	Fixed operator++( void );
	Fixed operator++( int );
	Fixed operator--( void );
	Fixed operator--( int );
	
	Fixed operator>( Fixed const & rhs ) const;
	Fixed operator<( Fixed const & rhs ) const;
	Fixed operator>=( Fixed const & rhs ) const;
	Fixed operator<=( Fixed const & rhs ) const;
	Fixed operator==( Fixed const & rhs ) const;
	Fixed operator!=( Fixed const & rhs ) const;
	
	static Fixed &min( Fixed &a, Fixed &b );
	static Fixed const &min( Fixed const &a, Fixed const &b );
	static Fixed &max( Fixed &a, Fixed &b );
	static Fixed const &max( Fixed const &a, Fixed const &b );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif