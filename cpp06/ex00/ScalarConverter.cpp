/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:28 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/25 11:22:15 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConverterUtils.hpp"
#include <iostream>

void	ScalarConverter::convert(const std::string& str) {
	enum e_type dataType = detectScalarType(str);
	std::cout << typeMessages[dataType] << std::endl;
	switch (dataType) {
		case (TYPE_UNKNOWN):
			handleImpossible();
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
		case (TYPE_PSEUDO):
			handlePseudo(str);
			break;

	}
}
