/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:20:33 by mateon            #+#    #+#             */
/*   Updated: 2026/07/21 17:39:14 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
	ClapTrap clapTrap2("ClapTrap2");

	clapTrap1.attack("ClapTrap2");
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(3);

	return 0;
}