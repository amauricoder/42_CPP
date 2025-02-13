/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/13 16:44:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h> // EXIT_FAILURE and EXIT_SUCCESS
#include <vector> // std::vector
#include <deque> //std::deque
#include <cctype> // isdigit()
#include <algorithm> //std::swap
#include <ctime> //clock()

class PmergeMe 
{
	private:
		std::vector<int>					_v_values; //maybe this will not be necessary
		std::deque<int>						_d_values; //maybe this will not be necessary
		std::vector<std::pair<int, int> >	_v_pairs;
		std::deque<std::pair<int, int> >	_d_pairs;
		clock_t								_initial_v_time;
		clock_t								_end_v_time;
		int									_qt_elements;
		PmergeMe();
	public:
	// ORTHODOX
		PmergeMe(PmergeMe const &src);
		PmergeMe& operator=(PmergeMe const &src);
		~PmergeMe();
	//Other Constructor
		PmergeMe(std::vector<std::string> input);
	//TEMPLATE METHODS
		template <typename T>
		static void	PrintContainer(T container, std::string prefix_msg)
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
	//METHODS
		void	VectorOrdenate();
		void	StartVectorOrdenate(int pair_lvl);
		
};

/********** FUNCTIONS ***********/

/*          ARGUMENT TREATMENT          */
bool 	is_argument_valid(int argc, std::vector<std::string> args);
bool	have_invalid_char(std::string content);

/*         ERROR TREATMENT/DEBUG         */
int		failure_msg(std::string msg, int ret_value);

//TEMPLATE FUNCTION
template <typename T>
static void	print_pairs(T container, std::string prefix_msg)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();
	if (!prefix_msg.empty())
		std::cout << prefix_msg << "\n";
	while (it != end)
	{
		std::cout << "| " << (*it).first << " | ";
		std::cout << (*it).second << " |\n";
		it ++;
	}
	std::cout << std::endl;
}

#endif