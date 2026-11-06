/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 19:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name("Default"), value(0) {}

Data::Data(const std::string &name, int value) : name(name), value(value) {}

Data::Data(const Data &other) : name(other.name), value(other.value) {}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		this->name = other.name;
		this->value = other.value;
	}
	return *this;
}

Data::~Data() {}
