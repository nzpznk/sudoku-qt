#ifndef INPUTBOARD_H
#define INPUTBOARD_H

#include <QWidget>
#include <QSignalMapper>
#include <QDebug>
#include "gridbtn.h"

namespace Ui {
class InputBoard;
}

class InputBoard : public QWidget
{
	Q_OBJECT

public:
	enum OPERATION{
		INPUTADD,
		EDITADD, // set a number
		REMOVE, // clear a grid
		CHECK // check all answer
	};

	explicit InputBoard(QWidget *parent = 0);
	~InputBoard();

signals:
	void oper(enum OPERATION, int num);

private slots:
	void setModeEdit();
	void setModeErase();
	void setModeCheck();
	void sendOperation(int num = 0);

private:
	Ui::InputBoard *ui;
	GridBtn* m_edit;
	GridBtn* m_erase;
	GridBtn* m_check;
	OPERATION mode; // 0 : input; 1 : edit; 2 : erase; 3 : check
};

#endif // INPUTBOARD_H
