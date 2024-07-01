#pragma once
#include <map>
#include <string>
#include <fstream>

typedef std::map<const std::string, const double> strDblMap;
class BitcoinExchange {
  private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	const BitcoinExchange	operator=(const BitcoinExchange& other);

	static strDblMap	_map;
	static bool			_fail;

	static void	_loadDatabaseFromCSV(const std::string& fPath);
	static void	_processCSVLine(const std::string& line);
	static bool	_validateDate(const std::string& keyDate);

  public:
	static void	convert(std::string& date, int amount);


};
