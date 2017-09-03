#include "testsukodugrid.h"
#include "ui_testsukodugrid.h"

TestSukoduGrid::TestSukoduGrid(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestSukoduGrid)
{
	ui->setupUi(this);
	connect(this, SIGNAL(setProblem(QVector<QVector<int> >)), ui->widget, SLOT(showProblem(QVector<QVector<int> >)));
	connect(this, SIGNAL(highlightGrids(int,QVector<int>)), ui->widget, SLOT(highlightGrids(int,QVector<int>)));
	connect(this, SIGNAL(setNum(int,int,bool,bool)), ui->widget, SLOT(setNum(int,int,bool,bool)));
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
			if(m_user[i][j] == m_user[row][col]) {
				btns.push_back(i * m_mat.size() + j);
			}
		}
	}

	emit highlightGrids(rank, btns);
}

void TestSukoduGrid::on_pushButton_clicked()
{
	FileLoader fl("./mat10.txt");
	m_mat = fl.load();
	m_user = m_mat;
	emit setProblem(m_mat);
}

void TestSukoduGrid::on_pushButton_2_clicked()
{
	QVector<int> g;
	g.push_back(0);
	g.push_back(15);
	g.push_back(20);
	g.push_back(25);
	emit highlightGrids(5, g);
}

void TestSukoduGrid::on_pushButton_3_clicked()
{
	QVector<int> v;
	v.push_back(5);
	ui->widget->showWrongMsg(v);
}

void TestSukoduGrid::on_pushButton_4_clicked()
{
	emit setNum(20, 5, true, true);
}

void TestSukoduGrid::on_pushButton_5_clicked()
{
	ui->widget->clearGrid(20);
}
