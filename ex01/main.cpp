/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 17:58:24 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		//test 1		
		Fixed a;
		Fixed b(a);
		Fixed c;
	
		c = a;
		std::cout << "a -> " << a.getRawBits() << std::endl;
		std::cout << "b -> " << b.getRawBits() << std::endl;
		std::cout << "c -> " << c.getRawBits() << std::endl;
	}
	
	return (0);
}