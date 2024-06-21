#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>

int main() {

	std::cout << "\n---1---" << std::endl;

	const std::string input = "4ä2";
	std::cout << "ScalarConverter(" << input << "): ";
	try {
		std::cout << ScalarConverter::convert(input) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Now it's your turn! Try out the converter (end with ctrl+D)\n";
	std::string userInput;
	while (std::getline(std::cin, userInput)) {
		try {
			std::cout << ScalarConverter::convert(userInput) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
