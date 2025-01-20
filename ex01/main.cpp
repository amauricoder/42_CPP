/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:26:08 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/20 16:04:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"



int main(void)
{

	int int_arr[] = {1, 2, 0, 6, 13};
	int len = arr_size(int_arr);
	iter(int_arr, len, callback_example<int>);

	std::string str_arr[] = {"first", "second", "third"};
	iter(str_arr, 3, callback_example<std::string>);

	double db_arr[] = {0.12, 42.13, 0.213};
	iter(db_arr, 3, callback_example<double>);
	return (0);
}
