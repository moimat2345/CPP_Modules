/*
** CPP - Module 01 - ex00 : BraiiiiiiinnnzzzZ
** main.cpp
*/

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	heapZombie;

	std::cout << "=== newZombie : allocation on the HEAP ===" << "\n";
	heapZombie = newZombie("Heapy");
	heapZombie->announce();
	delete heapZombie; // we MUST free what we allocated with new

	std::cout << "\n=== randomChump : allocation on the STACK ===" << "\n";
	randomChump("Stacky"); // destroyed automatically at the end of the function

	return 0;
}
