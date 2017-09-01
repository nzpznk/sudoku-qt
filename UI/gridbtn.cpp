#include "gridbtn.h"

#include <QDebug>
#include <QPushButton>

GridBtn::GridBtn(QWidget* parent) : QLabel(parent)
{
	for(int i = 0; i < 9; ++i) {
		m_arr[i] = false;
	}
	this->choosen = false;
	this->setFrameShape (QFrame::Box);
	this->setStyleSheet("border: 1px solid  #ff0000");
//	this->setMinimumSize(300, 300);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	add(0); add(5); add(7);
}

void GridBtn::paintEvent(QPaintEvent*)
{
	this->setFrameShape(QFrame::Box);
	QPainter p(this);
	QFont f("Helvetica");
	f.setPixelSize(this->size().height() / 3);
	p.setFont(f);
	p.setBrush(Qt::yellow);
	for(int i = 0; i < 9; ++i) {
		if(m_arr[i]) p.drawText(getPosi(i), QString::number(i + 1));
	}
}

void GridBtn::add(int num)
{
	m_arr[num] = true;
	update();
}

void GridBtn::remove(int num)
{
	m_arr[num] = false;
	update();
}

void GridBtn::mousePressEvent(QMouseEvent*)
{
	this->setStyleSheet("background-color: #ff0000");
}

void GridBtn::mouseReleaseEvent(QMouseEvent* ev)
{
	if(ev->x() < 0 || ev->x() > size().width() || ev->y() < 0 || ev->y() > size().height()) {
		this->setStyleSheet("background-color: #fff");
		return;
	}


//	setClicked(!choosen); ////////////////////////////////////////////
	emit click();
}

QRect GridBtn::getPosi(int r)
{
	int w = this->size().width() / 3;
	int h = this->size().height() / 3;
	int row = r / 3;
	int col = r % 3;
	return QRect(col * w + w / 4, row * h, w, h);
}
