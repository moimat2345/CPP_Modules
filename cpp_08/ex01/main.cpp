/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:30:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/12 19:30:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "Span.hpp"

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

static unsigned int bruteShortest(const std::vector<int> &v) {
	unsigned int best = UINT_MAX;

	for (std::size_t i = 0; i < v.size(); i++) {
		for (std::size_t j = i + 1; j < v.size(); j++) {
			unsigned int gap = v[i] > v[j]
				? static_cast<unsigned int>(v[i]) - static_cast<unsigned int>(v[j])
				: static_cast<unsigned int>(v[j]) - static_cast<unsigned int>(v[i]);
			if (gap < best)
				best = gap;
		}
	}
	return best;
}

int main() {
	std::srand(std::time(NULL));

	title("1. Subject test");
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	title("2. Exceptions");
	{
		Span empty(3);
		try { empty.shortestSpan(); } catch (const std::exception &e) { std::cout << "0 number  -> " << e.what() << std::endl; }
		empty.addNumber(42);
		try { empty.longestSpan(); } catch (const std::exception &e) { std::cout << "1 number  -> " << e.what() << std::endl; }
		empty.addNumber(1);
		empty.addNumber(2);
		try { empty.addNumber(3); } catch (const std::exception &e) { std::cout << "4th number -> " << e.what() << std::endl; }
		Span none;
		try { none.addNumber(1); } catch (const std::exception &e) { std::cout << "Span(0)    -> " << e.what() << std::endl; }
	}

	title("3. Add a range of iterators");
	{
		int array[5] = {1, 100, 50, 7, 8};
		std::vector<int> vec(array, array + 5);
		std::list<int> lst(array, array + 5);

		Span fromVector(5);
		fromVector.addRange(vec.begin(), vec.end());
		std::cout << "vector : shortest " << fromVector.shortestSpan() << ", longest " << fromVector.longestSpan() << std::endl;

		Span fromList(5);
		fromList.addRange(lst.begin(), lst.end());
		std::cout << "list   : shortest " << fromList.shortestSpan() << ", longest " << fromList.longestSpan() << std::endl;

		Span fromArray(5);
		fromArray.addRange(array, array + 5);
		std::cout << "array  : shortest " << fromArray.shortestSpan() << ", longest " << fromArray.longestSpan() << std::endl;

		Span tooSmall(3);
		try { tooSmall.addRange(vec.begin(), vec.end()); } catch (const std::exception &e) { std::cout << "5 into 3 -> " << e.what() << std::endl; }
		std::cout << "nothing was added: ";
		try { tooSmall.shortestSpan(); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}

	title("4. 20000 numbers");
	{
		Span big(20000);
		std::vector<int> values;
		for (int i = 0; i < 20000; i++)
			values.push_back(i * 3);
		big.addRange(values.begin(), values.end());
		std::cout << "i * 3  : shortest " << big.shortestSpan() << " (expected 3), longest " << big.longestSpan() << " (expected 59997)" << std::endl;
	}

	title("5. Random numbers checked against brute force");
	{
		std::vector<int> values;
		for (int i = 0; i < 5000; i++)
			values.push_back(std::rand());
		Span random(5000);
		random.addRange(values.begin(), values.end());
		std::cout << "span    : shortest " << random.shortestSpan() << ", longest " << random.longestSpan() << std::endl;
		std::cout << "brute   : shortest " << bruteShortest(values) << std::endl;
	}

	title("6. Extreme values");
	{
		Span extreme(2);
		extreme.addNumber(INT_MIN);
		extreme.addNumber(INT_MAX);
		std::cout << "INT_MIN..INT_MAX : " << extreme.longestSpan() << " (expected 4294967295)" << std::endl;
	}

	title("7. Copy and assignment");
	{
		Span original(3);
		original.addNumber(1);
		original.addNumber(10);

		Span copy(original);
		copy.addNumber(100);
		std::cout << "copy     longest " << copy.longestSpan() << std::endl;
		std::cout << "original longest " << original.longestSpan() << " (unchanged)" << std::endl;

		Span assigned(1);
		assigned = original;
		assigned.addNumber(5);
		std::cout << "assigned longest " << assigned.longestSpan() << ", shortest " << assigned.shortestSpan() << std::endl;
		try { assigned.addNumber(6); } catch (const std::exception &e) { std::cout << "assigned full -> " << e.what() << std::endl; }
	}

	return 0;
}
