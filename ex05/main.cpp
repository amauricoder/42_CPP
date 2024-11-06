/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:20:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 18:59:45 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	err(std::string msg, int exit_status)
{
	std::cout << "Error!" << std::endl;
	std::cout << msg << std::endl;
	return (exit_status);	
}

/**
 * @brief
 * usefful -> https://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
 */
int main(int argc, char **argv)
{
	if (argc != 2 || !argv)
		return (err("Invalid Argument", 1));
	std::string input(argv[1]);
    Harl man;

	man.complain(input);
    return (0);
}