/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:22 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/25 11:33:25 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConverterUtils.hpp"
#include <cctype>
#include <iomanip>
#include <sstream>
#include "iostream"

const std::string MSG_IMPOSSIBLE = "impossible";
const std::string MSG_UNPRINTABLE = "unprintable";
const std::string INF_POS = "+inf";
const std::string INF_NEG = "-inf";
const std::string NAN = "nan";
const std::string INFF_POS = "+inff";
const std::string INFF_NEG = "-inff";
const std::string NANF = "nanf";

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
	size_t	i = 0;
	bool	hasIntPart = false;
	bool	hasDecimalPart = false;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.size() && std::isdigit(str[i]); i++)
		hasIntPart = true;
	if (!hasIntPart || i == str.size() || str[i] != '.')
		return TYPE_UNKNOWN;
	i++;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			hasDecimalPart = true;
		else if (hasDecimalPart && str[i] == 'f' && i == str.size() - 1)
			return TYPE_FLOAT;
		else
		 	return TYPE_UNKNOWN;
	}
	if (hasDecimalPart)
		return TYPE_DOUBLE;
	return TYPE_UNKNOWN;
}

enum e_type	detectScalarType(const std::string& str) {
	if (str.size() < 1)
		return TYPE_UNKNOWN;
	if (str == INF_POS || str == INF_NEG || str == NAN
		||str == INFF_POS || str == INFF_NEG || str == NANF)
		return TYPE_PSEUDO;
	if (strIsChar(str))
		return TYPE_CHAR;
	if (strIsInt(str))
		return TYPE_INT;
	return strIsDoubleOrFloat(str);
}

void	printChar(int asciiCode) {
	if (asciiCode < 1 || asciiCode > 127)
		std::cout << "char: " << MSG_IMPOSSIBLE << "" << std::endl;
	else if (!std::isprint(asciiCode))
		std::cout << "char: " << MSG_UNPRINTABLE << "" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(asciiCode) << "'" << std::endl;
}

void	printFloat(float f) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;;
}

void	printDouble(double d) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void	handleImpossible() {
	std::cout << "char: " << MSG_IMPOSSIBLE << "" << std::endl;
	std::cout << "int: " << MSG_IMPOSSIBLE << std::endl;
	std::cout << "float: " << MSG_IMPOSSIBLE << std::endl;
	std::cout << "double: " << MSG_IMPOSSIBLE << std::endl;
}

void	handleChar(const std::string& str) {
	std::cout << "char: '" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<float>(str[0]) << std::endl;
}

void	handleInt(const std::string& str) {
	int	target;
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail()) {
		handleImpossible();
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
		handleImpossible();
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
		handleImpossible();
		return ;
	}
	printChar(static_cast<int>(target));
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	printFloat(static_cast<float>(target));
	printDouble(target);
}

void	handlePseudo(const std::string& str) {
	std::cout << "char: " << MSG_IMPOSSIBLE << std::endl;
	std::cout << "int: " << MSG_IMPOSSIBLE << std::endl;
	std::cout << "float: ";
	if (str == NAN)
		std::cout << NANF;
	else if (str == INF_POS)
		std::cout << INFF_POS;
	else if (str == INF_NEG)
		std::cout << INFF_NEG;
	else
		std::cout << str;
	std::cout << std::endl;
	std::cout << "double: ";
	if (str == NANF)
		std::cout << NAN;
	else if (str == INFF_POS)
		std::cout << INF_POS;
	else if (str == INFF_NEG)
		std::cout << INF_NEG;
	else
		std::cout << str;
	std::cout << std::endl;
}
