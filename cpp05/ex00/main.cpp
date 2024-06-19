#include "Bureaucrat.hpp"
#include <iostream>
#include <new>

int main() {
	try {
		// Bureaucrat heinz("Heinz", 5);
		// heinz.setAllocatedData('a');
		// std::cout << heinz << " | data: " << *heinz.getAllocatedData() << std::endl;
		// Bureaucrat test(heinz);
		// test.setAllocatedData('b');
		// std::cout << test << " | data: " << *test.getAllocatedData() << std::endl;
		// Bureaucrat test2;
		// std::cout << test2 << " | data: " << *test2.getAllocatedData() << std::endl;
		// test2 = test;
		// std::cout << test2 << " | data: " << *test2.getAllocatedData() << std::endl;

		Bureaucrat fredl("Fredl", 2);

		std::cout << fredl << std::endl;
		fredl.incrementGrade();
		std::cout << fredl << std::endl;
		fredl.decrementGrade();
		std::cout << fredl << std::endl;

		std::cout << std::endl;

		Bureaucrat franz("Franz", 130);

		std::cout << franz << std::endl;
		for (int i = 0; i < 21; i++)
			franz.decrementGrade();
		std::cout << franz << std::endl;

		std::cout << std::endl;

		Bureaucrat fritz("Fritz", 5);
				std::cout << fritz << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Caught unknown exception!" << std::endl;
	}
}
