/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:33:28 by tkasbari          #+#    #+#             */
/*   Updated: 2024/07/01 22:33:29 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "colors.hpp"

template <typename T>
void	assertEqual(T value, T expected) {
	if (value == expected)
		std::cout << GREEN_COLOR + "OK" + RESET_COLOR << std::endl;
	else
		std::cout << RED_COLOR + "KO" + RESET_COLOR << std::endl;
}
