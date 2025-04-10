/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:46:44 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/22 14:24:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//template functions

//this solution only works with size fixed arrays
template <typename T, std::size_t N>
int	arr_size(T (&arr)[N])
{
	(void)arr;
	return (N);
}

template <typename T, typename U, typename V>
void	iter(T addr, U len, V func)
{
	for (int i = 0; i < len; i ++)
		func(addr[i]);
	std::cout << "======================" << std::endl;
}

template <typename T>
void	callback_example(T addr_arr)
{
	std::cout << "Printed by callback: " << addr_arr << std::endl;
}

/******************************/
/* Not required by the subject*/
/******************************/

/* template <typename T>
void	acumuleNbr(T number)
{
	static T acumulative;

	acumulative += number;
	std::cout << "Acumulative: " << acumulative << std::endl;
} */
