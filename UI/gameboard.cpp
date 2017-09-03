#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GameBoard)
{
	ui->setupUi(this);
	connect(ui->sudokugrid, SIGNAL(btnChosen(int)), this, SLOT(setBtnChosen(int)));
	connect(ui->numberboard, SIGNAL(oper(InputBoard::OPERATION, int)), \
			this, SLOT(on_receive_operation(InputBoard::OPERATION, int)));
}

GameBoard::~GameBoard()
{
	delete ui;
}

void GameBoard::showProblem(const QVector<QVector<int> >& mat)
{
	ui->sudokugrid->showProblem(mat);
}

void GameBoard::highlightGrids(int rank, QVector<int> grids)
{
	ui->sudokugrid->highlightGrids(rank, grids);
}

void GameBoard::showWrong(const QVector<int>& grids)
{
	ui->sudokugrid->showWrongMsg(grids);
}

void GameBoard::showAnswer(const QVector<QVector<int> >& ans)
{
	ui->sudokugrid->showAnswer(ans);
}

void GameBoard::setNum(int rank, int num, bool isAdd, bool editMode)
{
	ui->sudokugrid->setNum(rank, num, isAdd, editMode);
}

void GameBoard::clearGrid(int rank)
{
	ui->sudokugrid->clearGrid(rank);
}

void GameBoard::on_receive_operation(InputBoard::OPERATION op, int num)
{
	qDebug() << "received operation" << "op = " << op << "number = " << num;
	if (op == InputBoard::CHECK) {
		emit check();
		return;
	}
	else if (op == InputBoard::REMOVE) {
		emit clearGrid(m_btnChosen);
		return;
	}
	bool isAdd = false;
	bool editMode = false;
	if(op == InputBoard::EDITADD) {
		isAdd = true;
		editMode = true;
	} else if (op == InputBoard::INPUTADD) {
		isAdd = true;
		editMode = false;
	} else {
		qDebug() << "something wrong in GameBoard::on_receive_operation";
	}
	emit setNumMsg(m_btnChosen, num, isAdd, editMode);
}

void GameBoard::setBtnChosen(int rank)
{
	qDebug() << "chose btn" << rank;
	m_btnChosen = rank;
	emit requestHighlight(rank);
}

//void GameBoard::setOperation(InputBoard::OPERATION op, int num) // unfinished
//{
//	switch(op){
//	case InputBoard::ADD:
//		operHistory.append(QPair("add", num));
//		emit setNum(m_btnChosen, num); break;
//	case InputBoard::REMOVE:
//		emit clearGrid(m_btnChosen); break;
//	case InputBoard::CHECK:
//		emit check();
//	}
//}

//void GameBoard::undo()
//{

//}

void GameBoard::on_pushButton_clicked()
{
	qDebug() << "requesting answer";
	emit getAnswer();
}
