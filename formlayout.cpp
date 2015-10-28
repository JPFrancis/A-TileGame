#include "formlayout.h"

FormLayout::FormLayout()
{
	QFormLayout* layout = new QFormLayout; 
	setLayout( layout );
	
	Manhattan = new QRadioButton("Manhattan");
	Out = new QRadioButton("Out Of Place"); 
	
	sizeEdit = new QLineEdit();
	startMovesEdit = new QLineEdit();
	randomSeedEdit = new QLineEdit();
	
	layout->addRow(Manhattan);
	layout->addRow(Out);
	layout->addRow( "Board Size:" , sizeEdit );
	layout->addRow( "Starting Moves:", startMovesEdit ); 
	layout->addRow( "Random Seed Value:", randomSeedEdit );
}
