/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/29 19:02:16 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	if (test_subject())
		return (EXIT_FAILURE);
	return (0);
}

/************************************************/
/*                  TESTS                       */
/************************************************/

int test_subject(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
  	std::cout << sp.shortestSpan() << std::endl;
  	std::cout << sp.longestSpan() << std::endl;

	if (sp.shortestSpan() != 2 || sp.longestSpan() != 14)
		return (err_invalid_test("test_subject", __LINE__, __FILE__));
	return (EXIT_SUCCESS);
}

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
