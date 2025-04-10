/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/28 16:15:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	if (test_easyfind_1() || test_easyfind_2()
		|| test_easyfind_notfound() /* || test_string() */)
		return (1);
	return (0);
}

/************************************************/
/*                  TESTS                       */
/************************************************/
int	test_easyfind_1(void)
{
	std::vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	if (!easyfind(arr, 2))
		return (err_invalid_test("test_easyfind_1", __LINE__, __FILE__));
	return (EXIT_SUCCESS);
}

int	test_easyfind_2(void)
{
	std::vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	if (!easyfind(arr, 3))
		return (err_invalid_test("test_easyfind_2", __LINE__, __FILE__));
	return (EXIT_SUCCESS);
}

int	test_easyfind_notfound(void)
{
	std::vector<int> arr;
	
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(10);
	if (!easyfind(arr, 5))
		return (EXIT_SUCCESS);
	return (err_invalid_test("test_easyfind_notfound", __LINE__, __FILE__));
}

//This is a very idiot test, because the subject specifies that
//we need to use an INT vector. But I want to see the behaviour of
//the compiler.
/* int	test_string(void)
{
	std::vector<std::string> arr;
	
	arr.push_back("Hello");
	arr.push_back("its me");
	arr.push_back("Adele");

	if (!easyfind(arr, 3))
		return (err_invalid_test("test_easyfind_2", __LINE__, __FILE__));
	return (EXIT_SUCCESS);
} */
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
