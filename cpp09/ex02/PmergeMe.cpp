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

// jacob[n] = jacob[n-2] * 2 + jacob[n-1]
static const int jacobsthal[33] = {
	0,		  1, 		 1, 		3, 		   5, 			11, 	  21,
	43, 	  85, 		 171, 	  	341, 	   683, 	  	1365, 	  2731,
	5461, 	  10923, 	 21845, 	43691, 	   87381, 		174763,   349525,
	699051,   1398101,   2796203,   5592405,   11184811, 	22369621, 44739243,
	89478485, 178956971, 357913941, 715827883, 1431655765};

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

std::vector<int>::iterator	binarySearch(std::vector<int>& mainChain, int val) {
	std::vector<int>::iterator	left = mainChain.begin();
	std::vector<int>::iterator	right = mainChain.end();
	while (left < right) {
		std::vector<int>::iterator	center = left + (right - left) / 2;
		if (*center < val)
			left = center + 1;
		else
			right = center;
	}
	return left;
}

int	fordJohnsonSort(std::vector<int>&source) {

	if (false)
		return Status::ERROR_FJ_VEC;
	if (source.size() < 2)
		return Status::SUCCESS;

	// dividing into n/2 pairs and sorting those pairs
	std::vector<int>::iterator	left = source.begin();
	std::vector<int>::iterator	right = left + 1;
	for (; left != source.end() && left != (source.end() - 1); left += 2, right += 2) {
		std::cout << "left: " << *left << " | right: " << *right << " | end(): " << *(source.end() - 1) << std::endl;
		if (*left > *right)
			std::swap(*left, *right);
	}
	std::cout << "source: ";
	printContainer(source, 10);

	// iterating through the larger elements of the pairs and binary inserting them into a new vector...
	std::vector<int>	mainChain;
	for (std::vector<int>::iterator it = (source.begin() + 1);
	it != source.end() && it != (source.end() - 1); it += 2) {
		std::vector<int>::iterator	insertPos = binarySearch(mainChain, *it);
		mainChain.insert(insertPos, *it);
	}
	std::cout << "main chain: ";
	printContainer(mainChain, 10);

	// TODO: binary insert the smaller elements of the pairs in order of jacobsthal
	// (start with lower element of (J)3rd pair, then 2nd, (J)5th, 4th, (J)11th, 10th, 9th, 8th, 7th, 6th, (J)21th...)
	// question: when to insert lower element of 1st pair?
	// careful with single element when source.size() is odd...



	// std::sort(vec.begin(), vec.end());
	return Status::SUCCESS;
}

int	fordJohnsonSort(std::list<int>&list) {
	if (false)
		return Status::ERROR_FJ_LIST;
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
