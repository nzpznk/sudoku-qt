#ifndef TESTSUKODUGRID_H
#define TESTSUKODUGRID_H

#include <QDialog>
#include "loader/fileloader.h"
#include "UI/sudokugrid.h"

namespace Ui {
class TestSukoduGrid;
}

class TestSukoduGrid : public QDialog
{
	Q_OBJECT

public:
	explicit TestSukoduGrid(QWidget *parent = 0);
	~TestSukoduGrid();

public slots:
	void setActivated(int rank);

signals:
	void setProblem(const QVector< QVector<int> >& mat);
	void highlightGrids(int rank, const QVector<int>&);
	void setNum(int rank, int val, bool isAdd, bool editMode);

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

private:
	int m_activated;
	QVector< QVector<int> > m_mat;
	QVector< QVector<int> > m_user;
	Ui::TestSukoduGrid *ui;
};

#endif // TESTSUKODUGRID_H
