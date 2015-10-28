#include "mainwindow.h"

MainWindow::MainWindow ()
{
	uiWindow = new FormLayout();
	
	setDockNestingEnabled(false);
	
	gw = new GraphicWindow();
	gw->created = false;
		
		QMenuBar *mb = menuBar();
		QMenu* file = new QMenu("File", this);
		QAction *quit = new QAction("Quit", this);
		QAction *startGame = new QAction("Start Game", this);
		file->addAction(startGame);
		file->addAction(quit);
		
		connect(quit, SIGNAL(triggered()), this, SLOT(close()) );
		connect(startGame, SIGNAL(triggered()), SLOT(start()));
	
		mb->addMenu(file);	
		mb->addSeparator();
		
	
	ToolBar *tools = new ToolBar(this);
	
	QDockWidget *qdw = new QDockWidget();
	qdw->setWidget( uiWindow );
	
	qdw->setFixedSize(300, 300);
	
	QDockWidget *qdw2 = new QDockWidget();
	StatusBox = new QListWidget(qdw2);
	StatusBox->addItem("Fill in the values and click 'Start Game' to begin");
	StatusBox->setFixedSize(500, 100);
	qdw2->setWidget(StatusBox);
	
	
	
	addToolBar(tools);
	setMenuBar(mb);

	//gw->view->show();
	
	//setCentralWidget(gw);
	
	//centralWidget()->setFixedSize(sizeHint());
	
	this->setFixedSize(600, 500);
	addDockWidget(Qt::LeftDockWidgetArea, qdw );
	addDockWidget(Qt::BottomDockWidgetArea, qdw2);
	
	qdw->setFeatures(QDockWidget::NoDockWidgetFeatures);
	qdw2->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setWindowTitle( "Graphical 8-Tile Puzzle");
}

void MainWindow::start()
{
	if(!uiWindow->sizeEdit->isModified() || !uiWindow->randomSeedEdit->isModified())
	{
		StatusBox->clear();
		StatusBox->addItem("Incomplete entry. You must fill in the boxes with valid integers");
	}
	else
	{
	QIntValidator Int(1, 500, this);
	int i=0;
	QString size = uiWindow->sizeEdit->text();
	QString moves = uiWindow->startMovesEdit->text();
	QString seed = uiWindow->randomSeedEdit->text();
	
	if(Int.validate(size, i)==0 || Int.validate(moves, i)==0 || Int.validate(seed, i)==0)
	{
		StatusBox->clear();
		StatusBox->addItem("Invalid entries. All values must be integers.");
	}
	else
	{
	double d_sqrt = sqrt(uiWindow->sizeEdit->text().toInt());
	int i_sqrt = d_sqrt;
	if ( d_sqrt != i_sqrt )
	{
		StatusBox->clear();
		StatusBox->addItem("Invalid entry. Size must be a perfect square.");
	}	
	else
	{
	StatusBox->clear();	
	gw = new GraphicWindow(uiWindow, this);
	gw->initializing=true;
	setCentralWidget(gw);
	b = new Board(uiWindow->sizeEdit->text().toInt(), uiWindow->startMovesEdit->text().toInt(), uiWindow->randomSeedEdit->text().toInt(), gw);
	gw->initializing=false;
	gw->created=true;
	gw->b_ = b;
	
	StatusBox->addItem("Click on a tile to move it");
	}
	}
	}
}

void MainWindow::runASTAR()
{
	if(!gw->created)
	{
		StatusBox->clear();
		StatusBox->addItem("You must create a board in order to Run A*");
	}
	else
	{
	Board board(*b);
	PuzzleSolver SolveIt(board);//= new PuzzleSolver(b);
	if(uiWindow->Manhattan->isChecked())
	{
  		OutOfPlaceHeuristic* heur= new OutOfPlaceHeuristic;
  		stringstream stream;
  		SolveIt.run(heur, stream);
  		StatusBox->clear();
  		string str = stream.str();
  		StatusBox->addItem(QString::fromStdString(str));
  	}
  	else if(uiWindow->Out->isChecked())
  	{
  		ManhattanHeuristic* heur = new ManhattanHeuristic;
  		stringstream stream;
  		SolveIt.run(heur, stream);
  		StatusBox->clear();
  		string str = stream.str();
  		StatusBox->addItem(QString::fromStdString(str));
  	}	
  	else
  	{
  		StatusBox->clear();
  		StatusBox->addItem("You must select either the 'Manhattan' or 'Out Of Place' option for your cheat");
  	}
  	}
}

	
