#include "gameboard.h"
#include <QRegExpValidator>
#include <QRegExp>

GameBoard::GameBoard(QWidget *parent) :
	QWidget(parent)
{
	init();
}



GameBoard::~GameBoard()
{

}

void GameBoard::sendChangeSignal(int rank)
{
	qDebug() << "( " << rank / 9 << ", " << rank % 9  << " ) changed to " << m_lineEdit[rank]->text();
	emit setNumber(m_lineEdit[rank]->text().toInt(), rank / 9, rank % 9);
}

void GameBoard::init() {
	m_lineEdit = new QLineEdit* [9 * 9];
	QGridLayout* gridLayout = new QGridLayout(this);

	QRegExpValidator* singleNumberValid = new QRegExpValidator(QRegExp("[1-9]")); // only allow the number from 1 to 9
	QSignalMapper* m_map = new QSignalMapper(this);
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			int rank = 9 * i + j;

			// config the line_edit
			//setStyle(m_lineEdit[9 * i + j]);
			m_lineEdit[rank] = new QLineEdit;
			m_lineEdit[rank]->setValidator(singleNumberValid);
			m_lineEdit[rank]->setFixedSize(50, 50);

			// map the line_edits to integers
			connect(m_lineEdit[rank], SIGNAL(textChanged(QString)), m_map, SLOT(map()));
			m_map->setMapping(m_lineEdit[rank], rank);
			gridLayout->addWidget(m_lineEdit[rank], i, j);
		}
	}
	connect(m_map, SIGNAL(mapped(int)), this, SLOT(sendChangeSignal(int))); // 这个信号和槽只连接这一次
	this->setLayout(gridLayout);
}
