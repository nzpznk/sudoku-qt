#include "UI/mainwindow.h"
#include <QApplication>

// #define DEBUG

#ifndef DEBUG
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
#endif // DEBUG

//#ifdef DEBUG
//#include "./test/test.cpp"
//#endif // DEBUG
