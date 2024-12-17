/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:07 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/17 19:18:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "ScalarConverter.hpp"

int		get_input_type(const std::string &literal);
int		print_values(std::string literal, long long original_value, long double original_float_value, long double original_double_value);
void	print_char(std::string literal);
void	print_int(long long original_value);
void	print_float(long double original_float_value);
void	print_double(long double original_double_value);
int		print_special(std::string type);

#endif