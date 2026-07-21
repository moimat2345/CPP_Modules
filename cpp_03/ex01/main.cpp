/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:20:33 by mateon            #+#    #+#             */
/*   Updated: 2026/07/21 18:25:45 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
	ScavTrap scavTrap1("ScavTrap1");
	
	clapTrap1.attack("ScavTrap1");
	scavTrap1.attack("ClapTrap1");

	clapTrap1.takeDamage(5);
	scavTrap1.takeDamage(5);
	
	clapTrap1.beRepaired(3);
	scavTrap1.beRepaired(3);

	scavTrap1.guardGate();
	
	return 0;
}