/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/20 19:12:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a(5); // init com int
		Fixed a2; //init com default constructor
		Fixed b(a); // copy constructor
		Fixed c;

		c = b; // assing constructor
		
		std::cout << "A rawbits : " << a.getRawBits() << std::endl;
		std::cout << "A is " << a << std::endl;

		b.setRawBits(60000);
		std::cout << "B rawbits : " << b.getRawBits() << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "C rawbits : " << c.getRawBits() << std::endl;
		std::cout << "c is " << c << std::endl;

		std::cout << "A2 rawbits : " << a2.getRawBits() << std::endl;
		std::cout << "a2 is " << a2 << std::endl;
		
		std::cout << BG_MAGENTA "TEST '>' OPERATOR" RESET << std::endl;
		if (a > a2)
			std::cout << "A is bigger!" << std::endl;

		std::cout << BG_MAGENTA "TEST '<' OPERATOR" RESET << std::endl;
		//set new fixed point value to a2
		a2.setRawBits(1536);
		std::cout << "a2 to int : " << a2.toInt() << std::endl;
		if (a < a2)
			std::cout << "A is lower!" << std::endl;
		
		std::cout << BG_MAGENTA "TEST '>=' OPERATOR" RESET << std::endl;
		//set new fixed point value to a2
		a2.setRawBits(1280);
		if (a >= a2)
		{
			std::cout << "a and a2 have the same value" << std::endl;
			std::cout << "a int value : " << a.toInt() << std::endl;
			std::cout << "a2 int value : " << a2.toInt() << std::endl;
		}
		std::cout << BG_MAGENTA "TEST '<=' OPERATOR" RESET << std::endl;
		//set new fixed point value to a2
		a2.setRawBits(1024);
		if (a2 <= a)
		{
			std::cout << "a2 is lower than a" << std::endl;
			std::cout << "a int value : " << a.toInt() << std::endl;
			std::cout << "a2 int value : " << a2.toInt() << std::endl;
		}
	}
	return (0);
}