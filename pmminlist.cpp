#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
  std::list<PuzzleMove*>::iterator it = slist_.begin();
  
  if(slist_.empty())
  {
  	slist_.insert(slist_.begin(), pm);
  }
  else
  {
  	if(*((*it)->b_)== *(pm->b_))
  	{
  		cout<<"CANNOT PUSH\n";
  	}
  	else
  	{
  	while(it!=slist_.end())
  	{
  		if(((*it)->g_ + (*it)->h_) > (pm->g_ + pm->h_))
  		{
  			slist_.insert(--it, pm);
  			break;
  		}
  		it++;
  	}
  	if(it == slist_.end())
  		slist_.insert(it, pm);
  	}
  }
}

void PMMinList::getMoves()
{
	bool flag=true;
	for(std::list<PuzzleMove*>::iterator it = slist_.begin(); it!=slist_.end(); it++)
	{
		flag=false;
		cout<<*(*it)->b_;
		cout<<"G:"<<(*it)->g_<<" H:"<<(*it)->h_<<endl<<endl<<endl;
	}
	if(flag)
		cout<<"EMPTY\n\n";
}
/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::pop()
{
	if(!slist_.empty())
  		slist_.pop_front();
  	else
  		cout<<"list is empty\n\n";
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
	//cout<<"Inside top: "<<slist_.front()->b_->getTiles()[<<endl;
  return slist_.front();
}

