#include "testsukodugrid.h"
#include "ui_testsukodugrid.h"

TestSukoduGrid::TestSukoduGrid(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestSukoduGrid)
{
	ui->setupUi(this);
}

TestSukoduGrid::~TestSukoduGrid()
{
	delete ui;
}

void TestSukoduGrid::setActivated(int rank)
{
	qDebug() << "set Activated rank" << rank;
	m_activated = rank;
	int row = rank / m_mat.size();
	int col = rank % m_mat.size();
	QVector<int> btns;
	for(int i = 0; i < m_mat.size(); ++i) {
		for(int j = 0; j < m_mat[i].size(); ++j) {
			if(i == row && j == col) continue;
			if(m_user[i][j] == m_user[row][col]) {
				btns.push_back(i * m_mat.size() + j);
			}
		}
	}

	emit highlightGrids(rank, btns);
}

void TestSukoduGrid::on_pushButton_clicked()
{
	testSetProblem();
}
