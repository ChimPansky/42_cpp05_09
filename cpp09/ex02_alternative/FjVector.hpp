#pragma once
#include <vector>
#include <ostream>

typedef typename std::vector<int> intVector;
typedef typename std::pair<int, int> intPair;
typedef typename std::vector<intPair> pairVector;

class FjVector : public intVector {
  public:
	FjVector();
	FjVector(const FjVector& other);
	~FjVector();

	FjVector&	operator=(const FjVector& other);

	void		sort();
	void		print() const;

  private:
	pairVector	_pairs;
	intVector	_sorted;
	intVector	_lower;
	bool		_hasStrayElement;

  private:
	void		_mergeInsert(const intVector& vec);
	pairVector	_makePairs(const intVector& vec);
	void		_sortPairsInternally(pairVector& pairs);

	// helpers (to be removed):
	inline void	_printVec(const intVector& vec) const;
	void		_printPairs(const pairVector& pairs);
};

std::ostream& operator<<(std::ostream& lHs, const intPair& rHs);
