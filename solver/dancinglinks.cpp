#include "dancinglinks.h"

DancingLinks::DancingLinks(const QVector< QVector<int> >& mat)
{
	nodes = new StdSudokuNodesContainer(mat);
	m_rowStack = new QStack< QStack<ListNode*>* >;
	m_colStack = new QStack< QStack<ListNode*>* >;

	for(int i = 0; i < mat.size(); ++i) {
		for(int j = 0; j < mat[i].size(); ++j) {
			if(mat[i][j]) solveConflict(getRowNum(mat[i][j], i, j), false);
		}
	}
}

DancingLinks::~DancingLinks()
{
	QStack<ListNode*>* tmp = nullptr;
	if(!m_rowStack->empty() || !m_colStack->empty()) {
		qDebug << "m_stack of dancing links is not empty!" << "please check!";
	}
	while(!m_rowStack->empty()) {
		tmp = m_rowStack->top();
		m_rowStack->pop();
		delete tmp;
	}
	while(!m_colStack->empty()) {
		tmp = m_colStack->top();
		m_colStack->pop();
		delete tmp;
	}
	tmp = nullptr;
	delete m_rowStack;
	delete m_colStack;
}

bool DancingLinks::empty()
{
	return nodes->colHeader()->right == nodes->colTailer();
}

int DancingLinks::chooseCol()
{
	int col = 0;
	int minSize = 100000000;
	ListNode* tailer = nodes->colTailer();
	ListNode* cur = nodes->colHeader();
	while(cur->right != tailer) {
		cur = cur->right;
		if(cur->size < minSize) {
			minSize = cur->size;
			col = cur->colNum;
		}
	}
	if(minSize > 0) return col;
	else return -1;
}

QVector<int> DancingLinks::Col(int rank)
{
	qDebug() << "Col(" << rank << ") called";
	ListNode* col = nodes->getCol(col);
	ListNode* cur = col;
	QVector<int> ans;
	while(cur->down != col) {
		cur = cur->down;
		ans.push_back(cur->rowRank);
	}
	qDebug() << "Col(" << rank << ") finished";
	return ans;
}

QVector<int> DancingLinks::Row(int rank)
{
	qDebug() << "Row(" << rank << ") called";
	QVector<ListNode*> rowNodeVec = nodes->getRow(rank);
	QVector<int> ans;
	for(ListNode* tmp : rowNodeVec) {
		ans.push_back(tmp->colNum);
	}
	return ans;
}

void DancingLinks::solveConflict(int row, bool trace)
{
	// deleted in backTrack()
	QStack<ListNode*>* removedRows = new QStack< ListNode* >;
	QStack<ListNode*>* removedCols = new QStack< ListNode* >;

	for(int col : Row(row)) {
		for(int rrow : Col(col)) {
			if(trace) removeRow(rrow, removedRows);
			else removeRow(rrow);
		}
		if(trace) removeCol(col, removedCols);
		else removeCol(col);
	}
	if(trace) {
		m_rowStack->push(removedRows);
		m_colStack->push(removedCols);
	} else {
		delete removedRows;
		delete removedCols;
	}
}

void DancingLinks::backTrack()
{
	QStack< ListNode* >* lastRows = m_rowStack->top();
	QStack< ListNode* >* lastCols = m_colStack->top();
	ListNode* tmp = nullptr;
	m_rowStack->pop();
	m_colStack->pop();
	nodes->restoreRow(lastRows);
	nodes->restoreCol(lastCols);

	delete lastRows;
	delete lastCols;
}

QPair<int, QPair<int, int> > DancingLinks::getVal(int row, int col)
{
	return nodes->getNumber(row, col);
}

void DancingLinks::removeRow(int row, QStack<ListNode*>* s)
{
	nodes->removeRow(row, s);
}

void DancingLinks::removeCol(int col, QStack<ListNode*>* s)
{
	nodes->removeCol(col, s);
}
