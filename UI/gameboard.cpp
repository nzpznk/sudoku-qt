#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent, const QVector< QVector<int> >& mat) :
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

	connect(static_cast<SudokuGrid*>(grid), SIGNAL(btnChosen(int)), this, SLOT(setBtnChosen(int)));
	connect(static_cast<InputBoard*>(numBoard), SIGNAL(oper(InputBoard::OPERATION, int num)), \
			this, SLOT(setOperation(InputBoard::OPERATION)));
	connect(this, SIGNAL(setNum(int, int)), static_cast<SudokuGrid*>(grid), SLOT(setNum(int,int)));
	connect(this, SIGNAL(clearGrid(int)), static_cast<SudokuGrid*>(grid), SLOT(clearGrid(int));
}

GameBoard::~GameBoard()
{
	delete ui;
}

void GameBoard::setBtnChosen(int rank)
{
	m_btnChosen = rank;
}

void GameBoard::setOperation(InputBoard::OPERATION op, int num)
{////////////////////////////////////////////////////////////////
	switch(op){
	case InputBoard::ADD:
		operHistory.append(QPair("add", num));
		emit setNum(m_btnChosen, num); break;
	case InputBoard::REMOVE:
		emit clearGrid(m_btnChosen); break;
	case InputBoard::CHECK:
		emit check();
	}
}

void GameBoard::undo()
{

}
