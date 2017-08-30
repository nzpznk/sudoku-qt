#ifndef NODESCONTAINER_H
#define NODESCONTAINER_H

#include <QVector>
#include <QPair>
#include "listnode.h"

class DLNodesContainer
{
public:
	DLNodesContainer();
	virtual QVector<ListNode*> getNodes(int row, int col = 0) = 0;
	virtual QPair< int, QPair<int, int> > getNumber(int row, int col) = 0;
	virtual ~DLNodesContainer() = 0;
	virtual ListNode* colHeader();
	virtual ListNode* colTailer();
	virtual ListNode* getCol(int col);

private:
	ListNode* m_colHeader;
	ListNode* m_colTailer;

};

#endif // NODESCONTAINER_H
