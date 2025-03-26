/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:35:36 by aconceic          #+#    #+#             */
/*   Updated: 2025/03/26 12:43:12 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<std::string> input(argv + 1, argv + argc);
	if (!is_argument_valid(argc, input))
		return (EXIT_FAILURE);
	
	PmergeMe	to_sort_vector(input);
	to_sort_vector.VectorOrdenate();
	
	PmergeMe	to_sort_deque(input);
	to_sort_deque.DequeOrdenate();
	return (0);
}
