/*
** CPP - Module 01 - ex02 : HI THIS IS BRAIN
** main.cpp
**
** A reference is just another NAME for an existing variable. Under the hood
** it behaves like a pointer that is always valid and auto-dereferenced.
** Proof: the variable, the pointer and the reference all share the SAME address.
*/

#include <iostream>
#include <string>

int	main( void )
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "--- Memory addresses ---" << "\n";
	std::cout << "address of the variable : " << &brain << "\n";
	std::cout << "address held by stringPTR : " << stringPTR << "\n";
	std::cout << "address of stringREF      : " << &stringREF << "\n";

	std::cout << "\n--- Values ---" << "\n";
	std::cout << "value of the variable   : " << brain << "\n";
	std::cout << "value via stringPTR     : " << *stringPTR << "\n";
	std::cout << "value via stringREF     : " << stringREF << "\n";

	return 0;
}
