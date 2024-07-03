#include "RPN.hpp"
#include <iostream>
#include <utility>
#include "unitTest.hpp"
#include "vector"

int main(int ac, char ** av) {
	if (ac != 2) {
		std::cout << "Error. Usage: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}
	long	result = 0;
	RPN::calculate(av[1], result);
	if (RPN::fail())
		return 1;
	std::cout << result << std::endl;

	// // some tests:
	// // Todo: figure out how to handle test cases where calculation failed (invalid format, division by zero...)
	// // because in those cases nothing is stored in the target interger...
	// std::vector<std::pair<std::string, long> > tests;
	// tests.push_back(std::make_pair("8 9 * 9 - 9 - 9 - 4 - 1 +", 42));
	// tests.push_back(std::make_pair("7 7 * 7 -", 42));
	// tests.push_back(std::make_pair("1 2 * 2 / 2 * 2 4 - +", 0));
	// tests.push_back(std::make_pair("0 1 +", 1));
	// tests.push_back(std::make_pair("0 0 *", 0));
	// // tests.push_back(std::make_pair("0 0 /", 0));
	// int	testNr = 1;
	// for (std::vector<std::pair<std::string, long> >::iterator it
	// 	= tests.begin(); it != tests.end(); it++, testNr++) {
	// 	std::cout << "---TEST " << testNr << "---" << std::endl;
	// 	std::cout << "Input: \"" << it->first << "\"" << std::endl;
	// 	RPN::calculate(it->first, result);
	// 	assertEqual(result, it->second);
	// }
	return 0;
}
