#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H

#include<cmath>

using namespace std;

class PuzzleHeuristic
{
 public:
  virtual int compute(int *tiles, int size) = 0;
};

class ManhattanHeuristic : public PuzzleHeuristic
{
	public:
		int compute(int *tiles, int size)
		{	
			int score=0;
			int dim= static_cast<int>(sqrt(size));
	
			for(int i=0; i<size; i++)
			{
				if(tiles[i]!=0)
				
					score+=( abs( (tiles[i]/dim)-(i/dim) ) + abs( (tiles[i]%dim)-(i%dim) ) );		
			}
	
			return score;
		};
};

class OutOfPlaceHeuristic : public PuzzleHeuristic
{
	public:
		int compute(int *tiles, int size)
		{
			int score=0;
			for(int i=0; i<size; i++)
			{
				if(tiles[i]!=0)
				if(tiles[i]!=i)
					score++;
			}
			return score;
		};
};

#endif
