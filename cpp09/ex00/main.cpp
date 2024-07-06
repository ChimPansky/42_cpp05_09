/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:33:20 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/06 16:15:43 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error. Usage: ./btc <path-to-input>" << std::endl;
		return 1;
	}
	if (BitcoinExchange::loadInputFile(av[1]) == false)
		return 1;
	std::string	csvPath = "data.csv";
	std::cout << "loading data from " << csvPath << "..." << std::endl;
	BitcoinExchange::loadDatabaseFromCSV(csvPath.data());
	if (BitcoinExchange::fail())
		return 1;
	// BitcoinExchange::printData();
	BitcoinExchange::processInputFile();
	return 0;
}
