#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QSignalMapper>
#include <QDebug>

class BackUpGameBoard : public QWidget
{
	Q_OBJECT

public:
	explicit BackUpGameBoard(QWidget *parent = 0);
	~BackUpGameBoard();

signals:
	void setNumber(const int val, const int row, const int col);

private slots:
	void sendChangeSignal(int);

private:
	void init();
	QLineEdit** m_lineEdit;
};

#endif // GAMEBOARD_H
