/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:30:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/12 19:30:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
	private :
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public :
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template <typename InputIt>
		void addRange(InputIt first, InputIt last);
};

template <typename InputIt>
void Span::addRange(InputIt first, InputIt last) {
	unsigned long count = static_cast<unsigned long>(std::distance(first, last));

	if (count > this->_maxSize - this->_numbers.size())
		throw std::runtime_error("Span Exception: the span is full!");
	this->_numbers.insert(this->_numbers.end(), first, last);
}

#endif
