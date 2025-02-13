/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:55 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/13 16:46:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**********************************************/
/*          ORTHODOX and CONSTRUCTORS         */
/**********************************************/
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_v_values = src._v_values;
		this->_d_values = src._d_values;
		this->_v_pairs = src._v_pairs;
		this->_d_pairs = src._d_pairs;
		this->_end_v_time = 0;
		this->_initial_v_time = 0;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}


PmergeMe::PmergeMe(std::vector<std::string> input)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//Everything that is commented maybe wont be necessary
	
	std::vector<std::string>::iterator it = input.begin();
	int	convertion = 0;
	while (it != input.end())
	{
		convertion = std::atoi(it->substr(0).c_str());
		this->_v_values.push_back(convertion);
		this->_d_values.push_back(convertion);
		it ++;
	}
	this->_end_v_time = 0;
	this->_initial_v_time = 0;
	this->_qt_elements = input.size();
	PrintContainer(input, "Before: ");
	//PrintContainer(this->_v_values, "VECTOR: ");
	//PrintContainer(this->_d_values, "DEQUE: ");

	//TRYING TO DO THE PAIRS
	/* int	first_value = 0;
	int	second_value = 0;
	for (std::size_t i = 0; i < input.size(); i += 2)
	{
		if (i + 1 < input.size())
		{
			first_value = std::atoi(input[i].substr(0).c_str());
			second_value = std::atoi(input[i + 1].substr(0).c_str());
			this->_v_pairs.push_back(std::make_pair(first_value, second_value));
			this->_d_pairs.push_back(std::make_pair(first_value, second_value));
		}
		else
		{
			first_value = std::atoi(input[i].substr(0).c_str());
			this->_v_pairs.push_back(std::make_pair(first_value, -1));
			this->_d_pairs.push_back(std::make_pair(first_value, -1));
		}
	}
	print_pairs(this->_v_pairs, "(constructor)PAIRS VECTOR :");
	print_pairs(this->_d_pairs, "(constructor)PAIRS DEQUE :"); */
}

/**********************************************/
/*                   METHODS                  */
/**********************************************/

void	PmergeMe::VectorOrdenate()
{
	this->_initial_v_time = clock();
	//get time to calculate miliseconds
	//this->_initial_v_time = clock();
	//Sorting pairs
	/* std::vector<std::pair<int, int> >::iterator it = this->_v_pairs.begin();
	while (it != this->_v_pairs.end())
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
		it ++;
	}
	print_pairs(this->_v_pairs, "(VectorOrdenate)PAIRS VECTOR SORTED:"); */
	//print_pairs(this->_v_pairs, "(VectorOrdenate)2PAIRS VECTOR SORTED:");
	
	StartVectorOrdenate(1);
	this->_end_v_time = clock();
}

void	PmergeMe::StartVectorOrdenate(int pair_lvl)
{
	
	int	pair_qt = this->_v_values.size() / pair_lvl;
	if (pair_qt < 2)
		return ;
	
	std::vector<int> max;
	std::vector<int> min;
	
	while (_v_values.size() > 1) 
	{
		if (_v_values[0] > _v_values[1])
		{
			max.push_back(_v_values[0]);
			min.push_back(_v_values[1]);
		} else 
		{
			max.push_back(_v_values[1]);
			min.push_back(_v_values[0]);
		}
		_v_values.erase(_v_values.begin(), _v_values.begin() + 2);
	}
	
	while (min.size() > 0 && max.size() > 0)
	{
		_v_values.push_back(min.front());
		_v_values.push_back(max.front());
		min.erase(min.begin());
		max.erase(max.begin());
	}
	min.clear();
	max.clear();
	PrintContainer(this->_v_values, "StartVectorOrdenate: ");
}

/**********************************************/
/*                 FUNCTIONS                  */
/**********************************************/

//             ARGUMENT TREATMENT
 
bool 	is_argument_valid(int argc, std::vector<std::string> input)
{
	if (argc == 1)
		return (failure_msg("Error!\nInvalid argument.", false));

	std::vector<std::string>::iterator it = input.begin() + 1;
	while (it != input.end())
	{
		if (it->empty() || have_invalid_char((*it)))
			return (failure_msg("Error!\nInvalid argument.", false));
		it ++;
	}
	return (true);
}

bool	have_invalid_char(std::string content)
{
	for (int i = 0; content[i]; i++)
	{
		if (!std::isdigit(content[i]))
			return (true);
	}
	return (false);
}

//             ERROR TREATMENT/DEBUG/MESSAGE

int	failure_msg(std::string msg, int ret_value)
{
	std::cerr << msg << std::endl;
	return (ret_value);
}
