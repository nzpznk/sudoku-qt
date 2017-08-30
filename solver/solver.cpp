#include "solver.h"

Solver::Solver(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Solver::operator()
 * @details used as function object to solve at most 2 answers of sudoku problem
 * @param mat
 * @return
 */
QVector< QVector< QVector<int> > > Solver::operator()(const QVector<QVector<int> >& mat)
{
	// solve at most 2 answers
	QVector < QVector< QVector<int> > > ans;

	DancingLinks dl(mat);
	recSolve(dl, mat, ans);
	return ans;
}


/**
 * @brief Solver::cntGivenNumber
 * @param mat
 * @return the number of filled place
 */
int Solver::cntGivenNumber(const QVector<QVector<int> >& mat)
{
	int cnt = 0;
	int width = mat.size();
	int height = mat[0].size();
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; ++j) {
			if(mat[i][j] > 0) cnt++;
		}
	}
	return cnt;
}

/**
 * @brief Solver::recSolve Solve the exact cover problem with dancing links
 * @details implementation of algorithm X
 * @param dl
 * @return true if the solution exists
 */
void Solver::recSolve(DancingLinks& dl, QVector< QVector<int> >& mat, QVector < QVector< QVector<int> > >& ans)
{
	if(ans.size() > 1) return;
	if(dl.empty()) {
		ans.push_back(mat);
		return;
	}
	int minCol = dl.chooseCol();
	if(minCol == -1) return; // failed to find an answer

	for(int row : dl.Col(minCol))  {
		dl.solveConflict(row);
		QPair<int, QPair<int, int> > tmp = dl.getVal(row, minCol);
		mat[tmp.second.first][tmp.second.second] = tmp.first;
		recSolve(dl, mat, ans);
		dl.backTrack(); // match with dl.solveConflict
	}
}
