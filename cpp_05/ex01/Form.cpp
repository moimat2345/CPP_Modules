/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:49:36 by mateon            #+#    #+#             */
/*   Updated: 2026/10/07 09:04:08 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//***********************************//
//  	   Form Class.               //
//***********************************//

// Constructors
Form::Form() : _name("Default"), _Signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

// Constructor with parameters
Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _Signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form parametrized constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _Signed(other._Signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator
Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->_Signed = other._Signed;
	}
	std::cout << "Form assignment operator called" << std::endl;
	return *this;
}

// Destructor
Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

//***********************//
//      Getters          //
//***********************//

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_Signed;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

//*************************//
//   Update Signed Status  //
//*************************//

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_Signed = true;
}

//***********************//
//      Exceptions       //
//***********************//

const char *Form::GradeTooHighException::what() const throw() {
	return "Form Exception: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form Exception: Grade is too low!";
}

//*************************//
//      Stream Operator    //
//*************************//

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form Name: " << form.getName() << std::endl;
	out << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	out << "Grade Required to Sign: " << form.getGradeToSign() << std::endl;
	out << "Grade Required to Execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
