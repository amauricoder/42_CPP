/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:10:07 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/27 18:44:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/*                     Orthodox Canonical Form                                */
/******************************************************************************/
ClapTrap::ClapTrap() :  _name("Incognito"),
						_hit_points(10),
						_energy_points(10),
						_attack_damage(0)
{
	std::cout << "ClapTrap Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy Constructor Constructor" << std::endl;
	this->_name = src._name;    
}

ClapTrap&   ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy Assignment Operator" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Default Destructor" << std::endl;
}

/******************************************************************************/
/*                  Constructor Requested by the subject                      */
/******************************************************************************/
ClapTrap::ClapTrap(std::string name) :  _hit_points(10),
										_energy_points(10),
										_attack_damage(0)
{
	std::cout << "ClapTrap String Constructor" << std::endl;
	this->_name = name;
}

/******************************************************************************/
/*              Public Member Function  Requested by the subject              */
/******************************************************************************/
void	ClapTrap::attack(const std::string& target)
{	
	if (this->_hit_points > 0)
	{
		std::cout
		<< this->_name << " attacks " << target << ", causing "
		<< this->_attack_damage << " points of damage!"
		<< std::endl;
		this->_energy_points --;
		if (_energy_points < 0)
			_energy_points = 0;
		return ;
	}
	std::cout 
	<< this->_name << " don't have enought energy points to attack - "
	<< this->_energy_points << " left."
	<< std::endl;	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout
	<< this->_name << " lost " << amount << " hit points"
	<< std::endl;
	this->_hit_points -= amount;
	if (_hit_points < 0)
		_hit_points = 0;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		std::cout << this->_name << " has repaired itself, and got " << amount 
		<< " points back" << std::endl;	
		this->_hit_points += amount;
		this->_energy_points --;
		if (_energy_points < 0)
			_energy_points = 0;
		return ;
	}
	std::cout
	<< this->_name << " don't have enought energy points to repair itself - "
	<< this->_energy_points << " left."
	<< std::endl;	
}

/******************************************************************************/
/*              Debug Member Functions - Not Requested by the subject         */
/******************************************************************************/
void	ClapTrap::printName(void)
{
	std::cout << this->_name << std::endl; 
};

void	ClapTrap::printHitPoints(void)
{
	std::cout << this->_hit_points << std::endl;
};
void	ClapTrap::printAttackDamage(void)
{
	std::cout << this->_attack_damage << std::endl;
};

void	ClapTrap::printEnergyPoints(void)
{
	std::cout << this->_energy_points << std::endl;
};