#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat frank;
	Bureaucrat heinz("Heinz", 50);
	std::cout << frank << " | grade: " << frank.getGrade() << std::endl;
	std::cout << heinz << " | grade: " << heinz.getGrade() << std::endl;
	heinz.incrementGrade();
	std::cout << heinz << " | grade: " << heinz.getGrade() << std::endl;
	heinz.decrementGrade();
	std::cout << heinz << " | grade: " << heinz.getGrade() << std::endl;
}
