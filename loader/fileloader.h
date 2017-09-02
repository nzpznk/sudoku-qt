#ifndef FILELOADER_H
#define FILELOADER_H

#include "loader.h"

class FileLoader : public Loader
{
	Q_OBJECT
public:
	FileLoader(QString path, QObject* parent = 0);
	QVector< QVector<int> > load();

private:
	QString m_path;

};

#endif // FILELOADER_H
