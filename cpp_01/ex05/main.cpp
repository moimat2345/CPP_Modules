/*
** CPP - Module 01 - ex05 : Harl 2.0
** main.cpp
*/

#include "Harl.hpp"

int	main( void )
{
	Harl	harl;

	std::cout << "----- complain(\"DEBUG\") -----" << "\n";
	harl.complain("DEBUG");

	std::cout << "\n----- complain(\"INFO\") -----" << "\n";
	harl.complain("INFO");

	std::cout << "\n----- complain(\"WARNING\") -----" << "\n";
	harl.complain("WARNING");

	std::cout << "\n----- complain(\"ERROR\") -----" << "\n";
	harl.complain("ERROR");

	return 0;
}
