#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
strDblMap	BitcoinExchange::_map;
bool		BitcoinExchange::_fail = false;

void	BitcoinExchange::_loadDatabaseFromCSV(const std::string& fPath) {
	_map.clear();
	std::ifstream	inFile(fPath);
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open database file: " << fPath << std::endl;
		_fail = true;
		return ;
	}
	std::string	line;
	while (std::getline(inFile, line) && !_fail) {
		_processCSVLine(line);
	}

}

void	BitcoinExchange::_processCSVLine(const std::string& line) {
	std::stringstream	ssLine(line);
	std::string			keyDate;
	if (!std::getline(ssLine, keyDate, ',') || !_validateDate(keyDate)) {
		_fail = true;
		return ;
	}


}

bool	BitcoinExchange::_validateDate(const std::string& keyDate) {

}

void	BitcoinExchange::convert(std::string &date, int amount) {

}
