#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
	MutantStack()
		: std::stack<T>() { std::cout << "MutantStack Default Constructor" << std::endl; }

	MutantStack(const MutantStack& other)
		: std::stack<T>(other) { std::cout << "MutantStack Copy Constructor" << std::endl;}

	~MutantStack() { std::cout << "MutantStack Destructor" << std::endl; }

	MutantStack& operator=(const MutantStack& other) {
		std::cout << "MutantStack copy assignment operator overload" << std::endl;
		if (this != &other)
			*this = other;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator 				begin() {
		return std::stack<T>::c.begin();
	};
	const_iterator 			begin() const {
		return std::stack<T>::c.begin();
	}

	iterator 				end() {
		return std::stack<T>::c.end();
	}
	const_iterator 			end() const {
		return std::stack<T>::c.end();
	}

	reverse_iterator 		rbegin() {
		return std::stack<T>::c.rbegin();
	}
	const_reverse_iterator 	rbegin() const {
		return std::stack<T>::c.rbegin();
	}

	reverse_iterator 		rend() {
		return std::stack<T>::c.rend();
	}
	const_reverse_iterator 	rend() const {
		return std::stack<T>::c.rend();
	}


	void	print() const {
		std::cout << "MutantStack.print()" << std::endl;
		if (std::stack<T>::c.empty())
			std::cout << "{empty}" << std::endl;
		for (MutantStack<int>::const_iterator it = this->begin(); it != this->end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	void	rprint() const {
		std::cout << "MutantStack.rprint()" << std::endl;
		if (std::stack<T>::c.empty())
			std::cout << "{empty}" << std::endl;
		for (MutantStack<int>::const_reverse_iterator it = this->rbegin(); it != this->rend(); it++) {
			std::cout << *it << std::endl;
		}
	}

};

	// typename std::stack<T>::container_type::iterator begin();
	// typename std::stack<T>::container_type::iterator end();

	// typename std::stack<T>::container_type::iterator end();
	// typename std::stack<T>::container_type::const_iterator cend() const;

	// typename std::stack<T>::container_type::reverse_iterator rbegin();
	// typename std::stack<T>::container_type::const_reverse_iterator crbegin() const;

	// typename std::stack<T>::container_type::reverse_iterator rend();
	// typename std::stack<T>::container_type::const_reverse_iterator crend() const;
