#pragma once
#include <vector>
#include <ostream>

typedef typename std::vector<int> intVector;
typedef typename std::pair<int, int> intPair;
typedef typename std::vector<intPair> pairVector;
typedef typename pairVector::iterator pairsIterator;
typedef typename pairVector::const_iterator pairsConstIterator;

class FjVector : public intVector {
  public:
	FjVector();
	FjVector(const FjVector& other);
	~FjVector();

	FjVector&	operator=(const FjVector& other);

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
	void		_mergeSortPairs(pairVector& target, pairsIterator left, pairsIterator right);
	void		_mergePairs(pairsIterator left, pairsIterator center, pairsIterator right);
	void		_splitPairs(const pairVector& pairs);
	void		_insertLowerChain(const pairVector& pairs);
	void		_binaryInsert(intVector& vec, intVector::iterator left, intVector::iterator right, int val);

	// helpers (to be removed):
	inline void	_printVec(const intVector& vec) const;
	void		_printPairs(const pairVector& pairs);
};

std::ostream& operator<<(std::ostream& lHs, const intPair& rHs);
