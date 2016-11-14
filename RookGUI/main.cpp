#include <QtWidgets/QApplication>

#include "GUI.h"
#include "GameController.h"

GUI *gui;
GameController *gc;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gui = new GUI;
	gc = new GameController;

	gc->StartGame();

	return a.exec();
}
