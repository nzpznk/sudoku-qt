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
                m_mat = FileLoader("./////////////////////")
	}
}

void LogicController::changeNum(int val, int row, int col)
{
//	mat[row][col] = val;
//	int collide = testCollide(row, col);
//	if(collide != -1) {
//		emit conflict(row * GAMESIZE + col, collide);
//	}
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

