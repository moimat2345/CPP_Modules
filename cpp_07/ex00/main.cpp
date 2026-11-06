/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:50:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 23:31:27 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl << "===== extra tests =====" << std::endl;
	double x = 1.5;
	double y = -4.25;
	::swap(x, y);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

	char e = 'z';
	char f = 'a';
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	int p = 42;
	int q = 42;
	std::cout << "equal values, min returns the second ? " << (&::min(p, q) == &q ? "YES" : "NO") << std::endl;
	std::cout << "equal values, max returns the second ? " << (&::max(p, q) == &q ? "YES" : "NO") << std::endl;

	return 0;
}
