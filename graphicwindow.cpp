#include "graphicwindow.h"

#include <cmath>
#include "guitile.h"
#include "mainwindow.h"
#include <QString>
#include <QTimer>

GraphicWindow::GraphicWindow()
{	
	int nextValue = 0;
	scene = new QGraphicsScene;		//added
	ROW_SIZE=3;
	tiles.clear();

	for(int i=0; i<ROW_SIZE; i++)
	{
		for(int j=0; j<ROW_SIZE; j++)
		{
			tiles.push_back(new GUITile(this, scene, i, j));
			nextValue++;			
		}
	}
	initializing=true;
	created=false;
	setScene(scene);
}

GraphicWindow::GraphicWindow(FormLayout* form, MainWindow* main)
{	
	int nextValue = 0;
	mw = main;
	ROW_SIZE = static_cast<int>(sqrt(form->sizeEdit->text().toInt()));
	
	scene = new QGraphicsScene;		//added
	tiles.clear();
	
	for(int i=0; i<ROW_SIZE; i++)
	{
		for(int j=0; j<ROW_SIZE; j++)
		{
			tiles.push_back(new GUITile(this, scene, i, j));
			nextValue++;			
		}
	}
	initializing=false;
	created=true;
	setScene(scene);
}

void GraphicWindow::moveTile(GUITile* selected)
{
	if(!initializing)
	{	
		if(b_->solved()||!b_->move(selected->tileNumber))
		{
			if(b_->solved())
			{
				mw->StatusBox->clear();
				mw->StatusBox->addItem("CONGRATULATIONS, YOU WIN!!");
			}
			else
			{
				mw->StatusBox->clear();
				mw->StatusBox->addItem("Tile could not be moved");
			}
		return;
		}
		
	}
	if(created)
	{
	//QTimer timer(this);
	
	double Xholder = selected->positionX;	
	double Yholder = selected->positionY;
	int location=0;
	for(unsigned int i=0; i<tiles.size(); i++)
	{
		if(selected->tileNumber==tiles[i]->tileNumber)
			location=i;
	}
	double XMover = tiles[0]->positionX - Xholder;
	double YMover = tiles[0]->positionY - Yholder;
	/*int i=XMover/XMover;
	int j=YMover/YMover;
	timer.start();
	while(timer.isActive())
	{
		i+=XMover/XMover;
		j+=YMover/YMover;
		if(i==XMover && j==YMover)
			timer.stop();
		tiles[location]->moveBy(XMover/XMover, YMover/YMover);
		tiles[0]->moveBy(-1*XMover/XMover, -1*YMover/YMover);
	}
	*/	
	tiles[location]->moveBy(XMover, YMover);  
	tiles[location]->positionX = tiles[0]->positionX;
	tiles[location]->positionY = tiles[0]->positionY;
	tiles[0]->moveBy(-1*XMover, -1*YMover);
	tiles[0]->positionX = Xholder;
	tiles[0]->positionY = Yholder;
	}
	if(!initializing)
	{
		if(b_->solved())
			{
				mw->StatusBox->clear();
				mw->StatusBox->addItem("CONGRATULATIONS, YOU WIN!!");
			}
	}	
}

/*GraphicWindow::GraphicWindow() {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    
    
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

}

void GraphicWindow::show() {

    view->show();
}

GraphicWindow::~GraphicWindow()
{
    //timer->stop();
    //delete timer;
    //delete item;
    //delete scene;
    //delete view;
}

*/


