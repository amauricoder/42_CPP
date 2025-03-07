/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2025/03/07 16:40:49 by aconceic         ###   ########.fr       */
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
#include <sstream>

class PmergeMe 
{
	private:
		std::vector<int>					_v_values; 
		//std::deque<int>						_d_values; 
		clock_t								_initial_v_time;
		clock_t								_end_v_time;
		int									_qt_elements;
		PmergeMe();
	public:
		static int nbr_comparations;
		// ORTHODOX
		PmergeMe(PmergeMe const &src);
		PmergeMe& operator=(PmergeMe const &src);
		~PmergeMe();
		//Other Constructor
		PmergeMe(std::vector<std::string> input);
	/******************************************************************************/
	/*                              TEMPLATES                                     */
	/******************************************************************************/
		//for comparitions
		template <typename T> 
		static bool CompareIterators(T lv, T rv) {
			PmergeMe::nbr_comparations++;
			return *lv < *rv;
		}

		template <typename T>
		T AdvanceIterator2(T it, int steps)
		{
			std::advance(it, steps);
			return it;
		}
	/******************************************************************************/
	/*                              METHODS VECTOR                                */
	/******************************************************************************/
		void									VectorOrdenate();
		void									DoPairsOrdenation(int pair_lvl);
		std::vector<int>::iterator 				AdvanceIterator(std::vector<int>::iterator it, int steps);
		void									SwapPairs(std::vector<int>::iterator it, int pair_lvl);
		void									DoInsertion(int pair_lvl, int pair_qt, std::vector<int>::iterator end);
};

/********** FUNCTIONS ***********/

/*          ARGUMENT TREATMENT          */
bool 	is_argument_valid(int argc, std::vector<std::string> args);
bool	have_invalid_char(std::string content);

/*         ERROR TREATMENT/DEBUG         */
int		failure_msg(std::string msg, int ret_value);
void	print_iterators(const std::vector<std::vector<int>::iterator> &vec, std::string prefix_msg);

template <typename T>
void	PrintContainer(T container, std::string prefix_msg)
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
#endif