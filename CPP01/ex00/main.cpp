/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:18:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 19:09:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <csignal>

int main(int argc, char **argv)
{
	(void)argv;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	std::string input;

	if (argc != 1)
		return (std::cout << "Try ./ex00 instead", 1);
	std::cout 
		<< "YOU ARE IN " BG_MAGENTA "'THE WALKING DEAD'" RESET
		<< " UNIVERSE\nYOUR " << BG_BLUE "BEST FRIEND" RESET
		<< " GET BIT BY A ZOMBIE\n \nWHAT IS THE "
		<< UNDERLINE "NAME" RESET " OF YOUR BEST FRIEND???"
	<< std::endl;

	if (getline(std::cin, input).eof() == true)
		return (std::cout << BG_RED "Canceling..." RESET << std::endl, 1);

	std::cout << "NOW " << input << " " << BG_RED "IS A ZOMBIE" RESET << std::endl;

	Zombie *bestfriend = newZombie(input);
	bestfriend->announce();
	
	std::cout 
		<< "NOW, YOUR " BG_BLUE "NEIGHBOR" RESET " GET BIT BY A ZOMBIE!!!\n \n"
		<< "WHAT IS HIS " UNDERLINE "NAME" RESET "????"
	<< std::endl;
	if (getline(std::cin, input).eof() == true)
	{
		delete bestfriend;
		return (std::cout << BG_RED "Canceling..." RESET << std::endl, 1);
	}
	std::cout << "NOW " << input << " " << BG_RED "IS A ZOMBIE TOO!" RESET << std::endl;
	randomChump(input);
	delete bestfriend;
	return (0);
}
