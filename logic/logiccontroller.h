#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QObject>

const int GAMESIZE = 9;

class LogicController : public QObject
{
	Q_OBJECT
public:
	explicit LogicController(QObject *parent = 0);

signals:
	void conflict(int rank1, int rank2);
	void congratulation();

public slots:
	void changeNum(int val, int row, int col);

private:
	int testCollide(int row, int col);

private:
	QVector< QVector<int>* >* m_mat;
	int m_emptyPlace;
};

#endif // LOGICCONTROLLER_H
