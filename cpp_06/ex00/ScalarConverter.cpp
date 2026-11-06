/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:40:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 18:40:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cctype>

namespace {

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

bool isPseudo(const std::string &s) {
	const std::string pseudos[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

	for (int i = 0; i < 6; i++) {
		if (s == pseudos[i])
			return true;
	}
	return false;
}

bool isChar(const std::string &s) {
	if (s.length() == 1)
		return !std::isdigit(static_cast<unsigned char>(s[0]));
	return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool isInt(const std::string &s) {
	size_t i = 0;

	if (s[0] == '+' || s[0] == '-')
		i = 1;
	if (i == s.length())
		return false;
	for (; i < s.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

bool isDecimal(const std::string &s) {
	size_t	i = 0;
	int		dots = 0;
	int		digits = 0;

	if (s[0] == '+' || s[0] == '-')
		i = 1;
	for (; i < s.length(); i++) {
		if (s[i] == '.')
			dots++;
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			digits++;
		else
			return false;
	}
	return dots == 1 && digits > 0;
}

bool isFloat(const std::string &s) {
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;
	return isDecimal(s.substr(0, s.length() - 1));
}

Type detectType(const std::string &s) {
	if (s.empty())
		return INVALID;
	if (isPseudo(s))
		return PSEUDO;
	if (isChar(s))
		return CHAR;
	if (isInt(s))
		return INT;
	if (isFloat(s))
		return FLOAT;
	if (isDecimal(s))
		return DOUBLE;
	return INVALID;
}

double toDouble(const std::string &s, Type type) {
	if (type == CHAR) {
		if (s.length() == 3)
			return static_cast<double>(s[1]);
		return static_cast<double>(s[0]);
	}
	if (type == PSEUDO) {
		if (s[0] == '+')
			return std::numeric_limits<double>::infinity();
		if (s[0] == '-')
			return -std::numeric_limits<double>::infinity();
		return std::numeric_limits<double>::quiet_NaN();
	}
	return std::strtod(s.c_str(), NULL);
}

bool isNan(double v) {
	return v != v;
}

bool isInf(double v) {
	return v == std::numeric_limits<double>::infinity()
		|| v == -std::numeric_limits<double>::infinity();
}

void printChar(double v) {
	std::cout << "char: ";
	if (isNan(v) || isInf(v) || v < 0 || v > 127)
		std::cout << "impossible" << std::endl;
	else if (v < 32 || v == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(v) << "'" << std::endl;
}

void printInt(double v) {
	std::cout << "int: ";
	if (isNan(v) || v <= -2147483649.0 || v >= 2147483648.0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(v) << std::endl;
}

std::string formatNumber(double v, int precision) {
	std::ostringstream oss;

	if (v == std::floor(v) && std::fabs(v) < 1e15)
		oss << std::fixed << std::setprecision(1) << v;
	else
		oss << std::setprecision(precision) << v;
	return oss.str();
}

void printFloat(double v) {
	std::cout << "float: ";
	if (isNan(v)) {
		std::cout << "nanf" << std::endl;
		return;
	}
	if (isInf(v)) {
		std::cout << (v > 0 ? "+inff" : "-inff") << std::endl;
		return;
	}
	if (v > std::numeric_limits<float>::max() || v < -std::numeric_limits<float>::max()) {
		std::cout << "impossible" << std::endl;
		return;
	}
	float f = static_cast<float>(v);
	std::cout << formatNumber(static_cast<double>(f), 7) << "f" << std::endl;
}

void printDouble(double v) {
	std::cout << "double: ";
	if (isNan(v)) {
		std::cout << "nan" << std::endl;
		return;
	}
	if (isInf(v)) {
		std::cout << (v > 0 ? "+inf" : "-inf") << std::endl;
		return;
	}
	std::cout << formatNumber(v, 15) << std::endl;
}

}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
	Type type = detectType(literal);

	if (type == INVALID) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	double value = toDouble(literal, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
