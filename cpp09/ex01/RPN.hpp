#pragma once
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
	enum _OperationType {
		RPN_UNKNOWN_OPERATOR = 0,
		RPN_PLUS = 1,
		RPN_MINUS = 2,
		RPN_MULT = 3,
		RPN_DIV = 4
	};
	// static members needed for evaluating mathematical expressions in RPN-format passed as a string
	static std::stack<int>	_stack;
	static bool				_fail;

	static void	_reset();
	static void	_clearStack();
	static void	_processNextElement(std::string& input);
	static void	_executeOperation(_OperationType operator); // !!!!!!!!!!!!!

  public:
	int		calculate(const std::string& expression, int& target);
	bool	fail();


};
