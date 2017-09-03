#include "logiccontroller.h"

#include "solver/solver.h"

LogicController::LogicController(QObject *parent) : \
	QObject(parent)
{
}

void LogicController::startGame(QString level)
{
	m_game = level;
	if(level == "random") {
		// use random generator
		return;
	} else {
		m_mat = FileLoader("./mat" + level + ".txt").load();
		m_size = m_mat.size();
		for(int i = 0; i < m_size; ++i) {
			QVector< QVector<bool> > rowVec;
			for(int j = 0; j < m_size; ++j) {
				QVector<bool> record;
				for(int k = 0; k < m_size; ++k) {
					if(m_mat[i][j] == k + 1) record.push_back(true);
					else record.push_back(false);
				}
				rowVec.push_back(record);
			}
			m_user.push_back(rowVec);
		}
		for(int i = 0; i < m_size; ++i) {
			QVector<bool> prev;
			for(int j = 0; j < m_size; ++j) {
				prev.push_back(false);
			}
			m_preMode.push_back(prev);
		}
		emit showProblem(m_mat);
		Solver sol;
		m_ans = sol(m_mat)[0];
	}
}

void LogicController::setNum(int rank, int num, bool isAdd, bool editMode)
{
	emptyRedoStack();
	m_undoStack_chosen.push(rank);
	m_undoStack_preMode.push(m_preMode);
	m_undoStack_user.push(m_user[rank / m_size][rank % m_size]);
	bool isRemove = !isAdd;
	bool f = false;
	if(m_mat[rank / m_size][rank % m_size]) return;
	if(isRemove) {
		if(m_mat[rank / m_size][rank % m_size]) { // 题面不能被删除
			return;
		} else {
			m_user[rank / m_size][rank % m_size][num - 1] = false;
			f = true;
		}
	} else if(editMode) {
		if(m_preMode[rank / m_size][rank % m_size] && \
			m_user[rank / m_size][rank % m_size][num - 1]) // 如果先前也是编辑模式而且有这个数，其实是移除
		{
			m_user[rank / m_size][rank % m_size][num - 1] = false;
			f = true;
		} else { // 先前是输入模式或没有这个数，都是编辑标记
			m_user[rank / m_size][rank % m_size][num - 1] = true;
			f = false;
		}
		m_preMode[rank / m_size][rank % m_size] = true;
	} else {
		if(m_preMode[rank / m_size][rank % m_size])
		{// 如果先前是编辑模式那么就是直接输入
			for(int i = 0; i < m_size; ++i) m_user[rank / m_size][rank % m_size][i] = false;
			m_user[rank / m_size][rank % m_size][num - 1] = true;
			f = false;
		} else if(!m_user[rank / m_size][rank % m_size][num - 1]) {// 先前是输入模式且没有这个数
			for(int i = 0; i < m_size; ++i) m_user[rank / m_size][rank % m_size][i] = false;
			m_user[rank / m_size][rank % m_size][num - 1] = true;
			f = false;
		} else { // 先前是输入模式且填过这个数了
			for(int i = 0; i < m_size; ++i) m_user[rank / m_size][rank % m_size][i] = false;
			f = true;
		}
		m_preMode[rank / m_size][rank % m_size] = false;
	}
	emit setNumMsg(rank, num, !f, editMode);
	calHighlights(rank);
	m_redoStack_chosen.push(rank);
	m_redoStack_preMode.push(m_preMode);
	m_redoStack_user.push(m_user[rank / m_size][rank % m_size]);
}

void LogicController::check()
{
	QVector<int> wrongGrids;
	for(int i = 0; i < m_size; ++i) {
		for(int j = 0; j < m_size; ++j) {
			if(m_preMode[i][j]) continue;
			bool f = false;
			for(int k = 0; k < m_size; ++k) {
				if(m_user[i][j][k]) f = true;
			}
			if(f && !m_user[i][j][m_ans[i][j] - 1]) wrongGrids.push_back(i*m_size + j);
		}
	}
	emit showWrong(wrongGrids);
}

void LogicController::clearGrid(int rank)
{
	qDebug() << "LogicController::clearGrid called";
	bool haveElem = false;
	for(int i = 0; i < m_size; ++i) {
		if(m_user[rank / m_size][rank % m_size][i]) {
			haveElem = true; break;
		}
	}
	if(!haveElem) return;
	emptyRedoStack();
	m_undoStack_chosen.push(rank);
	m_undoStack_preMode.push(m_preMode);
	m_undoStack_user.push(m_user[rank / m_size][rank % m_size]);
	int row = rank / m_size;
	int col = rank % m_size;
	if(m_mat[row][col]) return;
	for(int i = 0; i < m_size; ++i) {
		m_user[row][col][i] = false;
	}
	emit clearGridMsg(rank);
	m_redoStack_chosen.push(rank);
	m_redoStack_preMode.push(m_preMode);
	m_redoStack_user.push(m_user[rank / m_size][rank % m_size]);
	qDebug() << "LogicController::clearGrid finished";
}

void LogicController::calHighlights(int rank)
{
	qDebug() << "LogicController::calHighlights called";
	int row = rank / m_size;
	int col = rank % m_size;
	int cnt = 0;
	int val;
	QVector<int> ans;
	for(int i = 0; i < m_size; ++i) {
		if(m_user[row][col][i]) {
			cnt++;
			val = i + 1;
		}
	}
	qDebug() << "LogicController::calHighlight, cnt is" << cnt;
	if(cnt != 1 || m_preMode[row][col]) { // 未填或多填或标记模式
		emit highlightGrids(rank, ans);
		return;
	}
	for(int i = 0; i < m_size; ++i) {
		for(int j = 0; j < m_size; ++j) {
			if(!m_preMode[i][j] && m_user[i][j][val - 1]) {
				ans.push_back(i * m_size + j);
			}
		}
	}
	emit highlightGrids(rank, ans);
}

void LogicController::calAnswer()
{
	emptyUndoStack();
	emptyRedoStack();
	for(int i = 0; i < m_size; ++i) {
		for(int j = 0; j < m_size; ++j) {
			for(int k = 0; k < m_size; ++k) {
				m_user[i][j][k] = false;
			}
			m_user[i][j][m_ans[i][j] - 1] = true;
		}
	}
	emit showAnswer(m_ans);
}

void LogicController::restartGame()
{
	emptyUndoStack();
	emptyRedoStack();
	QVector< QVector<bool> > v;
	m_preMode = v;
	QVector< QVector< QVector<bool> > > u;
	m_user = u;
	startGame(m_game);
}

void LogicController::undo()
{
	if(m_undoStack_chosen.empty()) return;
	int rank = m_undoStack_chosen.top();
	m_redoStack_chosen.push(rank);
	m_undoStack_chosen.pop();
	m_preMode = m_undoStack_preMode.top();
	m_redoStack_preMode.push(m_preMode);
	m_undoStack_preMode.pop();

	QVector<bool> state = m_undoStack_user.top();
	m_redoStack_user.push(state);
	m_undoStack_user.pop();

	int row = rank / m_size;
	int col = rank % m_size;
	m_user[row][col] = state;
	for(int k = 0; k < m_size; ++k) {
		emit setNumMsg(rank, k + 1, state[k], m_preMode[row][col]);
	}

	calHighlights(rank);
}

void LogicController::redo()
{
	if(m_redoStack_chosen.empty()) return;
	int rank = m_redoStack_chosen.top();
	m_undoStack_chosen.push(rank);
	m_redoStack_chosen.pop();
	m_preMode = m_redoStack_preMode.top();
	m_undoStack_preMode.push(m_preMode);
	m_redoStack_preMode.pop();

	QVector<bool> state = m_redoStack_user.top();
	m_undoStack_user.push(state);
	m_redoStack_user.pop();

	int row = rank / m_size;
	int col = rank % m_size;
	m_user[row][col] = state;
	for(int k = 0; k < m_size; ++k) {
		emit setNumMsg(rank, k + 1, state[k], m_preMode[row][col]);
	}

	calHighlights(rank);
}

void LogicController::emptyUndoStack()
{
	while(!m_undoStack_chosen.empty()) {
		m_undoStack_chosen.pop();
	}
	while(!m_undoStack_preMode.empty()) {
		m_undoStack_preMode.pop();
	}
	while(!m_undoStack_user.empty()) {
		m_undoStack_user.pop();
	}
}

void LogicController::emptyRedoStack()
{
	while(!m_redoStack_chosen.empty()) {
		m_redoStack_chosen.pop();
	}
	while(!m_redoStack_preMode.empty()) {
		m_redoStack_preMode.pop();
	}
	while(!m_redoStack_user.empty()) {
		m_redoStack_user.pop();
	}
}

