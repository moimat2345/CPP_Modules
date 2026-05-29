/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:30:00 by mateon            #+#    #+#             */
/*   Updated: 2026/01/16 21:27:48 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
	this->_oldest = 0;
}

static std::string formatColumn(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return 	(str);
}

static std::string getInput(std::string prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return ("");
		}
	}
	return (input);
}

void	PhoneBook::addContact(void)
{
	std::string	input;
	int			index;

	if (this->_count < 8)
		index = this->_count;
	else
		index = this->_oldest;

	input = getInput("First name: ");
	if (input.empty()) return ;
	this->_contacts[index].setFirstName(input);

	input = getInput("Last name: ");
	if (input.empty()) return ;
	this->_contacts[index].setLastName(input);

	input = getInput("Nickname: ");
	if (input.empty()) return ;
	this->_contacts[index].setNickname(input);

	input = getInput("Phone number: ");
	if (input.empty()) return ;
	this->_contacts[index].setPhoneNumber(input);

	input = getInput("Darkest secret: ");
	if (input.empty()) return ;
	this->_contacts[index].setDarkestSecret(input);

	if (this->_count < 8)
		this->_count++;
	this->_oldest = (this->_oldest + 1) % 8;

	std::cout << "Contact added!" << std::endl;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	int			index;

	if (this->_count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < this->_count; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << formatColumn(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << formatColumn(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << formatColumn(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		return ;
	}

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	index = input[0] - '0';
	if (index >= this->_count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}
