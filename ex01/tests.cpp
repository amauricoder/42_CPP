/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:18:56 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/11 14:22:11 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

/***********************************************/
/*               DEBUG/ERROR MESSAGE           */
/***********************************************/

int	err_invalid_test(std::string test_name, int line, const char* file)
{
	std::ostringstream oss;
	oss << line;

	std::cerr << BG_RED << test_name << RESET << std::endl;
	std::cerr << BG_RED  "Error! in line " 
		+ oss.str() << " in file " << file << RESET
	<< std::endl;

	return (EXIT_FAILURE);
}

//print error msg and return status
int	err_msg(std::string msg, int status, int line, const char* file)
{
	std::cerr << "Error! Line " << line << " file " << file << "\n" << msg << std::endl;
	return (status);
}
