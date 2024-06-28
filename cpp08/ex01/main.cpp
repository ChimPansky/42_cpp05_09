#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <vector>

int main() {
	std::cout << "\n---Tests from subject---\n" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n---Additional tests---\n" << std::endl;

	{
		int	capacity = 10;
		int	fillCount = capacity;
		Span sp = Span(capacity);
		std::srand(std::time(0));
		sp.print();
		int maxVal = 100;
		std::cout << "\n---Filling span with " << fillCount << " random numbers...\n" << std::endl;
		int i;
		try {
			for (i = 0; i < fillCount; i++) {
				sp.addNumber(std::rand() % maxVal);
			}
			std::cout << "\nSuccessfully filled span with " << sp.getValues().size() << " random numbers..." << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
			std::cout << "Only managed to fill span with " << i << " out of " << fillCount << " random numbers :(\n" << std::endl;
		}
		sp.print();
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n---Test for adding range of numbers---\n" << std::endl;
	{
		int	capacity = 10;
		Span sp = Span(capacity);
		int	arrInt[] = {-54, 45, 120, 0, 10, 7, 66, -453};
		std::vector<int> numberSource;
		for (int i = 0; i < 8; i++) {
			numberSource.push_back(arrInt[i]);
		}

		sp.print();
		std::cout << std::endl;
		try {

			sp.addNumber(42);
			sp.addNumber(43);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		sp.print();
		try {
			sp.addRange(numberSource.begin(), numberSource.end());
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		sp.print();
	}

	return 0;
}
