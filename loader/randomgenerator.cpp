#include "randomgenerator.h"

RandomGenerator::RandomGenerator(int n) : \
	m_size(n)
{
	for(int i = 0; i < n; ++i) {
		QVector<int> row;
		for(int j = 0; j < n; ++j) {
			row.push_back(0);
		}
		mat.push_back(row);
	}
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

QVector<QVector<int> > RandomGenerator::load()
{
	QVector< QVector< QVector<int> > > ans;
	Solver solve;
	while(ans.size() < 1) {
		randomFill(7);
		ans = solve(mat);
	}
	mat = ans[0];
	int tmp = 0;
	for(int i = 0; i < 100; ++i) {
		int rank = qrand() % 81;
		if(mat[rank / m_size][rank % m_size]) {
			tmp = mat[rank / m_size][rank % m_size];
			mat[rank / m_size][rank % m_size] = 0;
			if(solve(mat).size() != 1) {
				mat[rank / m_size][rank % m_size] = tmp;
			}
		}
	}
	return mat;
}

void RandomGenerator::randomFill(int n)
{
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			mat[i][j] = 0;
		}
	}
	int cnt = 0;
	while(cnt < n) {
		int rank = qrand() % 81;
		int value = qrand() % 9 + 1;
		int row = rank / 9;
		int col = rank % 9;
		if(mat[row][col]) continue;
		else {
			mat[rank / m_size][rank % m_size] = value;
			cnt++;
		}
	}
}
