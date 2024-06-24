/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:36:20 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/24 11:50:24 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

enum	e_type {
	TYPE_UNKNOWN,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
};

bool	containsUnprintable(const std::string& str);

enum e_type	detectScalarType(const std::string& str);

void	handleChar(const std::string& str);
void	handleInt(const std::string& str);
void	handleFloat(const std::string& str);
void	handleDouble(const std::string& str);

bool	strToInt(const std::string& str, int& target);
bool	strToFloat(const std::string& str, float& target);
bool	strToDouble(const std::string& str, double& target);

void	printConversions(char c, int i, float f, double d);
