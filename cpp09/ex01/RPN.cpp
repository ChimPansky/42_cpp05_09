#include "RPN.hpp"
#include <string>


int		RPN::calculate(const std::string& expression, int& target) {
	_reset();
	std::string	input = expression;
	while (!input.empty() && !_fail) {
		_processNextElement(input);
	}
}

void	RPN::_reset() {
	_clearStack();
	_fail = false;
}

void	RPN::_clearStack() {
	while (!_stack.empty())
		_stack.pop();
}

void	RPN::_processNextElement(std::string& input) {
	// read spaces from input (check: can i "remove" chars from BOF std::string??)
	// read 1 char from input
	// char is digit ? -> put it on stack and return
	// char is + - / * -> 
}
