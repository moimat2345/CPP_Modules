/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:02:49 by matnusko          #+#    #+#             */
/*   Updated: 2026/05/29 13:14:21 by matnusko         ###   ########.fr       */
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

	Fixed & operator=( Fixed const & rhs );

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