/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:01 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/05 11:29:46 by aconceic         ###   ########.fr       */
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
		return (failure_msg("Error\nInvalid Argument!", false));
	std::string argv_str = argv[1];
	if (argv_str.empty() || argv_str.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		return (failure_msg("Error!\nEmpty Argument", false));
	std::ifstream file, database;
	file.open(argv[1]);
	database.open("data.csv");
	if (!file)
		return (failure_msg("Error\nInvalid File", false));
	if (!database)
		return (failure_msg("Error\nInvalid Database", false));
	file.close();
	database.close();
	return (true);
}

//Read the Bitcoin Database that the exercise give and
//return a map with values where string == DATE(YYYY-MM-DD) and double = value.
std::map<std::string, double> get_database(void)
{
	std::map<std::string, double> 	btc_data;
	std::string 					line, date;
	double							price;
	std::ifstream 					database;

	database.open("data.csv");
	std::getline(database, line);
	while (std::getline(database, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> price))
			btc_data[date] = price;
	}
	return (btc_data);
}

void	process_input(std::string path, std::map<std::string, double> btc_data)
{
	
}

/*****************************************************/
/*                       DEBUG AND TESTS             */
/*****************************************************/

void	print_map(const std::map<std::string, double> &to_print)
{
	std::map<std::string, double>::const_iterator it = to_print.begin();
	
	while (it != to_print.end())
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it ++;
	}	
}

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

int	failure_msg(std::string msg, int ret_value)
{
	std::cout << msg << std::endl;
	return (ret_value);
}