#pragma once
#include <stack>
#include <string>

// Reverse Polish Notation Calculater (stack-based)
class RPN {
	// Constructors: private, because no instance of class is needed
  private:
	RPN();
	RPN(const RPN& other);
	~RPN();

	// static members needed for evaluating mathematical expressions in RPN-format passed as a string
  private:
	static std::stack<int>	_stack;
	static bool				_fail;

  public:
	int		calculate(const std::string& expression);
	bool	fail();

};
