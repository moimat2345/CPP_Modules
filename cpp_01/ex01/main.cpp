/*
** CPP - Module 01 - ex01 : Moar brainz!
** main.cpp
*/

#include "Zombie.hpp"

int	main( void )
{
	int		N = 5;
	Zombie*	horde = zombieHorde(N, "Horde");

	if (horde == NULL)
	{
		std::cerr << "zombieHorde failed" << "\n";
		return 1;
	}

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde; // ONE deallocation frees the whole array

	return 0;
}
