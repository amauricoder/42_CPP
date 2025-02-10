/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:12:13 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/10 16:53:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

#include <iostream>
#include <stdlib.h> //to EXIT_SUCCESS adn EXIT_FAILURE
#include <stack> //to std::stack<>

//function
bool	is_argument_valid(int argc, char **argv);
int 	do_rpn(std::string expr);
void	do_operation(char op, std::stack<int> &s);

//debug / error msg
void	print_stack(std::stack<int> s);
int		success_msg(std::string name);
int		failure_msg(std::string msg, int ret_value);

#endif