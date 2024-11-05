/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:31:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 14:03:37 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	//std::cout << "Weapon Constructor" << std::endl;
	setType(type);
}

Weapon::~Weapon()
{
	//std::cout << "Weapon Destructor" << std::endl;
}

void	Weapon::setType(std::string to_set)
{
	type = to_set;
}

/**
 * @attention NEW
 * @brief const std::string& -> specifies that we are returning
 * a const reference to type. This avoid an unecessary copy and allow
 * the caller to access the type value without modifing the original.
 * The const after the name of the method indicates that this is a
 * constant method. This makes sure that the function wont change any 
 * attribute of the object that is called.
 */
const std::string& Weapon::getType() const
{
	return (this->type);	
}