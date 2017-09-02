#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QLinkedList>

#include "sudokugrid.h"
#include "inputboard.h"

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
	Q_OBJECT

public:
	explicit GameBoard(QWidget *parent = 0, const QVector< QVector<int> >& mat);
	~GameBoard();

signals:
	void setNum(int rank, int val);
	void clearGrid(int rank);
	void check();

public slots: // connect with logic
	void setBtnChosen(int rank); // show the btn chosen, highlight the row and column
	void setOperation(InputBoard::OPERATION op, int num = 0);
	void showWrong(const QVector<int>&); // show which grids are misfilled
	void showAnswer(const QVector< QPair<int, int> >&); // show answer of the problem

public slots: // connect with GUI
//	void chooseGrid(int rank); // choose a grid
	void undo();
	void redo();

private:
	int m_btnChosen;
	QLinkedList< QPair<QString, int> > operHistory;
	Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
