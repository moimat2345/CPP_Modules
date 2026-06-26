/*
** CPP - Module 01 - ex05 : Harl 2.0
** Harl.hpp
**
** The 4 message functions are PRIVATE. complain() picks the right one through
** an array of POINTERS TO MEMBER FUNCTIONS (no if/else forest).
*/

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:
	Harl( void );
	~Harl( void );

	void	complain( std::string level );
};

#endif
