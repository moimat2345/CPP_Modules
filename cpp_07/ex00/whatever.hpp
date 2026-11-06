/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:50:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 23:05:55 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

#endif
