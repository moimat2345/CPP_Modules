/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 03:23:03 by mateon            #+#    #+#             */
/*   Updated: 2026/10/07 08:40:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static void title(const std::string &text) {
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int main(void) {
	title("1. Valid form + operator<<");
	try {
		Form permit("Permit", 50, 20);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("2. Form with invalid grades");
	try {
		Form f("SignZero", 0, 10);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "sign 0     -> Exception: " << e.what() << std::endl;
	}
	try {
		Form f("Sign151", 151, 10);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "sign 151   -> Exception: " << e.what() << std::endl;
	}
	try {
		Form f("ExecZero", 10, 0);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "exec 0     -> Exception: " << e.what() << std::endl;
	}
	try {
		Form f("Exec151", 10, 151);
		std::cout << "should not be printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "exec 151   -> Exception: " << e.what() << std::endl;
	}

	title("3. signForm: grade high enough (10 signs a form needing 50)");
	try {
		Bureaucrat alice("Alice", 10);
		Form permit("Permit", 50, 20);
		alice.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("4. signForm: grade too low (120 tries a form needing 50)");
	try {
		Bureaucrat bob("Bob", 120);
		Form permit("Permit", 50, 20);
		bob.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("5. signForm: exact limit (50 signs a form needing 50)");
	try {
		Bureaucrat carl("Carl", 50);
		Form permit("Permit", 50, 20);
		carl.signForm(permit);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("6. signForm: just one grade too low (51 tries a form needing 50)");
	try {
		Bureaucrat dan("Dan", 51);
		Form permit("Permit", 50, 20);
		dan.signForm(permit);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("7. beSigned called directly throws Form::GradeTooLowException");
	try {
		Bureaucrat eve("Eve", 100);
		Form permit("Permit", 50, 20);
		permit.beSigned(eve);
		std::cout << "should not be printed" << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
	}

	title("8. Promote a bureaucrat until he can sign");
	try {
		Bureaucrat fred("Fred", 52);
		Form permit("Permit", 50, 20);
		fred.signForm(permit);
		fred.increment_grade();
		fred.increment_grade();
		std::cout << fred << std::endl;
		fred.signForm(permit);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("9. Form copy constructor and operator=");
	try {
		Bureaucrat boss("Boss", 1);
		Form original("Original", 30, 30);
		boss.signForm(original);

		Form copy(original);
		std::cout << "copy  -> " << copy << std::endl;

		Form other("Other", 100, 100);
		other = original;
		std::cout << "other -> " << other << "   (name and grades stay: they are const)" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
