#pragma once
#include <map>
#include <string>



class BitcoinExchange {
  private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	const BitcoinExchange	operator=(const BitcoinExchange& other);

	static std::map<std::string, float>	_map;


  public:
	static void	convert(std::string& date, int amount);


};
