#ifndef TESTGAMEBOARD_H
#define TESTGAMEBOARD_H

#include "UI/gameboard.h"
#include "loader/fileloader.h"
#include <QVector>

void testGameBoard() {
	FileLoader fl("./mat10.txt");
	QVector< QVector<int> > mat = fl.load();
	GameBoard* gameboard = new GameBoard(mat);
	gameboard->show();
}

#endif // TESTGAMEBOARD_H
