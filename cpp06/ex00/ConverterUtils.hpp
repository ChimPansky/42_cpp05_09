/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:20 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/25 11:30:39 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum	e_type {
	TYPE_UNKNOWN,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO
};

const std::string typeMessages[TYPE_PSEUDO + 1] = {
	"Could not determine Input type!",
	"Char Input detected!",
	"Int Input detected!",
	"Float Input detected!",
	"Double Input detected!",
	"Pseudo literal detected!"
};

bool	containsUnprintable(const std::string& str);

enum e_type	detectScalarType(const std::string& str);

void	handleImpossible();
void	handleChar(const std::string& str);
void	handleInt(const std::string& str);
void	handleFloat(const std::string& str);
void	handleDouble(const std::string& str);
void	handlePseudo(const std::string& str);

bool	strToInt(const std::string& str, int& target);
bool	strToFloat(const std::string& str, float& target);
bool	strToDouble(const std::string& str, double& target);

void	printConversions(char c, int i, float f, double d);
