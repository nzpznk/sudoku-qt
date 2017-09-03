#ifndef TESTINPUT_H
#define TESTINPUT_H

#include <QDialog>
#include <QDebug>
#include "UI/inputboard.h"

namespace Ui {
class TestInput;
}

class TestInput : public QDialog
{
	Q_OBJECT

public:
	explicit TestInput(QWidget *parent = 0);
	~TestInput();

public slots:
	void on_receive_op(InputBoard::OPERATION op, int num) {
		qDebug() << op << num;
	}

private:
	Ui::TestInput *ui;
};

#endif // TESTINPUT_H
