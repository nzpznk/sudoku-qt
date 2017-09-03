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
	explicit GameBoard(const QVector< QVector<int> >& mat, QWidget *parent = 0);
	~GameBoard();

signals:
	void setNumMsg(int rank, int num, bool isAdd, bool editMode);
	void check();
	void clearGridMsg(int rank);
	void requestHighlight(int rank);
	void getAnswer();

public slots: // connect with logic
	void highlightGrids(int rank, QVector<int> grids);
	void showWrong(const QVector<int>& girds); // show which grids are misfilled
	void showAnswer(const QVector< QVector<int> >& ans); // show answer of the problem
	void setNum(int rank, int num, bool isAdd, bool editMode);
	void clearGrid(int rank);

public slots:
////	void chooseGrid(int rank); // choose a grid
//	void undo();
//	void redo();


private slots: // connect with GUI
	void setBtnChosen(int rank); // show the btn chosen
	void on_receive_operation(InputBoard::OPERATION op, int num);
	void on_pushButton_clicked();

private:
	int m_btnChosen;
	QLinkedList< QPair<QString, int> > operHistory;
	Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
