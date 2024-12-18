/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:07 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 15:40:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "ScalarConverter.hpp"

int		get_input_type(const std::string &literal);
int		print_values(std::string literal, bool is_char);
void	print_char(std::string literal);
void	print_int(std::string literal, bool is_char);
void	print_float(std::string literal, bool is_char);
void	print_double(std::string literal, bool is_char);
int		print_special(std::string type);

#endif