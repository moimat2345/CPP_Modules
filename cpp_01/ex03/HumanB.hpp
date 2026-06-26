/*
** CPP - Module 01 - ex03 : Unnecessary violence
** HumanB.hpp
**
** HumanB may NOT always have a weapon and does not receive it in the
** constructor. -> the weapon is stored as a POINTER (can be null, can change).
*/

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon( Weapon& weapon );
	void	attack( void ) const;
};

#endif
