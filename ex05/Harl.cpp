/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:05 by aconceic         ###   ########.fr       */
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
 * @brief 
 */
void	Harl::complain(std::string level)
{
	std::string complain[] = {"debug", "info", "warning", "error"};
	void (Harl::*arr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //pointer to member function
	int	index = -1;

	for (int i = 0; i < 4; i ++)
	{
		if (!level.compare(complain[i]))
		{
			index = i;
			break ;
		}
	}
	if (index == -1 || level.empty())
		return ;
	(this->*arr[index])();
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