#include "PmergeMe.hpp"
#include <climits>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

bool	strIsNum(const std::string& str) {
	size_t		i = 0;
	bool		valid = false;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.size(); i++) {
		if (std::isdigit(str[i]))
			valid = true;
		else
			return false;
	}
	return valid;
}

bool	strToInt(const std::string& str, int& target) {
	std::stringstream	strStream(str);
	strStream >> target;
	if (strStream.fail())
		return false;
	return true;
}

int	readNumbersIntoVec(std::vector<int>& vec, char*& numbers) {
	std::stringstream	ssNumbers(numbers);
	std::string			strNumber;
	int					number;
	while (ssNumbers >> strNumber) {
		if (!strIsNum(strNumber) || !strToInt(strNumber, number) || number < 0) {
			std::cout << "Error: Found invalid number: " << strNumber << std::endl;
			return Status::ERROR_INVALID_NUMBER;
		}
		vec.push_back(number);
	}
	return Status::SUCCESS;
}

int	processArguments(std::vector<int>& vec, int argc, char**& numberArrays) {
	for (int i = 1; i < argc; i++) {
		if (readNumbersIntoVec(vec, numberArrays[i]) != Status::SUCCESS)
			return Status::ERROR_ARGUMENTS;
	}
	return Status::SUCCESS;
}

int	fordJohnsonSort(std::vector<int>&vec) {
	if (false)
		return Status::ERROR_FJ_VEC;
	for (size_t i = 0; i < INT_MAX; i++)
		(void)vec;
	std::sort(vec.begin(), vec.end());
	return Status::SUCCESS;
}

int	fordJohnsonSort(std::list<int>&list) {
	if (false)
		return Status::ERROR_FJ_LIST;
	for (size_t i = 0; i < INT_MAX; i++)
		(void)list;
	list.sort();
	return Status::SUCCESS;
}

int	sortAndDisplay(std::vector<int>& vec, std::size_t displayLimit) {
	std::list<int>		list(vec.begin(), vec.end());

	std::cout << std::left << std::fixed << std::setprecision(3);
	std::cout << std::setw(8) << "Before: ";
	printContainer(vec, displayLimit);
	clock_t	start = clock();
	int	status = fordJohnsonSort(vec);
	if (status != Status::SUCCESS)
		return status;
	clock_t	end = clock();
	double	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << std::setw(8) <<  "After: ";
	printContainer(vec, displayLimit);
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << sortDuration << " ms" <<  std::endl;
	start = clock();
	status = fordJohnsonSort(list);
	if (status != Status::SUCCESS)
		return status;
	end = clock();
	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << "Time to process a range of " << list.size()
		<< " elements with std::list   : " << sortDuration << " ms" << std::endl;
	return Status::SUCCESS;
}

int main (int argc, char** args) {
	if (argc < 2) {
		std::cout << "Error. Please provide a positive integer sequence as argument.\n"
			"Usage Example: ./PmergeMe 10 5 0 3" << std::endl;
		return Status::ERROR_ARGUMENTS;
	}
	std::vector<int>	vecNumbers;
	if (processArguments(vecNumbers, argc, args) != Status::SUCCESS)
		return Status::ERROR_ARGUMENTS;
	int	status = sortAndDisplay(vecNumbers, 10);
	if (status != Status::SUCCESS)
		return status;

	// exit(1); looks like exiting does not call destructors of containers...

	return Status::SUCCESS;
}
