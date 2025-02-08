/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:03 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/08 16:50:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

#define FAILURE 1
#define SUCCESS 0
#define false 0
#define true 1

#include <sstream>
#include <fstream> //std::ofstream
#include <iostream>
#include <algorithm> //lower_bound()
#include <cctype> //std::isdigit()
#include <climits> //limits
#include <string>
#include <map>


/********************* FUNCTIONS *********************/
bool							is_argument_valid(int argc, char **argv);
std::map<std::string, double> 	get_database(void);
void							process_input(std::string path, std::map<std::string, double> btc_data);
std::string 					trim_date(std::string date);
bool							is_dateformat_valid(std::string date);
bool							is_date_valid(std::string date);
int								print_values(std::string erro_msg, std::string date, double qt, std::map<std::string, double>btc_data);
void 							define_quantity_valicity(std::string &error_msg, std::istringstream &ss, double qt);
/********************* DEBUG *********************/
int		err_invalid_test(std::string test_name, int line, const char* file);
int		success_msg(std::string name);
int		failure_msg(std::string msg, int ret_value);
#endif