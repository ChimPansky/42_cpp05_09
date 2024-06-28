#pragma once
#include <set>
#include <vector>

class Span {
  private:
	unsigned int 	_capacity;
	std::multiset<int> _values;

  public:
	Span();
	Span(unsigned int capacity);
	Span(Span const & other);
	~Span();

	Span& operator=(Span const & other);

	void	addNumber(int number);
	void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan() const;
	int		longestSpan() const;

	std::multiset<int>	getValues() const;
	unsigned int		getCapacity() const;
	void				print() const;

	class SpanFullException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class RangeTooBigException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	class NotEnoughNumbersException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};
