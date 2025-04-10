/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:35:36 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/01 17:23:56 by aconceic         ###   ########.fr       */
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

	return (check_ordenation(to_sort_vector, to_sort_deque));
}
