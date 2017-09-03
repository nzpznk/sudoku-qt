#include "testgridbtn.h"
#include "ui_testgridbtn.h"

TestGridBtn::TestGridBtn(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestGridBtn)
{
	ui->setupUi(this);
}

TestGridBtn::~TestGridBtn()
{
	delete ui;
}

void TestGridBtn::on_pushButton_clicked()
{
	ui->label->highlight(true);
}

void TestGridBtn::on_pushButton_2_clicked()
{
	ui->label->setChosen(true);
}

void TestGridBtn::on_pushButton_3_clicked()
{
	ui->label->setCorrect(true);
}

void TestGridBtn::on_pushButton_4_clicked()
{
	ui->label->setCorrect(false);
}

void TestGridBtn::on_pushButton_5_clicked()
{
	ui->label->add(5, true);
}

void TestGridBtn::on_pushButton_7_clicked()
{
	ui->label->remove(0, true);
}

void TestGridBtn::on_pushButton_6_clicked()
{
	ui->label->add(3, false);
}

void TestGridBtn::on_pushButton_8_clicked()
{
	ui->label->clearState();
}

void TestGridBtn::on_pushButton_9_clicked()
{
	ui->label->setChosen(false);
}

void TestGridBtn::on_pushButton_10_clicked()
{
	ui->label->remove(3, false);
}

void TestGridBtn::on_pushButton_11_clicked()
{
	ui->label->remove(5, false);
}

void TestGridBtn::on_pushButton_12_clicked()
{
	ui->label->add(6, false);
}

void TestGridBtn::on_pushButton_13_clicked()
{
	ui->label->add(6, true);
}
