/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:01:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 15:15:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/**
 * @brief Exercise CPP01 ex04 - Read subject for requirements.
 * Check arguments validity, open the file, replace s1 for s2 and save it
 * in a string, create the new file and save the string in the new_file.
 */
int main(int argc, char **argv)
{
	if (argument_error(argc, argv))
		return (1);
	
	std::ifstream	file(argv[1]);
	int				qt_lines = get_qt_lines(file);

	file.clear();          // Clear any EOF or fail flags
    file.seekg(0);         // Move back to the beginning of the file
	std::string		lines_replaced = replace_word(argv, qt_lines, file);;
	std::string		new_file_name = std::string(argv[1]) + ".replace";
	std::ofstream	new_file;
	new_file.open(new_file_name.c_str());
	if (new_file.fail())
		return (err("Problem creating the file", 1));
	new_file << lines_replaced;
	return (0);
}