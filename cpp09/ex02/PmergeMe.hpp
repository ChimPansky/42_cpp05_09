#pragma once

#include <iostream>
namespace Status {
	enum StatusCodes {
		SUCCESS,
		ERROR,
		ERROR_ARGUMENTS,
		ERROR_MEMORY,
		ERROR_INVALID_NUMBER,
		ERROR_SORTING,
		ERROR_FJ_VEC,
		ERROR_FJ_LIST
	};
}

template <typename T>
void	printContainer(const T& container, std::size_t limit) {
	std::size_t i = 0;
	typename T::const_iterator cit;
	for (cit = container.begin(); cit != container.end() && i <= limit; cit++, i++ ){
		std::cout << *cit << " ";
	}
	if (limit < container.size())
		std::cout << "[...]";
	std::cout << std::endl;
}
