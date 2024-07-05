#include "FjVector.hpp"
#include "Verbose.hpp"
#include "JacobsThal.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

FjVector::FjVector() {}

FjVector::FjVector(const FjVector& other)
	: intVector(other) {}

FjVector::~FjVector() {}

FjVector&	FjVector::operator=(const FjVector& other) {
	if (this != &other)
		intVector::operator=(other);
	return (*this);
}

void		FjVector::print() const {
	VERBOSE_OUT("FjVector.print():");
	_printVec(*this);
	std::cout << std::endl;
}

void	FjVector::sort() {
	VERBOSE_OUT("FjVector.sort():");
	if (size() < 2)
		return ;
	VERBOSE_OUT("has stray element: " << _hasStrayElement);
	_sorted.clear();
	_lower.clear();
	_hasStrayElement = size() % 2 == 1;
	_lastElement = *(end() - 1);
	_sortComparisons = 0;
	_mergeInsert(*this);
}

void	FjVector::_mergeInsert(intVector& vec) {
	VERBOSE_OUT_ARGS("_mergeInsert", _printVec(vec));
	pairVector	pairs = _makePairs(vec);
	_orderPairs(pairs);
	_mergeSortPairs(pairs, pairs.begin(), pairs.end() - 1);
	std::cout << "sorted pairs: ";
	_printPairs(pairs);
	std::cout << std::endl;
	_insertLargerElements(pairs);
	VERBOSE_OUT_ARGS("sorted upper: ", _printVec(_sorted));


	_sorted.insert(_sorted.begin(), pairs[0].first);
	_insertSmallerElements(pairs);
	if (_hasStrayElement)
		_binaryInsert(_sorted, _sorted.begin(), _sorted.end(), _lastElement);
	intVector::operator=(_sorted);
	VERBOSE_OUT(size() << " elements sorted.");
	VERBOSE_OUT("Comparisons done: " << _sortComparisons);
	// 	_sorted.push_back(pairs[0].second);
	// 	return ;
	// }
	// intVector	upperElements;
	// for (pairVector::iterator it = pairs.begin(); it != pairs.end(); it++)
	// 	upperElements.push_back(it->second);
	// _insertLowerElements(pairs);
}

pairVector	FjVector::_makePairs(const intVector& vec) {
	VERBOSE_OUT_ARGS("_makePairs", _printVec(vec));
	pairVector	pairs;
	for (const_iterator cit = vec.begin(); cit != (vec.end() - vec.size() % 2); cit += 2)
		pairs.push_back(std::make_pair(*cit, *(cit + 1)));
	#if VERBOSE
		_printPairs(pairs);
		std::cout << std::endl;
	#endif
	return pairs;
}

// this compares integers pairwise...
// compare first and second element of each pair and order accordingly
// { (5, 3), (1, 9), (7, 4) } --> { (3,5), (1, 9), (4, 7) }
void	FjVector::_orderPairs(pairVector& pairs) {
	VERBOSE_OUT_ARGS("_orderPairs", _printPairs(pairs));
	for (pairVector::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
		_sortComparisons++;
	}
	#if VERBOSE
		_printPairs(pairs);
		std::cout << std::endl;
	#endif
}

// this compares PAIRS of integers...
// compare larger elements of each pair and sort accordingly
// { (3, 5), (1, 9), (4, 7) } -> { (3,5), (4, 7), (1, 9) }
void	FjVector::_mergeSortPairs(pairVector& target, pairsIterator left, pairsIterator right) {
	VERBOSE_OUT("_mergeSortPairs() left: " << *left << " | right: " << *right);
	if (left >= right)
		return ;
	pairsIterator	center;
	center = left + (right - left) / 2;
	center = left + std::distance(left, right) / 2;
	_mergeSortPairs(target, left, center);
	_mergeSortPairs(target, center + 1, right);
	_mergePairs(left, center, right);
}

void	FjVector::_mergePairs(pairsIterator left, pairsIterator center, pairsIterator right) {
	pairVector	leftPairs(left, center + 1);
	pairVector	rightPairs(center + 1, right + 1);

	pairsIterator	leftPos = leftPairs.begin();
	pairsIterator	rightPos = rightPairs.begin();
	pairsIterator	targetPos = left;

	while (leftPos != leftPairs.end() && rightPos != rightPairs.end()) {
		if (leftPos->second < rightPos->second)
			*targetPos = *leftPos++;
		else
			*targetPos = *rightPos++;
		targetPos++;
		_sortComparisons++;
	}
	while (leftPos != leftPairs.end()) {
		*targetPos = *leftPos++;
		targetPos++;
	}
	while (rightPos != rightPairs.end()) {
		*targetPos = *rightPos++;
		targetPos++;
	}
}

void	FjVector::_insertLargerElements(const pairVector& pairs) {
	for (pairsConstIterator cit = pairs.begin(); cit != pairs.end(); cit++)
		_sorted.push_back(cit->second);
}

void	FjVector::_insertSmallerElements(pairVector& pairs) {
	pairVector::size_type	pairNumber = 2;
	std::pair<std::size_t, std::size_t>	jacobsthal;

	intVector::iterator	left;
	intVector::iterator	right;

	intVector::iterator	optimalPos;

	int	insertVal;

	while (pairNumber <= pairs.size()) {
		jacobsthal = jacobsthal::getBounds(pairNumber);
		std::cout << "jacob bounds: (" << jacobsthal.first << "," << jacobsthal.second << ")" << std::endl;
		pairNumber = std::min(pairs.size(), jacobsthal.second);
		std::cout << "pairnumber: " << pairNumber << std::endl;
		while (pairNumber > jacobsthal.first) {
			// TODO: optimize insert range...
			left = _sorted.begin() + jacobsthal.first - 1;
			right = std::min(_sorted.begin() + jacobsthal.second * 2 - 1, _sorted.end() - 1);
			insertVal = (pairs.begin() + pairNumber - 1)->first;
			std::cout << "sorted.begin(): " << _sorted.begin().base() << std::endl;
			std::cout << "binary inserting pair number: " << pairNumber << " in range " << left - _sorted.begin() << "/" << right - _sorted.begin() << std::endl;
			//optimalPos = std::lower_bound(left, right, insertVal);
			optimalPos = std::lower_bound(_sorted.begin(), _sorted.end(), insertVal);
			//_sorted.insert(optimalPos, insertVal);
			_binaryInsert(_sorted, _sorted.begin(), _sorted.end(), insertVal);
			pairNumber--;
		}
		pairNumber = jacobsthal.second + 1;
	}
	// while (pairNumber > jacobsthal.second) {
	// 	// _binaryInsert(_sorted, (pairs.begin() + pairIndex)->first);
	// 	std::cout << "binary inserting lower insert index: " << pairNumber << std::endl;
	// 	pairNumber--;
	// }
}

void	FjVector::_binaryInsert(intVector& vec, intVector::iterator left, intVector::iterator right, int val) {
	intVector::iterator	center;
	int tempComp = 0;
	while (left < right) {
		// std::cout << "left: " << left - vec.begin() << " | right: " << right - vec.begin() << std::endl;
		center = left + (right - left) / 2;
		if (*center < val)
			left = center + 1;
		else
			right = center;
		tempComp++;
		_sortComparisons++;
	}
	// std::cout << "insert index: " << left - vec.begin() << std::endl;
	std::cout << "binary insert did " << tempComp << " comparisons..." << std::endl;
	vec.insert(left, val);
}


// helpers (to be removed):

inline void	FjVector::_printVec(const intVector& vec) const {
	// different ways for this derived class to iterate through the vector structure inherited
	// from base class intVector (aka std::vector<int>):
	// for (size_type i = 0; i < size(); i++) {
	// 	std::cout << (*this)[i] << std::endl;
	// }
	// for (size_type i = 0; i < size(); i++) {
	// 	std::cout << intVector::operator[](i) << std::endl;
	// }
	// for (intVector::const_iterator cit = intVector::begin(); cit != intVector::end(); cit++)
	// 	std::cout << *cit << std::endl;
	for (const_iterator cit = vec.begin(); cit != vec.end(); cit++)
		std::cout << *cit << ((cit != vec.end() - 1) ? ", " : "") ;
}

void		FjVector::_printPairs(const pairVector& pairs) {
	for (pairVector::const_iterator cit = pairs.begin(); cit != pairs.end(); cit++)
		std::cout << *cit << ((cit != pairs.end() - 1) ? ", " : "");
}

std::ostream& operator<<(std::ostream& lHs, const intPair& rHs) {
	lHs << "(" << rHs.first << ", " << rHs.second << ")";
	return lHs;
}
