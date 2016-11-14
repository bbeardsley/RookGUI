#ifndef CLICKABLECARD_H
#define CLICKABLECARD_H

#include <QLabel>
#include <QMouseEvent>

#include "Card.h"

class ClickableCard : public QLabel
{
	Q_OBJECT

private:

	Card *RookCard; // each "ClickableCard" is associated with a "Card"

public:

	ClickableCard(QString text, QWidget *parent = 0);
	
	~ClickableCard()
	{
	}

	void Initialize(Card *RookCardUse)
	{
		RookCard = RookCardUse;
	}

protected:

	void mousePressEvent(QMouseEvent *event);
};

#endif
