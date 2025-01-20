/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:46:44 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/20 16:04:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//template functions
template <typename T>
int	arr_size(T arr)
{
	int	i = 0;
	while (arr[i])
	{
		std::cout << arr[i] << std::endl;
		i ++;
	}
	return (i);	
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
