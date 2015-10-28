#ifndef GUITILE_H
#define GUITILE_H

#include "graphicwindow.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class GUITile : public QGraphicsRectItem
{
private:

	GraphicWindow* gw_;

public slots:

	
public:

	GUITile (GraphicWindow* g);
	GUITile (GraphicWindow* const, QGraphicsScene* scene, int&, int&);
	double positionX;
	double positionY;
	int tileNumber;
	void mousePressEvent(QGraphicsSceneMouseEvent* e);

};

#endif


