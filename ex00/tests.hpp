/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:03:26 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/17 17:39:36 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "ScalarConverter.hpp"

//colors declaration
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int	test_instantiate_ScalarConverter(void);
int	test_ScalarConverter_char_type_alphabet(void);
int	test_ScalarConverter_char_not_printable(void);
int	test_ScalarConverter_char_not_letter(void);
int test_ScalarConverter_nan(void);
int	test_inf_positive(void);
int	test_inf_negative(void);

int	err_invalid_test(std::string test_name, int line, const char* file);
int	err_msg(std::string msg, int status, int line, const char* file);

#endif