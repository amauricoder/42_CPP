/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/20 11:13:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base *generate(void)
{
	//Get current time
	std::time_t now = std::time(NULL);
	//Convert to local time
	std::tm *tm_ptr = std::localtime(&now);
	int randon_nbr = tm_ptr->tm_sec % 3;
	if (randon_nbr == 1)
		return (new A);
	if (randon_nbr == 2)
		return (new B);
	return (new C);
}
//return NULL in case of error
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A by ptr" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B by ptr" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C by ptr" << std::endl;
	else
		std::cout << "Identified Unknown by ptr" << std::endl;
}
//dynamic_cast<TypeYouWantToConvert&>(Expression);
//try - catch - throw exception std::bad_cast in error
void identify(Base& p)
{
	try
	{
		A& aRef = dynamic_cast<A&>(p);
		std::cout << "Identified A class by ref" << std::endl;
		(void)aRef;
	}
	catch (const std::exception &e)
	{
		try
		{
			B& bRef = dynamic_cast<B&>(p);
			std::cout << "Identified B class by ref" << std::endl;
			(void)bRef;
		}
		catch (const std::exception &e)
		{
			try
			{
				C& cRef = dynamic_cast<C&>(p);
				std::cout << "Identified C class by ref" << std::endl;
				(void)cRef;
			}
			catch (const std::exception &e)
			{	
				std::cout << "Identifycation unknown by ref" << std::endl;
			}
		}
	}
}
