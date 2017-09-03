#include "testgridbtn.h"
#include "ui_testgridbtn.h"

TestGridBtn::TestGridBtn(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestGridBtn)
{
	ui->setupUi(this);
}

TestGridBtn::~TestGridBtn()
{
	delete ui;
}
