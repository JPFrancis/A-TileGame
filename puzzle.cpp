#include <QtGui/QApplication>
#include "mainwindow.h"
#include "board.cpp"
#include "puzzle_heur.cpp"
#include "puzzle_solver.cpp"


using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	

	MainWindow main;
	
	main.show();
	
	return a.exec();
}


/*
int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }

  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);

  int choice=0;
  bool flag=false;
  
  while(!b.solved())
  {
  	choice=0;
  	cout<<b;
  	cout<<"Enter tile number to move or -1 for a cheat: ";
  	
  	if(flag)
  		cin.ignore(100, '\n');
  	
  	cin>>choice;
  	if(cin.fail())
  	{
  		cout<<"Invalid Tile\n\n";
  		cin.ignore(100, '\n');
  		cin.clear();
  		flag=true;
  		continue;
  	}
  	cout<<endl;
  	if(choice==-1)
  	{
  		//Board B(b);
  		PuzzleSolver SolveIt(b);//= new PuzzleSolver(b);
  		OutOfPlaceHeuristic* heur= new OutOfPlaceHeuristic;
  		//ManhattanHeuristic* heur = new ManhattanHeuristic;
  		SolveIt.run(heur);
  		cout<<endl;
  	}
  	else
  	{
  		b.move(choice); 
  	}
  }
  cout<<b;
  cout<<"CONGRATULATIONS! YOU WIN!\n\n";

  return 0;
}
*/
