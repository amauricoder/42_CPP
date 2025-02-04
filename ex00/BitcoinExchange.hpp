/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:03 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/04 15:05:27 by aconceic         ###   ########.fr       */
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
#include <algorithm>

/********************* FUNCTIONS *********************/
bool is_argument_valid(int argc, char **argv);

/********************* DEBUG *********************/
int	err_invalid_test(std::string test_name, int line, const char* file);
int	success_msg(std::string name);
int	failure_msg(std::string msg);
#endif