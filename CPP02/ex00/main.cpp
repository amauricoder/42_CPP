/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 17:26:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"

/**
 * @attention New concept! Orthodox Canonical Form
 * @brief More info on FixedPoint.hpp
 */
int main(void)
{
	FixedPoint	a;
	FixedPoint	b(a);
	FixedPoint	c;

	c = a;

	std::cout << "a -> " << a.getRawBits() << std::endl;
	std::cout << "b -> " << b.getRawBits() << std::endl;
	std::cout << "c -> " << c.getRawBits() << std::endl;
	
	a.setRawBits(42);
	FixedPoint d(a);
	std::cout << "d -> " << d.getRawBits() << std::endl;
	return (0);
}