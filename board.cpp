#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
#include "graphicwindow.h"

using namespace std;

Board::Board(int size, int numInitMoves, int seed, GraphicWindow* gw )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
    	for(int i=0; i<size_; i++)
    	{
    		if(tiles_[randNeighbor]==gw->tiles[i]->tileNumber)
    		{
    			gw->moveTile(gw->tiles[i]);
    			break;
    		}
    	}
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;				
    }
  }
}

 Board::Board(const Board &b)
 {
   size_=b.size_;
   tiles_=new int[size_];
   for(int i=0; i<size_; i++)
   {
   	tiles_[i]=b.tiles_[i];
   }
 }

  /** Another kind of "copy" constructor */
Board::Board(int *tiles, int size)
{   
   size_=size;
   tiles_=new int[size_];
   for(int i=0; i<size_; i++)
   {
   	tiles_[i]=tiles[i];
   }
 }

  /** Swaps the blank with the specified tile */
bool Board::move(int tile)
{
  int location=0;
  int dim= static_cast<int>(sqrt(size_));
  
  if(tile<0 || tile>size_)
  	cout<<"Invalid tile.\n\n";
  else
  {
  	for(int i=0; i<size_; i++)
  	{
  		if(tiles_[i]==tile)
  			location=i;
  	}
  	if((location-1)>=0 && tiles_[location-1]==0 && (location%dim!=0))
  	{
  		tiles_[location-1]=tile;
  		tiles_[location]=0;
  	}	
  	else if((location+1)<size_ && tiles_[location+1]==0 && (location%dim)!=(dim-1))      //maintain graphic relationship
  	{
  		tiles_[location+1]=tile;
 	 	tiles_[location]=0;
  	}
  	else if((location-dim)>=0 && tiles_[location-dim]==0)
  	{
  		tiles_[location-dim]=tile;
 	 	tiles_[location]=0;
  	}
  	else if((location+dim)<size_ && tiles_[location+dim]==0)
  	{
  		tiles_[location+dim]=tile;
  		tiles_[location]=0;
  	}
 	else
  	{
  		return false;
  		cout<<"Tile could not be moved.\n\n";
  	}
  }
  return true;
}

  /** Generate potential moves and returns new boards
   * Key=tile, Value=Ptr to corresponding Board */
 
 std::map<int, Board*> Board::potentialMoves()
 {
 	map<int, Board*> potential;
 	int blankLoc;
 	int dim= static_cast<int>(sqrt(size_));
 	
 	for(int i=0; i<size_; i++)
 	{
 		if(tiles_[i]==0)
 			blankLoc=i;
 	}
 	
 	if(blankLoc-1>=0 && blankLoc%dim!=0)
 	{
 		
 		Board* P1= new Board(*this);		//COPYING PARENT BOARD
 			
 		P1->tiles_[blankLoc]=P1->tiles_[blankLoc-1];	//SWITCHAROO

 		P1->tiles_[blankLoc-1]=0;
 		
 		int tile= P1->tiles_[blankLoc];
 		
 		//cout<<*P1;
 		
 		potential[tile]= P1;
 	}
 	if(blankLoc+1<size_ && (blankLoc+1)%dim!=0)
 	{
 		Board* P2= new Board(*this);		//COPYING PARENT BOARD
 		
 		P2->tiles_[blankLoc]=P2->tiles_[blankLoc+1];	//SWITCHAROO
 		P2->tiles_[blankLoc+1]=0;
 		
 		int tile= P2->tiles_[blankLoc];
 		
 		//cout<<*P2;
 		
 		potential[tile] = P2;
 	}
 	if(blankLoc-dim > 0)
 	{
 		Board* P3= new Board(*this);		//COPYING PARENT BOARD
 		
 		P3->tiles_[blankLoc]=P3->tiles_[blankLoc-dim];	//SWITCHAROO
 		P3->tiles_[blankLoc-dim]=0;
 		
 		int tile= P3->tiles_[blankLoc];
 		
 		//cout<<*P3;
 		
 		potential[tile] = P3;
 	}
 	if(blankLoc+dim < size_)
 	{
 		Board *P4=new Board(*this);		//COPYING PARENT BOARD
 		
 		P4->tiles_[blankLoc]=P4->tiles_[blankLoc+dim];	//SWITCHAROO
 		P4->tiles_[blankLoc+dim]=0;
 		
 		int tile= P4->tiles_[blankLoc];
 		
 		//cout<<*P4;
 		
 		potential[tile] = P4;
 	}
 	
 	return potential;
 }

  /** Returns true if the board is solved, false otherwise */
 bool Board::solved()
 {
 	bool flag=true;
 	//cout<<size_<<endl;
 	for(int i=0; i<size_; i++)
 	{
 		if(tiles_[i]!=i)
 			flag=false;
 	}
 	return flag;
 }

  // Operators
 std::ostream& operator<<(std::ostream &os, const Board &b)
 {
 	for(int i=0; i<b.size_; i++)
 	{
 		if(i!=0 && i%static_cast<int>(sqrt(b.size_))==0)
 		{
 			os<<endl;
 		}
 		if(b.tiles_[i]==0)
 		{
 			os<<"  ";
 			if(b.size_>10)
 				os<<" ";
 		}
 			
 		else
 		{
 			if(b.size_>10)
 				os<<left<<setw(3)<<b.tiles_[i];
 			else
 				os<<left<<setw(2)<<b.tiles_[i];
 		}
 	}
 	os<<endl<<endl;
 	return os;
 }
 bool Board::operator==(const Board& rhs) const
 {
   if(size_!=rhs.size_)
   	return false;
   else
   {
   	for(int i=0; i<size_; i++)
   	{
   		if(tiles_[i]!=rhs.tiles_[i])
   			return false;
   	}
   }
   
   return true;
 }
 bool Board::operator!=(const Board& rhs) const
 {
   if(size_!=rhs.size_)
   	return true;
   else
   {
   	for(int i=0; i<size_; i++)
   	{
   		if(tiles_[i]!=rhs.tiles_[i])
   			return true;
   	}
   }
   return false;
 }
 
/** Default constructor. provide documentation here */
Board::Board()
{
  size_=0;
  tiles_=NULL;
}

/** Default destructor. provide documentation here */
Board::~Board()
{
  size_=0; 
  delete tiles_;
}

 void Board::operator=(const Board& rhs)
 {
 	size_=rhs.size_;
   	tiles_=new int[size_];
   	for(int i=0; i<size_; i++)
   	{
   	tiles_[i]=rhs.tiles_[i];
   	}
 }	
bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}


