#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
	std::cout << "\n---Testing easyfind with std::vector---\n" << std::endl;
	std::vector<int> vec(10);
	for (int i = 0; i < 10; i++) {
		vec[i] = i;
	}
	if (easyfind(vec, 42) == vec.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}
	if (easyfind(vec, 5) == vec.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}

	std::cout << "\n---Testing easyfind with const std::vector---\n" << std::endl;
	const std::vector<int> cvec = vec;

	if (easyfind(cvec, 42) == cvec.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}
	if (easyfind(cvec, 5) == cvec.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}

	std::cout << "\n---Testing easyfind with std::list---\n" << std::endl;

	std::list<int> lst;
	for (std::size_t i = 0; i < 10; i++) {
		lst.push_back(static_cast<int>(i));
	}
	if (easyfind(lst, 42) == lst.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}
	if (easyfind(lst, 5) == lst.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}

	std::cout << "\n---Testing easyfind with std::deque---\n" << std::endl;

	std::deque<int> deq(10);
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
		*it = 42;
	}
	if (easyfind(deq, 42) == deq.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}
	if (easyfind(deq, 5) == deq.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found" << std::endl;
	}

	// no need to handle associative containers (consist of key-value pairs) like map or set...
}
