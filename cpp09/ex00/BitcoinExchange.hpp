/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:33:05 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/01 23:05:30 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <iostream>

typedef std::map<const std::string, const double> mapStrDbl;
typedef std::pair<const std::string, const double> pairStrDbl;
class BitcoinExchange {
  private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	const BitcoinExchange	operator=(const BitcoinExchange& other);

	static mapStrDbl		_map;
	static std::ifstream	_inFile;
	static bool				_fail;

	static void					_resetExchange();
	static void					_processCsvRecord(const std::string& line);
	static void					_processLookup(const std::string& line);
	static mapStrDbl::iterator	_lookup(const std::string& key);

  public:
	static void		loadDatabaseFromCSV(const char* fPath);
	static bool		loadInputFile(const char* fPath);
	static void		processInputFile();
	static void		convertBtc(pairStrDbl record);
	static bool		fail();
	static void		printData();

  private:
	template <typename T>
	static void		_convertAndPrint(const std::string& date, T btcAmount) {
		double	conversion = _lookup(date)->second * btcAmount;
		std::ios_base::fmtflags	savedFmtFlags = std::cout.flags();
		std::cout << std::setprecision(2);
		std::cout << date << "=> " << btcAmount << " = ";
		std::cout << std::fixed << std::setprecision(2) << conversion << std::endl;
		std::cout.flags(savedFmtFlags);
	}
};
