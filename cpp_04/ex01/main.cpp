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
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"

int main()
{
	std::cout << "===== TEST 1: array of Animals (half Dog, half Cat) =====" << std::endl;
	const int size = 6;
	Animal* animals[size];
	for (int n = 0; n < size; n++)
	{
		if (n < size / 2)
			animals[n] = new Dog();
		else
			animals[n] = new Cat();
	}
	for (int n = 0; n < size; n++)
	{
		std::cout << animals[n]->getType() << ": ";
		animals[n]->makeSound();
	}
	std::cout << "===== delete via Animal* (Dog/Cat/Brain destructors must show) =====" << std::endl;
	for (int n = 0; n < size; n++)
		delete animals[n];

	std::cout << "\n===== TEST 2: copy constructor =====" << std::endl;
	{
		Dog original;
		Dog copy(original);
		std::cout << original.getType() << " / " << copy.getType() << std::endl;
	}

	std::cout << "\n===== TEST 3: copy assignment =====" << std::endl;
	{
		Cat a;
		Cat b;
		b = a;
		std::cout << a.getType() << " / " << b.getType() << std::endl;
	}

	std::cout << "\n===== TEST 4: deep copy (scope end must not crash / double free) =====" << std::endl;
	{
		Dog* basic = new Dog();
		Dog* tmp = new Dog(*basic);
		delete basic;
		tmp->makeSound();
		delete tmp;
	}

	std::cout << "\n===== TEST 5: WrongCat =====" << std::endl;
	{
		const WrongAnimal* w = new WrongCat();
		w->makeSound();
		delete w;
	}

	std::cout << "\n===== TEST 6: deep copy proof =====" << std::endl;
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
