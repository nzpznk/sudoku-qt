#ifndef TESTSUKODUGRID_H
#define TESTSUKODUGRID_H

#include <QDialog>

namespace Ui {
class TestSukoduGrid;
}

class TestSukoduGrid : public QDialog
{
	Q_OBJECT

public:
	explicit TestSukoduGrid(QWidget *parent = 0);
	~TestSukoduGrid();

private:
	Ui::TestSukoduGrid *ui;
};

#endif // TESTSUKODUGRID_H
