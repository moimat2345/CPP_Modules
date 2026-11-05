/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 10:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &) {
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::createShrubbery(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(const std::string &target) const {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	typedef AForm *(Intern::*Creator)(const std::string &) const;

	const std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const Creator		creators[3] = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*creators[i])(target);
		}
	}
	std::cout << "Intern can't create \"" << name << "\": unknown form name" << std::endl;
	return NULL;
}
