#ifndef NODESCONTAINER_H
#define NODESCONTAINER_H

#include <QVector>
#include <QPair>
#include <QStack>
#include "listnode.h"
#include <QDebug>

class DLNodesContainer
{
public:
	DLNodesContainer();
	virtual ~DLNodesContainer();
	virtual QVector<ListNode*> getRow(int row, int col = 0) = 0;
	virtual ListNode* getCol(int col) = 0;
	virtual QPair< int, QPair<int, int> > getNumber(int row, int col) = 0;

public:
	// have default implement
	virtual void removeRow(int row, QStack<ListNode*>* s = nullptr);
	virtual void removeCol(int col, QStack<ListNode*>* s = nullptr);
	virtual void restoreRow(QStack<ListNode*>* lastRows);
	virtual void restoreCol(QStack<ListNode*>* LastCols);
	virtual ListNode* colHeader();
	virtual ListNode* colTailer();

/* for debug
public:

	void checkNewDL() {
		ListNode* cur = colHeader();
		int cnt1 = 0;
		while(cur->right != colTailer()) {
			++cnt1;
			if(cnt1 > 323) qDebug() << "infinite loop";
			cur = cur->right;
			ListNode* rcur = cur;
			int cnt2 = 0;
			while(rcur->down != cur) {
				cnt2++;
				rcur = rcur->down;
			}
			// if(cnt2 != 9) qDebug() << "column" << cur->colNum << "colsize" << cur->size;
		}
	}
*/

protected:
	ListNode* m_colHeader;
	ListNode* m_colTailer;

};

#endif // NODESCONTAINER_H
