#include <sstream>

#include <iostream>

int main()
{
	std::string str = " 2   5   6 -  +";
	std::stringstream ss(str);

	std::string element;

	while (ss >> element) {
		std::cout << "element: " << element << std::endl;
		std::cout << "size: " << element.size() << std::endl;
		std::cout << "len: " << element.length() << std::endl;
		std::cout << "ss.eof(): " << ss.eof() << std::endl;
		std::cout << "ss.rdstate(): " << ss.rdstate() << std::endl;
		std::cout << "ss.flags(): " << ss.flags() << std::endl;
		std::cout << "ss.good(): " << ss.good() << std::endl;


	}


}
