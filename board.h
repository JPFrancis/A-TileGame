#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <map>
#include <functional>

class GraphicWindow;

class Board
{
 public:
  Board(); 
  Board(int size, int numInitMoves, int seed, GraphicWindow*);
  Board(const Board &b);
  Board(int *tiles, int size); 
  ~Board();

  bool move(int tile);
  std::map<int, Board*> potentialMoves(); 
  bool solved();

  friend std::ostream& operator<<(std::ostream &os, const Board &b);
  void operator=(const Board& rhs);
  bool operator==(const Board& rhs) const;
  bool operator<(const Board& rhs) const;
  bool operator!=(const Board& rhs) const;
  
  int* getTiles(){return tiles_;};
  int getSize(){return size_;};
  // Add any accessors


 private:
  int *tiles_;
  int size_;
  // Add Data members

};

// Leave this alone and don't touch it!
struct BoardLessThan : 
  public std::binary_function<const Board*, const Board*,bool>
{
  bool operator()(const Board *b1, const Board *b2) const
  {
    return *b1 < *b2;
  }
};



#endif
