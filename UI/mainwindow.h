#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/gameboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void addGameBoard(GameBoard* w);

signals:
	void startGameMsg(const QString& level);

private slots:

	void on_stackedWidget_currentChanged(int arg1);

	void on_startBtn_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
