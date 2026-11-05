/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/05 21:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _Signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _Signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm parametrized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _Signed(other._Signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->_Signed = other._Signed;
	}
	std::cout << "AForm assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_Signed;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_Signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->_Signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	this->action();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Form Exception: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form Exception: Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form Exception: Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form Name: " << form.getName() << std::endl;
	out << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	out << "Grade Required to Sign: " << form.getGradeToSign() << std::endl;
	out << "Grade Required to Execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
