#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

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

	return 0;
}
