#include "testinput.h"
#include "ui_testinput.h"

TestInput::TestInput(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestInput)
{
	ui->setupUi(this);
	connect(ui->widget, SIGNAL(oper(InputBoard::OPERATION,int)), this, SLOT(on_receive_op(InputBoard::OPERATION,int)));
}

TestInput::~TestInput()
{
	delete ui;
}
