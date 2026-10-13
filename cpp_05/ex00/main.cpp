/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 03:23:03 by mateon            #+#    #+#             */
/*   Updated: 2026/09/26 03:23:04 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

static void title(const std::string &text) {
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int main(void) {
	title("1. Valid bureaucrat + operator<<");
	try {
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("2. Constructor with grade 0 (too high)");
	try {
		Bureaucrat tim("Tim", 0);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("3. Constructor with grade 151 (too low)");
	try {
		Bureaucrat jim("Jim", 151);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("4. Constructor with grade -5 (too high)");
	try {
		Bureaucrat neg("Neg", -5);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("5. Limits 1 and 150 are valid");
	try {
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);
		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("6. Increment: 3 -> 2 -> 1 -> exception");
	{
		Bureaucrat alice("Alice", 3);
		try {
			alice.increment_grade();
			std::cout << alice << std::endl;
			alice.increment_grade();
			std::cout << alice << std::endl;
			alice.increment_grade();
			std::cout << "should not be printed" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "After the failed increment: " << alice << std::endl;
	}

	title("7. Decrement: 148 -> 149 -> 150 -> exception");
	{
		Bureaucrat carl("Carl", 148);
		try {
			carl.decrement_grade();
			std::cout << carl << std::endl;
			carl.decrement_grade();
			std::cout << carl << std::endl;
			carl.decrement_grade();
			std::cout << "should not be printed" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "After the failed decrement: " << carl << std::endl;
	}

	title("8. Catch the precise exception type");
	try {
		Bureaucrat low("Low", 200);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	title("9. Copy constructor and operator=");
	try {
		Bureaucrat original("Original", 10);
		Bureaucrat copy(original);
		std::cout << "copy     -> " << copy << std::endl;

		Bureaucrat other("Other", 100);
		other = original;
		std::cout << "other    -> " << other << "   (name stays: it is const)" << std::endl;

		copy.increment_grade();
		std::cout << "copy     -> " << copy << std::endl;
		std::cout << "original -> " << original << "   (unchanged)" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("10. Default constructor");
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}

	return 0;
}
