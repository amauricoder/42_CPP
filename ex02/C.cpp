/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:17:09 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 15:29:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
	//std::cout << "C Constructor" << std::endl;
};

C::C(const C &src)
{
	//std::cout << "C Copy Constructor" << std::endl;
	*this = src;
};

C& C::operator=(const C &src)
{
	//std::cout << "C Assigment Operator" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
};

C::~C()
{
	//std::cout << "C Destructor" << std::endl;
};