#include "Bureaucrat.hpp"
#include <iostream>

int main() {

	std::cout << "\n---1---" << std::endl;
	try {
		Bureaucrat fredl("Fredl", 2);
		std::cout << fredl << std::endl;
		fredl.incrementGrade();
		std::cout << fredl << std::endl;
		fredl.decrementGrade();
		std::cout << fredl << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---2---" << std::endl;
	try {
		Bureaucrat fritz("Fritz", -1);
		std::cout << fritz << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---3---" << std::endl;
	try {
		Bureaucrat hans("Hans", 200);
		std::cout << hans << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---4---" << std::endl;
	try {
		Bureaucrat franz("Franz", 130);

		std::cout << franz << std::endl;
		franz.decrementGrade();
		std::cout << franz << std::endl;
		for (int i = 0; i < 21; i++)
			franz.decrementGrade();
		std::cout << franz << std::endl;

		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
