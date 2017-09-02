#include "inputboard.h"
#include "ui_inputboard.h"

InputBoard::InputBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::InputBoard)
{
	ui->setupUi(this);
	QSignalMapper* btn2num = new QSignalMapper(this);
	GridBtn* mybtn = nullptr;
	for(int i = 0; i < 9; ++i) {
		mybtn = new GridBtn;
		btn2num->setMapping(mybtn, i + 1);
		connect(mybtn, SIGNAL(click()), btn2num, SLOT(map()));
	}
	connect(btn2num, SIGNAL(mapped(int)), this, SLOT());
}

InputBoard::~InputBoard()
{
	delete ui;
}
