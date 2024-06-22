/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:28 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 14:49:04 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void	ScalarConverter::convert(const std::string& str) {
	if (containsUnprintable(str))
		throw NonDisplayableException();
	enum e_type dataType = detectScalarType(str);
	std::cout << "detected TYPE: " << dataType << std::endl;
	char	cSource = 0;
	int		iSource = 0;
	float	fSource = 0.f;
	double	dSource = 0.;
	switch (dataType) {
		case (TYPE_UNKNOWN):
			std::cout << "Could not determine data type of scalar to convert!" << std::endl;
			break;
		case (TYPE_CHAR):
			strToChar(str, cSource);
			printConversions(static_cast<char>(cSource), static_cast<int>(cSource),
				static_cast<float>(cSource), static_cast<double>(cSource));
			break;
		case (TYPE_INT):
			strToInt(str, iSource);
			printConversions(static_cast<char>(iSource), static_cast<int>(iSource),
				static_cast<float>(iSource), static_cast<double>(iSource));
			break;
		case (TYPE_FLOAT):
			strToFloat(str, fSource);
			printConversions(static_cast<char>(fSource), static_cast<int>(fSource),
				static_cast<float>(fSource), static_cast<double>(fSource));
			break;
		case (TYPE_DOUBLE):
			strToDouble(str, dSource);
			printConversions(static_cast<char>(dSource), static_cast<int>(dSource),
				static_cast<float>(dSource), static_cast<double>(dSource));
			break;
	}
}
