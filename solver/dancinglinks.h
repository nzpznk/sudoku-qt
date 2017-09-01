#ifndef DANCINGLINKS_H
#define DANCINGLINKS_H

#include <QVector>
#include <QPair>
#include <QDebug>
#include <QStack>
#include "dlnodescontainer.h"
#include "stdsudokunodescontainer.h"

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

private:
	StdSudokuNodesContainer* nodes;
	QStack< QStack<ListNode*>* >* m_rowStack;
	QStack< QStack<ListNode*>* >* m_colStack;
};

#endif // DANCINGLINKS_H
