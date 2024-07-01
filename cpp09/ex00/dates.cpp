/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dates.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:33:13 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/01 22:55:13 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dates.hpp"
#include <sstream>
#include <iostream>

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
	if (ssYear.fail() || year < 1900 || year > 2100)
		return false;

	std::stringstream ssMonth(date.substr(5, 2));
	ssMonth >> month;
	if (ssMonth.fail() || month < 1 || month > 12)
		return false;

	std::stringstream ssDay(date.substr(8, 2));
	ssDay >> day;
	if (ssDay.fail() || !validateDay(year, month, day))
		return false;
	return true;
}
