#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error. Usage: ./btc <path-to-input>" << std::endl;
		return 1;
	}
	BitcoinExchange::loadDatabaseFromCSV("data.csv");
	if (BitcoinExchange::fail())
		return 1;
	BitcoinExchange::printData();
	BitcoinExchange::lookupInputs(av[1]);
// 	BitcoinExchange::convertBtc("1999-11-1", 5);
// 	BitcoinExchange::convertBtc("2009-01-01", 2.1);
// 	BitcoinExchange::convertBtc("2009-01-02", 1.0);
// 	BitcoinExchange::convertBtc("2009-01-03", 3.0);
// 	BitcoinExchange::convertBtc("2009-01-04", 4.0);
// 	BitcoinExchange::convertBtc("2009-01-05", 4.0);
// 	BitcoinExchange::convertBtc("2018-12-31", 2);
// 	BitcoinExchange::convertBtc("2022-03-29", 10);
// 	BitcoinExchange::convertBtc("2026-07-12", 1.5);
	return 0;
}
