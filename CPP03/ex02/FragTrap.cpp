/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:22:20 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/29 16:39:25 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************/
/*                     Orthodox Canonical Form                                */
/******************************************************************************/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FlagTrap Default Constructor" << std::endl;
	this->_attack_damage = 30;
	this ->_energy_points = 100;
	this->_hit_points = 100;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FlagTrap copy Constructor" << std::endl;
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this ->_energy_points = src._energy_points;
	this->_hit_points = src._hit_points;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FlagTrap overload =" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_attack_damage = src._attack_damage;
		this ->_energy_points = src._energy_points;
		this->_hit_points = src._hit_points;
	}
	return (*this);
}


FragTrap::~FragTrap()
{
	std::cout << "FlapTrap Destructor" << std::endl;
}

/******************************************************************************/
/*                    Constructor Requested by the subject                    */
/******************************************************************************/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FlagTrap String Constructor" << std::endl;
	this->_attack_damage = 30;
	this ->_energy_points = 100;
	this->_hit_points = 100;
}

/******************************************************************************/
/*                    Member Function requested by the subject                */
/******************************************************************************/

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << ": HI FIVE ?!?!" << std::endl;
}
