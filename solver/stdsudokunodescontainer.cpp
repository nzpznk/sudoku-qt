#include "stdsudokunodescontainer.h"

StdSudokuNodesContainer::StdSudokuNodesContainer(const QVector< QVector<int> >&)
{
	colSize = 4 * SIZE * SIZE;
	rowSize = SIZE * SIZE * SIZE;
	m_nodes = new ListNode*[rowSize];
	m_colNodes = new ListNode[colSize];
	for(int i = 0; i < colSize - 1; ++i) {
		m_colNodes[i].down = m_colNodes[i].up = &m_colNodes[i];
		m_colNodes[i].right = &m_colNodes[i + 1];
		m_colNodes[i + 1].left = &m_colNodes[i];
	}
	gridNum = SIZE * SIZE;
	for(int i = 0; i < rowSize; ++i) {
		m_nodes[i] = new ListNode[4];
		for(int j = 0; j < 4; ++j) {
			m_nodes[i][j].rowNum = i;
		}
		int v = i / gridNum;
		int r = i % gridNum;
		int mCol = r % SIZE;
		int mRow = r / SIZE;
		m_colNodes[v + SIZE * mCol].size++;
		m_nodes[i][0].up = m_colNodes[v + SIZE * mCol].up;
		m_nodes[i][0].down = &m_colNodes[v + SIZE * mCol];
		m_colNodes[v + SIZE * mCol].up = &m_nodes[i][0];
		m_nodes[i][0].up->down = &m_nodes[i][0];
		m_nodes[i][0].colNum = v + SIZE * mCol;

		m_colNodes[gridNum + v + SIZE * mRow].size++;
		m_nodes[i][1].up = m_colNodes[gridNum + v + SIZE * mRow].up;
		m_nodes[i][1].down = &m_colNodes[gridNum + v + SIZE * mRow];
		m_colNodes[gridNum + v + SIZE * mRow].up = &m_nodes[i][1];
		m_nodes[i][1].up->down = &m_nodes[i][1];
		m_nodes[i][1].colNum = gridNum + v + SIZE * mRow;

		int nthBigGrid = (mRow % 3) * 3 + mCol % 3;
		m_colNodes[gridNum * 2 + v + SIZE * nthBigGrid].size++;
		m_nodes[i][2].up = m_colNodes[gridNum * 2 + v + SIZE * nthBigGrid].up;
		m_nodes[i][2].down = &m_colNodes[gridNum * 2 + v + SIZE * nthBigGrid];
		m_colNodes[gridNum * 2 + v + SIZE * nthBigGrid].up = &m_nodes[i][2];
		m_nodes[i][2].up->down = &m_nodes[i][2];
		m_nodes[i][2].colNum = gridNum * 2 + v + SIZE * nthBigGrid;

		m_colNodes[gridNum * 3 + mRow * SIZE + mCol].size++;
		m_nodes[i][3].up = m_colNodes[gridNum * 3 + mRow * SIZE + mCol].up;
		m_nodes[i][3].down = &m_colNodes[gridNum * 3 + mRow * SIZE + mCol];
		m_colNodes[gridNum * 3 + mRow * SIZE + mCol].up = &m_nodes[i][3];
		m_nodes[i][3].up->down = &m_nodes[i][3];
		m_nodes[i][3].colNum = gridNum * 3 + mRow * SIZE + mCol;
	}

	m_colHeader = new ListNode;
	m_colTailer = new ListNode;
	m_colHeader->right = &m_colNodes[0];
	m_colHeader->left = nullptr;
	m_colTailer->right = nullptr;
	m_colTailer->left = &m_colNodes[colSize - 1];
	m_colNodes[0].left = m_colHeader;
	m_colNodes[colSize - 1].right = m_colTailer;
}

StdSudokuNodesContainer::~StdSudokuNodesContainer()
{
	for(int i = 0; i < rowSize; ++i) {
		delete[] m_nodes[i];
	}
	delete[] m_nodes;
	m_nodes = nullptr;
	delete m_colHeader;
	m_colHeader = nullptr;
	delete m_colTailer;
	m_colTailer = nullptr;
	delete[] m_colNodes;
	m_colNodes = nullptr;
}

int StdSudokuNodesContainer::getRowNum(int val, int mRow, int mCol)
{
	return val * gridNum + mRow * SIZE + mCol;
}

QPair<int, QPair<int, int> > StdSudokuNodesContainer::getNumber(int row, int col)
{
	int val = row / gridNum + 1;
	row %= gridNum;
	return QPair< int, QPair<int, int> >(val, QPair<int, int>(row / SIZE, row % SIZE));
}

ListNode*StdSudokuNodesContainer::getCol(int col)
{
	return &m_colNodes[col];
}

QVector<ListNode*> StdSudokuNodesContainer::getRow(int row, int)
{
	QVector<ListNode*> ans;
	for(int i = 0; i < 4; ++i) {
		ans.push_back(&m_nodes[row][i]);
	}
	return ans;
}
