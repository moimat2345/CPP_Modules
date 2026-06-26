/*
** CPP - Module 01 - ex00 : BraiiiiiiinnnzzzZ
** randomChump.cpp
**
** STACK allocation: the zombie is only needed INSIDE this function, so we
** create it on the stack. It is destroyed automatically when the scope ends.
*/

#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	zombie(name);

	zombie.announce();
}
