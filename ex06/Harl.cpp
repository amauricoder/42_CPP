/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 18:09:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "debug message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "info message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "warning message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "error message" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string type[] = {"debug", "info", "warning", "error"};
	void	(Harl::*ptr[4])() = {&Harl::debug, &Harl::info,
									&Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i ++)
	{
		if (level == type[i])
			return ((this->*ptr[i])());
	}
}
