#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GameBoard),
	m_btnChosen(-1),
	m_isStopped(false)
{
	ui->setupUi(this);
	ui->startpausebtn->setIconSize(QSize(40, 40));
	ui->undobtn->setIconSize(QSize(40, 40));
	ui->redobtn->setIconSize(QSize(40, 40));
	ui->undobtn->setIcon(QIcon(":/icon/resources/icons/undo.png"));
	ui->redobtn->setIcon(QIcon(":/icon/resources/icons/redo.png"));

	m_startIcon = QIcon(":/icon/resources/icons/start.png");
	m_pauseIcon = QIcon(":/icon/resources/icons/pause.png");
	ui->startpausebtn->setIcon(m_pauseIcon);
	timer = new QTimer(this);
	initTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
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
	qDebug() << "gameboard::highlightGrids called";
	ui->sudokugrid->highlightGrids(rank, grids);
	qDebug() << "gameboard::highlightGrids finished";
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
	if(m_isStopped) return;
	qDebug() << "received operation" << "op = " << op << "number = " << num;
	if(m_btnChosen == -1) return;
	if (op == InputBoard::CHECK) {
		emit check();
		return;
	}
	else if (op == InputBoard::REMOVE) {
		emit clearGridMsg(m_btnChosen);
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
	if(m_isStopped) return;
	qDebug() << "chose btn" << rank;
	m_btnChosen = rank;
	emit requestHighlight(rank);
}

void GameBoard::on_pushButton_clicked()
{
	if(m_isStopped) return;
	qDebug() << "requesting answer";
	emit getAnswer();
}

void GameBoard::updateTime()
{
	// qDebug() << "GameBoard::updateTime() called";
	ui->timeLCD->display(time.toString("hh:mm:ss"));
	time = time.addSecs(1);
	// qDebug() << time.toString("hh:mm:ss");
}

void GameBoard::on_startpausebtn_clicked()
{
	if(m_isStopped) {
		timer->start(1000);
		m_isStopped = false;
		ui->startpausebtn->setIcon(m_pauseIcon);
	} else {
		timer->stop();
		m_isStopped = true;
		ui->startpausebtn->setIcon(m_startIcon);
	}
}

void GameBoard::on_restart_clicked()
{
	initTimer();
	emit restartMsg();
}

void GameBoard::initTimer()
{
	time = QTime::fromString("00:00:00", "hh:mm:ss");
	ui->timeLCD->display(time.toString("hh:mm:ss"));
	if(!m_isStopped) timer->start(1000);
}

void GameBoard::on_undobtn_clicked()
{
	emit undoMsg();
}

void GameBoard::on_redobtn_clicked()
{
	emit redoMsg();
}
