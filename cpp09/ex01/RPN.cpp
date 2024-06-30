#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <string>
#include <iostream>

std::stack<int>		RPN::_stack;
bool				RPN::_fail = false;
std::stringstream	RPN::_ssInput;

void	RPN::calculate(const std::string& input, int& target) {
	_reset(input);
	std::string	rpnToken;
	while (_ssInput >> rpnToken && !_fail) {
		_processToken(rpnToken);
	}
	if (_stack.size() != 1) {
		_fail = true;
		std::cout << "Error" << std::endl;
		return ;
	}
	target = _stack.top();
	_stack.pop();
}

bool	RPN::fail() {
	return _fail;
}

void	RPN::_reset(const std::string& input) {
	_clearStack();
	_ssInput.str(input);
	_ssInput.clear();
	_fail = false;
}

void	RPN::_clearStack() {
	while (!_stack.empty())
		_stack.pop();
}

void	RPN::_processToken(std::string& rpnToken) {
	if (rpnToken == "+" || rpnToken == "-" || rpnToken == "*" || rpnToken == "/") {
		_executeOperation(rpnToken);
		return ;
	}
	else if (std::isdigit(rpnToken[0])) {
		_stack.push(rpnToken[0] - '0');
		return ;
	}
	_fail = true;
	std::cout << "Error: Found invalid Character: " << rpnToken[0] << std::endl;
}

void	RPN::_executeOperation(std::string& op) {
	if (_stack.size() < 2) {
		std::cout << "Error: Not enough operands to execute: " << op << std::endl;
	}
	int	right = _stack.top();
	_stack.pop();
	int	left = _stack.top();
	_stack.pop();
	if (op == "+")
		_stack.push(left + right);
	else if (op == "-")
		_stack.push(left - right);
	else if (op == "*")
		_stack.push(left * right);
	else if (op == "/") {
		if (right == 0) {
			std::cout << "Error: Division by zero: " << left << op << right << std::endl;
			_fail = true;
		}
		_stack.push(left / right);
	}
	else {
		std::cout << "Invalid operator: " << op << std::endl;
		_fail = true;
	}
}
