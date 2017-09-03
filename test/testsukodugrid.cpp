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
