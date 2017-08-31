#include "dlnodescontainer.h"

DLNodesContainer::DLNodesContainer()
{

}

void DLNodesContainer::removeRow(int row, QStack<ListNode*>* s)
{
	QVector<ListNode*> rowVec = getRow(row);
	qDebug() << "begin remove row " << rowVec[0]->rowNum;
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
	qDebug() << "removed row" << row;
}

void DLNodesContainer::removeCol(int col, QStack<ListNode*>* s)
{
	ListNode* tmp = getCol(col);
	qDebug() << "begin remove column" << col;
	if(tmp->removed) {
		qDebug() << "column" << tmp->colNum << "removed twice";
	}
	tmp->left->right = tmp->right;
	tmp->right->left = tmp->left;
	tmp->removed = true;
	qDebug() << "removed column" << tmp->colNum;
}

void DLNodesContainer::restoreRow(QStack<ListNode*>* lastRows)
{
	ListNode* tmp = nullptr;
	while(!lastRows->empty()) {
		tmp = lastRows->top();
		getCol(tmp->colNum)->size++;
		tmp->up->down = tmp;
		tmp->down->up->tmp;
		tmp->removed = false;
	}
}

void DLNodesContainer::restoreCol(QStack<ListNode*>* lastCols)
{
	ListNode* tmp = nullptr;
	while(!lastCols->empty()) {
		tmp = lastCols->top();
		tmp->left->right = tmp;
		tmp->right->left = tmp;
		tmp->removed = false;
	}
}
