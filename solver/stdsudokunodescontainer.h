#ifndef STDSUDOKUNODESCONTAINER_H
#define STDSUDOKUNODESCONTAINER_H

#include "dlnodescontainer.h"

class StdSudokuNodesContainer : public DLNodesContainer
{
public:
	StdSudokuNodesContainer(const QVector< QVector<int> >& mat); // finish

	/**
	 * @brief getNumber
	 * @param row
	 * @param col
	 * @return the value and position correspond with the position in dancinglinks
	 */
	virtual QPair< int, QPair<int, int> > getNumber(int row, int col = 0); // finish

	virtual ListNode* getCol(int col); // finish

	virtual QVector<ListNode*> getRow(int row); // finish

	/**
	 * @brief ~StdSudokuNodesContainer
	 */
	virtual ~StdSudokuNodesContainer(); // finish

private:
	const int SIZE = 9;
	int gridNum;
	int rowSize;
	int colSize;
	ListNode** m_nodes; // (n^3 row) x (restrict col)
	ListNode* m_colNodes; // array of column header
};

#endif // STDSUDOKUNODESCONTAINER_H
