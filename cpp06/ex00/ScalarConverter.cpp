/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:28 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/24 11:46:00 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void	ScalarConverter::convert(const std::string& str) {
	enum e_type dataType = detectScalarType(str);
	std::cout << "detected TYPE: " << dataType << std::endl;
	switch (dataType) {
		case (TYPE_UNKNOWN):
			std::cout << "Could not determine data type of scalar to convert!" << std::endl;
			break;
		case (TYPE_CHAR):
			handleChar(str);
			break;
		case (TYPE_INT):
			handleInt(str);
			break;
		case (TYPE_FLOAT):
			handleFloat(str);
			break;
		case (TYPE_DOUBLE):
			handleDouble(str);
			break;
	}
}
