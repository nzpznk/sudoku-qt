﻿
#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QPushButton>

//#define LOADER
//#define SUDOKUGRID
//#define SOLVER
//#define INPUTBOARD
//#define GRIDBTN

#ifdef LOADER
#include "loader/fileloader.h"
#include "logger.h"
void testFileLoader() {
	FileLoader* fl = new FileLoader("./mat1.txt");
	Logger* logger = new Logger;
	QPushButton* btn = new QPushButton;
//	btn->setGeometry(500, 500, 50, 30);
	QObject::connect(btn, SIGNAL(clicked(bool)), fl, SLOT(load()));
	QObject::connect(fl, SIGNAL(loadResult(const QVector< QVector<int> >&)), logger, SLOT(logmat(const QVector< QVector<int> >&)));
	btn->show();
}
#endif // LOADER

#ifdef SOLVER
#include "testsolver.h"
#endif // SOLVER

#ifdef GRIDBTN
#include "testgridbtn.h"
void testGridBtn() {
	TestGridBtn* widg = new TestGridBtn;
	widg->show();
}
#endif GIRDBTN


#ifdef SUDOKUGRID
#include "testsukodugrid.h"

void testSukoduGrid() {
	TestSukoduGrid* obj = new TestSukoduGrid;
	SudokuGrid* grid = new SudokuGrid;
	QObject::connect(obj, SIGNAL(setProblem(QVector<QVector<int> >)), grid, SLOT(showProblem(QVector<QVector<int> >)));
	QObject::connect(grid, SIGNAL(btnChosen(int)), obj, SLOT(setActivated(int)));
	obj->show();
}

#endif

#ifdef INPUTBOARD
#include "testinput.h"
void testInputBoard() {
	TestInput* obj = new TestInput;
	obj->show();
}

#endif

#ifdef GAMEBOARD
#include "test/testgameboard.h"
#endif

#ifdef LOGIC
#include "test/testlogic.h"
#endif

//int main(int argc, char** argv)
//{
//	QApplication app(argc, argv);
////	testFileLoader(); // test pass;
////	testSudokuGrid(); // test pass;
////	testSolver();
////	testSukoduGrid();
//	testGridBtn();
////	testInputBoard();
////	testGameBoard();
////	testLogic();
//	return app.exec();
//}
