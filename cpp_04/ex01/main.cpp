/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:28:18 by mateon            #+#    #+#             */
/*   Updated: 2026/07/23 19:29:04 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/dog.hpp"
#include "include/cat.hpp"
#include "include/wrongcat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* l = new WrongAnimal();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	k->makeSound();
	l->makeSound();
	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;
	return 0;
}