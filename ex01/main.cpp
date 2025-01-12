/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/12 12:50:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Serializer.hpp"

//new concept - reinterpret_cast<type>(to_be_casted)
int main(void)
{
	if (test_compare_data_address() || test_compare_content()
		|| test_using_same_ptr() || test_stress())
		return (FAIL);
	
	return (0);
}
