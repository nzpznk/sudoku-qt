#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include <QVector>

class Loader : public QObject
{
	Q_OBJECT
public:
	explicit Loader(QObject *parent = 0);
	virtual QVector< QVector<int> > load() = 0;
};

#endif // LOADER_H
