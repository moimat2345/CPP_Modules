/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnusko <matnusko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:08:21 by matnusko          #+#    #+#             */
/*   Updated: 2026/05/29 13:06:17 by matnusko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed & operator=( Fixed const & rhs );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int _value;
	static const int _fractionalBits = 8;
};

#endif