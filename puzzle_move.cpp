#include "puzzle_move.h"

/*int tileMove_;  
Board *b_;      
int g_;        
int h_;         
PuzzleMove *prev_;
*/

PuzzleMove::PuzzleMove(Board &b)
{
	//b_ = new Board(*b_);
	b_=&b;
	g_ = 0;
	//h_= PuzzleHeuristic::compute(b_->getTiles(), b_->getSize());
	tileMove_ = 0;
	prev_= NULL;
}

  // Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent)
{
	g_=parent->g_+1;
	tileMove_ = tile;
	b_ = b;
	//h_= PuzzleHeuristic::compute(b_->getTiles(), b->getSize());
	prev_ = parent;
}

  // Destructor
PuzzleMove::~PuzzleMove()
{
	//delete b_;
	delete prev_;
}

  // Compare to PuzzleMoves based on f distance 

bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	if((g_+h_)==(p.g_+p.h_))
		return true;
	else 
		return false;
}

// Compare to PuzzleMoves based on f distance (needed for priority queue
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

