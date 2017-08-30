#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>
#include <QVector>
#include <QPair>
#include "dancinglinks.h"

class Solver : public QObject
{
	Q_OBJECT
public:
	explicit Solver(QObject *parent = 0);
	QVector< QVector< QVector<int> > > operator() (const QVector< QVector<int> >& mat);
	int cntGivenNumber(const QVector< QVector<int> >& mat);

signals:

public slots:

private:
	void recSolve(DancingLinks* dl, QVector< QVector<int> >& mat, QVector < QVector< QVector<int> > >& ans);
};

#endif // SOLVER_H
