/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:28 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 15:59:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

#define SUCCESS 0
#define FAIL 1

#include <sstream>

int	test_instanciate_Base(void);
int	test_instanciate_ABC(void);
void test_identify_ptr_a(void);
void test_identify_ptr_b(void);
void test_identify_ptr_c(void);
void test_identify_ref_a(void);
void test_identify_ref_b(void);
void test_identify_ref_c(void);
void test_identify_unknown(void);

int	err_invalid_test(std::string test_name, int line, const char* file);
int	err_msg(std::string msg, int status, int line, const char* file);

#endif