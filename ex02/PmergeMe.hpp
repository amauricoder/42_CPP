/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/01 18:33:33 by aconceic         ###   ########.fr       */
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
#include <iomanip> // std::setprecision(6)
#include <cmath> //to pow

class PmergeMe 
{
	private:
		std::vector<int>					_v_values; 
		std::deque<int>						_d_values; 
		clock_t								_vector_initial_time;
		clock_t								_vector_end_time;
		clock_t								_deque_initial_time;
		clock_t								_deque_end_time;
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
	/*                              GETTER                                        */
	/******************************************************************************/
	std::vector<int> 	GetVector();
	std::deque<int> 	GetDeque();

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
		T AdvanceIterator(T it, int steps)
		{
			std::advance(it, steps);
			return it;
		}
	/******************************************************************************/
	/*                              METHODS VECTOR                                */
	/******************************************************************************/
		void									VectorOrdenate();
		void									DoMergeInsertVector(int pair_lvl);
		std::vector<int>::iterator 				AdvanceVecIterator(std::vector<int>::iterator it, int steps);
		void									SwapPairs(std::vector<int>::iterator it, int pair_lvl);
	/******************************************************************************/
	/*                              METHODS DEQUE                                 */
	/******************************************************************************/
		void									DequeOrdenate();
		void									DoMergeInsertDeque(int pair_lvl);
		std::deque<int>::iterator				AdvanceDequeIterator(std::deque<int>::iterator it, int steps);
		void									SwapDequePairs(std::deque<int>::iterator it, int pair_lvl);
};

/********** FUNCTIONS ***********/

/*          ARGUMENT TREATMENT          */
bool 	is_argument_valid(int argc, std::vector<std::string> args);
bool	have_invalid_char(std::string content);

/*         ERROR TREATMENT/DEBUG         */
int		failure_msg(std::string msg, int ret_value);
void	print_iterators(const std::vector<std::vector<int>::iterator> &vec, std::string prefix_msg);
long 	jacobsthal_nbr(long n);
int		check_ordenation(PmergeMe vec, PmergeMe deq);

template <typename T>
void	PrintContainer(T container, std::string prefix_msg, int lvl)
{
	if (lvl)
		std::cout << "Pair level :" << lvl << std::endl;
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