/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 03:23:54 by mateon            #+#    #+#             */
/*   Updated: 2026/10/07 09:04:21 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


//***********************************//
//  	   Bureaucrat Class          //
//***********************************//

// Constructors
Bureaucrat::Bureaucrat() : _name("Default"), _grade(149){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "parametrized constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}


//***********************//
//      Getters          //
//***********************//

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}


//***********************//
//   Update Grade        //
//***********************//

void Bureaucrat::increment_grade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement_grade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}


//***********************//
//      Exceptions       //
//***********************//

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

//*************************//
//   Overloaded Operators  //
//*************************//

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade." << bureaucrat.getGrade();
	return out;
}

//***********************//
//   Sign a form         //
//***********************//

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
