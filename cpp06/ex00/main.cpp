/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:40 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/24 11:50:46 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

static void	demoConverter(void) {
	std::cout << "\n---1---" << std::endl;

	const std::string input = "42";
	ScalarConverter::convert(input);
	// add some more demo cases...
	std::cout << "Now it's your turn! Try out the converter (end with ctrl+D)\n";
	std::string userInput;
	while (std::getline(std::cin, userInput)) {
		ScalarConverter::convert(userInput);
	}
}

int main(int ac, char** av) {
	switch (ac) {
	case 1:
		demoConverter();
		break ;
	case 2:
		ScalarConverter::convert(av[1]);
		break ;
	default:
		std::cerr << "Error: Invalid program arguments." << std::endl;
	}
	return (0);
}
