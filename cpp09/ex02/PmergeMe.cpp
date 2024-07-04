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
	0,		  1,		  1, 		3, 		 5, 		11, 	   21,
	43, 	  85, 		 171, 	  	341, 	   683, 	  	1365, 	  2731,
	5461, 	  10923, 	 21845, 	43691, 	   87381, 		174763,   349525,
	699051,   1398101,   2796203,   5592405,   11184811, 	22369621, 44739243,
	89478485, 178956971, 357913941, 715827883, 1431655765};

static int	compareCounter = 0;

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
		compareCounter++;
	}
	return left;
}

int	fordJohnsonSort(std::vector<int>&raw, std::vector<int>&sorted) {
	if (false)
		return Status::ERROR_FJ_VEC;
	if (raw.size() == 1) {
		sorted.push_back(*raw.begin());
		return Status::SUCCESS;
	}

	// dividing into n/2 pairs and sorting those pairs
	std::vector<int>	lowerElements;
	std::vector<int>::iterator	left = raw.begin();
	std::vector<int>::iterator	right = left + 1;
	for (; left != raw.end() && left != (raw.end() - 1); left += 2, right += 2) {
		std::cout << "left: " << *left << " | right: " << *right << " | end(): " << *(raw.end() - 1) << std::endl;
		if (*left > *right)
			std::swap(*left, *right);
		lowerElements.push_back(*left);
		compareCounter++;
	}
	if (raw.size() % 2 == 1)
		lowerElements.push_back(*(raw.end() - 1));
	std::cout << "source: ";
	printContainer(raw, 10);

	std::vector<int>::iterator	insertPos;

	// iterating through the larger elements of the pairs and binary inserting them into sorted...
	for (std::vector<int>::iterator it = (raw.begin() + 1);	it != raw.end() && it != raw.end() + 1; it += 2) {
		insertPos = binarySearch(sorted, *it);	// we could use vector.upper_bound instead of binarySearch, but then we cannot keep track of how many comparisons we made (compareCounter)....
		sorted.insert(insertPos, *it);
	}
	std::cout << "main chain after larger elements insertion: ";
	printContainer(sorted, 10);
	std::cout << "lower elements: ";
	printContainer(lowerElements, 10);

	// iterating through the smaller elements of the pairs and inserting them into sorted with the help of jacobsthal
	int	limit = lowerElements.size();	// half of the raw vector (+1 if odd)
	std::vector<int>::iterator	right_bound;
	std::vector<int>::iterator	left_bound = lowerElements.begin() + 1;
	sorted.insert(sorted.begin(), *lowerElements.begin());
	for (int i = 3; jacobsthal[i] <= limit; i++) {
		right_bound = lowerElements.begin() + jacobsthal[i];
		std::cout << "jacobsthal right bound: " << right_bound - lowerElements.begin() << std::endl;
		for (; right_bound != left_bound; right_bound--) {
			insertPos = binarySearch(sorted, *right_bound);	// improve binary search for this
			std::cout << "inserting: " << *right_bound << std::endl;
			sorted.insert(insertPos, *right_bound);
		}
		left_bound = lowerElements.begin() + jacobsthal[i];
	}
	std::cout << "main chain after lower elements insertion: ";
	printContainer(sorted, 10);
	// insert rest of lowerElements into sorted vector (needs to be done when lowerElements.size() is not a jacobsthal-number)
	for (; left_bound != lowerElements.end(); left_bound++) { // TODO: check the bounds. it inserts too much
		std::cout << "inserting rest: " << *left_bound << std::endl;
		insertPos = binarySearch(sorted, *left_bound); // improve binary search for this
		sorted.insert(insertPos, *left_bound);
	}
	std::cout << "main chain after inserting rest of lowerElements: ";
	printContainer(sorted, 10);


	// TODO: binary insert the smaller elements of the pairs in order of jacobsthal
	// (start with lower element of (J)3rd pair, then 2nd, (J)5th, 4th, (J)11th, 10th, 9th, 8th, 7th, 6th, (J)21th...)
	// question: when to insert lower element of 1st pair? --> can be inserted at the very beginning of main chain without comparisopn
	//
	// careful with single element when source.size() is odd...



	// std::sort(vec.begin(), vec.end());
	return Status::SUCCESS;
}

int	fordJohnsonSort(std::list<int>&raw, std::list<int>&sorted) {
	(void)sorted;
	if (false)
		return Status::ERROR_FJ_LIST;
	raw.sort();
	return Status::SUCCESS;
}

int	sortAndDisplay(std::vector<int>& vecRaw, std::size_t displayLimit) {
	std::list<int>		listRaw(vecRaw.begin(), vecRaw.end());
	std::vector<int>	vecSorted;
	std::list<int>		listSorted;


	std::cout << std::left << std::fixed << std::setprecision(3);
	std::cout << std::setw(8) << "Before: ";
	printContainer(vecRaw, displayLimit);
	clock_t	start = clock();
	int	status = fordJohnsonSort(vecRaw, vecSorted);
	if (status != Status::SUCCESS)
		return status;
	clock_t	end = clock();
	double	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << std::setw(8) <<  "After: ";
	printContainer(vecSorted, displayLimit);
	std::cout << "Time to process a range of " << vecRaw.size()
		<< " elements with std::vector : " << sortDuration << " ms" <<  std::endl;
	start = clock();
	status = fordJohnsonSort(listRaw, listSorted);
	if (status != Status::SUCCESS)
		return status;
	end = clock();
	sortDuration = static_cast<double>(end - start) / 1000;
	std::cout << "Time to process a range of " << listRaw.size()
		<< " elements with std::list   : " << sortDuration << " ms" << std::endl;
	std::cout << "Number of comparisons used: " << compareCounter << std::endl;
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
	// TODO: allow duplicates? does it all work with duplicate values?
	int	status = sortAndDisplay(vecNumbers, 10);
	if (status != Status::SUCCESS)
		return status;

	// exit(1); looks like exiting does not call destructors of containers...

	return Status::SUCCESS;
}
