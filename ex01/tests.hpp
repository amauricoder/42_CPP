/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:56:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 18:26:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define RESET       "\033[0m"

void    test_dog_make_sound(void);
void    test_cat_make_sound(void);
void    test_animal_make_sound(void);
void    test_inherit_dog_make_sound(void);
void    test_inherit_cat_make_sound(void);
void	test_subject(void);
void    test_filling_brain_with_ideas(void);
void	test_cat_ideas(void);
void    test_dog_ideas(void);
void    test_half_cats_and_dogs_in_array(void);
void	test_deep_copies(void);
void    test_brain_constructor(void);
#endif