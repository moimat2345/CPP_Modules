/*
** CPP - Module 01 - ex00 : BraiiiiiiinnnzzzZ
** newZombie.cpp
**
** HEAP allocation: the zombie must OUTLIVE this function, so we use `new`.
** The caller becomes responsible for `delete`-ing it.
*/

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	return new Zombie(name);
}
