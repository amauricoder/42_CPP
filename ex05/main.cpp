/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:20:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief
 * usefful -> https://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
 */
int main(void)
{
    Harl man;

	man.complain("debug");
	man.complain("info");
	man.complain("warning");
	man.complain("error");
	man.complain("");
	man.complain("invalid");
	man.complain("invalid2");
	man.complain("warning");
	man.complain("warning");
	man.complain("info");

    return (0);
}