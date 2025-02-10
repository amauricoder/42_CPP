/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:12:10 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/10 10:28:16 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**********************************************/
/*                   FUNCTIONS                */
/**********************************************/

/*              ARGUMENT TREATMENT            */

bool	is_argument_valid(int argc, char **argv)
{
	if (argc != 2)
		return (failure_msg("Error!\nInvalid Argument.", false));

	std::string valid_chars = " +-/*";
	for (int i = 0; argv[1][i] != '\0'; i++) {
		if (std::isdigit(argv[1][i]) && std::isdigit(argv[1][i + 1]))
			return failure_msg("Error!\nInvalid Argument.", false);
		if (!(std::isdigit(argv[1][i]) || valid_chars.find(argv[1][i]) != std::string::npos))
			return failure_msg("Error!\nInvalid Argument.", false);
	}

	return (true);
}

/**********************************************/
/*               DEBUG / ERROR MSG            */
/**********************************************/

int	success_msg(std::string name)
{
	std::cout << BG_GREEN << name << " SUCESS!" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	failure_msg(std::string msg, int ret_value)
{
	std::cerr << msg << std::endl;
	return (ret_value);
}