#include "toolbar.h"
#include "mainwindow.h"

ToolBar::ToolBar(MainWindow* mw)
{
	QAction *startGameAction = new QAction( "Start Game", this );
	addAction( startGameAction );
	connect( startGameAction, SIGNAL(triggered()), mw, SLOT( start() ));
	
	QAction *quitGameAction = new QAction( "Quit", this );
	addAction( quitGameAction );
	connect( quitGameAction, SIGNAL(triggered()), mw, SLOT( close() ));
	
	QAction *runAstarGameAction = new QAction( "Run A*", this );
	addAction( runAstarGameAction );
	connect( runAstarGameAction, SIGNAL( triggered() ), mw, SLOT( runASTAR() ));	
}
