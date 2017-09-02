#ifndef INPUTBOARD_H
#define INPUTBOARD_H

#include <QWidget>
#include <QSignalMapper>
#include "gridbtn.h"

namespace Ui {
class InputBoard;
}

class InputBoard : public QWidget
{
	Q_OBJECT

public:
	enum OPERATION{
		ADD, // set a number
		REMOVE, // clear a grid
		CHECK // check all answer
	};

	explicit InputBoard(QWidget *parent = 0);
	~InputBoard();

signals:
	void oper(enum OPERATION, int num);

public slots:


private:
	Ui::InputBoard *ui;
};

#endif // INPUTBOARD_H
