/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 11:00:00 by mateon            #+#    #+#             */
/*   Updated: 2026/11/07 11:00:00 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < this->_size; i++)
		this->_data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		T *newData = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			newData[i] = other._data[i];
		delete[] this->_data;
		this->_data = newData;
		this->_size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw OutOfBoundsException();
	return this->_data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw OutOfBoundsException();
	return this->_data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return "Array Exception: index is out of bounds!";
}

#endif
