#ifndef DANCINGLINKS_H
#define DANCINGLINKS_H

#include <QVector>
#include <QPair>
#include <QDebug>
#include <QStack>
#include "dlnodescontainer.h"
#include "stdsudokunodescontainer.h"

#include <iostream>

class DancingLinks
{
public:
	DancingLinks(const QVector< QVector<int> >& mat); // finish
	~DancingLinks(); // finished
	bool empty(); // finish
	int chooseCol(); // finish
	QVector<int> Col(int rank); // finish
	QVector<int> Row(int rank); // finish
	void solveConflict(int row, bool trace = true); // finished
	void backTrack(); // finished
	QPair<int, QPair<int, int> > getVal(int row, int col); // finished

private:
	void removeRow(int row, QStack<ListNode*>* s = nullptr); // finished
	void removeCol(int col, QStack<ListNode*>* s = nullptr); // finished
public:
	void showStatus() {
		ListNode* cur = nodes->colHeader();
		while(cur->right != nodes->colTailer()) {
			cur = cur->right;
			int k = cur->colNum;
			if(k / 81 == 0) {
				qDebug() << "col number: " << k / 9 << ": ";
			} else if(k / 81 == 1) {
				qDebug() << "row number: " << (k-81) / 9 << ": ";
			} else if(k / 81 == 2) {
				qDebug() << "grid number: " << (k-162) / 9 << ": ";
			} else {
				qDebug() << "posi: (" << (k-243) / 9 << ", " << (k-243) % 9 << ") : ";
			}
			for(int row : Col(k)) {
				qDebug() << row / 81 + 1 << ":" << "(" << (row % 81) / 9 << ", " << (row % 81) % 9 << ")";
			}
		}
	}

private:
	StdSudokuNodesContainer* nodes;
	QStack< QStack<ListNode*>* >* m_rowStack;
	QStack< QStack<ListNode*>* >* m_colStack;
};

#endif // DANCINGLINKS_H
