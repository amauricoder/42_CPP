/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:20:39 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/11 14:32:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <sstream>
#include <string>

//colors declaration
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int	err_invalid_test(std::string test_name, int line, const char* file);
int	err_msg(std::string msg, int status, int line, const char* file);

#endif