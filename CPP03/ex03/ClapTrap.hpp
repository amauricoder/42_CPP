/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:10:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/28 15:00:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
	public:
		//Ortodox Canonical 
		ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap& operator=(const ClapTrap &src);
		~ClapTrap();
		//Constructor requested by the subject
		ClapTrap(std::string name);
		//Public member functions resquested
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		//debug function (not required by the subject)
		void	printName(void);
		void	printHitPoints(void);
		void	printAttackDamage(void);
		void	printEnergyPoints(void);
};

#endif