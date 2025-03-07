/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:55 by aconceic          #+#    #+#             */
/*   Updated: 2025/03/07 16:45:23 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::nbr_comparations = 0;

/******************************************************************************/
/*                       ORTHODOX and CONSTRUCTORS                            */
/******************************************************************************/

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
		this->_end_v_time = 0;
		this->_initial_v_time = 0;
		this->_qt_elements = src._qt_elements;
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

/******************************************************************************/
/*                              METHODS VECTOR                                */
/******************************************************************************/

void	PmergeMe::VectorOrdenate()
{

	this->_initial_v_time = clock();
	DoPairsOrdenation(1);
	PrintContainer(this->_v_values, "AFTER DoPairsOrdenation: ");
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
	std::vector<int>::iterator last = AdvanceIterator(this->_v_values.begin(), pair_lvl * (pair_qt));
	std::vector<int>::iterator end = AdvanceIterator(last, -(is_odd * pair_lvl));

	//troca de pares dentro do container.
	//aqui os pares sao comparados e ordenados por secao
	//sobrando o tamanho do par a cada iteracao.
	int jump = 2 * pair_lvl;

	for (std::vector<int>::iterator it = start; it != end; std::advance(it, jump))
	{
		std::vector<int>::iterator this_el = AdvanceIterator(it, pair_lvl - 1);
		std::vector<int>::iterator next_el = AdvanceIterator(it, pair_lvl * 2 - 1);
		if (CompareIterators(next_el, this_el))
			SwapPairs(this_el, pair_lvl);
	}

	//recursao para continuar a ordenacao
	std::ostringstream oss;
	oss << "During " << pair_lvl << " pair level :"; 
	std::string msg = oss.str();
	PrintContainer(this->_v_values, msg);
	std::cout << "\n";

	DoPairsOrdenation(pair_lvl * 2);
	DoInsertion(pair_lvl, pair_qt, end);
}

void PmergeMe::DoInsertion(int pair_lvl, int pair_qt, std::vector<int>::iterator end)
{
	std::vector<std::vector<int>::iterator>main;
	std::vector<std::vector<int>::iterator>pend;

	/* Initialize the main chain with the {b1, a1}. */
	main.insert(main.end(), AdvanceIterator(this->_v_values.begin(), pair_lvl - 1));
	main.insert(main.end(), AdvanceIterator(this->_v_values.begin(), pair_lvl * 2 - 1));

	/* Insert the rest of a's into the main chain.
       Insert the rest of b's into the pend. */
	for (int i = 4; i <= pair_qt; i += 2)
	{
		pend.insert(pend.end(), next(this->_v_values.begin(), pair_lvl * (i - 1) - 1));
		main.insert(main.end(), next(this->_v_values.begin(), pair_lvl * i - 1));
	}

	/* If is Odd */
	if ((this->_v_values.size() / pair_lvl) % 2 == 1)
	{
		//std::cout << "entrou aqui" << std::endl;
		pend.insert(pend.end(), next(end, pair_lvl - 1));
	}
	
	/*DEBUG 1*/
/*  	std::ostringstream oss;
	oss << "Main DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg = oss.str();
	print_iterators(main, msg);
	std::cout << "\n";

	std::ostringstream oss2;
	oss2 << "Pend DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg2 = oss2.str();
	print_iterators(pend, msg2);
	std::cout << "\n"; */

	/*END DEBUG 1*/

	//NOW, I need to start to add the itens from pend to main
	static const unsigned long long jacobsthal_values[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };
	
	int	inserted_numbers_qt = 0;
	int	prev_jacobstal = jacobsthal_values[0];

	for (int k = 1; true; ++k)
	{
		int cur_jacobstal = jacobsthal_values[k];
		int jacob_diff = cur_jacobstal - prev_jacobstal;
		int offset = 0;
		if (jacob_diff > static_cast<int>(pend.size()))
            break;
		int	number_of_times = jacob_diff;
		std::vector<std::vector<int>::iterator>::iterator pend_it = pend.begin();
		std::advance(pend_it, jacob_diff - 1);
		std::vector<std::vector<int>::iterator>::iterator bound_it = main.begin();
		std::advance(bound_it, jacobsthal_values[k] + inserted_numbers_qt);
		while (number_of_times)
		{
			std::vector<std::vector<int>::iterator>::iterator insertion_pt = 
				std::upper_bound(main.begin(), bound_it, *pend_it, CompareIterators<std::vector<int>::iterator>);
			std::vector<std::vector<int>::iterator>::iterator inserted =
				main.insert(insertion_pt, *pend_it);
			number_of_times --;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			offset += (inserted - main.begin()) == cur_jacobstal + inserted_numbers_qt;
			bound_it = next(main.begin(), cur_jacobstal + inserted_numbers_qt - offset);
		}
		prev_jacobstal = cur_jacobstal;
		inserted_numbers_qt += jacob_diff;
		offset = 0;
	}

 	//DEBUG 2
	std::ostringstream oss;
	oss << "Debug 2 Main DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg = oss.str();
	print_iterators(main, msg);
	std::cout << "\n";

	std::ostringstream oss2;
	oss2 << "Debug 2 Pend DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg2 = oss2.str();
	print_iterators(pend, msg2);
	std::cout << "\n";
	//END DEBUG 2

	for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<std::vector<int>::iterator>::iterator curr_pend = next(pend.begin(), i);

        std::vector<std::vector<int>::iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + ((this->_v_values.size() / pair_lvl) % 2 == 1));

		std::vector<std::vector<int>::iterator>::iterator to_insert =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, CompareIterators<std::vector<int>::iterator>);
        main.insert(to_insert, *curr_pend);
    }
	
	//DEBUG 3
	std::ostringstream oss3;
	oss3 << "Debug 3 Main DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg3 = oss3.str();
	print_iterators(main, msg3);
	std::cout << "\n";

	std::ostringstream oss4;
	oss4 << "Debug 3 Pend DoInsertion | pair_lvl : " << pair_lvl << " -> "; 
	std::string msg4 = oss4.str();
	print_iterators(pend, msg4);
	std::cout << "\n";
	//END DEBUG 3
}
std::vector<int>::iterator PmergeMe::AdvanceIterator(std::vector<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

void	PmergeMe::SwapPairs(std::vector<int>::iterator it, int pair_lvl)
{
	std::vector<int>::iterator start = AdvanceIterator(it, -pair_lvl + 1);
	std::vector<int>::iterator end = AdvanceIterator(start, pair_lvl);
	while (start != end)
	{
		std::iter_swap(start, AdvanceIterator(start, pair_lvl));
		start ++;
	}
}

/******************************************************************************/
/*                              GENERAL FUNCTIONS                             */
/******************************************************************************/

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

void print_iterators(const std::vector<std::vector<int>::iterator> &vec, std::string prefix_msg)
{
	if (!prefix_msg.empty())
		std::cout << prefix_msg;
    for (std::vector<std::vector<int>::iterator>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *(*it) << " "; 
	}
    std::cout << std::endl;
}

