/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:27:00 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/20 13:54:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <sstream>

//colors definition
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"
//values definition
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

//Templates functions
template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

/******************************/
/*    TESTS (NOT REQUIRED)    */
/******************************/
int		test_max_int_positive(void);
int		test_max_int_negative(void);
int		test_max_int_positive_and_negative(void);
int		test_max_int_same_value(void);
int		test_min_int_positive(void);
int		test_min_int_negative(void);
int		test_min_int_positive_and_negative(void);
int		test_min_int_same_value(void);
int 	test_swap_int(void);
int		test_max_double_positive(void);
int		test_max_double_negative(void);
int		test_max_double_positive_and_negative(void);
int		test_max_double_same_value(void);
int		test_swap_double(void);
int		test_max_int_ptr_pos(void);
int		test_subject(void);

//DEBUG/ERROR MESSAGE
int	err_invalid_test(std::string test_name, int line, const char* file);
int	err_msg(std::string msg, int status, int line, const char* file);

#endif