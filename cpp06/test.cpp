#include <iostream>

int main() {
    // Integral Types
    int myInt = 42;
    unsigned int myUnsignedInt = 42;
    short myShort = 42;
    long myLong = 42;
    unsigned long myUnsignedLong = 42;
    char myChar = 'A';
    signed char mySignedChar = -65;
    unsigned char myUnsignedChar = 65;

    // Floating-Point Types
    float myFloat = 3.14f;
    double myDouble = 3.14;
    long double myLongDouble = 3.14L;

    // Boolean Type
    bool myBool = true;

    // Character Types
    wchar_t myWideChar = L'A';

    // Enumerated Type
    enum Color { RED, GREEN, BLUE };
    Color myColor = RED;

    // Pointer Types
    int* myIntPtr = &myInt;
    void* myVoidPtr = &myInt;

    // Null Pointer Type
    int* myNullPtr = NULL;

    // Output some of the scalar types
    std::cout << "Integer: " << myInt << std::endl;
    std::cout << "Unsigned Integer: " << myUnsignedInt << std::endl;
    std::cout << "Short: " << myShort << std::endl;
    std::cout << "Long: " << myLong << std::endl;
    std::cout << "Float: " << myFloat << std::endl;
    std::cout << "Double: " << myDouble << std::endl;
    std::cout << "Long Double: " << myLongDouble << std::endl;
    std::cout << "Boolean: " << myBool << std::endl;
    std::cout << "Character: " << myChar << std::endl;
    std::cout << "Wide Character: " << myWideChar << std::endl;
    std::cout << "Enum Color: " << myColor << std::endl;

    return 0;
}
