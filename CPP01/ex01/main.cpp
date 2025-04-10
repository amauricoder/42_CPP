/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:01:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/01 16:54:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout 
	<< "AFTER DEFEATING YOUR BEST FRIEND AND NEIGHNOUR IN ex00\n"
	<< "YOU ENCOUNTER A ZOMBIE HORDE of 10 ZOMBIES!!!"
	<< std::endl;

	Zombie *horde = zombieHorde(10, "zombie");
	
	std::cout
	<< "THE LEADER OF THE HORDE IS " << BG_BLUE << horde->get_zombie_name() << RESET
	<< "\nAND YOU CAN HEAR ALL THE OTHER ZOMBIES SCREAMING!\n"
	<< std::endl;
		
	for (int i = 0; i < 10; i ++)
		horde[i].announce();
	
	std::cout
	<< "THEN, YOU FIND A SHOTGUN AND " BG_RED "FINISH ALL THE ZOMBIES" RESET "\n"
	<< std::endl;

	delete[] horde;
	return (0);
}