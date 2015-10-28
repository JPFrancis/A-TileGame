#ifndef PMMINLIST_H
#define PMMINLIST_H
#include <list>

/**
 * PMMinList implements a sorted list of PuzzleMoves
 * based on their f-score (from smallest to largest)
 */
class PMMinList 
{
 public:
  
  PMMinList();
  ~PMMinList();
  int size() const { return slist_.size(); }  		/** Returns the size of items in the list */
  bool empty() const { return slist_.empty(); }		/** Returns true if the list is empty */
  void push(PuzzleMove* pm);		/** Adds a puzzle move to the sorted list */
  void pop();		/** Removes the minimum scored (front) puzzle move */
  PuzzleMove* top();	/** Returns the PuzzleMove with the lowest score */
  void getMoves();
  
 private:
  /** the sorted list */
  std::list<PuzzleMove*> slist_;
};

#endif
