#pragma once
#include <sstream>
#include <stack>
#include <string>

// Reverse Polish Notation Calculater (stack-based)
// restrictions:
// - operands have to be positive single digits ( 0 <= x <= 9)
// - supported operators: + - / *
// - no brackets
class RPN {
	// Constructors: private, because no instance of class is needed
  private:
	RPN();
	RPN(const RPN& other);
	~RPN();
  private:
	// static members needed for evaluating mathematical expressions in RPN-format passed as a string
	static std::stack<int>				_stack;
	static bool							_fail;
	static std::stringstream			_ssInput;

	static void	_resetCalculator(const std::string& input);
	static void	_clearStack();
	static void	_processToken(std::string& rpnToken);
	static void	_executeOperation(std::string& op);

  public:
	static void	calculate(const std::string& expression, int& target);
	static bool	fail();
};
