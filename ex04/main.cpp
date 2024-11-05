/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:01:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 18:14:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int argc, char **argv)
{
	if (argument_error(argc, argv))
		return (1);
	
	std::ifstream	file(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	int				qt_lines = get_qt_lines(file);
	std::string		arr[qt_lines];

	file.clear();          // Clear any EOF or fail flags
    file.seekg(0);         // Move back to the beginning of the file

	//Minha ideia aqui eh ler a linha com get_line(), entao
	//verificar se na linha tem a palavra s1, se tiver, preciso substituila por s2.
	// You can use a combination of find(),
	//erase(), and insert() to locate and replace parts of a string.
	for (int i = 0; i < qt_lines; i ++)
	{
		getline(file, arr[i]);
		std::cout << "LINE CONTENT -> " << arr[i] << std::endl;
	} 	
	return (0);
}