#include "fileloader.h"

#include <QFile>
#include <QDataStream>
#include <QVector>
#include <QDebug>

FileLoader::FileLoader(QString path, QObject* parent): \
	m_path(path), Loader(parent)
{

}

QVector< QVector<int> > FileLoader::load()
{
	qDebug() << "slot load called";
	int width, height;
	QVector< QVector<int> > mat;
	QFile file(m_path);
	if(!file.open(QIODevice::ReadOnly)) {
		qDebug() << QString("file") << m_path << QString("load failed");
	}
	QTextStream ts(&file);
	ts >> width >> height;
	if(width != 9 || height != 9) {
		qDebug() << "width or height not equal 9";
	}
	// qDebug() << width << height;
	int tmp = 0;
	for(int i = 0; i < width; ++i) {
		mat.push_back(QVector<int>());
		for(int j = 0; j < height; ++j) {
			ts >> tmp;
			mat[i].push_back(tmp);
		}
	}
	return mat;
}

