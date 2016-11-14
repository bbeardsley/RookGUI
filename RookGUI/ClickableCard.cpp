#include "ClickableCard.h"
#include "Gui.h"
#include "GameController.h"

extern GUI *gui;
extern GameController *gc;

ClickableCard::ClickableCard(QString text, QWidget *parent) : QLabel(text, parent)
{
	RookCard = nullptr;
}

void ClickableCard::mousePressEvent(QMouseEvent *event)
{
	bool LeftClick = (event->buttons() == Qt::LeftButton);

	if (LeftClick)
	{
		bool IsCardPlayed = gc->PlayHumanCard(RookCard);
		
		if (IsCardPlayed) // is card was played, we need to re draw the hand
		{
			gc->PrintHand();
		}
	}
}