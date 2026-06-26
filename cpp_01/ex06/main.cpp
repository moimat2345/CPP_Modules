/*
** CPP - Module 01 - ex06 : Harl filter
** main.cpp
**
** The switch has NO `break` between cases on purpose: matching a level falls
** through to all the levels above it ("this level and above").
*/

#include "Harl.hpp"

static int	getLevel( std::string level )
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <LEVEL>" << "\n";
		return 1;
	}

	Harl	harl;

	switch (getLevel(argv[1]))
	{
		case 0:
			harl.debug();
			// fall through
		case 1:
			harl.info();
			// fall through
		case 2:
			harl.warning();
			// fall through
		case 3:
			harl.error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
	}
	return 0;
}
