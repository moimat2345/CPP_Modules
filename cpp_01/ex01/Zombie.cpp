/*
** CPP - Module 01 - ex01 : Moar brainz!
** Zombie.cpp
*/

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("")
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " is now destroyed" << "\n";
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
