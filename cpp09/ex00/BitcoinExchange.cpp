/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:32:59 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/06 17:26:07 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "dates.hpp"

mapStrDbl		BitcoinExchange::_map;
std::ifstream	BitcoinExchange::_inFile;
bool			BitcoinExchange::_fail = false;

// public methods:
// TODO: move filechecks to separate function
void	BitcoinExchange::loadDatabaseFromCSV(const char* fPath) {
	_resetExchange();
	std::ifstream	inFile(fPath);
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open database file: " << fPath << std::endl;
		_fail = true;
		return ;
	}
	char c;
	if (!(_inFile >> c)) {
		std::cerr << "Error: cannot read from file: " << fPath << std::endl;
		_fail = true;
		return ;
	}
	_inFile.clear();
	_inFile.seekg(0, std::ios::beg);
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line) && !_fail)
		_processCsvRecord(line);
	if (_map.empty()) {
		std::cerr << "Error: empty database file: " << fPath << std::endl;
		_fail = true;
		return ;
	}
	std::cout << "Data has been loaded successfully!" << std::endl;
}

bool	BitcoinExchange::loadInputFile(const char *fPath) {
	_inFile.open(fPath);
	if (_inFile.fail() || !_inFile.is_open()) {
		std::cerr << "Error: cannot open input file: " << fPath << std::endl;
		return false;
	}
	char c;
	if (!(_inFile >> c)) {
		std::cerr << "Error: cannot read from file: " << fPath << std::endl;
		return false;
	}
	_inFile.clear();
	_inFile.seekg(0, std::ios::beg);
	return true;
}

void	BitcoinExchange::processInputFile() {
	std::string	line;
	std::getline(_inFile, line);
	while (std::getline(_inFile, line) && !_fail)
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
			std::cout << it->first << " | " << it->second << std::endl;
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
	if (!std::getline(ssLine, key, ',')) {
		std::cerr << "Error: cannot extract date from CSV - skipping insert" << std::endl;
		return ;
	}
	if (!validateDate(key)) {
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
	if (!validateDate(date)) {
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

mapStrDbl::iterator	BitcoinExchange::_lookup(const std::string& key) {
	mapStrDbl::iterator foundRecord = _map.upper_bound(key);
	if (foundRecord != _map.begin())
		return --foundRecord;
	return foundRecord;
}
