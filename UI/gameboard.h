#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>

#include "sudokugrid.h"
// #include "inputboard.h"

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
	Q_OBJECT

public:
	explicit GameBoard(QWidget *parent = 0);
	~GameBoard();

signals:
	void setNum(int rank, int val);
	void remNum(int rank);
	void check();

public slots: // connect with logic
	void showWrong(const QVector<int>&); // show which grids are misfilled
	void showAnswer(const QVector< QPair<int, int> >&); // show answer of the problem

public slots: // connect with GUI
	void chooseGrid(int rank); // choose a grid
	void undo();
	void redo();

private:
	QList< QPair<QString, int> > operHistory;
	Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
