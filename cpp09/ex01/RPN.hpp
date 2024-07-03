#pragma once
#include <sstream>
#include <stack>
#include <string>

// Reverse Polish Notation Calculater (stack-based)
// restrictions:
// - supported operators: + - / *
// - no brackets
class RPN {
  private:
	// Constructors are private, because no instance of class is needed
	RPN();
	RPN(const RPN& other);
	~RPN();

	const RPN operator=(const RPN& other);

	static std::stack<long>		_stack;
	static bool					_fail;
	static bool					_operandsGreaterTen;
	static bool					_overflow;
	static bool					_underflow;
	static std::stringstream	_ssInput;

	static void	_resetCalculator(const std::string& input);
	static void	_clearStack();
	static bool	_strIsNum(const std::string& str);
	static bool	_strToLong(const std::string& str, long& target);
	static void	_processToken(std::string& rpnToken);
	static void	_add(long left, long right);
	static void	_sub(long left, long right);
	static void	_mult(long left, long right);
	static void	_div(long left, long right);
	static void	_executeOperation(std::string& op);

  public:
	static void	calculate(const std::string& expression, long& target);
	static bool	fail();
};
