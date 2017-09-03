#include "sudokugrid.h"
#include "ui_sudokugrid.h"

SudokuGrid::SudokuGrid(QWidget *parent) : \
	QWidget(parent),
	ui(new Ui::SudokuGrid)
{
	ui->setupUi(this);

	m_btns.resize(9);
	for(int i = 0; i < 9; ++i) {
		m_btns[i].resize(9);
	}

	QSignalMapper* btn2int = new QSignalMapper(this);
	QGridLayout* midGrid = nullptr;
	GridBtn* btn = nullptr;
	for(int i = 0; i < 9; ++i) {
		midGrid = findChild<QGridLayout*>("gridLayout_" + QString::number(i + 1));
		for(int j = 0; j < 9; ++j) {
			btn = new GridBtn(this);
			btn2int->setMapping(btn, ((i/3)*3 + j/3) * 9 + ((i%3)*3) + j%3);
			connect(btn, SIGNAL(click()), btn2int, SLOT(map()));
			m_btns[(i/3)*3 + j/3][((i%3)*3) + j%3] = btn;
			midGrid->addWidget(btn, j / 3, j % 3);
		}
	}
	connect(btn2int, SIGNAL(mapped(int)), this, SIGNAL(btnChosen(int)));
}

SudokuGrid::~SudokuGrid()
{
	delete ui;
}

void SudokuGrid::showProblem(const QVector<QVector<int> >& mat)
{
	qDebug() << "SukoduGrid show problem slot called";
	for(int i = 0; i < mat.size(); ++i) {
		for(int j = 0; j < mat[i].size(); ++j) {
			m_btns[i][j]->clearState();
			if(mat[i][j]) {
				m_btns[i][j]->add(mat[i][j], false);
			} else {
				m_btns[i][j]->remove(0, true);
			}
		}
	}
	qDebug() << "SukoduGrid show problem slot finished";
}

void SudokuGrid::setNum(int rank, int val, bool isAdd, bool editMode)
{
	qDebug() << "SukoduGrid setNum slot called";
	if(isAdd) {
		m_btns[rank / 9][rank % 9]->add(val, editMode);
	} else {
		m_btns[rank / 9][rank % 9]->remove(val, false);
	}
	qDebug() << "SukoduGrid setNum slot finished";
}

void SudokuGrid::showWrongMsg(QVector<int> grids)
{
	qDebug() << "SukoduGrid showWrongMsg slot called";
	for(int rank : grids) {
		m_btns[rank / 9][rank % 9]->setCorrect(false);
	}
	qDebug() << "SukoduGrid showWrongMsg slot finished";
}

void SudokuGrid::highlightGrids(int rank, const QVector<int>& sameNums)
{
	qDebug() << "SukoduGrid highlightGrid slot called";
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			m_btns[i][j]->clearState();
		}
	}
	for(int i = 0; i < 9; ++i) {
		m_btns[i][rank % 9]->highlight(true);
		m_btns[rank / 9][i]->highlight(true);
	}
	for(int r : sameNums) {
		m_btns[r / 9][r % 9]->setSameNumHighlight(true);
	}
	m_btns[rank / 9][rank % 9]->setSameNumHighlight(true);
	m_btns[rank / 9][rank % 9]->setChosen(true);
	qDebug() << "SukoduGrid highlightGrid slot finished";
}

void SudokuGrid::clearGrid(int rank)
{
	qDebug() << "SukoduGrid clearState slot called";
	m_btns[rank / 9][rank % 9]->remove(0, true);
	qDebug() << "SukoduGrid clearState slot finished";
}

void SudokuGrid::showAnswer(const QVector<QVector<int> >& ans)
{
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			if(ans[i][j]) {
				m_btns[i][j]->add(ans[i][j], false);
			}
		}
	}
}
