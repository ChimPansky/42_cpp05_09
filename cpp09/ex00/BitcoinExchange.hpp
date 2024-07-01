#pragma once
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

	static mapStrDbl	_map;
	static bool			_fail;

	static void					_resetExchange();
	static void					_processCsvRecord(const std::string& line);
	static void					_processLookup(const std::string& line);
	static bool					_validateDate(const std::string& date);
	static mapStrDbl::iterator	_lookup(const std::string& key);

  public:
	static void		loadDatabaseFromCSV(const char* fPath);
	static void		lookupInputs(const char* fPath);
	static void		convertBtc(pairStrDbl record);
	static bool		fail();
	static void		printData();

  private:
	template <typename T>
	static void		_convertAndPrint(const std::string& date, T btcAmount) {
		double	conversion = _lookup(date)->second * btcAmount;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << date << "=> " << conversion << std::endl;
	}
};
