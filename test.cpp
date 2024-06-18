class A{
  public:
	int	x;
	char *data;

	A() {
		data = new char[100000000];
	}
	~A() {
		delete[] data;
	}
};

#include <iostream>

int main()
{
	A* test = new A;
	test->x = 42;
	std::cout << test->x << std::endl;
	delete test;
}
