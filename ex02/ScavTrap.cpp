/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:54:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/28 15:11:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/******************************************************************************/
/*                     Orthodox Canonical Form                                */
/******************************************************************************/

ScavTrap:: ScavTrap() : ClapTrap()
{
    std::cout <<  "ScavTrap Default Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Copy Assignment operator" << std::endl; 
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy_points = src._energy_points;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

ScavTrap:: ~ScavTrap()
{
	std::cout << "ScavTrap Destructor" << std::endl; 
}

/******************************************************************************/
/*                  Constructor Requested by the subject                      */
/******************************************************************************/
ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap String Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

/******************************************************************************/
/*                Member function requested by the subject                    */
/******************************************************************************/

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is on Gate keeper mode" << std::endl;
}