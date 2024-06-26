#include "iter.hpp"
#include <iostream>

void	shiftRight(char& c) {
	c++;
}

void	shiftLeft(char& c) {
	c--;
}

int main( void ) {
	char	str[10] = "abcdefghi";

	std::cout << str << std::endl;
	iter(str, 9, &shiftLeft);
	std::cout << str << std::endl;
	iter(str, 9, &shiftRight);
	std::cout << str << std::endl;

	return 0;
}
