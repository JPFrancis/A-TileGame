#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "mylist.h"
#include <sstream>

class PuzzleSolver
{
 public:
  
  typedef std::set<Board *, BoardLessThan> BoardSet;

  PuzzleSolver(const Board &b);		// Constructor (makes a copy of the Board and stores it in _b

  ~PuzzleSolver();
    
  int run(PuzzleHeuristic *ph, stringstream& ss); 

  std::list<int> getSolution();
 
  int getNumExpansions();	

 private:
  Board b_;
  int expansions_;
  std::list<int> solutionList_;			//**** Declare a List to store your solutions sequence of tiles to move
};

#endif
