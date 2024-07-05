#include "FjVector.hpp"
#include "Verbose.hpp"

#include <iostream>
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
	_hasStrayElement = size() % 2 == 1;
	VERBOSE_OUT("has stray element: " << _hasStrayElement);
	_pairs.clear();
	_sorted.clear();
	_lower.clear();
	_mergeInsert(*this);

}

void	FjVector::_mergeInsert(const intVector& vec) {
	VERBOSE_OUT_ARGS("_mergeInsert", _printVec(vec));
	pairVector	pairs = _makePairs(vec);
	_sortPairsInternally(pairs);
	if (pairs.size() <= 1)
		return ;
	intVector	upperElements;
	for (pairVector::iterator it = pairs.begin(); it != pairs.end(); it++)
		upperElements.push_back(it->second);
	_mergeInsert(upperElements);
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

void	FjVector::_sortPairsInternally(pairVector& pairs) {
	VERBOSE_OUT_ARGS("_sortPairsInternally", _printPairs(pairs));
	for (pairVector::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	#if VERBOSE
		_printPairs(pairs);
		std::cout << std::endl;
	#endif
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
