/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/02 17:36:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//stack because is RPN, that works naturally as a stack.
int	main(int argc, char **argv)
{
	if (!is_argument_valid(argc, argv) || do_rpn(argv[1]))
		return (EXIT_FAILURE);
	return (0);
}
