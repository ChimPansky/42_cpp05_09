#include "Serializer.hpp"
#include <iostream>

int main() {
	std::cout << "---serialize-Test--- " << std::endl;
	Data 		originalData;

	originalData.info = "Hello World";
	originalData.randomValue = 999;

	std::cout << "\noriginalData.info: " << originalData.info << std::endl;
	std::cout << "originalData.randomValue: " << originalData.randomValue << std::endl;

	std::cout << "\nData --> uintptr_t..." << std::endl;
	uintptr_t 	convertedData = Serializer::serialize(&originalData);
	std::cout << "uintptr_t --> Data..." << std::endl;
	Data*		convertedUintPtr = Serializer::deserialize(convertedData);

	std::cout << "\nconvertedUintPtr->info: " << convertedUintPtr->info << std::endl;
	std::cout << "convertedUintPtr->randomValue: " << convertedUintPtr->randomValue << "\n" << std::endl;

	std::cout << "sizeof(Data): " << sizeof(originalData) << std::endl;
	std::cout << "sizeof(uintptr_t): " << sizeof(uintptr_t) << std::endl;

	return 0;
}
