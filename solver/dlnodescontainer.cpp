#include "dlnodescontainer.h"
#include <QDebug>

DLNodesContainer::DLNodesContainer()
{

}

DLNodesContainer::~DLNodesContainer()
{

}

void DLNodesContainer::removeRow(int row, QStack<ListNode*>* s)
{
	QVector<ListNode*> rowVec = getRow(row);
	//qDebug() << "begin remove row " << rowVec[0]->rowNum;
	for(ListNode* tmp : rowVec) {
		if(tmp->removed) {
			qDebug() << "list node" << "(row, col) = (" << tmp->rowNum << "," << tmp->colNum << ") removed twice";
		}
		getCol(tmp->colNum)->size--;
		tmp->up->down = tmp->down;
		tmp->down->up = tmp->up;
		tmp->removed = true;
		if(s) s->push(tmp);
	}
	//qDebug() << "removed row" << row;
}

void DLNodesContainer::removeCol(int col, QStack<ListNode*>* s)
{
	ListNode* tmp = getCol(col);
	if(tmp->removed) {
		qDebug() << "column" << tmp->colNum << "removed twice";
	}
	tmp->left->right = tmp->right;
	tmp->right->left = tmp->left;
	tmp->removed = true;
	if(s) s->push(tmp);
}

void DLNodesContainer::restoreRow(QStack<ListNode*>* lastRows)
{
	ListNode* tmp = nullptr;
	while(!lastRows->empty()) {
		tmp = lastRows->top();
		lastRows->pop();
		getCol(tmp->colNum)->size++;
		tmp->up->down = tmp;
		tmp->down->up = tmp;
		tmp->removed = false;
	}
}

void DLNodesContainer::restoreCol(QStack<ListNode*>* lastCols)
{
	ListNode* tmp = nullptr;
	while(!lastCols->empty()) {
		tmp = lastCols->top();
		lastCols->pop();
		tmp->left->right = tmp;
		tmp->right->left = tmp;
		tmp->removed = false;
	}
}

ListNode*DLNodesContainer::colHeader() { return m_colHeader; }

ListNode*DLNodesContainer::colTailer() { return m_colTailer; }
