/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:02:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 17:51:11 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp" 

int    err(std::string msg, int exit)
{
	std::cout << "Error\n" << msg << std::endl;
	return (exit);
}

int argument_error(int argc, char **argv)
{
	if (argc != 4)
		return (err("Invalid Arguments", 1));

	std::ifstream file_path(argv[1]);
	if (file_path.fail())
		return (err("Invalid File", 1));
	return (0);
}

int	get_qt_lines(std::ifstream &file)
{
	int	i = 0;
	std::string str;
	
	while (getline(file, str))
		i ++;
	return (i);
}