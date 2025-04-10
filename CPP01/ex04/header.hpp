/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 14:48:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <fstream> //::ifstream
#include <cstring> //c_str()

int			err(std::string msg, int exit);
int 		argument_error(int argc, char **argv);
int			get_qt_lines(std::ifstream &file);
std::string replace_word(char **argv, int qt_lines, std::ifstream &file);

#endif