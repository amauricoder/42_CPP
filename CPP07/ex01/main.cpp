/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:26:08 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/22 14:24:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"



int main(void)
{
	int int_arr[] = {1, 2, 6, 13};
	int len = arr_size(int_arr);
	iter(int_arr, len, callback_example<int>);

	std::string str_arr[] = {"first", "second", "third", "forth", "faivi"};
	len = arr_size(str_arr);
	iter(str_arr, len, callback_example<std::string>);

	double db_arr[] = {0.12, 42.13, 0.213, 0.064654, 458.45, 5484.6};
	len = arr_size(db_arr);
	iter(db_arr, len, callback_example<double>);

	float f_arr[] = {0.42f, 0.43f, 0.44f, 0.45f, 0.46f};
	len = arr_size(f_arr);
	iter(f_arr, len, callback_example<float>);

	char	ch_arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	len = arr_size(ch_arr);
	iter(ch_arr, len, callback_example<char>);
	
	/************************************************************/
	/*  below are tests for myselft not required by the subject */
	/************************************************************/
	//uncomment here and on .hpp to see if you want
	/* len = arr_size(int_arr);
	iter(int_arr, len, acumuleNbr<int>);

	len = arr_size(db_arr);
	iter(db_arr, len, acumuleNbr<double>); */
	

}
