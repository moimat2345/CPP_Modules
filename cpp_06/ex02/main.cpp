/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:30:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 19:30:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));

	std::cout << "===== 1. Known objects =====" << std::endl;
	A a;
	B b;
	C c;
	std::cout << "pointer   : "; identify(&a);
	std::cout << "reference : "; identify(a);
	std::cout << "pointer   : "; identify(&b);
	std::cout << "reference : "; identify(b);
	std::cout << "pointer   : "; identify(&c);
	std::cout << "reference : "; identify(c);

	std::cout << std::endl << "===== 2. Through a Base pointer (generate) =====" << std::endl;
	for (int i = 0; i < 8; i++) {
		Base *p = generate();
		std::cout << "pointer   : "; identify(p);
		std::cout << "reference : "; identify(*p);
		delete p;
	}

	std::cout << std::endl << "===== 3. A plain Base =====" << std::endl;
	Base *base = new Base;
	std::cout << "pointer   : "; identify(base);
	std::cout << "reference : "; identify(*base);
	delete base;

	return 0;
}
