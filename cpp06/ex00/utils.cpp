/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:22 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/24 13:24:20 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cctype>
#include <sstream>
#include "iostream"

const std::string msg_impossible = "impossible";
const std::string msg_unprintable = "unprintable";

bool	containsUnprintable(const std::string& str) {
	for (size_t	i = 0; i < str.length(); i++) {
		if (!std::isprint(str[i]))
			return true;
	}
	return (str.length() < 1);
}

enum e_type	checkNumericTypes(const std::string& str) {
	int	i;
	int	start = 1;
	enum e_type result = TYPE_UNKNOWN;
	if (str[0] == '+' || str[0] == '-')
		start++;
	if (!std::isdigit(str[start - 1]))
		return TYPE_UNKNOWN;
	i = start;
	if ((i = str.find(".")) != std::string::npos) {
		result = TYPE_DOUBLE;
	}
	else
	 	//check only digits now...;

	for (; i < str.size(); i++) {

		if (!std::isdigit(str[0]))
			break;
	}
	if (i == str.size())
		return TYPE_INT;

}

enum e_type	detectScalarType(const std::string& str) {
	int	i = 0;
	if (str.size() < 1)
		return TYPE_UNKNOWN;
	if (str.size() == 1) {
		if (std::isdigit(str[0]))
			return TYPE_INT;
		else
			return TYPE_CHAR;
	}
	return checkNumericTypes(str);

	if (checkTypeInt(str))
		return TYPE_INT;
	if (checkTypeInt(str))
		return TYPE_INT;
	if (str.size() <= 2) {
		if (str.size() == 1) {
			if (std::isdigit(str[0]))
				return TYPE_INT;
			else
				return TYPE_CHAR;
		}
		return std::isdigit(str[1]) ? TYPE_INT ;
	}
	if ((i = str.find(".", 0)) != std::string::npos) {

		return TYPE_DOUBLE;
	}

	if (str.find("f", 0) != std::string::npos && str.find(".", 0) != std::string::npos){
		std::cout << "str.find(f, 0)" << str.find("f", 0) << std::endl;
		std::cout << "str.find(., 0)" << str.find(".", 0) << std::endl;
		return TYPE_FLOAT;
	}
	if ((str[0] == '-' || str[0] == '+') && std::isdigit(str[1]))
		return TYPE_INT;
	if (std::isdigit(str[0]))
		return TYPE_INT;
	return TYPE_UNKNOWN;
}

void	handleChar(const std::string& str) {
	std::cout << "char: '" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<float>(str[0]) << std::endl;
}

void	printChar(int asciiCode) {
	if (asciiCode < 1 || asciiCode > 127)
		std::cout << "char: " << msg_impossible << "" << std::endl;
	else if (std::isprint(asciiCode))
		std::cout << "char: " << msg_unprintable << "" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(asciiCode) << "'" << std::endl;
}

void	handleInt(const std::string& str) {
	int	target;
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail()) {
		std::cout << "char: " << msg_impossible << "" << std::endl;
		std::cout << "int: " << msg_impossible << std::endl;
		std::cout << "float: " << msg_impossible << std::endl;
		std::cout << "double: " << msg_impossible << std::endl;
		return ;
	}
	printChar(target);
	std::cout << "int: " << target << std::endl;
	std::cout << "float: " << static_cast<float>(target) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(target) << std::endl;
}

void	handleFloat(const std::string& str) {
	float	target;
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail()) {
		std::cout << "char: " << msg_impossible << "" << std::endl;
		std::cout << "int: " << msg_impossible << std::endl;
		std::cout << "float: " << msg_impossible << std::endl;
		std::cout << "double: " << msg_impossible << std::endl;
		return ;
	}
	printChar(static_cast<int>(target));
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	std::cout << "float: " << target << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(target) << std::endl;
}

void	handleDouble(const std::string& str) {
	double	target;
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail()) {
		std::cout << "char: " << msg_impossible << "" << std::endl;
		std::cout << "int: " << msg_impossible << std::endl;
		std::cout << "float: " << msg_impossible << std::endl;
		std::cout << "double: " << msg_impossible << std::endl;
		return ;
	}
	printChar(static_cast<int>(target));
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	std::cout << "float: " << static_cast<float>(target) << "f" << std::endl;
	std::cout << "double: " << target << std::endl;
}
