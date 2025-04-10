/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/20 15:27:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << BG_GREEN "STARTING SUBJECT TEST" RESET << std::endl;
		Fixed	a;
		Fixed const b(10);
		Fixed const c(42.42f);
		Fixed const d(b);

		a = Fixed(1234.4321f);
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << BG_GREEN "STARTING OTHER TEST" RESET << std::endl;
		Fixed first;
		Fixed second(5);
		Fixed third(15.99f);
		Fixed forth(second);

		first = Fixed(666.666f);
		
		std::cout << BG_GREEN "                     " RESET << std::endl;
		std::cout << "first is " << first << std::endl;
		std::cout << "First " << first.getRawBits() << std::endl;

		std::cout << BG_MAGENTA "                     " RESET << std::endl;
		std::cout << "second is " << second << std::endl;
		std::cout << "Second " << second.getRawBits() << std::endl;
		
		std::cout << BG_GREEN "                     " RESET << std::endl;
		std::cout << "third is " << third << std::endl;
		std::cout << "Third " << third.getRawBits() << std::endl;

		std::cout << BG_MAGENTA "                     " RESET << std::endl;
		std::cout << "forth is " << forth << std::endl;
		std::cout << "Forth " << forth.getRawBits() << std::endl;
		
		std::cout << BG_GREEN "                     " RESET << std::endl;
		std::cout << "first is " << first.toInt() << " as integer" << std::endl;
		std::cout << "second is " << second.toInt() << " as integer" << std::endl;
		std::cout << "third is " << third.toInt() << " as integer" << std::endl;
		std::cout << "forth is " << forth.toInt() << " as integer" << std::endl;
		
	}
	return (0);
}