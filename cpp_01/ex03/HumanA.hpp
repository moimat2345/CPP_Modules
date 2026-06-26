/*
** CPP - Module 01 - ex03 : Unnecessary violence
** HumanA.hpp
**
** HumanA is ALWAYS armed and receives the Weapon in its constructor.
** -> the weapon is stored as a REFERENCE (can never be null, set once).
*/

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

	void	attack( void ) const;
};

#endif
