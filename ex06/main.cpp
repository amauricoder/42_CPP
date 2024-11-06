/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:48:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 18:53:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	err(std::string msg, int exit_status)
{
	std::cout << "Error!" << std::endl;
	std::cout << msg << std::endl;
	return (exit_status);	
}

static int	complain_level(std::string &input)
{
	std::string type[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i ++)
	{
		if (input == type[i])
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	std::string input(argv[1]);
	if (argc != 2 || input.empty())
		return (err("Invalid Arguments", 1));
	Harl man;
	int level = complain_level(input);

	switch (level)
	{
	case 0:
		man.complain("debug");
		man.complain("info");
		man.complain("warning");
		man.complain("error");
		break;
	
	case 1:
		man.complain("info");
		man.complain("warning");
		man.complain("error");
		break;

	case 2:
		man.complain("warning");
		man.complain("error");
		break;

	case 3:
		man.complain("error");
		break;
	default:
		std::cout << "Probably complaining about insignificant problems" << std::endl;
		break;
	}
	
	return (0);
}
