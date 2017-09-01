#include "sudokugrid.h"
#include "ui_sudokugrid.h"

SudokuGrid::SudokuGrid(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SudokuGrid)
{
	ui->setupUi(this);
	QSignalMapper* btn2int = new QSignalMapper(this);
	QGridLayout* midGrid = nullptr;
	GridBtn* btn = nullptr;
	for(int i = 0; i < 9; ++i) {
		midGrid = findChild<QGridLayout*>("gridLayout_" + QString::number(i + 1));
		for(int j = 0; j < 9; ++j) {
			btn = new GridBtn(this);
			btn2int->setMapping(btn, ((i/3)*3 + j/3) * 9 + ((i%3)*3) + j%3);
			connect(btn, SIGNAL(click()), btn2int, SLOT(map()));
			midGrid->addWidget(btn, j / 3, j % 3);
		}
	}
	connect(btn2int, SIGNAL(mapped(int)), this, SLOT(log(int)));
}

SudokuGrid::~SudokuGrid()
{
	delete ui;
}

void SudokuGrid::log(int rank)
{
	qDebug() << rank;
}
