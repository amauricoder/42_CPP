/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 18:58:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "Debug Message" << std::endl;	
}
void	Harl::info(void)
{
	std::cout << "Info Message" << std::endl;	
}
void	Harl::warning(void)
{
	std::cout << "Warning Message" << std::endl;	
}
void	Harl::error(void)
{
	std::cout << "Error message" << std::endl;	
}

/**
 * @attention New Concept: Pointers to member functions
 */
void	Harl::complain(std::string level)
{
	std::string complain[] = {"debug", "info", "warning", "error"};
	void (Harl::*arr[4])() = {&Harl::debug, &Harl::info,
								&Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i ++)
	{
		if (!level.compare(complain[i]))
			return ((this->*arr[i])());
	}
	std::cout << "Not a valid complain" << std::endl;
};

/* 
void	(Harl::*ptrDebug)() = &Harl::debug;
void	(Harl::*ptrInfo)() = &Harl::info;
void	(Harl::*ptrWarning)() = &Harl::warning;
void	(Harl::*ptrError)() = &Harl::error;
(this->*ptrDebug)();
(this->*ptrInfo)();
(this->*ptrWarning)();
(this->*ptrError)(); 
*/