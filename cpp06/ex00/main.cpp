/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:40 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/26 11:29:32 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

static void	demoConverter(void) {
	std::cout << "\n---1---" << std::endl;

	std::string test;

	test = "42";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = " ";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "a";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "-1";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "127";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "128";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "-1";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "0";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "-1";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "42.24";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "42.24f";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "2147483647";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "-2147483648";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);

	test = "2147483648";
	std::cout << "\nconverting \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);


	std::cout << "\nNow it's your turn! Try out the converter (end with ctrl+D)\n";
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
