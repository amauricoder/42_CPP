/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/11 19:33:52 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h> // EXIT_FAILURE and EXIT_SUCCESS
#include <vector> // std::vector
#include <deque> //std::deque
#include <cctype> // isdigit()

class PmergeMe 
{
	private:
		std::vector<int>	_v_values;
		std::deque<int>		_d_values;
		PmergeMe();
	public:
	// ORTHODOX
		PmergeMe(PmergeMe const &src);
		PmergeMe& operator=(PmergeMe const &src);
		~PmergeMe();
	//Other Constructor
		PmergeMe(std::vector<std::string> input);

	/*         TEMPLATE FUNCTION         */
		template <typename T>
		static void	print_container(T container, std::string prefix_msg)
		{
			typename T::iterator it = container.begin();
			typename T::iterator end = container.end();
			if (!prefix_msg.empty())
				std::cout << prefix_msg;
			while (it != end)
			{
				std::cout << (*it) << " ";
				it ++;
			}
			std::cout << std::endl;
		}
};

/*          ARGUMENT TREATMENT          */
bool 	is_argument_valid(int argc, std::vector<std::string> args);
bool	have_invalid_char(std::string content);

/*         ERROR TREATMENT/DEBUG         */
int		failure_msg(std::string msg, int ret_value);

#endif