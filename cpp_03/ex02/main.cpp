/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:20:33 by mateon            #+#    #+#             */
/*   Updated: 2026/07/21 18:28:09 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
	ScavTrap scavTrap1("ScavTrap1");
	FragTrap fragTrap1("FragTrap1");
	
	clapTrap1.attack("ScavTrap1");
	scavTrap1.attack("FragTrap1");
	fragTrap1.attack("ClapTrap1");
	
	scavTrap1.takeDamage(5);
	fragTrap1.takeDamage(5);
	clapTrap1.takeDamage(5);
	
	scavTrap1.beRepaired(3);
	fragTrap1.beRepaired(3);
	clapTrap1.beRepaired(3);

	scavTrap1.guardGate();
	fragTrap1.highFivesGuys();
	return 0;
}