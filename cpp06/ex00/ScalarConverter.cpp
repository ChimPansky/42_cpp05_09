#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>


int	ScalarConverter::convert(const std::string& str) {
	if (containsUnprintable(str))
		throw NonDisplayableException();
	return 42;
}

bool	ScalarConverter::containsUnprintable(const std::string &str) {
	for (size_t	i = 0; i < str.length(); i++) {
		if (!std::isprint(str[i]))
			return true;
	}
	return (str.length() < 1);
}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return ("Cannot convert non-displayable characters!");
}
