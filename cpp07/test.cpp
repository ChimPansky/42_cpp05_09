#include <iostream>
template <typename X>
X add(X left, X right) {
	return left + right;
}

template <typename ANY>
ANY sub(ANY left, ANY right) {
	return left - right;
}

int main() {
	int intX = 1;
	int intY = 2;
	int	intResult = add(intX, intY);
	std::cout << "intResult: " << intResult << std::endl;

	double dblX = 1.5;
	double dblY = 2.456;
	double dblResult = add(dblX, dblY);
	std::cout << "dblResult: " << dblResult << std::endl;

	return 0;
}
