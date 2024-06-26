#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
	int	randomNum;
	randomNum = rand() % 4;
	switch (randomNum) {
		case(0):
			return new A();
		case(1):
			return new B();
		case(2):
			return new C();
		default:
			return new Base();
	}
}

void	identify(Base* p) {
	std::cout << "identify(Base* p) detected type: ";
	if ((dynamic_cast<A*>(p)) != 0) {
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != 0) {
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != 0) {
		std::cout << "C" << std::endl;
		return ;
	}
	if (dynamic_cast<Base*>(p) != 0) {
		std::cout << "Base" << std::endl;
		return ;
	}
	std::cout << "unknown" << std::endl;
}

void	identify(Base& p) {
	std::cout << "identify(Base& p) detected type: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	try {
		(void)dynamic_cast<Base&>(p);
		std::cout << "Base" << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	std::cout << "unknown" << std::endl;
}

#define SIZE 10

int main() {
	std::cout << "\n---SECTION1---" << std::endl;
	std::cout << "Randomly creating " << SIZE << " 'mystery' pointers of type A/B/C/Base...\n" << std::endl;
	std::srand(time(0));
	Base* poly[SIZE];
	for (int i = 0; i < SIZE; i++) {
		poly[i] = generate();
	}

	std::cout << "---identify by reference tests---\n" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		identify(*poly[i]);
	}

	std::cout << "\n---identify by pointer tests---\n" << std::endl;

	for (int i = 0; i < SIZE; i++) {
		identify(poly[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		delete poly[i];
	}


	std::cout << "\n---SECTION2---\n" << std::endl;
	std::cout << "Creating specific pointers of type A/B/C/Base...\n" << std::endl;

	A 	aRef;
	B	bRef;
	C	cRef;
	Base base;

	Base* aPtr = new A();
	Base* bPtr = new B();
	Base* cPtr = new C();
	Base* basePtr = new Base();;

	std::cout << "---identify by reference tests---\n" << std::endl;

	identify(aRef);
	identify(bRef);
	identify(cRef);
	identify(base);
	std::cout << std::endl;
	identify(*aPtr);
	identify(*bPtr);
	identify(*cPtr);
	identify(*basePtr);
	std::cout << std::endl;

	std::cout << "---identify by pointer tests---\n" << std::endl;

	identify(&aRef);
	identify(&bRef);
	identify(&cRef);
	identify(&base);
	std::cout << std::endl;
	identify(aPtr);
	identify(bPtr);
	identify(cPtr);
	identify(basePtr);
	std::cout << std::endl;

	delete aPtr;
	delete bPtr;
	delete cPtr;
	delete basePtr;
	return 0;
}
