/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/07 10:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &x) {
	std::cout << x << " ";
}

template <typename T>
void increment(T &x) {
	x++;
}

void shout(std::string &s) {
	s += "!";
}

int main() {
	std::cout << "===== 1. int array, non-const reference =====" << std::endl;
	int numbers[5] = {1, 2, 3, 4, 5};
	std::cout << "before : ";
	::iter(numbers, 5, print<int>);
	std::cout << std::endl;
	::iter(numbers, 5, increment<int>);
	std::cout << "after  : ";
	::iter(numbers, 5, print<int>);
	std::cout << std::endl;

	std::cout << std::endl << "===== 2. const array, const reference =====" << std::endl;
	const int constNumbers[3] = {10, 20, 30};
	::iter(constNumbers, 3, print<int>);
	std::cout << std::endl;

	std::cout << std::endl << "===== 3. std::string array =====" << std::endl;
	std::string words[3] = {"hello", "42", "world"};
	::iter(words, 3, shout);
	::iter(words, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << std::endl << "===== 4. char and double arrays =====" << std::endl;
	char letters[4] = {'a', 'b', 'c', 'd'};
	double values[3] = {1.5, 2.5, 3.5};
	::iter(letters, 4, increment<char>);
	::iter(letters, 4, print<char>);
	std::cout << std::endl;
	::iter(values, 3, increment<double>);
	::iter(values, 3, print<double>);
	std::cout << std::endl;

	std::cout << std::endl << "===== 5. length 0 (nothing happens) =====" << std::endl;
	::iter(numbers, 0, increment<int>);
	std::cout << "ok" << std::endl;

	return 0;
}
