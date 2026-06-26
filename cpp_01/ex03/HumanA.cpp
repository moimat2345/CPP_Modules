/*
** CPP - Module 01 - ex03 : Unnecessary violence
** HumanA.cpp
*/

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "\n";
}
