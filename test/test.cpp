
#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QPushButton>

#include "loader/fileloader.h"
#include "logger.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	FileLoader* fl = new FileLoader("./mat1.txt");
	Logger* logger = new Logger;
	QPushButton* btn = new QPushButton;
	btn->setGeometry(500, 500, 50, 30);
	QObject::connect(btn, SIGNAL(clicked(bool)), fl, SLOT(load()));
	QObject::connect(fl, SIGNAL(loadResult(QVector<QVector<int>*>*)), logger, SLOT(logmat(QVector<QVector<int>*>*)));
	btn->show();
	return app.exec();
}
