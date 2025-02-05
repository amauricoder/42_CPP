/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:55:07 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/05 11:27:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Ler o banco de dados CSV contendo os preços do Bitcoin ao longo do tempo.
Ler o arquivo de entrada fornecido como argumento na linha de comando.
Verificar e validar os dados de entrada (formato da data e valores).
Para cada entrada, calcular o valor correspondente multiplicando a quantidade fornecida pelo preço do Bitcoin na data mais próxima disponível.
Exibir os resultados. */

int	main(int argc, char **argv)
{
	if (!is_argument_valid(argc, argv))
		return (FAILURE);
	std::map<std::string, double> btc_data = get_database();
	//print_map(btc_data);
	process_input(argv[1], btc_data);
	return (SUCCESS);
}
