/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:01 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/02 17:20:40 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/********************************************/
/*                 FUNCTIONS                */
/********************************************/

/*--------------------------- ARGUMENT TREATMENT ---------------------------*/

//Check if the argument is valid. Boolean. return true(1) || false(0).
//https://stackoverflow.com/questions/7880/how-do-you-open-a-file-in-c
//https://cplusplus.com/reference/istream/istream/peek/
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
	if (!file || file.peek() == std::ifstream::traits_type::eof())
		return (failure_msg("Error\nInvalid File", false));
	if (!database || database.peek() == std::ifstream::traits_type::eof())
		return (failure_msg("Error\nInvalid Database", false));
	file.close();
	database.close();
	return (true);
}

/*--------------------------- DATABASE TREATMENT ---------------------------*/

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
	if (btc_data.empty())
		exit(failure_msg("Error\nInvalid Database!", EXIT_FAILURE));
	return (btc_data);
}

/*--------------------------- IMPUT TREATMENT ---------------------------*/

/**
 * Get file data, get the date until |, then check if the date is a vald date.
 * Check if the quantity given is valid, then print the values.
 */
void	process_input(std::string path, std::map<std::string, double> btc_data)
{
	std::string		line, date, error_msg;
	double			qt;
	std::ifstream	input;

	input.open(path.c_str());
	//std::getline(input, line); //uncomment this if evaluator does not accept my solution, just is just to jump the first line
	while (std::getline(input, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, '|'))
		{
			date = trim_date(date);
			if (!is_dateformat_valid(date) || !is_date_valid(date))
				error_msg = "Error: bad input => " + date;
			if (!(ss >> qt))
				qt = 0;
			define_quantity_valicity(error_msg, ss, qt);
			print_values(error_msg, date, qt, btc_data);
			error_msg.clear();
		}
	}
}

/*--------------------------- DATE TREATMENT ---------------------------*/

//erase(pos,n) -> remove n chars from the pos n
//std::remove() move all the occurences of char ' ' to the end of the string
/* Remove invalid spaces*/
std::string trim_date(std::string date)
{
	//std::cout << "THIS IS DATE " << date << std::endl;
	if (date.length() < 10)
		return (date);
	for (int i = 9; date[i]; i++)
	{
		if (std::isalpha(date[i]))
			return (date);
	}
	date.erase(std::remove(date.begin() + 9, date.end(), ' '), date.end());
	return (date);
}

/*
 * Check if the date format is valid following the subject Recquirements
 */
bool is_dateformat_valid(std::string date)
{
	if (date.length() == 10)
	{
		for (int i = 0; date[i]; i++)
		{
			if (i == 4 || i == 7)
			{
				if (date[i] != '-')
					return (false);
			}
			else 
			{
				if (!std::isdigit(date[i]))
					return (false);
			}
		}
		return (true);
	}
	return (false);
}

/*
	Check if the date is a valid, includes leap year solution.
*/
bool	is_date_valid(std::string date)
{
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 6).c_str());
	int	day = std::atoi(date.substr(8, 10).c_str());
	int	days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
       days_in_month[1] = 29;

	if (year <= 0 || year > 3025 || month < 1 
		|| month > 12 || day > days_in_month[month - 1] || day <= 0)
		return (false);
	return (true);
}

//std::lower_bound(first, last, value);
int	print_values(std::string error_msg, std::string date, double qt, std::map<std::string, double>btc_data)
{
	if (!error_msg.empty())
		return (failure_msg(error_msg, FAILURE));
	
	std::map<std::string, double>::iterator it = btc_data.lower_bound(date);
	if (it != btc_data.end())
	{
		if (it->first == date)
			std::cout << it->first << " => " << qt << " = " << it->second * qt <<std::endl;
		else
		{
			if (it != btc_data.begin())
			{
				it --;
				std::cout << it->first << " => " << qt << " = " << it->second * qt <<std::endl;
			}
			else
				std::cout << it->first << " => " << qt << " = " << it->second * qt <<std::endl;
		}
	}
	else
	{
		it--;
		std::cout << it->first << " => " << qt << it->second * qt <<std::endl;
	}
	return (SUCCESS);
}

/*--------------------------- PRICE TREATMENT ---------------------------*/

//check if price is valid
//if not, it will set an specific error msg that will triggers on the next function
void	define_quantity_valicity(std::string &error_msg, std::istringstream &ss, double qt)
{
	std::string line;
	ss >> line;
	if (!line.empty())
		error_msg = "Error: " + line + " invalid characters";
	if (!error_msg.empty())
		return ;
	if (!qt)
		error_msg = "Error: no bitcoin quantity defined.";
	if (qt < 0)
		error_msg = "Error: not a positive number.";
	if (qt > 1000)
		error_msg = "Error: too large a number.";
}

/*****************************************************/
/*                       DEBUG AND TESTS             */
/*****************************************************/


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