/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/12 19:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

template <typename T>
static void search(T &container, int value) {
	try {
		typename T::iterator it = easyfind(container, value);
		std::cout << value << " found at position " << std::distance(container.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << value << " -> " << e.what() << std::endl;
	}
}

int main() {
	const int values[6] = {10, 20, 30, 20, -5, 0};

	title("1. std::vector");
	std::vector<int> vec(values, values + 6);
	search(vec, 30);
	search(vec, -5);
	search(vec, 99);

	title("2. std::list");
	std::list<int> lst(values, values + 6);
	search(lst, 0);
	search(lst, 10);
	search(lst, 42);

	title("3. std::deque");
	std::deque<int> deq(values, values + 6);
	search(deq, 20);
	search(deq, 7);

	title("4. First occurrence (20 appears twice)");
	search(vec, 20);

	title("5. Modify through the returned iterator");
	*easyfind(vec, 30) = 300;
	std::cout << "vec[2] = " << vec[2] << std::endl;
	search(vec, 30);
	search(vec, 300);

	title("6. Empty container");
	std::vector<int> empty;
	search(empty, 1);

	title("7. Const container");
	const std::vector<int> constVec(values, values + 6);
	try {
		std::vector<int>::const_iterator it = easyfind(constVec, 20);
		std::cout << "found " << *it << " in a const vector" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
