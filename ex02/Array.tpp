/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:28:16 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/22 20:19:35 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP


/******************************************/
/*                ORTHODOX                */
/******************************************/
template <class T>
Array<T>::Array() : _arr(NULL), _arr_size(0)
{
	//std::cout << "Default constructor" << std::endl;
}

template <class T>
Array<T>::Array(const Array<T> &src)
{
	std::cout << "Copy constructor" << std::endl;
	if (this == &src)
		return ;

	if (this->_arr)
		delete[] this->_arr;

	int j = 0;
	while (src._arr[j])
	{
		this->arr[j] = new T;
		_arr[j] = src._arr[j];
		j ++;
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T> &src)
{
	std::cout << "Copy assignment" << std::endl;
	if (this != &src)
	{
		if (this->_arr)
			delete[] this->_arr;
		int j = 0;
		while (src._arr[j])
		{
			this->arr[j] = new T;
			_arr[j] = src._arr[j];
			j ++;
		}
	}
	return (*this);
}

template <class T>
Array<T>::~Array()
{
	//std::cout << "Default Destructor" << std::endl;
	delete[] this->_arr;
}
/******************************************/
/*            OTHER CONSTRUCTORS          */
/******************************************/

template <class T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _arr_size(n)
{
	std::cout << "unsigned int constructor" << std::endl;
}

template <class T>
T&	Array<T>::operator[](unsigned int index)
{
	if (this->_arr_size == 0)
		throw EmptyArray();
	if (index >= this->_arr_size)
		throw OutOfBounds();
	return (this->_arr[index]);
}

/******************************************/
/*            MEMBER FUNCTIONS            */
/******************************************/

template <class T>
unsigned int Array<T>::size(void) const
{
	return (this->_arr_size);
}

/******************************************/
/*                 EXCEPTION              */
/******************************************/
template <class T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds!";
}

template <class T>
const char* Array<T>::EmptyArray::what() const throw()
{
	return "Empty Array!";
}

#endif