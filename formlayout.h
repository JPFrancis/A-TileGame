#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H

#include <QFormLayout>
#include <QLineEdit>
#include <QRadioButton>

class FormLayout : public QWidget
{
	public:
		FormLayout();
		QLineEdit* sizeEdit; 
		QLineEdit* startMovesEdit; 
		QLineEdit* randomSeedEdit;
		QRadioButton* Manhattan;
		QRadioButton* Out; 
};

#endif
