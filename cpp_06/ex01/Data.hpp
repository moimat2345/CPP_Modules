/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 19:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
	std::string	name;
	int			value;

	Data();
	Data(const std::string &name, int value);
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};

#endif
