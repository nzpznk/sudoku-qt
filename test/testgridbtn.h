#ifndef TESTGRIDBTN_H
#define TESTGRIDBTN_H

#include <QDialog>
#include "UI/gridbtn.h"

namespace Ui {
class TestGridBtn;
}

class TestGridBtn : public QDialog
{
	Q_OBJECT

public:
	explicit TestGridBtn(QWidget *parent = 0);
	~TestGridBtn();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_9_clicked();

	void on_pushButton_10_clicked();

	void on_pushButton_11_clicked();

	void on_pushButton_12_clicked();

	void on_pushButton_13_clicked();

private:
	Ui::TestGridBtn *ui;
};

#endif // TESTGRIDBTN_H
