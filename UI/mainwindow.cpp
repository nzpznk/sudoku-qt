#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	BackUpGameBoard* board = new BackUpGameBoard(this);
	board->setGeometry(0, 0, 500, 500); // 未设置位置会造成不能显示
	this->setFixedSize(800, 800);
}

MainWindow::~MainWindow()
{

}
