#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <QWidget>
#include <QSignalMapper>
#include <QGridLayout>
#include <qDebug>
#include "gridbtn.h"

namespace Ui {
class SudokuGrid;
}

class SudokuGrid : public QWidget
{
	Q_OBJECT

public:
	// init with a mat
	explicit SudokuGrid(QWidget *parent = 0, const QVector< QVector<int> >& mat);
	~SudokuGrid();

signals:
	void btnChosen(int rank);

public slots:
	setNum(int val, int rank);
	clearGrid(int rank);
	void log(int rank);

private:
	Ui::SudokuGrid *ui;
};

#endif // SUDOKUGRID_H
