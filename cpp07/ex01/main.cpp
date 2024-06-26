#include "iter.hpp"
#include <iostream>

void	shiftRight(char& c) {
	c++;
}

void	shiftLeft(char& c) {
	c--;
}

void	shout(std::string& msg) {
	std::cout << msg << std::endl;
}

int main( void ) {
	char	str[10] = "abcdefghi";

	std::cout << str << std::endl;
	iter(str, 9, &shiftLeft);
	std::cout << str << std::endl;
	iter(str, 9, &shiftRight);
	std::cout << str << std::endl;

	std::cout << std::endl;

	std::string messages[3] = {
		"HEY!",
		"HO!",
		"OK, BYE!"
	};
	iter(messages, 3, &shout);

	return 0;
}
