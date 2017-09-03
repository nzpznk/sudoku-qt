#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QObject>
#include "loader/fileloader.h"

const int GAMESIZE = 9;


class LogicController : public QObject
{
	Q_OBJECT
public:
	explicit LogicController(QObject *parent = 0);

signals:
	void showProblem(const QVector< QVector<int> >& mat);
	void setNumMsg(int rank, int num, bool isAdd, bool editMode);
	void showWrong(const QVector<int>& grids);
	void clearGridMsg(int rank);
	void highlightGrids(int rank, const QVector<int>& grids);
	void showAnswer(const QVector<QVector<int> >& ans);
//	void wrongPosi(const QVector<int>& rank); // emited when check is over
//	void congratulation();
//	void conflict(int rank1, int rank2);

public slots:
	void startGame(QString level); // init the gameboard in logic controller
	void setNum(int rank, int num, bool isAdd, bool editMode);
	void check(); // check if is correct
	void clearGrid(int rank); // clear all number in the posi
	void calHighlights(int rank); // calculate the grids that should be highlighted
	void calAnswer();
	void restartGame();

//	void setBtnActivated(int rank);
//	void changeNum(bool editMode, int num); // if input widget is ok, emit the setNum signal
	// void setNum(int val, int rank); // store the user's operation including add and remove
	// void changeNum(int val, int row, int col);
private:
	QVector< QVector<int> > m_mat;
	QVector< QVector< QVector<bool> > > m_user;
	QVector< QVector<int> > m_ans;
	QVector< QVector<bool> > m_preMode; // true is edit mode; false is input mode
	int m_emptyPlace;
	int m_size;
};

#endif // LOGICCONTROLLER_H

