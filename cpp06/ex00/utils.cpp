/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:22 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 15:01:51 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cctype>
#include <sstream>
#include "iostream"

bool	containsUnprintable(const std::string& str) {
	for (size_t	i = 0; i < str.length(); i++) {
		if (!std::isprint(str[i]))
			return true;
	}
	return (str.length() < 1);
}

enum e_type	detectScalarType(const std::string& str) {
	if (str.size() < 1)
		return TYPE_UNKNOWN;
	if (str.size() == 1 && !std::isdigit(str[0]))
		return TYPE_CHAR;
	if (str.find("f", 0) != std::string::npos && str.find(".", 0) != std::string::npos){
		std::cout << "str.find(f, 0)" << str.find("f", 0) << std::endl;
		std::cout << "str.find(., 0)" << str.find(".", 0) << std::endl;
		return TYPE_FLOAT;
	}
	if (str.find(".", 0) != std::string::npos)
		return TYPE_DOUBLE;
	if (std::isdigit(str[0]))
		return TYPE_INT;
	return TYPE_UNKNOWN;
}

bool	strToChar(const std::string& str, char& target) {
	std::stringstream	strStream(str);

	strStream >> target;
	if (strStream.fail())
		return (false);
	return (true);
}

bool	strToInt(const std::string& str, int& target) {
	std::stringstream	strStream(str);

	strStream >> target;
	if (strStream.fail())
		return (false);
	return (true);
}

bool	strToFloat(const std::string& str, float& target) {
	std::stringstream	strStream(str);

	strStream >> target;
	if (strStream.fail())
		return (false);
	return (true);
}

bool	strToDouble(const std::string& str, double& target) {
	std::stringstream	strStream(str);

	strStream >> target;
	if (strStream.fail())
		return (false);
	return (true);
}

void	printConversions(char c, int i, float f, double d) {
	std::cout << "char: '" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

const char* NonDisplayableException::what() const throw() {
	return ("Cannot convert non-displayable characters!");
}
