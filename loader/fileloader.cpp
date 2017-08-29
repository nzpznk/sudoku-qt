#include "fileloader.h"

#include <QFile>
#include <QDataStream>
#include <QVector>
#include <QDebug>

FileLoader::FileLoader(QString path, QObject* parent): \
	m_path(path), Loader(parent)
{

}

void FileLoader::load()
{
	int width, height;
	QVector< QVector<int>* >* mat = new QVector< QVector<int>* >;
	QFile file(m_path);
	if(!file.open(QIODevice::ReadOnly)) {
		qDebug() << QString("file") << m_path << QString("load failed");
	}
	QTextStream ts(&file);
	ts >> width >> height;
	if(width != 9 || height != 9) {
		qDebug() << "width or height not equal 9";
	}
	qDebug() << width << height;
	QVector<int>* rowVec = nullptr;
	int tmp = 0;
	for(int i = 0; i < width; ++i) {
		rowVec = new QVector<int>();
		for(int j = 0; j < height; ++j) {
			ts >> tmp;
			rowVec->push_back(tmp);
		}
		mat->push_back(rowVec);
		rowVec = nullptr;
	}
	emit loadResult(mat);
}

