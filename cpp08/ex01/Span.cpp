#include "Span.hpp"
#include <iostream>

Span::Span() : _capacity(0) {}

Span::Span(unsigned int capacity) : _capacity(capacity) {}

Span::Span(Span const & other) {
	*this = other;
}

Span::~Span() {}

Span& Span::operator=(Span const & other) {
	if (this != &other) {
		_capacity = other._capacity;
		_values = other._values;
	}
	return *this;
}

void	Span::addNumber(int number) {
	if (_values.size() < _capacity) {
		_values.insert(number);
	} else {
		throw SpanFullException();
	}
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_values.size() + (end - begin) > _capacity)
		throw RangeTooBigException();
	_values.insert(begin, end);
}

int Span::shortestSpan() const {
	if (_values.size() < 2) {
		throw NotEnoughNumbersException();
	}
	int left;
	int right;
	int shortest = *_values.rbegin() - *_values.begin();
	for (std::multiset<int>::iterator it = _values.begin(); it != _values.end(); it++) {
		if (it == _values.begin()) {
			left = *it;
			continue;
		}
		right = *it;
		if (right - left < shortest)
			shortest = right - left;
		left = right;
	}
	return shortest;
}

int Span::longestSpan() const {
	if (_values.size() < 2) {
		throw NotEnoughNumbersException();
	}
	return (*_values.rbegin() - *_values.begin());
}

std::multiset<int> Span::getValues() const {
	return _values;
}

unsigned int	Span::getCapacity() const {
	return _capacity;
}

void Span::print() const {
	if (_values.size() == 0) {
		std::cout << "{empty}" << std::endl;
		return;
	}
	std::cout << "Span size: " << _values.size() << "/" << _capacity << std::endl;
	for (std::multiset<int>::iterator it = _values.begin(); it != _values.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "smallest aka _values.begin(): " << *(_values.begin()) << std::endl;
	std::cout << "largest aka _values.rbegin(): " << *(_values.rbegin()) << "\n" <<  std::endl;
}

const char* Span::SpanFullException::what() const throw() {
	return "So sorry Madam/Sir, but this span is quite full already!";
}

const char* Span::RangeTooBigException::what() const throw() {
	return "So sorry Madam/Sir, but the range you are trying to add is simply too large!";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return "So sorry Madam/Sir, but there are not enough numbers to calculate a span!";
}
