#ifndef NODESCONTAINER_H
#define NODESCONTAINER_H

#include <QVector>
#include <QPair>
#include <QStack>
#include "listnode.h"

class DLNodesContainer
{
public:
	DLNodesContainer();
	virtual ~DLNodesContainer() = 0;
	virtual QVector<ListNode*> getRow(int row, int col = 0) = 0;
	virtual ListNode* getCol(int col) = 0;
	virtual QPair< int, QPair<int, int> > getNumber(int row, int col) = 0;

public:
	// have default implement
	virtual void removeRow(int row, QStack<ListNode*>* s = nullptr);
	virtual void removeCol(int col, QStack<ListNode*>* s = nullptr);
	virtual void restoreRow(QStack<ListNode*>* lastRows);
	virtual void restoreCol(QStack<ListNode*>* LastCols);
	virtual ListNode* colHeader() { return m_colHeader; }
	virtual ListNode* colTailer() { return m_colTailer; }

protected:
	ListNode* m_colHeader;
	ListNode* m_colTailer;

};

#endif // NODESCONTAINER_H
