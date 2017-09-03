#ifndef TESTGRIDBTN_H
#define TESTGRIDBTN_H

#include <QDialog>

namespace Ui {
class TestGridBtn;
}

class TestGridBtn : public QDialog
{
	Q_OBJECT

public:
	explicit TestGridBtn(QWidget *parent = 0);
	~TestGridBtn();

private:
	Ui::TestGridBtn *ui;
};

#endif // TESTGRIDBTN_H
