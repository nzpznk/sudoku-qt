#ifndef STDSUDOKUNODESCONTAINER_H
#define STDSUDOKUNODESCONTAINER_H

#include "dlnodescontainer.h"

class StdSudokuNodesContainer : public DLNodesContainer
{
public:
	StdSudokuNodesContainer(const QVector< QVector<int> >& mat);

	/**
	 * @brief getNodes
	 * @param row row number in DancingLinks
	 * @return the Nodes in the same row
	 */
	virtual QVector<ListNode*> getNodes(int row, int col = 0);

	/**
	 * @brief getNumber
	 * @param row
	 * @param col
	 * @return the value and position correspond with the position in dancinglinks
	 */
	virtual QPair< int, QPair<int, int> > getNumber(int row, int col = 0);

	virtual ListNode* colHeader();

	virtual ListNode* colTailer();

	virtual ListNode* getCol(int col);

	/**
	 * @brief ~StdSudokuNodesContainer
	 */
	virtual ~StdSudokuNodesContainer();

private:
	void constructDL();

private:
	const int SIZE = 9;
	int rowSize;
	int colSize;
	ListNode** colNodes;
};

#endif // STDSUDOKUNODESCONTAINER_H
