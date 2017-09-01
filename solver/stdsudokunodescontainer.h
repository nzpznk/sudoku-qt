#ifndef STDSUDOKUNODESCONTAINER_H
#define STDSUDOKUNODESCONTAINER_H

#include "dlnodescontainer.h"

class StdSudokuNodesContainer : public DLNodesContainer
{
public:
	StdSudokuNodesContainer(const QVector< QVector<int> >&); // finish

	QPair< int, QPair<int, int> > getNumber(int row, int col = 0); // finish

	ListNode* getCol(int col); // finish

	QVector<ListNode*> getRow(int row, int col = 0); // finish

	~StdSudokuNodesContainer(); // finish

	int getRowNum(int val, int mRow, int mCol);

private:
	const int SIZE = 9;
	int gridNum;
	int rowSize;
	int colSize;
	ListNode** m_nodes; // (n^3 row) x (restrict col)
	ListNode* m_colNodes; // array of column header
};

#endif // STDSUDOKUNODESCONTAINER_H
