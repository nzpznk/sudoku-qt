#include "logiccontroller.h"

LogicController::LogicController(QObject *parent) : \
	QObject(parent)
{

}

void LogicController::startGame(QString level)
{
	if(level == "random") {
		// use random generator
		return;
	} else {
		m_mat = FileLoader("./mat" + level).load();
		emit showProblem(m_mat);
	}
}

void LogicController::setBtnActivated(int rank)
{
	m_activated = rank;
	QVector<int> btnRanks;
	int row = rank / 9;
	int col = rank % 9;
	for(int i = 0; i < GAMESIZE; ++i) {
		btnRanks.push_back(row * 9 + i);
		btnRanks.push_back(GAMESIZE * i + col);
	}

	for(int i = 0; i < GAMESIZE; ++i) {
		for(int j = 0; j < GAMESIZE; ++j) {
			if(m_user[i][j] == m_user[rank / GAMESIZE][rank % GAMESIZE]) {
				btnRanks.push_back(GAMESIZE * i + j);
			}
		}
	}
	emit highlightGrids(rank, btnRanks);
}

void LogicController::changeNum(int val, int row, int col)
{
	mat[row][col] = val;
	int collide = testCollide(row, col);
	if(collide != -1) {
		emit conflict(row * GAMESIZE + col, collide);
	}
}

int LogicController::testCollide(int row, int col)
{
//	for(int i = 0; i < GAMESIZE; ++i) {
//		if(i == row) continue;
//		if(m_mat[row][col] == m_mat[i][col]) {
//			return i * GAMESIZE + col;
//		}
//	}
//	for(int i = 0; i < GAMESIZE; ++i) {
//		if(i == col) continue;
//		if(m_mat[i][col] == m_mat[row][col]) {
//			return row * GAMESIZE + i;
//		}
//	}
//	for(int)

	return 0;
}

