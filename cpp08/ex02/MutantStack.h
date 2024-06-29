#pragma once
#include <stack>
#include <iostream>

// by default std::stack has a std::deque as its underlying container
// we can change this by providing a second template argument for MutantStack
template <typename _Tp, typename _Sequence = std::deque<_Tp> >
class MutantStack : public std::stack<_Tp, _Sequence> {
  public:
	MutantStack()
		: std::stack<_Tp, _Sequence>() { std::cout << "MutantStack Default Constructor" << std::endl; }

	MutantStack(const MutantStack& other)
		: std::stack<_Tp, _Sequence>(other) { std::cout << "MutantStack Copy Constructor" << std::endl;}

	~MutantStack() { std::cout << "MutantStack Destructor" << std::endl; }

	MutantStack& operator=(const MutantStack& other) {
		std::cout << "MutantStack copy assignment operator overload" << std::endl;
		if (this != &other)
			*this = other;
		return *this;
	}

	typedef typename std::stack<_Tp, _Sequence> base_stack;

	typedef typename _Sequence::iterator iterator;
	typedef typename _Sequence::iterator const_iterator;
	typedef typename _Sequence::reverse_iterator reverse_iterator;
	typedef typename _Sequence::const_reverse_iterator const_reverse_iterator;
	// could also write typedefs in this pattern:
	//typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator 				begin() {
		return base_stack::c.begin();
	};
	const_iterator			begin() const {
		return base_stack::c.begin();
	}
	iterator				end() {
		return base_stack::c.end();
	}
	const_iterator			end() const {
		return base_stack::c.end();
	}
	reverse_iterator		rbegin() {
		return base_stack::c.rbegin();
	}
	const_reverse_iterator 	rbegin() const {
		return base_stack::c.rbegin();
	}
	reverse_iterator		 rend() {
		return base_stack::c.rend();
	}
	const_reverse_iterator 	rend() const {
		return base_stack::c.rend();
	}

	void	print() {
		std::cout << "MutantStack.print()" << std::endl;
		if (base_stack::c.empty())
			std::cout << "{empty}" << std::endl;
		for (iterator it = this->begin(); it != this->end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	void	rprint() {
		std::cout << "MutantStack.rprint()" << std::endl;
		if (base_stack::c.empty())
			std::cout << "{empty}" << std::endl;
		for (reverse_iterator it = this->rbegin(); it != this->rend(); it++) {
			std::cout << *it << std::endl;
		}
	}

};
