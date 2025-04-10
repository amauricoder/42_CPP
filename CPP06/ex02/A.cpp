/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:40:44 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:39 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A()
{
	//std::cout << "A Constructor" << std::endl;

	//uncomment line below to run test test_instanciate_ABC()
	//this is throwing an error just to check if the function is working properly.
	//throw std::runtime_error("Error instantiating A");
}

A::A(const A &src)
{
	//std::cout << "A Copy Constructor" << std::endl;
	*this = src;
}

A& A::operator=(const A &src)
{
	//std::cout << "A Assignment operator" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

A::~A()
{
	//std::cout << "A Destructor" << std::endl;
}