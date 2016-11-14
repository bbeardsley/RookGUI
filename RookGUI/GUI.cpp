#include "GUI.h"

#include "GameVariables.h"

GUI::GUI() :
	CardIcons(MAXPLAYERCARDS)
{
	cardTable = new QListView();

	QPixmap QPx;

	for (int i = 0; i < MAXPLAYERCARDS; i++) // Setup pixmap of cards
	{
		CardIcons[i] = new ClickableCard("", cardTable);

		QPx = QPixmap(":/RookGUI/images/rook.gif");
		CardIcons[i]->setPixmap(QPx.scaled(CARDWIDTH, CARDHEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		CardIcons[i]->setAttribute(Qt::WA_TranslucentBackground);
	}

	VerticalLayout = new QVBoxLayout();
	VerticalLayout->addWidget(cardTable);

	MainLayout = new QGridLayout();
	MainLayout->addLayout(VerticalLayout, 0, 0, 1, 1);

	MainWidget = new QWidget();

	MainWidget->setStyleSheet("background-image: url(:/RookGUI/images/background.PNG); border:0px");

	MainWidget->setLayout(MainLayout);

	MainWidget->setMinimumSize(GAMEWIDTH, GAMEHEIGHT);
	MainWidget->setMaximumSize(GAMEWIDTH, GAMEHEIGHT);

	MainWidget->show();

	ClearCardIcons();
}

GUI::~GUI()
{
	// Only need to delete widget here

	if (MainWidget)
	{
		delete MainWidget;
	}
}

void GUI::ClearCardIcons()
{
	for (int i = 0; i < CardIcons.size(); i++)
	{
		CardIcons[i]->clear();
	}
}

void GUI::PrintHand(vector<Card *> PlayerCards) // the hand gets ReDrawn every time the cards are modified
{
	ClearCardIcons(); // Clear cards currently showing

	QPixmap QPx;

	int NumberPlayerCards = PlayerCards.size();

	for (int i = 0; i < NumberPlayerCards; i++) // Show all the players cards
	{
		QString ImageFile = ":/RookGUI/images/" 
						  + NUMBERS[PlayerCards[i]->Number] 
						  + SUITS[PlayerCards[i]->Color] 
						  + ".gif";

		QPx = QPixmap(ImageFile);

		CardIcons[i]->setPixmap(QPx.scaled(CARDWIDTH, CARDHEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		CardIcons[i]->move((MAXPLAYERCARDS - NumberPlayerCards)*(CARDWIDTH/10) + i * 45*CARDWIDTH/200, 
						   GAMEHEIGHT - CARDHEIGHT - 25*CARDWIDTH/200);
		CardIcons[i]->raise();

		// Associate cards (which user can click) with Card class

		CardIcons[i]->Initialize(PlayerCards[i]);
	}

	MainWidget->setStyleSheet("background-image: url(:/RookGUI/images/background.PNG); border:0px");
	MainWidget->repaint();
}