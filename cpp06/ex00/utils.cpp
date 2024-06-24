/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:22 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/24 17:14:10 by tkasbari         ###   ########.fr       */
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

bool	strIsChar(const std::string& str) {
	return str.size() == 1 && !std::isdigit(str[0]);
}

bool	strIsInt(const std::string& str) {
	size_t		i = 0;
	bool	valid = false;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			valid = true;
		else
			return false;
	}
	return valid;
}

enum e_type	strIsDoubleOrFloat(const std::string& str) {
	size_t		i = 0;
	bool	valid = false;
	std::cout << "strIsDoubleOrFloat" << std::endl;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.size() - 1; i++) {
		if (std::isdigit(str[i]))
			continue;
		if (str[i] == '.') {
			i++;
			break;
		}
		else
			return TYPE_UNKNOWN;
	}
	std::cout << "after dot i: " << i << std::endl;
	for (; i < str.size() - 1; i++) {
		if (std::isdigit(str[i]))
			valid = true;
	}
	if (valid && std::isdigit(str[i]))
		return TYPE_DOUBLE;
	if (valid && str[i] == 'f')
		return TYPE_FLOAT;
	return TYPE_UNKNOWN;
}

enum e_type	detectScalarType(const std::string& str) {
	if (str.size() < 1)
		return TYPE_UNKNOWN;
	if (strIsChar(str)) {
		std::cout << "str is char!" << std::endl;
		return TYPE_CHAR;
	}
	if (strIsInt(str)) {
		std::cout << "str is int!" << std::endl;
		return TYPE_INT;
	}
	return strIsDoubleOrFloat(str);
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
	else if (!std::isprint(asciiCode))
		std::cout << "char: " << msg_unprintable << "" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(asciiCode) << "'" << std::endl;
}

void	printFloat(float f) {
	std::cout << "float: " << f;
	// todo: check if i need to add ".0"...
	std::cout << "f" << std::endl;
}

void	printDouble(double d) {
	std::cout << "double: " << d;
	// todo: check if i need to add ".0"...
	std::cout << std::endl;
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
	printFloat(static_cast<float>(target));
	printDouble(static_cast<double>(target));
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
	printFloat(target);
	printDouble(static_cast<double>(target));
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
	printFloat(static_cast<float>(target));
	printDouble(target);
}
