/*
** CPP - Module 01 - ex00 : BraiiiiiiinnnzzzZ
** Zombie.cpp
*/

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " is now destroyed" << "\n";
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
