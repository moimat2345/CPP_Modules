/*
** CPP - Module 01 - ex01 : Moar brainz!
** Zombie.hpp
*/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie( void );
	~Zombie( void );

	void	setName( std::string name );
	void	announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif
