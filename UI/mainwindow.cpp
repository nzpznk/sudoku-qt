#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addGameBoard(GameBoard* w)
{
	ui->stackedWidget->addWidget(w);
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{

}

void MainWindow::on_startBtn_clicked()
{
	emit startGameMsg(ui->comboBox->currentText());
	ui->stackedWidget->setCurrentIndex(1);
}
