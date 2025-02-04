/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:01 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/04 15:12:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/********************************************/
/*                 FUNCTIONS                */
/********************************************/
//ARGUMENT

//Check if the argument is valid. Boolean. return true(1) || false(0).
//https://stackoverflow.com/questions/7880/how-do-you-open-a-file-in-c
bool is_argument_valid(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (false);
	std::string argv_str = argv[1];
	if (argv_str.empty() || argv_str.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		return (false);
	std::ifstream file;
	file.open(argv[1]);
	if (!file)
		return (false);
	file.close();
	return (true);
}

//DEBUG
int	err_invalid_test(std::string test_name, int line, const char* file)
{
	std::ostringstream oss;
	oss << line;

	std::cerr << BG_RED << test_name << RESET << std::endl;
	std::cerr << BG_RED  "Error! in line " 
		+ oss.str() << " in file " << file << RESET
	<< std::endl;

	return (FAILURE);
}

int	success_msg(std::string name)
{
	std::cout << BG_GREEN << name << " SUCESS!" RESET << std::endl;
	return (SUCCESS);
}

int	failure_msg(std::string msg)
{
	std::cout << msg << std::endl;
	return (FAILURE);
}