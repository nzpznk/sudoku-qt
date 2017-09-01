#ifndef GRIDBTN_H
#define GRIDBTN_H

#include <QLabel>
#include <QPainter>
#include <QMouseEvent>

class GridBtn : public QLabel
{
	Q_OBJECT
public:
	GridBtn(QWidget* parent = 0);
	//void setStyle();

signals:
	void click();

public slots:
	void paintEvent(QPaintEvent*);
	void add(int);
	void remove(int);

private:
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent* ev);
	QRect getPosi(int r);
	bool m_arr[9];
	bool choosen;
};

#endif // GRIDBTN_H
