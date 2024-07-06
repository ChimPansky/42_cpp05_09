#pragma once
#include <list>

typedef std::list<int> intList;
typedef std::pair<int, int> lIntPair;
typedef std::list<lIntPair> pairList;
typedef pairList::iterator lPairsIterator;
typedef pairList::const_iterator lPairsConstIterator;
class MutantList : public intList {
  public:
	MutantList();
	MutantList(const MutantList& other);
	~MutantList();

	MutantList&	operator=(const MutantList& other);

	void		sort();
	void		print() const;


  private:
	intList	_sortedChain;
	intList	_lowerChain;
	bool	_hasStrayElement;
	int		_lastElement;
	int		_sortComparisons;

  private:
	void		_mergeInsert(intList& list);
	pairList	_makePairs(const intList& list);
	void		_orderPairs(pairList& pairs);
	pairList	_mergeSortPairs(pairList& pairs);
	pairList	_mergePairs(pairList& left, pairList& right);
	void		_splitPairs(const pairList& pairs);
	void		_insertLowerChain(const pairList& pairs);
	void		_binaryInsert(intList& list, iterator left, intList::iterator right, int val);
	intList::iterator	_getRightBoundFromPairs(const pairList& pairs, intList::size_type index);
	intList::iterator	_getIteratorAt(intList& list, intList::size_type index);

	// helpers
	void		_printList(const intList& list) const;
	void		_printPairs(const pairList& pairs);

};
