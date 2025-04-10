/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:02:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/01 16:43:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie_1 = new Zombie;

	zombie_1->set_zombie_name(name);
	return (zombie_1);
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];
	
	for (int i = 0; i < N; i ++)
	{
		char	digit = i + '0';
		z[i].set_zombie_name(name + " " + digit);
	}
	return (z);
}