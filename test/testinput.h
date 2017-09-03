#ifndef TESTINPUT_H
#define TESTINPUT_H

#include <QDialog>
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

private:
	Ui::TestInput *ui;
};

#endif // TESTINPUT_H
