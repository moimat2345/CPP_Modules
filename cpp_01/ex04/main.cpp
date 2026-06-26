/*
** CPP - Module 01 - ex04 : Sed is for losers
** main.cpp
*/

#include "FileReplacer.hpp"

int	main( int argc, char** argv )
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << "\n";
		return 1;
	}

	std::string	s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "Error: s1 (the string to replace) must not be empty" << "\n";
		return 1;
	}

	FileReplacer	replacer(argv[1], argv[2], argv[3]);
	if (!replacer.run())
		return 1;

	std::cout << "Done: created '" << std::string(argv[1]) << ".replace'" << "\n";
	return 0;
}
