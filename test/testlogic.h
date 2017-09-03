#ifndef TESTLOGIC_H
#define TESTLOGIC_H

#include "logic/logiccontroller.h"
#include "UI/gameboard.h"
#include <QObject>
#include <QWidget>
#include <QPushButton>

void testLogic() {
	LogicController* logic = new LogicController;
	GameBoard* gameboard = new GameBoard;
	QObject::connect(logic, SIGNAL(showProblem(QVector<QVector<int> >)), gameboard, SLOT(showProblem(QVector<QVector<int> >)));
	QObject::connect(gameboard, SIGNAL(setNumMsg(int,int,bool,bool)), logic, SLOT(setNum(int,int,bool,bool)));
	QObject::connect(gameboard, SIGNAL(check()), logic, SLOT(check()));
	QObject::connect(gameboard, SIGNAL(clearGridMsg(int)), logic, SLOT(clearGrid(int)));
	QObject::connect(gameboard, SIGNAL(requestHighlight(int)), logic, SLOT(calHighlights(int)));
	QObject::connect(gameboard, SIGNAL(getAnswer()), logic, SLOT(calAnswer()));

	QObject::connect(logic, SIGNAL(setNumMsg(int,int,bool,bool)), gameboard, SLOT(setNum(int,int,bool,bool)));
	QObject::connect(logic, SIGNAL(showWrong(QVector<int>)), gameboard, SLOT(showWrong(QVector<int>)));
	QObject::connect(logic, SIGNAL(clearGridMsg(int)), gameboard, SLOT(clearGrid(int)));
	QObject::connect(logic, SIGNAL(highlightGrids(int,QVector<int>)), gameboard, SLOT(highlightGrids(int,QVector<int>)));
	QObject::connect(logic, SIGNAL(showAnswer(QVector<QVector<int> >)), gameboard, SLOT(showAnswer(QVector<QVector<int> >)));
	gameboard->show();
}


#endif // TESTLOGIC_H
