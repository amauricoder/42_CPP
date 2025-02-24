/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:55 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/24 16:26:45 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::nbr_comparations = 0;

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
		//this->_d_values = src._d_values;
		this->_v_pairs = src._v_pairs;
		//this->_d_pairs = src._d_pairs;
		this->_end_v_time = 0;
		this->_initial_v_time = 0;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}


PmergeMe::PmergeMe(std::vector<std::string> input)
{
	std::vector<std::string>::iterator it = input.begin();
	int	convertion = 0;
	while (it != input.end())
	{
		convertion = std::atoi(it->substr(0).c_str());
		this->_v_values.push_back(convertion);
		//this->_d_values.push_back(convertion);
		it ++;
	}
	this->_end_v_time = 0;
	this->_initial_v_time = 0;
	this->_qt_elements = input.size();
	//PrintContainer(input, "Before: ");
}

/**********************************************/
/*               METHODS VECTOR               */
/**********************************************/

void	PmergeMe::VectorOrdenate()
{

	this->_initial_v_time = clock();
	DoPairsOrdenation(1);
	PrintContainer(this->_v_values, "AFTER DoPairsOrdenation: ");
	//DoMergeInsertionSort();
	this->_end_v_time = clock();
}

void	PmergeMe::DoPairsOrdenation(int pair_lvl)
{
	//Count numbers of pairs. If there are no pairs, stop recurtion.
	int	pair_qt = this->_v_values.size() / pair_lvl;
	if (pair_qt < 2)
		return ;
	
	bool is_odd = pair_qt % 2 == 1;

	//determina o inicio e fim da iteracao
	std::vector<int>::iterator start = this->_v_values.begin();
	std::vector<int>::iterator last = next(this->_v_values.begin(), pair_lvl * (pair_qt));
	std::vector<int>::iterator end = next(last, -(is_odd * pair_lvl));

	//troca de pares dentro do container.
	//aqui os pares sao comparados e ordenados por secao
	//sobrando o tamanho do par a cada iteracao.
	int jump = 2 * pair_lvl;
	
	for (std::vector<int>::iterator it = start; it != end; std::advance(it, jump))
	{
		std::vector<int>::iterator this_pair = next(it, pair_lvl - 1);
		std::vector<int>::iterator next_pair = next(it, pair_lvl * 2 - 1);
		if (compare_its(next_pair, this_pair))
			swap_pairs(this_pair, pair_lvl);
	}

	//recursao para continuar a ordenacao
	std::ostringstream oss;
	oss << "During " << pair_lvl << " pair level :"; 
	std::string msg = oss.str();
	PrintContainer(this->_v_values, msg);
	std::cout << "\n";
	DoPairsOrdenation(pair_lvl * 2);
	//DoMergeInsertionSort();
}

void PmergeMe::DoMergeInsertionSort()
{
	std::vector<int>main;
	std::vector<int>pend;

	main.insert(main.end(), this->_v_values[0]);
	main.insert(main.end(), this->_v_values[1]);
	for (int i = 2; i < this->_qt_elements; i ++)
	{
		if (i % 2 == 0)
			pend.insert(pend.end(), this->_v_values[i]);
		else
			main.insert(main.end(), this->_v_values[i]);
	}
	PrintContainer(main, "Main :");
	PrintContainer(pend, "Pend :");
}
std::vector<int>::iterator PmergeMe::next(std::vector<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

bool PmergeMe::compare_its(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
	PmergeMe::nbr_comparations ++;
	return (*left < *right);
}

void	PmergeMe::swap_pairs(std::vector<int>::iterator it, int pair_lvl)
{
	std::vector<int>::iterator start = next(it, -pair_lvl + 1); //por que -pair_lvl
	std::vector<int>::iterator end = next(start, pair_lvl);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_lvl));
		start ++;
	}
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
