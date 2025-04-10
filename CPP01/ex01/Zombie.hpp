/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:02:33 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/01 16:33:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>

#define RESET		"\033[0m"
#define BLACK       "\033[1;30m"
#define RED         "\033[1;31m"
#define BG_RED		"\033[41m"
#define BG_MAGENTA  "\033[45m"
#define BG_BLUE		"\033[44m"
#define UNDERLINE   "\033[4m" 

class   Zombie
{
	private:
		std::string name;
	
	public:
		Zombie();
		~Zombie();
		//setter
		void		set_zombie_name(std::string z_name);
		//getter
		std::string	get_zombie_name(void);
		//Methods
		void		announce(void);
};

Zombie *newZombie(std::string name);
Zombie *zombieHorde(int n, std::string name);
void    randomChump(std::string name);

#endif