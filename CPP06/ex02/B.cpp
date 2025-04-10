/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:10:24 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B()
{
	//std::cout << "B Constructor" << std::endl;
};

B::B(const B &src)
{
	//std::cout << "B Copy Constructor" << std::endl;
	*this = src;
};

B& B::operator=(const B &src)
{
	//std::cout << "B Assignment operator" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
};

B::~B()
{
	//std::cout << "B Destructor" << std::endl;
};