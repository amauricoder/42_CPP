/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:02:36 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/01 15:56:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	//std::cout << "Zombie Constructor" << std::endl;
}

Zombie::~Zombie()
{
	std::string name = get_zombie_name();
	std::cout 
		<< "Zombie " << BG_MAGENTA << name << RESET
		<< " has been " BG_RED "eliminated" RESET
	<< std::endl;
}

//setter
void	Zombie::set_zombie_name(std::string z_name)
{
	this->name = z_name;
}

//getter
std::string	Zombie::get_zombie_name(void)
{
	return (this->name);	
}


void    Zombie::announce(void)
{
	std::string zombie_name = get_zombie_name();

	std::cout 
		<< RED << zombie_name << RESET << BLACK ": BraiiiiiiinnnzzzZ..."RESET
	<< std::endl;
}