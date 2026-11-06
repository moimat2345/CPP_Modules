/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/06 19:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void test(Data *original) {
	uintptr_t	raw = Serializer::serialize(original);
	Data		*back = Serializer::deserialize(raw);

	std::cout << "original pointer : " << original << std::endl;
	std::cout << "raw (decimal)    : " << raw << std::endl;
	std::cout << "raw (hexa)       : 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "back pointer     : " << back << std::endl;
	std::cout << "same pointer ?   : " << (back == original ? "YES" : "NO") << std::endl;
	std::cout << "data via back    : " << back->name << " / " << back->value << std::endl;
}

int main() {
	std::cout << "===== 1. Data on the stack =====" << std::endl;
	Data stackData("stack", 42);
	test(&stackData);

	std::cout << std::endl << "===== 2. Data on the heap =====" << std::endl;
	Data *heapData = new Data("heap", 1337);
	test(heapData);

	std::cout << std::endl << "===== 3. Modify through the deserialized pointer =====" << std::endl;
	Data *back = Serializer::deserialize(Serializer::serialize(heapData));
	back->value = 7;
	std::cout << "heapData->value  : " << heapData->value << std::endl;

	delete heapData;
	return 0;
}
