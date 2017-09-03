#include "inputboard.h"
#include "ui_inputboard.h"

InputBoard::InputBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::InputBoard)
{
	ui->setupUi(this);
	QSignalMapper* btn2num = new QSignalMapper(this);
	QPushButton* numbtn = nullptr;
	for(int i = 0; i < 9; ++i) {
		numbtn = findChild<QPushButton*>("pushButton_" + QString::number(i+1));
		btn2num->setMapping(numbtn, i + 1);
		connect(numbtn, SIGNAL(clicked(bool)), btn2num, SLOT(map()));
	}
	connect(btn2num, SIGNAL(mapped(int)), this, SLOT(sendOperation(int)));
	m_edit = findChild<GridBtn*>("edit");
	m_edit->setSelfIcon(QPixmap(":/icon/resources/icons/edit.png"));
	m_erase = findChild<GridBtn*>("erase");
	m_erase->setSelfIcon(QPixmap(":/icon/resources/icons/eraser.png"));
	m_check = findChild<GridBtn*>("check");
	m_check->setSelfIcon(QPixmap(":/icon/resources/icons/check.png"));
	connect(m_edit, SIGNAL(click()), this, SLOT(setModeEdit()));
	connect(m_erase, SIGNAL(click()), this, SLOT(setModeErase()));
	connect(m_check, SIGNAL(click()), this, SLOT(setModeCheck()));
}

InputBoard::~InputBoard()
{
	delete ui;
}

void InputBoard::setModeEdit()
{
	if(mode != EDITADD) {
		mode = EDITADD;
		m_edit->highlight(true);
		m_erase->highlight(false);
		m_check->highlight(false);
	} else {
		mode = INPUTADD;
		m_edit->highlight(false);
	}
}

void InputBoard::setModeErase()
{
	if(mode != REMOVE) {
		mode = REMOVE;
		m_edit->highlight(false);
		m_erase->highlight(true);
		m_check->highlight(false);
	} else {
		mode = INPUTADD;
		m_erase->highlight(false);
	}
}

void InputBoard::setModeCheck()
{
	if(mode != CHECK) {
		mode = CHECK;
		m_edit->highlight(false);
		m_erase->highlight(false);
		m_check->highlight(true);
		sendOperation(0);
	} else {
		mode = INPUTADD;
		m_check->highlight(false);
	}
}

void InputBoard::sendOperation(int num)
{
	if(mode == CHECK && num != 0) return;
	qDebug() << mode << num;
	emit oper(mode, num);
}
