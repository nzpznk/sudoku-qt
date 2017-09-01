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
	explicit SudokuGrid(QWidget *parent = 0);
	~SudokuGrid();

signals:


public slots:
	void log(int rank);

private:
	Ui::SudokuGrid *ui;
};

#endif // SUDOKUGRID_H
