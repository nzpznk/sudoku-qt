﻿#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QIcon>
#include "sudokugrid.h"
#include "inputboard.h"

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
	void setNumMsg(int rank, int num, bool isAdd, bool editMode);
	void check();
	void clearGridMsg(int rank);
	void requestHighlight(int rank);
	void getAnswer();
	void restartMsg();
	void undoMsg();
	void redoMsg();

public slots: // connect with logic
	void showProblem(const QVector< QVector<int> >& mat);
	void highlightGrids(int rank, QVector<int> grids);
	void showWrong(const QVector<int>& girds); // show which grids are misfilled
	void showAnswer(const QVector< QVector<int> >& ans); // show answer of the problem
	void setNum(int rank, int num, bool isAdd, bool editMode);
	void clearGrid(int rank);

private slots: // connect with GUI
	void setBtnChosen(int rank); // show the btn chosen
	void on_receive_operation(InputBoard::OPERATION op, int num);
	void on_pushButton_clicked();
	void updateTime();
	void on_startpausebtn_clicked();
	void on_restart_clicked();
	void on_undobtn_clicked();
	void on_redobtn_clicked();

private:
	void initTimer();

private:
	int m_btnChosen;
	QTime time;
	QTimer* timer;
	bool m_isStopped;
	QIcon m_startIcon;
	QIcon m_pauseIcon;
	Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
