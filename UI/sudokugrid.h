#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <QWidget>
#include <QSignalMapper>
#include <QGridLayout>
#include <QVector>
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
	void btnChosen(int rank);

public slots:
	void showProblem(const QVector< QVector<int> >& mat);
	void setNum(int rank, int val, bool isAdd, bool editMode);
	void showWrongMsg(int rank);
	void highlightGrids(int rank, const QVector<int>& sameNums); // finish
	void clearGrid(int rank); // finish

private:
	QVector< QVector<GridBtn*> > m_btns;
	Ui::SudokuGrid *ui;
};

#endif // SUDOKUGRID_H
