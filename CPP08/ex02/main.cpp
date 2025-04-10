/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/03 21:59:52 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	if (test_subject() || test_with_list()
		|| test_print_using_iterator())
		return (EXIT_FAILURE);
	return (0);
}

/************************************************/
/*                  TESTS                       */
/************************************************/
int	test_subject(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
    	std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack);
	return (success_msg("test_subject"));
}

int	test_with_list(void)
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3); mstack.push_back(5); mstack.push_back(737); //[...] mstack.push(0);
	std::list<int>::iterator it = mstack.begin(); std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
    	std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int, std::list<int> > s(mstack);
	return (success_msg("test_with_list"));
}

int	test_print_using_iterator(void)
{
	MutantStack<int> st;
	
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	for (MutantStack<int>::iterator it = st.begin(); it != st.end(); it ++)
		std::cout << (*it) << "\n";
	return (success_msg("test_print_using_iterator"));
}

int	test_using_float(void)
{
	MutantStack<float> st;
	
	return (success_msg("test_using_float"));
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