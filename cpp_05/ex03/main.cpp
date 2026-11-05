/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 10:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

static void title(const std::string &s) {
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	title("1. The example from the subject");
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}

	title("2. The three known forms");
	{
		Intern intern;
		const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		for (int i = 0; i < 3; i++) {
			AForm *form = intern.makeForm(names[i], "Target");
			std::cout << *form;
			delete form;
		}
	}

	title("3. Unknown form name");
	{
		Intern intern;
		AForm *form = intern.makeForm("coffee order", "Bender");
		if (form == NULL)
			std::cout << "-> got NULL, nothing to delete" << std::endl;
		delete form;
	}

	title("4. Intern + Bureaucrat: sign and execute");
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm *form = intern.makeForm("presidential pardon", "Arthur");
		if (form) {
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	return 0;
}
