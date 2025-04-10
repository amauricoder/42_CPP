/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/04 11:44:13 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	if (test_subject() || test_addRange_1()
		|| test_addRange_2() || test_addRange_3()
		|| test_span_10000() || test_shortestSpan_1()
		|| test_shortestSpan_2() || test_longestSpan_1()
		|| test_longestSpan_2() || test_copy_constructor()
		|| test_copy_assignment())
		return (EXIT_FAILURE);
	return (0);
}

/************************************************/
/*                  TESTS                       */
/************************************************/

//test given by the subject
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
	return (success_msg("test_subject"));
}

//Test addRange with values from the vector of Span itself
int	test_addRange_1(void)
{
	Span sp = Span(10);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);

	sp.addRange(sp.getData().begin(), sp.getData().end());

	std::ostringstream oss;
	oss << sp.ossSpan();

	if (oss.str() != "1234512345")
		return (err_invalid_test("test_addRange_1", __LINE__, __FILE__));
	return (success_msg("test_addRange_1"));
}

//Same test as before, but this time with a vector that is not
//possible to add anymore of anything. Needs to go to exception
int	test_addRange_2(void)
{
	try
	{
		Span sp = Span(10);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		sp.addNumber(6);
		sp.addRange(sp.getData().begin(), sp.getData().end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (success_msg("test_addRange_2"));
	}
	return (err_invalid_test("test_addRange_2", __LINE__, __FILE__));
	
}

//Try to add 5 values when they are available
//using std::list<int> to test values from other type of structure
int	test_addRange_3(void)
{
	Span sp = Span(10);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);

	std::list<int> lst(5);
	lst.clear();
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(10);
	sp.addRange(lst.begin(), lst.end());
	std::ostringstream oss;
	oss << sp.ossSpan();

	if (oss.str() != "12345678910")
		return (err_invalid_test("test_addRange_3", __LINE__, __FILE__));
	return (success_msg("test_addRange_3"));
}

//Test required by the subject with 10000 numbers.
//obs. is not necessary to seed the rand() (srand(seed)),
//because for this specific test is not necessary.
int	test_span_10000(void)
{
	Span sp = Span(10000);

	for (int i = 0; i < 10000; i ++)
	{
		int number = rand() % 10000;
		sp.addNumber(number);
	}
	//sp.printSpan();
	if (sp.getMaxQt() != 10000)
		return (err_invalid_test("test_span_10000", __LINE__, __FILE__));
	return (success_msg("test_span_10000"));
}

//this must the return the value of shortest span
int	test_shortestSpan_1(void)
{
	Span sp = Span(5);
	sp.addNumber(100);
	sp.addNumber(101);
	sp.addNumber(205);
	sp.addNumber(209);
	sp.addNumber(250);

	if (sp.shortestSpan() != 1)
		return (err_invalid_test("test_shortestSpan_1", __LINE__, __FILE__));
	return (success_msg("test_shortestSpan_1"));
}

//must go to exception because there is only 1 number on Span's vector
int	test_shortestSpan_2(void)
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(1);

		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (success_msg("test_shortestSpan_2"));
	}
	return (err_invalid_test("test_shortestSpan_2", __LINE__, __FILE__));
}

//must return the value of longestspan
int	test_longestSpan_1(void)
{
	Span sp = Span(5);
	sp.addNumber(1);
	sp.addNumber(10);
	sp.addNumber(100);
	sp.addNumber(1000);
	sp.addNumber(10000);

	if (sp.longestSpan() != 9999)
		return (err_invalid_test("test_longestSpan_1", __LINE__, __FILE__));
	return (success_msg("test_longestSpan_1"));
}

//must go to exception because there is only 1 number on Span's vector
int	test_longestSpan_2(void)
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(1);
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (success_msg("test_longestSpan_2"));
	}
	return (err_invalid_test("test_longestSpan_2", __LINE__, __FILE__));
}

//values of sp and sp2 must be the same
int	test_copy_constructor(void)
{
	Span sp = Span(3);
	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);

	Span sp2 = Span(sp);
	if (sp2.getData()[0] != 10 || sp2.getData()[1] != 20 || sp2.getData()[2] != 30)
		return (err_invalid_test("test_copy_constructor", __LINE__, __FILE__));
	return (success_msg("test_copy_constructor"));
}

//values of sp and sp2 must be the same
int	test_copy_assignment(void)
{
	Span sp = Span(3);
	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);

	Span sp2 = Span(3);
	sp2.addNumber(40);
	sp2.addNumber(50);
	sp2.addNumber(60);
	
	sp2 = sp;
	if (sp2.getData()[0] != 10 || sp2.getData()[1] != 20 || sp2.getData()[2] != 30)
		return (err_invalid_test("test_copy_assignment", __LINE__, __FILE__));
	return (success_msg("test_copy_assignment"));
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

int	success_msg(std::string msg)
{
	std::cout << BG_GREEN << "SUCCESS - " << msg << RESET << std::endl;
	return (EXIT_SUCCESS);
}