#include "RPN.hpp"
#include <limits>
#include <iostream>

std::stack<long>	RPN::_stack;
bool				RPN::_fail = false;
bool				RPN::_operandsGreaterTen = false;
bool				RPN::_overflow = false;
bool				RPN::_underflow = false;
std::stringstream	RPN::_ssInput;

void	RPN::calculate(const std::string& input, long& target) {
	_resetCalculator(input);
	std::string	rpnToken;
	while (_ssInput >> rpnToken && !_fail)
		_processToken(rpnToken);
	if (_fail)
		return ;
	if (_stack.size() > 1)
		std::cout << "Error: Missing operator(s)" << std::endl;
	if (_stack.size() < 1)
		std::cout << "Error: Missing operand(s)" << std::endl;
	if (_stack.size() != 1) {
		_fail = true;
		return ;
	}
	target = _stack.top();
	_stack.pop();
	if (_operandsGreaterTen)
		std::cout << "Warning: Found operands not less than 10!\n";
	if (_overflow || _underflow)
		std::cout << "Warning: Calculations resulted in overflow/underflow!\n";
}

bool	RPN::fail() {
	return _fail;
}

void	RPN::_resetCalculator(const std::string& input) {
	_clearStack();
	_ssInput.str(input);
	_ssInput.clear();
	_fail = false;
	_overflow = false;
	_underflow = false;
	_operandsGreaterTen = false;
}

void	RPN::_clearStack() {
	while (!_stack.empty())
		_stack.pop();
}

bool	RPN::_strIsNum(const std::string& str) {
	size_t		i = 0;
	bool		valid = false;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			valid = true;
		else
			return false;
	}
	return valid;
}

bool	RPN::_strToLong(const std::string& str, long& target) {
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail())
		return false;
	return true;
}

void	RPN::_processToken(std::string& rpnToken) {
	if (rpnToken == "+" || rpnToken == "-" || rpnToken == "*" || rpnToken == "/") {
		_executeOperation(rpnToken);
		return ;
	}
	else {
		long	operand;
		if (!_strIsNum(rpnToken) || !_strToLong(rpnToken, operand)) {
			std::cout << "Error: Found invalid token: " << rpnToken << std::endl;
			_fail = true;
			return ;
		}
		if (operand >= 10)
			_operandsGreaterTen = true;
		_stack.push(operand);
	}
}

void	RPN::_add(long left, long right) {
	if (right > 0 && (left > (std::numeric_limits<long>::max() - right)))
		_overflow = true;
	else if (right < 0 && (left < (std::numeric_limits<long>::min() - right)))
		_underflow = true;
	_stack.push(left + right);
}

void	RPN::_sub(long left, long right) {
	if (right < 0 && (left > (std::numeric_limits<long>::max() + right)))
		_overflow = true;
	else if (right > 0 && (left < (std::numeric_limits<long>::min() + right)))
		_underflow = true;
	_stack.push(left - right);
}

void	RPN::_mult(long left, long right) {
	long	product = left * right;
	if (right != 0 && product / right != left)
		_overflow = true;
	_stack.push(product);
}

void	RPN::_div(long left, long right) {
	if (right == 0) {
		std::cout << "Error: Division by zero: " << left << "/" << right << std::endl;
		_fail = true;
		return ;
	}
	long	quot;
	quot = left / right;
	_stack.push(quot);
}

void	RPN::_executeOperation(std::string& op) {
	if (_stack.size() < 2) {
		std::cout << "Error: Not enough operands to execute: " << op << std::endl;
		_fail = true;
		return ;
	}
	long	right = _stack.top();
	_stack.pop();
	long	left = _stack.top();
	_stack.pop();
	if (op == "+")
		_add(left, right);
	else if (op == "-")
		_sub(left, right);
	else if (op == "*")
		_mult(left, right);
	else if (op == "/")
		_div(left, right);
	else {
		std::cout << "Error: Invalid operator: " << op << std::endl;
		_fail = true;
	}
}
