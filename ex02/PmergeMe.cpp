/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:55 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/01 18:47:27 by aconceic         ###   ########.fr       */
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
		this->_d_values = src._d_values;
		this->_vector_end_time = 0;
		this->_vector_initial_time = 0;
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
		this->_d_values.push_back(convertion);
		it ++;
	}
	this->_vector_end_time = 0;
	this->_vector_initial_time = 0;
	this->_qt_elements = input.size();
}


/******************************************************************************/
/*                              GETTER                                        */
/******************************************************************************/
std::vector<int> PmergeMe::GetVector()
{
	return (this->_v_values);
}

std::deque<int> PmergeMe::GetDeque()
{
	return (this->_d_values);	
}

/******************************************************************************/
/*                              METHODS VECTOR                                */
/******************************************************************************/

void	PmergeMe::VectorOrdenate()
{

	PrintContainer(this->_v_values, "Before : ", 0);
	this->_vector_initial_time = clock();
	DoMergeInsertVector(1);
	this->_vector_end_time = clock();
	double total_time = static_cast<double>(this->_vector_end_time - this->_vector_initial_time) / CLOCKS_PER_SEC;
	PrintContainer(this->_v_values, "After : ", 0);
	std::cout << "Time to process range of " 
		<< this->_v_values.size() << " elements with std::vector: "
		<< std::fixed << std::setprecision(6) << total_time << " us\n";
}

void	PmergeMe::DoMergeInsertVector(int pair_lvl)
{
	typedef std::vector<int>::iterator Iterator;
	
	//Count numbers of pairs. If there are no pairs, stop recurtion.
	int	pair_qt = this->_v_values.size() / pair_lvl;
	if (pair_qt < 2)
		return ;
	
	//check if has stray itens
	bool has_stray = pair_qt % 2 == 1;

	//determines the beginning and end of operation
	Iterator start = this->_v_values.begin();
	Iterator last = AdvanceIterator(this->_v_values.begin(), pair_lvl * (pair_qt));
	Iterator end = AdvanceIterator(last, -(has_stray * pair_lvl));

	//swap pairs inside the container
	//here, the pairs are swapped by section
	//changing the pair by each iteration
	int jump = 2 * pair_lvl;
	for (Iterator it = start; it != end; std::advance(it, jump))
	{
		Iterator this_el = AdvanceVecIterator(it, pair_lvl - 1);
		Iterator next_el = AdvanceVecIterator(it, pair_lvl * 2 - 1);
		if (CompareIterators(next_el, this_el))
			SwapPairs(this_el, pair_lvl);
	}

	DoMergeInsertVector(pair_lvl * 2);
	std::vector<Iterator>main;
	std::vector<Iterator>pend;

	//init main with {b1, a1}
	main.insert(main.end(), AdvanceVecIterator(this->_v_values.begin(), pair_lvl - 1));
	main.insert(main.end(), AdvanceVecIterator(this->_v_values.begin(), pair_lvl * 2 - 1));
	
	//insert the rest of a's into main chain
	//insert the rest of b's into the pend
	for (int i = 4; i <= pair_qt; i += 2)
	{
		pend.insert(pend.end(), AdvanceIterator(this->_v_values.begin(), pair_lvl * (i - 1) - 1));
		main.insert(main.end(), AdvanceIterator(this->_v_values.begin(), pair_lvl * i - 1));
	}

	//insert odd element
	if (has_stray)
	{
		pend.insert(pend.end(), AdvanceIterator(end, pair_lvl - 1));
	}

	 /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
       During insertion, main numbers serve as an upper bound for inserting numbers,
       in order to save number of comparisons, as we know already that, for example,
       b5 is lesser than a5, we binary search only until a5, not until the end
       of the container.
    	We can calculate the index of the bound element. With the way I do it,
        the index of the bound is inserted_numbers + current_jacobsthal_number. */
	int prev_jacobsthal = jacobsthal_nbr(1);
	int inserted_numbers = 0;
	for (int k = 2; true; k ++)
	{
		int curr_jacobsthal = jacobsthal_nbr(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
		int nbr_of_times = jacobsthal_diff;
		std::vector<Iterator>::iterator pend_it = 
			AdvanceIterator(pend.begin(), jacobsthal_diff - 1);
		std::vector<Iterator>::iterator bound_it =
            AdvanceIterator(main.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			std::vector<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, CompareIterators<Iterator>);
			std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			/* Sometimes the inserted number in inserted at the exact index of where the bound should be.
			   When this happens, it eclipses the bound of the next pend, and it does more comparisons
			   than it should. We need to offset when this happens. */
			   offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			   bound_it = AdvanceIterator(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
	}
	
	/* Insert the remaining elements in the sequential order. Here we also want to
       perform as less comparisons as possible, so we calculate the starting bound
       to insert pend number to be the pair of the first pend number. If the first
       pend number is b6, the bound is a6, if the pend number is b8, the bound is a8 etc.
       With the way I do it the index of bound is
       size_of_main - size_of_pend + index_of_current_pend. */
	   for (size_t i = 0; i < pend.size(); i++)
	   {
			std::vector<std::vector<int>::iterator>::iterator curr_pend = 
		   		AdvanceIterator(pend.begin(), i);
			std::vector<std::vector<int>::iterator>::iterator curr_bound =
		   		AdvanceIterator(main.begin(), main.size() - pend.size() + i + has_stray);
			std::vector<std::vector<int>::iterator>::iterator idx =
			   std::upper_bound(main.begin(), curr_bound, *curr_pend, CompareIterators<std::vector<int>::iterator>);
		   main.insert(idx, *curr_pend);
	   }

	    /* Use copy vector to store all the numbers, in order not to overwrite the
    	original iterators. */
		std::vector<int> copy;
		copy.reserve(this->_v_values.size());
	   	for (std::vector<std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	   	{
			for (int i = 0; i < pair_lvl; i++)
			{
				std::vector<int>::iterator pair_start = *it;
				std::advance(pair_start, -pair_lvl + i + 1);
				copy.insert(copy.end(), *pair_start);
			}
		}

		/* Replace values in the original container. */
		Iterator container_it = this->_v_values.begin();
    	std::vector<int>::iterator copy_it = copy.begin();
    	while (copy_it != copy.end())
    	{
    	    *container_it = *copy_it;
   	     	container_it++;
   	     	copy_it++;
   		}
}

std::vector<int>::iterator PmergeMe::AdvanceVecIterator(std::vector<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

void	PmergeMe::SwapPairs(std::vector<int>::iterator it, int pair_lvl)
{
	std::vector<int>::iterator start = AdvanceVecIterator(it, -pair_lvl + 1);
	std::vector<int>::iterator end = AdvanceVecIterator(start, pair_lvl);
	while (start != end)
	{
		std::iter_swap(start, AdvanceVecIterator(start, pair_lvl));
		start ++;
	}
}

/******************************************************************************/
/*                              METHODS DEQUE                                 */
/******************************************************************************/
void	PmergeMe::DequeOrdenate()
{
	//PrintContainer(this->_d_values, "Before : ", 0);
	this->_deque_initial_time = clock();
	DoMergeInsertDeque(1);
	this->_deque_end_time = clock();
	double total_time = static_cast<double>(this->_deque_end_time - this->_deque_initial_time) / CLOCKS_PER_SEC;
	//PrintContainer(this->_d_values, "After : ", 0);
	std::cout << "Time to process range of " 
		<< this->_qt_elements << " elements with std::deque: "
		<< std::fixed << std::setprecision(6) << total_time << " us\n";
}

void	PmergeMe::DoMergeInsertDeque(int pair_lvl)
{
	typedef std::deque<int>::iterator Iterator;

	int	pair_qt = this->_d_values.size() / pair_lvl;
	if (pair_qt < 2)
		return ;
	
	bool has_stray = pair_qt % 2 == 1;

	Iterator start = this->_d_values.begin();
	Iterator last = AdvanceIterator(this->_d_values.begin(), pair_lvl * (pair_qt));
	Iterator end = AdvanceIterator(last, -(has_stray * pair_lvl));

	int jump = 2 * pair_lvl;
	for (Iterator it = start; it != end; std::advance(it, jump))
	{
		Iterator this_el = AdvanceIterator(it, pair_lvl - 1);
		Iterator next_el = AdvanceIterator(it, pair_lvl * 2 - 1);
		if (CompareIterators(next_el, this_el))
			SwapDequePairs(this_el, pair_lvl);
	}

	DoMergeInsertDeque(pair_lvl * 2);
	std::deque<Iterator>main;
	std::deque<Iterator>pend;

	main.insert(main.end(), AdvanceIterator(this->_d_values.begin(), pair_lvl - 1));
	main.insert(main.end(), AdvanceIterator(this->_d_values.begin(), pair_lvl * 2 - 1));
	for (int i = 4; i <= pair_qt; i += 2)
	{
		pend.insert(pend.end(), AdvanceIterator(this->_d_values.begin(), pair_lvl * (i - 1) - 1));
		main.insert(main.end(), AdvanceIterator(this->_d_values.begin(), pair_lvl * i - 1));
	}

	if (has_stray)
	{
		pend.insert(pend.end(), AdvanceIterator(end, pair_lvl - 1));
	}

	int prev_jacobsthal = jacobsthal_nbr(1);
	int inserted_numbers = 0;
	for (int k = 2; true; k ++)
	{
		int curr_jacobsthal = jacobsthal_nbr(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
		int nbr_of_times = jacobsthal_diff;
		std::deque<Iterator>::iterator pend_it = 
			AdvanceIterator(pend.begin(), jacobsthal_diff - 1);
		std::deque<Iterator>::iterator bound_it =
            AdvanceIterator(main.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			std::deque<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, CompareIterators<Iterator>);
			std::deque<Iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = AdvanceIterator(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
	}
	
	   for (size_t i = 0; i < pend.size(); i++)
	   {
			std::deque<std::deque<int>::iterator>::iterator curr_pend = 
		   		AdvanceIterator(pend.begin(), i);
			std::deque<std::deque<int>::iterator>::iterator curr_bound =
		   		AdvanceIterator(main.begin(), main.size() - pend.size() + i + has_stray);
			std::deque<std::deque<int>::iterator>::iterator idx =
			   std::upper_bound(main.begin(), curr_bound, *curr_pend, CompareIterators<std::deque<int>::iterator>);
		   main.insert(idx, *curr_pend);
	   }

		std::deque<int> copy;
	   	for (std::deque<std::deque<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	   	{
			for (int i = 0; i < pair_lvl; i++)
			{
				std::deque<int>::iterator pair_start = *it;
				std::advance(pair_start, -pair_lvl + i + 1);
				copy.push_back(*pair_start);
			}
		}

		Iterator container_it = this->_d_values.begin();
    	std::deque<int>::iterator copy_it = copy.begin();
    	while (copy_it != copy.end())
    	{
    	    *container_it = *copy_it;
   	     	container_it++;
   	     	copy_it++;
   		}
}

std::deque<int>::iterator PmergeMe::AdvanceDequeIterator(std::deque<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

void	PmergeMe::SwapDequePairs(std::deque<int>::iterator it, int pair_lvl)
{
	std::deque<int>::iterator start = AdvanceIterator(it, -pair_lvl + 1);
	std::deque<int>::iterator end = AdvanceIterator(start, pair_lvl);
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

	if (argc == 2)
		return (failure_msg("Error\nYou need to have more than one number", false));
		
	std::vector<std::string>::iterator it = input.begin();
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

long jacobsthal_nbr(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }


int	check_ordenation(PmergeMe vec_obj, PmergeMe deq_obj)
{
	std::vector<int> 	vec = vec_obj.GetVector();
	std::deque<int> 	deq = deq_obj.GetDeque();


	for (std::vector<int>::iterator 	vec_it = vec.begin(); vec_it != vec.end() - 1; vec_it ++)
	{
		if ((*vec_it) > *(vec_it + 1))
			return(failure_msg("Vector not ordenated", 1));
	}

	for (std::deque<int>::iterator 	dev_it = deq.begin(); dev_it != deq.end() - 1; dev_it ++)
	{
		if ((*dev_it) > *(dev_it + 1))
			return(failure_msg("Deque not ordenated", 1));
	}

	(void)deq_obj;

	return (0);
}