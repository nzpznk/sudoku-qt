
#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QPushButton>

//#define LOADER
//#define SUDOKUGRID
#define

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

#ifdef SUDOKUGRID
#include "UI/sudokugrid.h"
#include "UI/gridbtn.h"
void testSudokuGrid() {
	SudokuGrid* grid = new SudokuGrid;
	grid->show();
}
#endif // SUDOKUGRID

#ifdef SOLVER
#include "testsolver.h"
#endif // SOLVER

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
//	testFileLoader(); // test pass;
//	testSudokuGrid(); // test pass;
//	testSolver();
	return app.exec();
}
