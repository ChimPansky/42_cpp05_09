#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	edd("Edd", 30);
		ShrubberyCreationForm	shrubb1("Trees!");

		shrubb1.execute(bob);
		edd.executeForm(shrubb1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Caught unknown exception!" << std::endl;
	}

	std::cout << "---\n";

	try {
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	edd("Edd", 30);
		ShrubberyCreationForm	shrubb1("Trees!");

		bob.signForm(shrubb1);
		shrubb1.execute(bob);
		// edd.executeForm(shrubb1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Caught unknown exception!" << std::endl;
	}
}
