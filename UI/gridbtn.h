#ifndef GRIDBTN_H
#define GRIDBTN_H

#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QMouseEvent>

class GridBtn : public QLabel
{
	Q_OBJECT
public:
	GridBtn(QWidget* parent = 0);
	void paintEvent(QPaintEvent*);
	void highlight(bool isHighlight); // finish
	void setSameNumHighlight(bool isSameNumHighLight);
	void setChosen(bool isChosen); // highlight + special icon
	void setCorrect(bool isCorrect); // finish
	void add(int num, bool editMode); // finish
	void remove(int num, bool allRemove); // finish
	void clearState(); // finish
	void setSelfIcon(const QPixmap& myicon);

signals:
	void click();

private:
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent* ev);
	QRect getPosi(int r); // finish

private:
	QPixmap m_chosenIcon;
	QPixmap m_wrongIcon;
	QPixmap m_selfIcon;
	QString m_chosenColor;
	QString m_normalColor;
	QString m_sameNumColor;
	bool m_arr[9];
	bool m_editMode;
	bool m_highlight;
	bool m_sameNumHighlight;
	bool m_chosen;
	bool m_correct;
	bool m_haveSelfIcon;
};

#endif // GRIDBTN_H
