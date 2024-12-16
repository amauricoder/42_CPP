/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/16 17:27:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//static int	err_invalid_test(std::string test_name, int line);
#include "tests.hpp"

int main(int argc, char **argv)
{
	(void)argv;

	if (argc != 2)
		return (err_msg("invalid argument.", 1, __LINE__, __FILE__));
	
	return (0);
}

