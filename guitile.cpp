#include "guitile.h"

GUITile :: GUITile (GraphicWindow* gw, QGraphicsScene* scene, int& x, int& y)
{	
	setRect(x*WINDOW_MAX_X/gw->ROW_SIZE, y*WINDOW_MAX_Y/gw->ROW_SIZE, WINDOW_MAX_X/gw->ROW_SIZE, WINDOW_MAX_Y/gw->ROW_SIZE);
	tileNumber = x + gw->ROW_SIZE*y;	
	QString str = QString::number(tileNumber);
	QGraphicsSimpleTextItem* simpleText = new QGraphicsSimpleTextItem(str, this);
	simpleText->setFont(QFont("Times", 40, QFont::Bold));
	
	if(tileNumber==0)
		simpleText->setBrush(QBrush(Qt::white));
	else
		simpleText->setBrush(QBrush(Qt::black));	
	
	positionX = double(x*WINDOW_MAX_X/gw->ROW_SIZE);
	positionY = double(y*WINDOW_MAX_Y/gw->ROW_SIZE);
	simpleText->setPos(x*WINDOW_MAX_X/gw->ROW_SIZE, y*WINDOW_MAX_Y/gw->ROW_SIZE);
	
	gw_ = gw;
	scene->addItem(this);
}

void GUITile::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
	gw_->moveTile(this);
}

