#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <vector>

#include "formlayout.h"
#include "board.h"

using namespace std;

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class GUITile; 
class MainWindow;

class GraphicWindow : public QGraphicsView
{
  Q_OBJECT

	private:
					//Changed to pointer
		MainWindow* mw;

	public:
		vector<GUITile*> tiles;
		GraphicWindow(FormLayout*, MainWindow*);
		GraphicWindow();
		void swapTile (int, int); //just do even # of swaps not with blank
		int ROW_SIZE;
		//QGraphicsView* view;			  //just change x and y's with setPos
		//QGraphicsSimpleTextItem* poop;
		void moveTile(GUITile* selected);
		QGraphicsScene* scene;
		Board* b_;
		bool initializing;
		bool created;
};


/*

class GraphicWindow : public QGraphicsView {
    Q_OBJECT
  
    
public:
    explicit GraphicWindow();
    ~GraphicWindow();

    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    int counter;
    int rectangleCount;

public slots:

    //void handleTimer();
    //void changeTimer();
    //void randomColor(BouncingRectangle *item);
};
*/
#endif // GRAPHICWINDOW_H

