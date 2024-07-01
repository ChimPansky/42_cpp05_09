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
  private:
	// Constructors are private, because no instance of class is needed
	RPN();
	RPN(const RPN& other);
	~RPN();

	const RPN operator=(const RPN& other);

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
