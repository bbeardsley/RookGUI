#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QListView>
#include <QtWidgets/QLabel>
#include <QtGui>
#include <QtWidgets/QVBoxLayout>
#include <QtCore>
#include "ClickableCard.h"

#include "Card.h"

#include <vector>
using std::vector;

class GUI
{
private:

	QListView *cardTable;
	vector<ClickableCard *> CardIcons;	// for drawing human player cards

	QVBoxLayout *VerticalLayout;
	QGridLayout *MainLayout;

	QWidget *MainWidget;

public:

	GUI();

	void ClearCardIcons();

	void PrintHand(vector<Card *> PlayerCards);
	//void DrawHand();

	~GUI();
};

#endif