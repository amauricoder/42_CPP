/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:02:49 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
int	*easyfind(T &container, int nbr)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nbr);
	if (it != container.end())
		return (found_item(it));
	std::cout << "Item not found on container" << std::endl;
	return (NULL);
}

//returns the iterator with a msg showing that he is on the container
template <typename T>
int	*found_item(T &it)
{
	std::cout << "The number " << (*it) << " is on the container!" << std::endl;
	return (&(*it));
}

#endif

