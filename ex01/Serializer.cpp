/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:30:20 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/11 15:07:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor" << std::endl;	
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer Copy Constructor" << std::endl;
	*this = src;
}

Serializer& Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer Assignmnt Operator" << std::endl;
	if (this != &src)
			*this = src;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));	
}
