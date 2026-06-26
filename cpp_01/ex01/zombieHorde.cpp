/*
** CPP - Module 01 - ex01 : Moar brainz!
** zombieHorde.cpp
**
** Allocates N zombies in a SINGLE allocation (new Zombie[N]) and names them.
** Returns a pointer to the first zombie. The caller must use `delete[]`.
*/

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
