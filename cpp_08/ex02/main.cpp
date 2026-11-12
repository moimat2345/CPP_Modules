/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/12 20:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include "MutantStack.hpp"

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

static std::string withMutantStack() {
	std::ostringstream out;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	out << mstack.top() << std::endl;
	mstack.pop();
	out << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		out << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return out.str();
}

static std::string withList() {
	std::ostringstream out;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	out << mstack.back() << std::endl;
	mstack.pop_back();
	out << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		out << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	return out.str();
}

int main() {
	title("1. Subject test with MutantStack");
	std::string mutantOutput = withMutantStack();
	std::cout << mutantOutput;

	title("2. Same test with std::list");
	std::string listOutput = withList();
	std::cout << listOutput;

	title("3. Are both outputs identical ?");
	std::cout << (mutantOutput == listOutput ? "YES" : "NO") << std::endl;

	title("4. Stack behaviour is kept");
	{
		MutantStack<int> stack;
		std::cout << "empty : " << (stack.empty() ? "yes" : "no") << std::endl;
		for (int i = 1; i <= 5; i++)
			stack.push(i * 10);
		std::cout << "size = " << stack.size() << ", top = " << stack.top() << std::endl;
		stack.pop();
		std::cout << "after pop : size = " << stack.size() << ", top = " << stack.top() << std::endl;
	}

	title("5. Iterators: modify, const, reverse");
	{
		MutantStack<int> stack;
		for (int i = 1; i <= 4; i++)
			stack.push(i);
		for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
			*it *= 10;
		std::cout << "begin -> end   : ";
		for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << "rbegin -> rend : ";
		for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		const MutantStack<int> &constStack = stack;
		std::cout << "const begin -> end : ";
		for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	title("6. Copy and assignment");
	{
		MutantStack<std::string> original;
		original.push("a");
		original.push("b");
		original.push("c");

		MutantStack<std::string> copy(original);
		copy.push("d");
		MutantStack<std::string> assigned;
		assigned = original;
		assigned.pop();
		std::cout << "original : " << original.size() << " elements, top " << original.top() << std::endl;
		std::cout << "copy     : " << copy.size() << " elements, top " << copy.top() << std::endl;
		std::cout << "assigned : " << assigned.size() << " elements, top " << assigned.top() << std::endl;
	}

	title("7. STL algorithms work on the iterators");
	{
		MutantStack<int> stack;
		for (int i = 1; i <= 6; i++)
			stack.push(i * i);
		MutantStack<int>::iterator found = std::find(stack.begin(), stack.end(), 16);
		std::cout << "std::find(16)  : " << (found != stack.end() ? "found" : "not found") << std::endl;
		std::cout << "std::count(25) : " << std::count(stack.begin(), stack.end(), 25) << std::endl;
		std::cout << "max element    : " << *std::max_element(stack.begin(), stack.end()) << std::endl;
	}

	return 0;
}
