#include "PmergeMe.hpp"
#include "FjVector.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
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

int	sortAndDisplay(FjVector& vec, std::size_t displayLimit) {
	std::cout << std::left << std::fixed << std::setprecision(3);
	std::cout << std::setw(8) << "Before: ";
	printContainer(vec, displayLimit);
	clock_t	start = clock();
	vec.sort();
	clock_t	end = clock();
	double	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << std::setw(8) <<  "After: ";
	printContainer(vec, displayLimit);
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << sortDuration << " ms" <<  std::endl;
	start = clock();
	//vec.sort();
	end = clock();
	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::list   : " << sortDuration << " ms" << std::endl;
	return Status::SUCCESS;
}

int main (int argc, char** args) {
	if (argc < 2) {
		std::cout << "Error. Please provide a positive integer sequence as argument.\n"
			"Usage Example: ./PmergeMe 10 5 0 3" << std::endl;
		return Status::ERROR_ARGUMENTS;
	}
	FjVector	vecNumbers;
	if (processArguments(vecNumbers, argc, args) != Status::SUCCESS)
		return Status::ERROR_ARGUMENTS;
	// TODO: allow duplicates? does it all work with duplicate values?
	int	status = sortAndDisplay(vecNumbers, 30);
	if (status != Status::SUCCESS)
		return status;
	return Status::SUCCESS;
}
