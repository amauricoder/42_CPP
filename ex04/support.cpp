/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:02:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 19:05:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp" 

/**
 * @brief Print error msg and return a value of exit code;
 */
int    err(std::string msg, int exit)
{
	std::cout << "Error\n" << msg << std::endl;
	return (exit);
}

/**
 * @brief Check if the arguments are valid
 * Empty "" returns error; More than 3 Arguments returns error;
 * Invalid file returns error;
 */
int argument_error(int argc, char **argv)
{
	
	if (argc != 4 || !argv[2] || !argv[3])
		return (err("Invalid Arguments", 1));

	std::ifstream file_path(argv[1]);
	if (file_path.fail())
		return (err("Invalid File", 1));
	
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (s1.empty() || s2.empty())
		return (err("Empty Argument", 1));
	return (0);
}

/**
 * @brief Gets the qt of lines of the file
 * @param file Reference for the std::ifstream file variable declared on main();
 */
int	get_qt_lines(std::ifstream &file)
{
	int	i = 0;
	std::string str;
	
	while (getline(file, str))
		i ++;
	return (i);
}

/**
 * @brief Replace s1 for s2 and save it in a big line;
 * uses getline() to read the file and save it in line,
 * then check the line using str.find() to see if s1 is present in the line.
 * if is, erase s1 using str.erase() and insert s1 in the place using line.insert();
 * Erase the last "\n" and return the line with all the info.
 */
std::string replace_word(char **argv, int qt_lines, std::ifstream &file)
{
	std::string				s1(argv[2]);
	std::string				s2(argv[3]);
	std::string				line;
	std::string				tmp;
	std::string::size_type	pos = 0;

	for (int i = 0; i < qt_lines; i ++)
	{
		getline(file, line);
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		tmp += line + "\n";
	}
	if (!tmp.empty())
		tmp.erase(tmp.end() - 1);
	return (tmp);
}
