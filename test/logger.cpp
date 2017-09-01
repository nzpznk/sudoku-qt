#include "logger.h"
#include <QVector>
#include <QDebug>

#include <iostream>

Logger::Logger(QObject* parent)
{
}

void Logger::logmat(QVector< QVector<int>* >* mat)
{
	qDebug() << "slot logmat called";
	for(int i = 0; i < mat->size(); ++i) {
		for(int j = 0; j < mat->operator[](i)->size(); ++j) {
			std::cout << (*(*mat)[i])[j] << " ";
		}
		std::cout << std::endl;
	}
}

void Logger::log(int integer)
{
	qDebug() << integer;
}
