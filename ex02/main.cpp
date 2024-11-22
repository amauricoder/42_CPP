/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/22 16:39:09 by aconceic         ###   ########.fr       */
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
		std::cout << BG_MAGENTA "TEST '==' OPERATOR" RESET << std::endl;
		//set new fixed point value to a2
		a2.setRawBits(1280);
		if (a2 == a)
		{
			std::cout << "a2 is equal to a" << std::endl;
			std::cout << "a int value : " << a.toInt() << std::endl;
			std::cout << "a2 int value : " << a2.toInt() << std::endl;
		}
		std::cout << BG_MAGENTA "TEST '!=' OPERATOR" RESET << std::endl;
		//set new fixed point value to a2
		a2.setRawBits(1024);
		if (a2 != a)
		{
			std::cout << "a2 is different to a" << std::endl;
			std::cout << "a int value : " << a.toInt() << std::endl;
			std::cout << "a2 int value : " << a2.toInt() << std::endl;
		}
		//Test sum
		std::cout << BG_MAGENTA "TEST '+' OPERATOR" RESET << std::endl;
		Fixed sum;
		sum = a + a2;
		std::cout << sum.getRawBits() << "\n" << sum << std::endl;
		
		//Test Diff
		std::cout << BG_MAGENTA "TEST '+' OPERATOR" RESET << std::endl;
		Fixed diff;
		diff = a - a2;
		std::cout << diff.getRawBits() << "\n" << diff << std::endl;

		//Test Multiplication
		a.setRawBits(1280);
		a2.setRawBits(1280);
		std::cout << BG_MAGENTA "TEST '*' OPERATOR" RESET << std::endl;
		std::cout << a << std::endl;
		std::cout << a2 << std::endl;
		Fixed mult;
		mult = a * a2;
		std::cout << "raw bits : " << mult.getRawBits() << "\nInt : " << mult.toInt() << std::endl;
		
		//Test Divisiom
		std::cout << BG_MAGENTA "TEST '/' OPERATOR" RESET << std::endl;
		a.setRawBits(1536);
		a2.setRawBits(512);
		std::cout << a << std::endl;
		std::cout << a2 << std::endl;
		Fixed div;
		div = a / a2;
		std::cout << "raw bits : " << div.getRawBits() << "\nInt : " << div.toInt() << std::endl;
		
		//Test increments
		std::cout << BG_MAGENTA "TEST PRE INCREMENT" RESET << std::endl;
		//pre increment
		a.setRawBits(1280);
		std::cout << "Initial value: " << a << std::endl;
		for (int i = 0; i < 5; i ++)
		{
			Fixed b;
			b = a++;
			std::cout << "After a++ (iteration " << i + 1 << "): " << a << ", returned: " << b << std::endl;
		}
		std::cout << "Final value after all increments: " << a << std::endl;

		//post increment
		std::cout << BG_MAGENTA "TEST POST INCREMENT" RESET << std::endl;
		a.setRawBits(1280);
		std::cout << "Initial value: " << a << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Fixed b;
			b = ++a;
			std::cout << "After ++a (iteration " << i + 1 << "): " << a << ", returned: " << b << std::endl;
		}
		std::cout << "Final value after all increments: " << a << std::endl;
		
		//test decrements
		std::cout << BG_MAGENTA "TEST PRE DECREMENT" RESET << std::endl;
		//PRE DECREMENT
		a.setRawBits(1280);
		std::cout << "Initial value: " << a << std::endl;
		for (int i = 0; i < 5; i ++)
		{
			Fixed b;
			b = a--;
			std::cout << "After a-- (iteration " << i + 1 << "): " << a << ", returned: " << b << std::endl;
		}
		std::cout << "Final value after all increments: " << a << std::endl;
		
		std::cout << BG_MAGENTA "TEST POST DECREMENT" RESET << std::endl;
		a.setRawBits(1280);
		std::cout << "Initial value: " << a << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Fixed b;
			b = --a;
			std::cout << "After --a (iteration " << i + 1 << "): " << a << ", returned: " << b << std::endl;
		}

		std::cout << BG_MAGENTA "TEST STATIC MEMBER FUNCTIONS" RESET << std::endl;
		//testing non constant
		a.setRawBits(1280);
		a2.setRawBits(256);
		Fixed nonconst_min = Fixed::min(a, a2);
		std::cout << "No constant min : " << nonconst_min << std::endl;
		nonconst_min = a;
		std::cout << "No constant min after modify because its possible : " 
			<< nonconst_min << std::endl;

		//testing constant
		const Fixed const_min = Fixed::min(a, a2);
		std::cout << "Constant min : " << const_min << std::endl;
		
		/* 
		//uncomment this to test the constant
		//it will return a compilation error
		const_min = a;
		std::cout << "No constant min after modify because its possible : " 
			<< const_min << std::endl; 
		*/
		
		Fixed nonconst_max = Fixed::max(a, a2);
		std::cout << "No constant max : " << nonconst_max << std::endl;
		nonconst_max = a2;
		std::cout << "No constant max after modify because its possible : " 
			<< nonconst_max << std::endl;

		const Fixed const_max = Fixed::max(a2, a);
		std::cout << "Constant max : " << const_max << std::endl;
		
		/* 
		//uncomment this to test the constant
		//it will return a compilation error
		const_max = a;
		std::cout << "No constant min after modify because its possible : " 
			<< const_max << std::endl; 
		*/
	}
	return (0);
}