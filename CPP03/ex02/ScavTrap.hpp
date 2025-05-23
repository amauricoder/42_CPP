/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:54:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/28 14:51:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap();
		
		void	guardGate();
};

#endif