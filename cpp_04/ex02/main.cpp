/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:28:18 by mateon            #+#    #+#             */
/*   Updated: 2026/07/23 21:50:08 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"

int main()
{
	// Animal a;               // must NOT compile (abstract class)
	// Animal* b = new Animal(); // must NOT compile

	std::cout << "===== TEST 1: polymorphism through Animal* =====" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;

	std::cout << "\n===== TEST 2: array of Animals =====" << std::endl;
	const int size = 4;
	Animal* animals[size];
	for (int n = 0; n < size; n++)
	{
		if (n < size / 2)
			animals[n] = new Dog();
		else
			animals[n] = new Cat();
	}
	for (int n = 0; n < size; n++)
		animals[n]->makeSound();
	for (int n = 0; n < size; n++)
		delete animals[n];

	std::cout << "\n===== TEST 3: copies =====" << std::endl;
	{
		Dog d1;
		Dog d2(d1);
		Cat c1;
		Cat c2;
		c2 = c1;
		std::cout << d2.getType() << " / " << c2.getType() << std::endl;
	}

	std::cout << "\n===== TEST 4: WrongCat =====" << std::endl;
	{
		const WrongAnimal* w = new WrongCat();
		w->makeSound();
		delete w;
	}

	std::cout << "\n===== TEST 5: deep copy proof =====" << std::endl;
	{
		Dog a;
		a.getBrain()->setIdea(0, "bone");
		Dog b(a);
		b.getBrain()->setIdea(0, "ball");
		std::cout << a.getBrain()->getIdea(0) << " / " << b.getBrain()->getIdea(0) << std::endl;

		Dog c;
		c = a;
		c.getBrain()->setIdea(0, "stick");
		std::cout << a.getBrain()->getIdea(0) << " / " << c.getBrain()->getIdea(0) << std::endl;
	}
	return 0;
}
