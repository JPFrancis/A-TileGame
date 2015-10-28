#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>

class MainWindow;

class ToolBar : public QToolBar
{
	Q_OBJECT
	public:
		ToolBar(MainWindow*);
	
};

#endif
