/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:54:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/30 16:37:48 by aconceic         ###   ########.fr       */
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

void	ScavTrap::attack(const std::string& target)
{	
	if (this->_energy_points == 0)
		std::cout << this->_name << "DIFFERENT MSG FOR ATTTACK - no energy points" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << this->_name << "DIFFERENT MSG FOR ATTTACK - no hit points" << std::endl;
	else
	{
		std::cout
		<< this->_name << " DIFFERENT MSG FOR ATTTACK - attacks " << target << ", causing "
		<< this->_attack_damage << " points of damage - DIFFERENT MSG FOR ATTTACK!"
		<< std::endl;
		this->_energy_points --;
		if (_energy_points < 0)
			_energy_points = 0;
	}	
}

/******************************************************************************/
/*                Member function requested by the subject                    */
/******************************************************************************/

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is on Gate keeper mode" << std::endl;
}