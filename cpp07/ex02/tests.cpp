#include "Array.hpp"
#include <iostream>
#include <string>

int main() {

	std::cout << "\n---Default constructor---" << std::endl;
	Array<std::string> strEmpty;
	std::cout << "\nstrEmpty Size: " << strEmpty.size() << std::endl;
	strEmpty.print();

	std::cout << "\n---Constructor(size_t n)---" << std::endl;

	Array<std::string> strArr1(5);
	std::cout << "\nstrArr1 Size: " << strArr1.size() << std::endl;
	strArr1.print();
	strArr1[0] = "Hello";
	strArr1[1] = "World";

	std::cout << std::endl;

	std::cout << "\nstrArr1 Size: " << strArr1.size() << std::endl;
	strArr1.print();

	std::cout << "\n---Copy constructor--- " << std::endl;
	Array<std::string> strArr2(strArr1);
	std::cout << "\nstrArr2 Size: " << strArr2.size() << std::endl;
	strArr2.print();
	strArr2[2] = "This is only in strArr2";
	std::cout << "\nstrArr1 Size: " << strArr1.size() << std::endl;
	strArr1.print();
	std::cout << "\nstrArr2 Size: " << strArr2.size() << std::endl;
	strArr2.print();

	std::cout << "\n---Copy assignment operator overload--- " << std::endl;
	strEmpty = strArr2;
	std::cout << "\nstrEmpty Size: " << strEmpty.size() << std::endl;
	strEmpty.print();

	std::cout << "\n---Out of bounds exception---" << std::endl;

	std::cout << "strArr1[6]: ";
	try {
		strArr1[6] = "No can do Sir!";
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "strArr1[-1]: ";
	try {
		strArr1[-1] = "No can do Sir!";
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---Size_t Array---" << std::endl;
	Array<size_t> size_tArr(50);
	for (size_t i = 0; i < size_tArr.size(); i++) {
		if (i < 2)
			size_tArr[i] = 1;
		else
			size_tArr[i] = size_tArr[i - 2] + size_tArr[i - 1];
	}
	std::cout << "\nsize_tArr Size: " << size_tArr.size() << std::endl;
	size_tArr.print();
	std::cout << std::endl;

	return 0;
}
