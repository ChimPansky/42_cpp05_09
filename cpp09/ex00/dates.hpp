/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dates.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:32:35 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/01 22:32:51 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

// checking if string contains a date in the form "YYYY-MM-DD"
// no leading whitespaces
// trailing whitespaces are ok
bool	validateDate(const std::string& date);
bool	validateDay(int year, int month, int day);
bool	isLeapYear(int year);
