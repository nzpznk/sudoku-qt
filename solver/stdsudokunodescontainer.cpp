#include "stdsudokunodescontainer.h"

StdSudokuNodesContainer::StdSudokuNodesContainer(const QVector< QVector<int> >& mat)
{
	colSize = 4 * SIZE * SIZE;
	rowSize = SIZE * SIZE * SIZE;
	colNodes = new ListNode[rowSize];
	for(int i = 0; i < rowSize; ++i) {
		colNodes[i] = new ListNode[4];
		for(int j = 0; j < 4; ++j) {
			colNodes[i][j].rowNum = i;
			colNodes[i][j].right = &colNodes[i][(j + 1) % 4];
			colNodes[i][j].left = &colNodes[i][(4 - j - 1) % 4];
		}
	}
	colHeader = new ListNode[colSize];
	constructDL(mat);
}

QVector<ListNode*> StdSudokuNodesContainer::getNodes(int row, int col)
{
	QVector<ListNode*> sameRowNodes;
	for(int i = 0; i < 4; ++i) {
		sameRowNodes.push_back(&colNodes[row][i]);
	}
	return sameRowNodes;
}

StdSudokuNodesContainer::~StdSudokuNodesContainer()
{
	for(int i = 0; i < rowSize; ++i) {
		delete[] node[i];
	}
	delete[] colHeader;
	delete[] node;
	node = nullptr;
	colHeader = nulptr;
}

void StdSudokuNodesContainer::constructDL()
{
	int gridNum = SIZE * SIZE;
	for(int i = 0; i < colSize; ++i) {
		colHeader[i].left = &colHeader[(i + 1) % colSize];
		colHeader[i].right = &colHeader[(colSize - i) % colSize];
	}
	for(int i = 0; i < colSize; ++i) {
		ListNode* cur = &colHeader[i];
		ListNode* ccur = cur;
		for(int j = 0; j < SIZE; ++j) {
			cur->down = colNodes[j * gridNum + j];
			cur = cur->down;
			cur->up = ccur;
			cur->colNum = i;
			ccur = cur;
		}
		cur->down = &colHeader[i];
		colHeader[i].up = cur;
	}
}

QPair<int, QPair<int, int> > StdSudokuNodesContainer::getNumber(int row, int col)
{
	int gridNum = SIZE * SIZE;
	int val = row / gridNum + 1;
	row %= gridNum;
	return QPair< int, QPair<int, int> >(val, QPair<int, int>(row / SIZE, row % SIZE));
}
