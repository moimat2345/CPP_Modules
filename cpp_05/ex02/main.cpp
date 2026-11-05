/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/05 21:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	title("1. Shrubbery : sign + execute");
	{
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm form("home");
		bob.signForm(form);
		bob.executeForm(form);
	}

	title("2. Execute without signing");
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form("Arthur");
		boss.executeForm(form);
	}

	title("3. Sign OK but grade too low to execute");
	{
		Bureaucrat mid("Mid", 50);
		RobotomyRequestForm form("Marvin");
		mid.signForm(form);
		mid.executeForm(form);
	}

	title("4. Grade too low to sign");
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Ford");
		intern.signForm(form);
	}

	title("5. Robotomy x4 (50% chance)");
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm form("Bender");
		boss.signForm(form);
		for (int i = 0; i < 4; i++)
			boss.executeForm(form);
	}

	title("6. Polymorphism via AForm*");
	{
		Bureaucrat boss("Boss", 1);
		AForm *forms[3];
		forms[0] = new ShrubberyCreationForm("garden");
		forms[1] = new RobotomyRequestForm("Wall-E");
		forms[2] = new PresidentialPardonForm("Zaphod");
		for (int i = 0; i < 3; i++) {
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	title("7. Print a form");
	{
		PresidentialPardonForm form("Trillian");
		std::cout << form;
	}

	return 0;
}
