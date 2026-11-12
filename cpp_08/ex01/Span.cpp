/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:30:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/12 19:30:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int n) : _maxSize(n), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_maxSize)
		throw std::runtime_error("Span Exception: the span is full!");
	this->_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Span Exception: not enough numbers to find a span!");

	std::vector<int> sorted(this->_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = static_cast<unsigned int>(sorted[1]) - static_cast<unsigned int>(sorted[0]);
	for (std::size_t i = 2; i < sorted.size(); i++) {
		unsigned int gap = static_cast<unsigned int>(sorted[i]) - static_cast<unsigned int>(sorted[i - 1]);
		if (gap < shortest)
			shortest = gap;
	}
	return shortest;
}

unsigned int Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Span Exception: not enough numbers to find a span!");

	int smallest = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int biggest = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return static_cast<unsigned int>(biggest) - static_cast<unsigned int>(smallest);
}
