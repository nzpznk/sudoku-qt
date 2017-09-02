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
	void wrongPosi(const QVector<int>& rank); // emited when check is over
	void conflict(int rank1, int rank2);
	void congratulation();

public slots:
	void startGame(QString level); // init the gameboard in logic controller
	void setNum(int val, int rank); // store the user's operation including add and remove
	void check(); // check if is correct
	void changeNum(int val, int row, int col);

private:
	int testCollide(int row, int col);

private:
	QVector< QVector<int> > m_user;
	QVector< QVector<int> > m_mat;
	int m_emptyPlace;
};

#endif // LOGICCONTROLLER_H
