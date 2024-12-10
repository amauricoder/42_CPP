/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:07:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/10 18:27:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor" << std::endl;
	this->p_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
	this->p_type = src.p_type;
}

WrongCat&	WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

//Member function to makeSound
void	WrongCat::makeSound() const
{
	std::cout << "OOOOOOOOOOOOOTROOOO GATO" << std::endl;
}
