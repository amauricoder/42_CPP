/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:28:52 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/14 19:02:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ctime"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif