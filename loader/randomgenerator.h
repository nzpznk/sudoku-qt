#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QObject>
#include <loader/loader.h>

class RandomGenerator : public Loader
{
public:
	RandomGenerator();
	QVector< QVector<int> > load();
private:
//	void generateRandomNumber()
//	{
//		qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//		for(int i=0; i<10; i++)
//		{
//			int test =qrand()%10;
//			qDebug()<<test;
//		}
//	}
};

#endif // RANDOMGENERATOR_H
