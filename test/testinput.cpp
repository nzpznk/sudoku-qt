#include "testinput.h"
#include "ui_testinput.h"

TestInput::TestInput(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestInput)
{
	ui->setupUi(this);
}

TestInput::~TestInput()
{
	delete ui;
}
