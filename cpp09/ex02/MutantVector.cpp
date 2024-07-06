#include "MutantVector.hpp"
#include "Verbose.hpp"
#include "JacobsThal.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

MutantVector::MutantVector() {}

MutantVector::MutantVector(const MutantVector& other)
	: intVector(other) {}

MutantVector::~MutantVector() {}

MutantVector&	MutantVector::operator=(const MutantVector& other) {
	if (this != &other)
		intVector::operator=(other);
	return (*this);
}

void		MutantVector::print() const {
	VERBOSE_OUT("MutantVector.print():");
	_printVec(*this);
	std::cout << std::endl;
}

void	MutantVector::sort() {
	VERBOSE_OUT("MutantVector.sort():");
	if (size() < 2)
		return ;
	_sortedChain.clear();
	_lowerChain.clear();
	_hasStrayElement = size() % 2 == 1;
	_lastElement = *(end() - 1);
	_sortComparisons = 0;
	_mergeInsert(*this);
}

void	MutantVector::_mergeInsert(intVector& vec) {
	VERBOSE_OUT_ARGS("_mergeInsert", _printVec(vec));
	pairVector	pairs = _makePairs(vec);
	_orderPairs(pairs);
	_mergeSortPairs(pairs, pairs.begin(), pairs.end() - 1);
	VERBOSE_OUT_ARGS("Sorted pairs: ", _printPairs(pairs));
	_splitPairs(pairs);
	VERBOSE_OUT("Inserting smaller element of pairnumber 1 at beginning...");
	_sortedChain.insert(_sortedChain.begin(), _lowerChain[0]);
	VERBOSE_OUT_ARGS("Sorted vector: ", _printVec(_sortedChain));
	_insertLowerChain(pairs);
	if (_hasStrayElement) {
		VERBOSE_OUT("Inserting stray element...");
		_binaryInsert(_sortedChain, _sortedChain.begin(), _sortedChain.end(), _lastElement);
	}
	intVector::operator=(_sortedChain);
	VERBOSE_OUT(size() << " elements sorted.");
	VERBOSE_OUT("std::vector Comparisons done: " << _sortComparisons << "\n");
}

pairVector	MutantVector::_makePairs(const intVector& vec) {
	VERBOSE_OUT_ARGS("_makePairs", _printVec(vec));
	pairVector	pairs;
	for (const_iterator cit = vec.begin(); cit != (vec.end() - vec.size() % 2); cit += 2)
		pairs.push_back(std::make_pair(*cit, *(cit + 1)));
	return pairs;
}

// this compares integers pairwise...
// compare first and second element of each pair and order accordingly
// { (5, 3), (1, 9), (7, 4) } --> { (3,5), (1, 9), (4, 7) }
void	MutantVector::_orderPairs(pairVector& pairs) {
	VERBOSE_OUT_ARGS("_orderPairs", _printPairs(pairs));
	for (pairVector::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->second < it->first)
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
void	MutantVector::_mergeSortPairs(pairVector& target, vPairsIterator left, vPairsIterator right) {
	VERBOSE_OUT("_mergeSortPairs()");
	if (left >= right)
		return ;
	vPairsIterator	center;
	center = left + (right - left) / 2;
	center = left + std::distance(left, right) / 2;
	_mergeSortPairs(target, left, center);
	_mergeSortPairs(target, center + 1, right);
	_mergePairs(left, center, right);
}

void	MutantVector::_mergePairs(vPairsIterator left, vPairsIterator center, vPairsIterator right) {
	pairVector	leftPairs(left, center + 1);
	pairVector	rightPairs(center + 1, right + 1);
	vPairsIterator	leftPos = leftPairs.begin();
	vPairsIterator	rightPos = rightPairs.begin();
	vPairsIterator	targetPos = left;
	while (leftPos != leftPairs.end() && rightPos != rightPairs.end()) {
		if (leftPos->second <= rightPos->second)
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

void	MutantVector::_splitPairs(const pairVector& pairs) {
	VERBOSE_OUT("Split Pairs into upper (sorted) chain and lower chain...");
	for (vPairsConstIterator cit = pairs.begin(); cit != pairs.end(); cit++) {
		_sortedChain.push_back(cit->second);
		_lowerChain.push_back(cit->first);
	}
	VERBOSE_OUT_ARGS("Sorted chain: ", _printVec(_sortedChain));
	VERBOSE_OUT_ARGS("Lower chain: ", _printVec(_lowerChain));
}

void	MutantVector::_insertLowerChain(const pairVector& pairs) {
	intVector::size_type	lowerIdx = 2;
	while (lowerIdx <= _lowerChain.size()) {
		std::pair<std::size_t, std::size_t>	jacobsthal = jacobsthal::getBounds(lowerIdx);
		VERBOSE_OUT("Jacobsthal bounds: (" << jacobsthal.first << "/" << jacobsthal.second << ")");
		lowerIdx = std::min(_lowerChain.size(), jacobsthal.second);
		while (lowerIdx > jacobsthal.first) {
			intVector::iterator	left = _sortedChain.begin();
			intVector::iterator	right = std::find(_sortedChain.begin(), _sortedChain.end(), (pairs.begin() + lowerIdx - 1)->second);
			int insertVal = _lowerChain[lowerIdx - 1];
			VERBOSE_OUT("Pairnumber " << lowerIdx << ": Binary inserting smaller element in range "
				<< left - _sortedChain.begin() + 1 << "/" << right - _sortedChain.begin() + 1);
			_binaryInsert(_sortedChain, left, right, insertVal);
			VERBOSE_OUT_ARGS("Sorted vector: ", _printVec(_sortedChain));
			lowerIdx--;
		}
		lowerIdx = jacobsthal.second + 1;
	}
}

void	MutantVector::_binaryInsert(intVector& vec, intVector::iterator left, intVector::iterator right, int val) {
	intVector::iterator	center;
	int insertComparisons = 0;
	while (left < right) {
		center = left + (right - left) / 2;
		if (*center < val)
			left = center + 1;
		else
			right = center;
		insertComparisons++;
		_sortComparisons++;
	}
	VERBOSE_OUT("Binary insert did " << insertComparisons << " comparisons...");
	vec.insert(left, val);
}

// helpers (just for printing steps of sorting algorithm):
void	MutantVector::_printVec(const intVector& vec) const {
	for (const_iterator cit = vec.begin(); cit != vec.end(); cit++)
		std::cout << *cit << ((cit != vec.end() - 1) ? ", " : "") ;
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
}

void		MutantVector::_printPairs(const pairVector& pairs) {
	for (pairVector::const_iterator cit = pairs.begin(); cit != pairs.end(); cit++)
		std::cout << "(" << cit->first << ", " << cit->second << ")"  << ((cit != pairs.end() - 1) ? ", " : "");
}
