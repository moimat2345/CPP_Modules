/*
** CPP - Module 01 - ex06 : Harl filter
** Harl.hpp
**
** Here the 4 message functions are PUBLIC so main() can call them directly
** from a switch (which falls through to print this level AND every level above).
*/

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
public:
	Harl( void );
	~Harl( void );

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif
