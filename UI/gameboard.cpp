#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GameBoard)
{
	ui->setupUi(this);
	QWidget* grid = findChild<QWidget*>("sudokugrid");
	delete grid;
	grid = new SudokuGrid(this);
	QWidget* numBoard = findChild<QWidget*>("numberboard");
	delete numBoard;
	numBoard = new InputBoard(this);
	connect();
	connect();
}

GameBoard::~GameBoard()
{
	delete ui;
}
