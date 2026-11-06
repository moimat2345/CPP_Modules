/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 11:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/07 11:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

static int subjectTest() {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete [] mirror;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}

static void testEmpty() {
	Array<int> empty;
	std::cout << "size = " << empty.size() << std::endl;
	try {
		empty[0] = 1;
	} catch (const std::exception &e) {
		std::cout << "empty[0] -> " << e.what() << std::endl;
	}
}

static void testDefaultValues() {
	Array<int> ints(5);
	Array<std::string> strings(3);
	std::cout << "ints    : ";
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << " ";
	std::cout << std::endl << "strings : ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << "[" << strings[i] << "] ";
	std::cout << std::endl;
}

static void testDeepCopy() {
	Array<int> original(3);
	for (unsigned int i = 0; i < 3; i++)
		original[i] = static_cast<int>(i) + 1;

	Array<int> copy(original);
	copy[0] = 100;
	original[1] = 200;
	std::cout << "original : " << original[0] << " " << original[1] << " " << original[2] << std::endl;
	std::cout << "copy     : " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;

	Array<int> assigned(10);
	assigned = original;
	assigned[2] = 300;
	std::cout << "assigned : size " << assigned.size() << " -> " << assigned[0] << " " << assigned[1] << " " << assigned[2] << std::endl;
	std::cout << "original : " << original[0] << " " << original[1] << " " << original[2] << " (unchanged)" << std::endl;

	Array<int> &alias = assigned;
	assigned = alias;
	std::cout << "self-assignment ok, size " << assigned.size() << std::endl;
}

static void testConst() {
	Array<std::string> words(2);
	words[0] = "hello";
	words[1] = "world";
	const Array<std::string> &constWords = words;
	std::cout << constWords[0] << " " << constWords[1] << " (size " << constWords.size() << ")" << std::endl;
	try {
		std::cout << constWords[2] << std::endl;
	} catch (const std::exception &e) {
		std::cout << "constWords[2] -> " << e.what() << std::endl;
	}
}

static void testBounds() {
	Array<int> arr(3);
	const int indexes[3] = {2, 3, -1};
	for (int i = 0; i < 3; i++) {
		try {
			arr[indexes[i]] = 42;
			std::cout << "arr[" << indexes[i] << "] ok" << std::endl;
		} catch (const std::exception &e) {
			std::cout << "arr[" << indexes[i] << "] -> " << e.what() << std::endl;
		}
	}
}

int main() {
	title("1. Subject test");
	if (subjectTest() != 0)
		return 1;
	std::cout << "subject test finished" << std::endl;

	title("2. Empty array");
	testEmpty();

	title("3. Default values");
	testDefaultValues();

	title("4. Deep copy and assignment");
	testDeepCopy();

	title("5. Const array");
	testConst();

	title("6. Bounds");
	testBounds();

	return 0;
}
