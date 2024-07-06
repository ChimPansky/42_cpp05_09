#include "MutantList.hpp"
#include "Verbose.hpp"
#include "JacobsThal.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

MutantList::MutantList() {}

MutantList::MutantList(const MutantList& other)
	: intList(other) {}

MutantList::~MutantList() {}

MutantList&	MutantList::operator=(const MutantList& other) {
	if (this != &other)
		intList::operator=(other);
	return (*this);
}

void		MutantList::print() const {
	VERBOSE_OUT("MutantList.print():");
	_printList(*this);
	std::cout << std::endl;
}

void	MutantList::sort() {
	VERBOSE_OUT("MutantList.sort():");
	if (size() < 2)
		return ;
	_sortedChain.clear();
	_lowerChain.clear();
	_hasStrayElement = size() % 2 == 1;
	_lastElement = *(--end());
	_sortComparisons = 0;
	_mergeInsert(*this);
}

void	MutantList::_mergeInsert(intList& list) {
	VERBOSE_OUT_ARGS("_mergeInsert", _printList(list));
	pairList	pairs = _makePairs(list);
	_orderPairs(pairs);
	pairs = _mergeSortPairs(pairs);
	VERBOSE_OUT_ARGS("Sorted pairs: ", _printPairs(pairs));
	_splitPairs(pairs);
	VERBOSE_OUT("Inserting smaller element of pairnumber 1 at beginning...");
	_sortedChain.insert(_sortedChain.begin(), *_lowerChain.begin());
	VERBOSE_OUT_ARGS("Sorted list: ", _printList(_sortedChain));
	_insertLowerChain(pairs);
	intList::operator=(_sortedChain);
	VERBOSE_OUT(size() << " elements sorted.");
	VERBOSE_OUT("std::list Comparisons done: " << _sortComparisons);
}

pairList	MutantList::_makePairs(const intList& list) {
	VERBOSE_OUT_ARGS("_makePairs", _printList(list));
	pairList	pairs;
	const_iterator	itEnd = list.size() % 2 == 0 ? list.end() : --list.end();
	for (const_iterator cit = list.begin(); cit != itEnd; cit++) {
		int	lower = *cit;
		cit++;
		int	upper = *cit;
		pairs.push_back(std::make_pair(lower, upper));
	}
	return pairs;
}

// this compares integers pairwise...
// compare first and second element of each pair and order accordingly
// { (5, 3), (1, 9), (7, 4) } --> { (3,5), (1, 9), (4, 7) }
void	MutantList::_orderPairs(pairList& pairs) {
	VERBOSE_OUT_ARGS("_orderPairs", _printPairs(pairs));
	for (pairList::iterator it = pairs.begin(); it != pairs.end(); it++) {
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
// void	MutantList::_mergeSortPairs2(pairList& target, lPairsIterator left, lPairsIterator right) {
// 	VERBOSE_OUT("_mergeSortPairs() left: " << *left << " | right: " << *right);

// 	if (left >= right)
// 		return ;
// 	lPairsIterator	center;
// 	center = left + (right - left) / 2;
// 	center = left + std::distance(left, right) / 2;
// 	_mergeSortPairs(target, left, center);
// 	_mergeSortPairs(target, center + 1, right);
// 	_mergePairs(left, center, right);
// }

// void	MutantList::_mergePairs2(lPairsIterator left, lPairsIterator center, lPairsIterator right) {
// 	pairList	leftPairs(left, center + 1);
// 	pairList	rightPairs(center + 1, right + 1);
// 	lPairsIterator	leftPos = leftPairs.begin();
// 	lPairsIterator	rightPos = rightPairs.begin();
// 	lPairsIterator	targetPos = left;
// 	while (leftPos != leftPairs.end() && rightPos != rightPairs.end()) {
// 		if (leftPos->second <= rightPos->second)
// 			*targetPos = *leftPos++;
// 		else
// 			*targetPos = *rightPos++;
// 		targetPos++;
// 		_sortComparisons++;
// 	}
// 	while (leftPos != leftPairs.end()) {
// 		*targetPos = *leftPos++;
// 		targetPos++;
// 	}
// 	while (rightPos != rightPairs.end()) {
// 		*targetPos = *rightPos++;
// 		targetPos++;
// 	}
// }


// this compares PAIRS of integers...
// compare larger elements of each pair and sort accordingly
// { (3, 5), (1, 9), (4, 7) } -> { (3,5), (4, 7), (1, 9) }
pairList MutantList::_mergeSortPairs(pairList& pairs) {
	if (pairs.size() <= 1)
		return pairs;
	pairList left, right;
	lPairsIterator it = pairs.begin();
	std::advance(it, pairs.size() / 2);
	left.splice(left.begin(), pairs, pairs.begin(), it);
	right.splice(right.begin(), pairs, pairs.begin(), pairs.end());
	left = _mergeSortPairs(left);
	right = _mergeSortPairs(right);
	return _mergePairs(left, right);
}

pairList	MutantList::_mergePairs(pairList& left, pairList& right) {
	pairList result;

	while (!left.empty() && !right.empty()) {
		if (left.front().second <= right.front().second) {
			result.push_back(left.front());
			left.pop_front();
		}
		else {
			result.push_back(right.front());
			right.pop_front();
		}
		_sortComparisons++;
	}
	result.splice(result.end(), left);
	result.splice(result.end(), right);

	return result;
}

void	MutantList::_splitPairs(const pairList& pairs) {
	VERBOSE_OUT("Split Pairs into upper (sorted) chain and lower chain...");
	for (lPairsConstIterator cit = pairs.begin(); cit != pairs.end(); cit++) {
		_sortedChain.push_back(cit->second);
		_lowerChain.push_back(cit->first);
	}
	if (_hasStrayElement) {
		VERBOSE_OUT("Adding stray element to end of lower chain...");
		_lowerChain.push_back(_lastElement);
	}
	VERBOSE_OUT_ARGS("Sorted chain: ", _printList(_sortedChain));
	VERBOSE_OUT_ARGS("Lower chain: ", _printList(_lowerChain));
}

intList::iterator	MutantList::_getRightBoundFromPairs(const pairList& pairs, intList::size_type index) {
	if (index >= pairs.size())
		return _sortedChain.end();
	lPairsConstIterator	pairIt = pairs.begin();
	std::advance(pairIt, index);
	intList::iterator	rightBound = std::find(_sortedChain.begin(), _sortedChain.end(), pairIt->second);
	return rightBound;
}

intList::iterator	MutantList::_getIteratorAt(intList& list, intList::size_type index) {
	intList::iterator	it = list.begin();
	std::advance(it, index);
	return (it);
}

void	MutantList::_insertLowerChain(const pairList& pairs) {
	intList::size_type	lowerIdx = 2;
	while (lowerIdx <= _lowerChain.size()) {
		std::pair<std::size_t, std::size_t>	jacobsthal = jacobsthal::getBounds(lowerIdx);
		VERBOSE_OUT("Jacobsthal bounds: (" << jacobsthal.first << "/" << jacobsthal.second << ")");
		lowerIdx = std::min(_lowerChain.size(), jacobsthal.second);
		while (lowerIdx > jacobsthal.first) {
			intList::iterator	left = _sortedChain.begin();
			intList::iterator	right = _getRightBoundFromPairs(pairs, lowerIdx - 1);
			int insertVal = *_getIteratorAt(_lowerChain, lowerIdx - 1);
			VERBOSE_OUT("Binary inserting " << insertVal << "...");
			_binaryInsert(_sortedChain, left, right, insertVal);
			VERBOSE_OUT_ARGS("Sorted list: ", _printList(_sortedChain));
			lowerIdx--;
		}
		lowerIdx = jacobsthal.second + 1;
	}
}

void	MutantList::_binaryInsert(intList& list, intList::iterator left, intList::iterator right, int val) {
	int insertComparisons = 0;
	while (left != right) {
		intList::iterator	center = left;
		std::advance(center, std::distance(left, right) / 2);
		if (*center < val) {
			left = center;
			left++;
		}
		else
			right = center;
		insertComparisons++;
		_sortComparisons++;
	}
	VERBOSE_OUT("Binary insert did " << insertComparisons << " comparisons...");
	list.insert(left, val);
}

// helpers (just for printing steps of sorting algorithm):
void	MutantList::_printList(const intList& list) const {
	const_iterator	secondToLast = --list.end();
	for (const_iterator cit = list.begin(); cit != list.end(); cit++)
		std::cout << *cit << ((cit != secondToLast) ? ", " : "") ;
}

void		MutantList::_printPairs(const pairList& pairs) {
	pairs.back();
	lPairsConstIterator	secondToLast = --pairs.end();
	for (lPairsConstIterator cit = pairs.begin(); cit != pairs.end(); cit++)
		std::cout << "(" << cit->first << ", " << cit->second << ")" << ((cit != secondToLast) ? ", " : "");
}
