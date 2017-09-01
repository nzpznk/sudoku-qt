#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "loader/fileloader.h"

class Logger : public QObject
{
	Q_OBJECT
public:
	explicit Logger(QObject *parent = 0);

public slots:
	void logmat(QVector< QVector<int>* >* mat);
	void log(int integer);

};

#endif // LOGGER_H
