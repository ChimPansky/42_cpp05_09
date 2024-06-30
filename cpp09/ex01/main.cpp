#include "RPN.hpp"
#include <iostream>

int main(int ac, char ** av) {
	if (ac != 2) {
		std::cout << "Error. Usage: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}
	int	result = 0;
	RPN::calculate(av[1], result);
	if (RPN::fail())
		return 1;
	std::cout << result << std::endl;
	return 0;
}
