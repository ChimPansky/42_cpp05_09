#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

mapStrDbl	BitcoinExchange::_map;
bool		BitcoinExchange::_fail = false;

// public methods:
void	BitcoinExchange::loadDatabaseFromCSV(const char* fPath) {
	_resetExchange();
	std::ifstream	inFile(fPath);
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open database file: " << fPath << std::endl;
		_fail = true;
		return ;
	}
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line) && !_fail)
		_processCsvRecord(line);
	if (_map.empty()) {
		std::cerr << "Error: empty database file: " << fPath << std::endl;
		_fail = true;
	}
}

void	BitcoinExchange::lookupInputs(const char *fPath) {
	if (_fail || _map.empty()) {
		std::cerr << "Error: There seems to be a problem with the database."
			<< "Use loadDatabaseFromCSV() to (re)populate..." << std::endl;
		return ;
	}
	std::ifstream	inFile(fPath);
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open input file: " << fPath << std::endl;
		return ;
	}
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line) && !_fail)
		_processLookup(line);
}

bool	BitcoinExchange::fail() {
	return _fail;
}

void	BitcoinExchange::printData() {
	if (_map.empty()) {
		std::cout << "{empty database}" << std::endl;
		std::cout << "Use loadDatabaseFromCSV() to populate..." << std::endl;
		return ;
	}
	for (mapStrDbl::const_iterator it
		= _map.begin(); it != _map.end(); it++) {
			std::cout << it->first << " | " << std::fixed << it->second << std::endl;
	}
}

// private methods:
void	BitcoinExchange::_resetExchange() {
	_map.clear();
	_fail = false;
}

void	BitcoinExchange::_processCsvRecord(const std::string& line) {
	std::stringstream	ssLine(line);
	std::string			key;
	double				val;
	std::cout << "inserting..." << std::endl;
	if (!std::getline(ssLine, key, ',')) {
		std::cerr << "Error: cannot extract date from CSV - skipping insert" << std::endl;
		return ;
	}
	if (!_validateDate(key)) {
		std::cerr << "Error: found invalid date in CSV - skipping insert" << std::endl;
		return ;
	}
	if (!(ssLine >> val)) {
		std::cerr << "Error: cannot extract exchange rate from CSV - skipping insert" << std::endl;
		return ;
	}
	_map.insert(std::make_pair(key, val));
}

void	BitcoinExchange::_processLookup(const std::string& line) {
	std::stringstream	ssLine(line);
	std::string			date;
	float				btcAmount;
	if (!std::getline(ssLine, date, '|')) {
		std::cerr << "Error: cannot extract date from input file" << std::endl;
		return ;
	}
	if (!_validateDate(date)) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (!(ssLine >> btcAmount)) {
		std::cerr << "Error: cannot extract BTC amount from input file" << std::endl;
		return ;
	}
	if (btcAmount < 0) {
		std::cerr << "Error: not a positive number. (" << btcAmount << ")" << std::endl;
		return ;
	}
	if (btcAmount > 1000) {
		std::cerr << "Error: too large a number. (" << btcAmount << ")" << std::endl;
		return ;
	}
	_convertAndPrint(date, btcAmount);
}

bool	BitcoinExchange::_validateDate(const std::string& keyDate) {	//Todo: add proper date check...
	std::cout << "DATE LENGTH: " << keyDate.length() << std::endl;
	if (keyDate.length() == 10 || keyDate.length() == 11)
		return true;
	return false;
}

mapStrDbl::iterator	BitcoinExchange::_lookup(const std::string& key) {
	mapStrDbl::iterator foundRecord = _map.upper_bound(key);
	if (foundRecord != _map.begin())
		return --foundRecord;
	return foundRecord;
}
