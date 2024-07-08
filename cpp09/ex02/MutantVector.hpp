#pragma once
#include <vector>

typedef std::vector<int> intVector;
typedef std::pair<int, int> intPair;
typedef std::vector<intPair> pairVector;
typedef pairVector::iterator vPairsIterator;
typedef pairVector::const_iterator vPairsConstIterator;

class MutantVector : public intVector {
  public:
	MutantVector();
	MutantVector(const MutantVector& other);
	~MutantVector();

	MutantVector&	operator=(const MutantVector& other);

	void		sort();
	void		print() const;


  private:
	intVector	_sortedChain;
	intVector	_lowerChain;
	bool		_hasStrayElement;
	int			_lastElement;
	int			_sortComparisons;

  private:
	void		_mergeInsert(intVector& vec);
	pairVector	_makePairs(const intVector& vec);
	void		_orderPairs(pairVector& pairs);
	void		_mergeSortPairs(pairVector& target, vPairsIterator left, vPairsIterator right);
	void		_mergePairs(vPairsIterator left, vPairsIterator center, vPairsIterator right);
	void		_splitPairs(const pairVector& pairs);
	void		_insertLowerChain(const pairVector& pairs);
	void		_binaryInsert(intVector& vec, iterator left, iterator right, int val);

	// helpers
	void	_printVec(const intVector& vec) const;
	void	_printPairs(const pairVector& pairs);
};
