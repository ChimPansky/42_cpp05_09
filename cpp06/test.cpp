#include <iostream>

#include <string>
// class A{
//   public:
// 	int	x;
// 	char *data;

// 	A() {
// 		data = new char[100000000];
// 	}
// 	~A() {
// 		delete[] data;
// 	}
// };



#include <iostream>
#include <sstream>
int main()
{
	std::string	input;
	std::stringstream ssInput;
	char c;
	int	i;
	float f;
	double d;
	while (std::getline(std::cin, input)) {
		std::stringstream ssInput(input);
		ssInput << input;
		ssInput >> c;
		std::cout << "ssInput: " << ssInput.str() << std::endl;
		if (ssInput.fail())
			std::cerr << "c-Conversion failed!\n";
		std::cout << "c: " << c << std::endl;
		ssInput.seekg(0);
		ssInput >> i;
		std::cout << "ssInput: " << ssInput.str() << std::endl;
		if (ssInput.fail())
			std::cerr << "i-Conversion failed!\n";
		std::cout << "i: " << i << std::endl;
		ssInput.seekg(0);
		ssInput >> f;
		std::cout << "ssInput: " << ssInput.str() << std::endl;
		if (ssInput.fail())
			std::cerr << "f-Conversion failed!\n";
		std::cout << "f: " << f << std::endl;
		ssInput.seekg(0);
		ssInput >> d;
		std::cout << "ssInput: " << ssInput.str() << std::endl;
		if (ssInput.fail())
			std::cerr << "d-Conversion failed!\n";
		std::cout << "d: " << d << std::endl;
	}
	return 0;
}


// int main() {
//     // Integral Types
//     int myInt = 42;
//     unsigned int myUnsignedInt = 42;
//     short myShort = 42;
//     long myLong = 42;
//     unsigned long myUnsignedLong = 42;
//     char myChar = 'A';
//     signed char mySignedChar = -65;
//     unsigned char myUnsignedChar = 65;

//     // Floating-Point Types
//     float myFloat = 3.14f;
//     double myDouble = 3.14;
//     long double myLongDouble = 3.14L;

//     // Boolean Type
//     bool myBool = true;

//     // Character Types
//     wchar_t myWideChar = L'A';

//     // Enumerated Type
//     enum Color { RED, GREEN, BLUE };
//     Color myColor = RED;

//     // Pointer Types
//     int* myIntPtr = &myInt;
//     void* myVoidPtr = &myInt;

//     // Null Pointer Type
//     int* myNullPtr = NULL;

//     // Output some of the scalar types
//     std::cout << "Integer: " << myInt << std::endl;
//     std::cout << "Unsigned Integer: " << myUnsignedInt << std::endl;
//     std::cout << "Short: " << myShort << std::endl;
//     std::cout << "Long: " << myLong << std::endl;
//     std::cout << "Float: " << myFloat << std::endl;
//     std::cout << "Double: " << myDouble << std::endl;
//     std::cout << "Long Double: " << myLongDouble << std::endl;
//     std::cout << "Boolean: " << myBool << std::endl;
//     std::cout << "Character: " << myChar << std::endl;
//     std::cout << "Wide Character: " << myWideChar << std::endl;
//     std::cout << "Enum Color: " << myColor << std::endl;

//     return 0;
// }
