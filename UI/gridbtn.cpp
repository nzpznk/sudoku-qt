﻿#include "gridbtn.h"

#include <QDebug>
#include <QPushButton>

GridBtn::GridBtn(QWidget* parent) : \
	QLabel(parent), m_chosen(false), m_correct(true), m_editMode(false), m_highlight(false)
{
	for(int i = 0; i < 9; ++i) {
		m_arr[i] = false;
	}
	this->setFrameShape (QFrame::Box);
	this->setStyleSheet("border: 1px solid  #ff0000");
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_chosenColor = "background-color: #7bbfea";
	m_normalColor = "background-color: #fff";
	m_sameNumColor = "background-color: #ffff00";
	m_chosenIcon = QPixmap("E:\\CS_Repository\\Project\\build-sudoku-qt-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\resources\\icons\\circle.png");
	m_wrongIcon = QPixmap("E:\\CS_Repository\\Project\\build-sudoku-qt-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\resources\\icons\\cross.png");
}

void GridBtn::paintEvent(QPaintEvent*)
{
	QPainter p(this);
//	this->setFrameShape(QFrame::Box);
	if(m_highlight) {
		setStyleSheet(m_chosenColor);
	} else {
		setStyleSheet(m_normalColor);
	}
	if(m_chosen) {
		p.drawPixmap(0, 0, size().width(), size().height(), m_chosenIcon);
	}
	if(!m_correct) {
		p.drawPixmap(0, 0, size().width(), size().height(), m_wrongIcon);
	}
	QFont f("Helvetica");
	if(m_editMode) {
		f.setPixelSize(this->size().height() / 3);
		p.setFont(f);
		for(int i = 0; i < 9; ++i) {
			if(m_arr[i]) p.drawText(getPosi(i), QString::number(i));
		}
	} else {
		f.setPixelSize(this->size().height() * 3 / 4);
		p.setFont(f);
		for(int i = 0; i < 9; ++i) {
			if(m_arr[i]) {
				p.drawText(getPosi(i), QString::number(i));
				break;
			}
		}
	}
}

void GridBtn::highlight(bool isHighlight)
{
	m_highlight = isHighlight;
	update();
}

void GridBtn::setChosen(bool isChosen)
{
	m_chosen = isChosen;
	update();
}

void GridBtn::setCorrect(bool iscorrect)
{
	m_correct = iscorrect;
	update();
}

void GridBtn::add(int num, bool editMode)
{
	if(!editMode) {
		for(int i = 0; i < 9; ++i) {
			m_arr[i] = false;
		}
	}

	m_arr[num] = true;
	m_editMode = editMode;
	update();
}

void GridBtn::remove(int num, bool allRemove)
{
	if(allRemove) {
		for(int i = 0; i < 9; ++i) {
			m_arr[i] = false;
		}
	} else {
		m_arr[num] = false;
	}
	update();
}


void GridBtn::clearState()
{
	m_editMode = false;
	m_chosen = false;
	m_correct = true;
	m_highlight = false;
	update();
}

void GridBtn::mousePressEvent(QMouseEvent*)
{
	//setColor(m_chosenColor);
}

void GridBtn::mouseReleaseEvent(QMouseEvent* ev)
{
	if(ev->x() < 0 || ev->x() > size().width() || ev->y() < 0 || ev->y() > size().height()) {
		this->setStyleSheet("background-color: #fff");
		return;
	}
	m_chosen = !m_chosen;
	update();
	emit click();
}

QRect GridBtn::getPosi(int r)
{
	int w = 0, h = 0, row = 0, col = 0;
	if(m_editMode) {
		w = this->size().width() / 3;
		h = this->size().height() / 3;
		row = r / 3;
		col = r % 3;
		return QRect(col * w + w / 4, row * h, w, h);
	} else {
		w = this->size().width();
		h = this->size().height();
		return QRect(w / 3, h / 8, w, h);
	}
}
