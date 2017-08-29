#ifndef LOADER_H
#define LOADER_H

#include <QObject>

class Loader : public QObject
{
	Q_OBJECT
public:
	explicit Loader(QObject *parent = 0);

signals:
	void loadResult(QVector< QVector<int>* >*);

public slots:
	virtual void load() = 0;
};

#endif // LOADER_H
