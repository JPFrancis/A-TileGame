#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;
 
/*
  Board b_;
  int expansions_;
  std::list<int> solutionList_;	
*/
PuzzleSolver::PuzzleSolver(const Board &b)
{
	b_=b;
	//cout<<"HERE\n";
	//Board b_(b);
	expansions_=0;
	solutionList_.clear();
}

PuzzleSolver::~PuzzleSolver(){}
    
int PuzzleSolver::run(PuzzleHeuristic *ph, stringstream& ss)  // Run the A* search returning -1 if no solution exists or the number of moves in the solution
{
   //cout<<"Run function called\n\n";
   BoardSet closedList;
   PMMinList open_list;
   vector<Board*> garbage;
   int numberOfMoves=-1;
   bool solutionFound = false;
   PuzzleMove* pmoveIt = new PuzzleMove(b_);
   //cout<<*(pmoveIt->b_);
   open_list.push(pmoveIt);					//Add the start state (start move) to the open_list
   closedList.insert(pmoveIt->b_);
   garbage.push_back(pmoveIt->b_); 								//Add the starting board to the closed_list
   
while(open_list.top()!=NULL && !solutionFound)				//while(open_list is not empty and no solution has been found)
{				
    //ADD STATEMENT TO SEE OLD BOARD AND CHOICE
    //cout<<"Old board:\n\n"<<*(pmoveIt->b_);
    //cout<<"Old list:\n\n";
    //open_list.getMoves();
    pmoveIt = open_list.top();					//move = remove min. f-value state from open_list
    //cout<<"Choice:\n";
    //cout<<*(pmoveIt->b_);
    garbage.push_back(pmoveIt->b_);				//Add move's board to the garbage list
    open_list.pop(); 
    //cout<<"Current open list:\n";
    //open_list.getMoves(); 
    			
    if(pmoveIt->b_->solved())						//if move is goal node then trace path backwards & break
    {
    	//cout<<"Inside solved\n\n";
    	numberOfMoves++;
    	solutionFound=true;
    	vector<int> solutions; 	
    	for(std::list<int>::iterator it = solutionList_.begin(); pmoveIt->prev_ != NULL; it++)
    	{
    		solutions.push_back(pmoveIt->tileMove_);
    		solutionList_.insert(it, pmoveIt->tileMove_);
    		pmoveIt = pmoveIt->prev_;
    		numberOfMoves++;
    	}
    	ss<<"Try this sequence: ";
 
    	for(int i=solutions.size()-1; i>=0; i--)
    	{
    		ss<<solutions[i]<<" ";
    	}
    	//cout<<endl<<"(Expansions = "<<expansions_<<")";	
    	break;
    }

    map<int, Board*> pMoves;
    pMoves.clear();
    pMoves = pmoveIt->b_->potentialMoves();	//Generate next potential moves (i.e. expansions)
    for(map<int,Board*>::iterator it = pMoves.begin(); it != pMoves.end(); it++) //For each potential move (successor), s
    {
    	bool flag=false;
    	/*for(BoardSet::iterator itClosed = closedList.begin(); itClosed != closedList.end(); itClosed++)
    	{
    		if( *(*itClosed) == *(it->second))
    		{
    			flag=true;
    			cout<<"FLAG WAS THROWN\n\n";
    		}
    	}
    	//cout<<"Garbage check:\n";*/
    	for(unsigned int i=0; i<garbage.size(); i++)
    	{
    		if(*(it->second) == *(garbage[i]))
    		{
    			flag=true;
    			//cout<<"Flag thrown\n\n";
    			break;
    		}
    	}
      if(!flag)			//if the board of s is not in the closed set
      {
      	PuzzleMove* PuzMove= new PuzzleMove(it->first, it->second, pmoveIt);   	 
        PuzMove->h_ = ph->compute(it->second->getTiles() , it->second->getSize());//Compute f values for each potential move
        closedList.insert(it->second);//Add the board of s to the closed set
        open_list.push(PuzMove);//Add s to the open_list
        garbage.push_back(PuzMove->b_);
        //Increment number of expansions
      }
     }
     expansions_++; 
 }

 cout<<endl;
 garbage.clear();
 closedList.clear();
 while(!open_list.empty())
 {
 	open_list.pop();
 }
 return numberOfMoves;  
}

std::list<int> PuzzleSolver::getSolution()
{
  return solutionList_;
}
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
