/*
** CPP - Module 01 - ex03 : Unnecessary violence
** HumanB.cpp
*/

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
	else
		std::cout << this->_name << " has no weapon to attack with" << "\n";
}
