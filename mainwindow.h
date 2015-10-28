#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "graphicwindow.cpp"

#include <iostream>
#include <QMainWindow>
#include <QMenuBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QFormLayout>
#include <QMenuBar>
#include <vector>
#include <QDockWidget>
#include <QWidget>
#include <QObject>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIntValidator>
#include <QRadioButton>
#include <cmath>
#include <sstream>

#include "board.h"
#include "puzzle_solver.h"
#include "graphicwindow.h"
#include "toolbar.h"
#include "formlayout.h"
#include "guitile.h"



class MainWindow : public QMainWindow
{
	Q_OBJECT
		
	public:
		MainWindow();
		Board *b;
		QListWidget* StatusBox;
	private:
		FormLayout* uiWindow;
		GraphicWindow* gw;
	
	public slots:
		
		void start();
		void runASTAR();
};

#endif
