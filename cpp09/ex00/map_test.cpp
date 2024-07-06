/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:33:25 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/06 12:27:56 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "unitTest.hpp"
#include <sstream>

typedef std::map<std::string, const double> mapStrDbl;
typedef std::pair<const std::string, const double> pairType;

bool	isLeapYear(int year) {
	if (year % 4 != 0)
		return false;
	if (year % 100 == 0 && year % 400 == 0)	// even centuries also have to be divisible by 400
		return true;
	if (year % 100 == 0 && year % 400 != 0)
		return false;
	return true;
}

bool	validateDay(int year, int month, int day) {
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && isLeapYear(year) && day > 29)
		return false;
	if (month == 2 && !isLeapYear(year) && day > 28)
		return false;
	return true;
}

bool	validateDate(const std::string& date) {
	std::string			datePart;
	int	year, month, day;

	if (date.length() < 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::stringstream ssYear(date.substr(0, 4));
	ssYear >> year;
	std::cout << "YEAR: " << year << std::endl;
	if (ssYear.fail() || year < 1900 || year > 2100)
		return false;

	std::stringstream ssMonth(date.substr(5, 2));
	ssMonth >> month;
	std::cout << "MONTH: " << month << std::endl;
	if (ssMonth.fail() || month < 1 || month > 12)
		return false;

	std::stringstream ssDay(date.substr(8, 2));
	ssDay >> day;
	std::cout << "DAY: " << day << std::endl;
	if (ssDay.fail() || !validateDay(year, month, day))
		return false;
	return true;
}

typedef std::pair<const std::string, bool> pairStrBool;
int main() {
	std::vector<pairStrBool> tests;
	tests.push_back(std::make_pair("2023-11-01", true));
	tests.push_back(std::make_pair("abcd-11-01", false));
	tests.push_back(std::make_pair("2020-ef-01", false));
	tests.push_back(std::make_pair("2019-12-xx", false));
	tests.push_back(std::make_pair("    -12-01", false));
	tests.push_back(std::make_pair(" 152-12-01", false));
	tests.push_back(std::make_pair("2101-12-01", false));
	tests.push_back(std::make_pair("125-11-01", false));
	tests.push_back(std::make_pair("2023--1-01", false));
	tests.push_back(std::make_pair("2023-25-01", false));
	tests.push_back(std::make_pair("2023-02-29", false));
	tests.push_back(std::make_pair("2024-02-29", true));
	tests.push_back(std::make_pair("2024-01-50", false));
	int	testNr = 1;
	for (std::vector<pairStrBool >::iterator it
		= tests.begin(); it != tests.end(); it++, testNr++) {
		std::cout << "---TEST " << testNr << "---" << std::endl;
		std::cout << "Input: \"" << it->first << "\"" << std::endl;
		assertEqual(validateDate(it->first), it->second);
	}
	return 0;

	mapStrDbl db;
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-01"), static_cast<const double>(42.5)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-02"), static_cast<const double>(17)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-10"), static_cast<const double>(137)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-10-05"), static_cast<const double>(0.5)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-10-21"), static_cast<const double>(7443.3)));
	// db.insert(std::make_pair(static_cast<const std::string>("100"), static_cast<const double>(0.25)));
	// db.insert(std::make_pair(static_cast<const std::string>("0"), static_cast<const double>(44.5)));
	// db.insert(std::make_pair(static_cast<const std::string>("7"), static_cast<const double>(13.0)));

	for (mapStrDbl::const_iterator it
		= db.begin(); it != db.end(); it++) {
			std::cout << it->first << " | " << std::setprecision(2) << it->second << std::endl;	// why are values with no decimal points not displayed as x.00??
	}

	// customFind(db, "0000-00-00");
	// customFind(db, "9999-00-00");
	// customFind(db, "2023-01-31");
	// customFind(db, "2022-10-15");
	// customFind(db, "2091-05-06");
	// customFind(db, "1999-10-10");
	// customFind(db, "2024-01-01");

	return 0;

}
