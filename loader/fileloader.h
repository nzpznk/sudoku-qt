#ifndef FILELOADER_H
#define FILELOADER_H

#include "loader.h"

class FileLoader : public Loader
{
public:
	FileLoader(QString path, QObject* parent = 0);

public slots:
	virtual void load();

private:
	QString m_path;

};

#endif // FILELOADER_H
