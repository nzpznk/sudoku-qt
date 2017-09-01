
#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QPushButton>

#include "loader/fileloader.h"
#include "logger.h"

#include "UI/sudokugrid.h"
#include "UI/gridbtn.h"

void testFileLoader() {
	FileLoader* fl = new FileLoader("./mat1.txt");
	Logger* logger = new Logger;
	QPushButton* btn = new QPushButton;
	btn->setGeometry(500, 500, 50, 30);
	QObject::connect(btn, SIGNAL(clicked(bool)), fl, SLOT(load()));
	QObject::connect(fl, SIGNAL(loadResult(QVector<QVector<int>*>*)), logger, SLOT(logmat(QVector<QVector<int>*>*)));
	btn->show();
	delete logger;
}

void testSudokuGrid() {
	SudokuGrid* grid = new SudokuGrid;
	grid->show();
}


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
//	testSudokuGrid(); test pass;
	return app.exec();
}
