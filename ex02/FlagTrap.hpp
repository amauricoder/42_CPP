/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:22:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/28 16:28:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ScavTrap.hpp"

class FlagTrap : public ClapTrap
{
	public :
		FlagTrap();
		FlagTrap(std::string name);
		FlagTrap(const FlagTrap &src);
		FlagTrap& operator=(const FlagTrap &src);
		~FlagTrap();
		
		void	highFivesGuys(void);
};

#endif
