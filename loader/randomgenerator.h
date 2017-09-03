#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QObject>
#include <QTime>
#include "loader/loader.h"
#include "solver/solver.h"

class RandomGenerator : public Loader
{
public:
	RandomGenerator(int n);
	QVector< QVector<int> > load();
private:
	void randomFill(int n);
	int m_size;
	QVector< QVector<int> > mat;
};

#endif // RANDOMGENERATOR_H
