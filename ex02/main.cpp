/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:01:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 12:27:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"

int main(void)
{
	
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << BG_MAGENTA "ADDRESSES" RESET << std::endl;
	std::cout << "Memory address of str variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringREF << std::endl;//3
	
	std::cout << BG_MAGENTA "VALUES" RESET << std::endl;
	std::cout << "The value of str variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}

/*
	std::string &stringREF = str;
	Creates a reference called stringREF to str. 
	A reference in C++ is an alias for an existing variable, 
	so stringREF is essentially another name for str. 
	When you use stringREF, it directly accesses the str variable's 
	value and memory address without any need for dereferencing.
*/