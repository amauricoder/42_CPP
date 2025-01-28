/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:02:51 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/28 16:15:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

//templates
template <typename T>
int	*easyfind(T &container, int nbr);
template <typename T>
int	*found_item(T &it);
int	test_easyfind_1(void);
int	test_easyfind_2(void);
int	test_easyfind_notfound(void);
//int	test_string(void);
int	err_invalid_test(std::string test_name, int line, const char* file);

#include "easyfind.tpp"

#endif