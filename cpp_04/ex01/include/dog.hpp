/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:58:21 by mateon            #+#    #+#             */
/*   Updated: 2026/07/23 19:27:29 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();
		
		void makeSound() const;
		Brain* getBrain() const;
};

#endif