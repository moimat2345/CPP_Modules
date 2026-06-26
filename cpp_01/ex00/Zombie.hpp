/*
** CPP - Module 01 - ex00 : BraiiiiiiinnnzzzZ
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
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );
};

// Free functions (not members): defined in their own .cpp files
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
