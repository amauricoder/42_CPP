/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/04/02 17:26:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * MAP because of key value.
 */
int	main(int argc, char **argv)
{
	if (!is_argument_valid(argc, argv))
		return (FAILURE);
	std::map<std::string, double> btc_data = get_database();
	process_input(argv[1], btc_data);
	return (SUCCESS);
}
