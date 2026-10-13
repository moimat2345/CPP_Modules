/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:49:45 by mateon            #+#    #+#             */
/*   Updated: 2026/10/07 09:04:01 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool				_Signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		
	// Getters //
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
	// Update signed status //
		void beSigned(const Bureaucrat &bureaucrat);
		
	// Exceptions //
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif