#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QObject>
#include "loader/fileloader.h"
#include <QStack>

const int GAMESIZE = 9;


class LogicController : public QObject
{
	Q_OBJECT
public:
	explicit LogicController(QObject *parent = 0);

signals:
	void showProblem(const QVector< QVector<int> >& mat);
	void setNumMsg(int rank, int num, bool isAdd, bool editMode);
	void showWrong(const QVector<int>& grids);
	void clearGridMsg(int rank);
	void highlightGrids(int rank, const QVector<int>& grids);
	void showAnswer(const QVector<QVector<int> >& ans);
//	void congratulation();

public slots:
	void startGame(QString level); // init the gameboard in logic controller
	void setNum(int rank, int num, bool isAdd, bool editMode); // support undo and redo
	void check(); // check if is correct
	void clearGrid(int rank); // clear all number in the posi; support undo and redo
	void calHighlights(int rank); // calculate the grids that should be highlighted
	void calAnswer(); // will empty undo redo stack
	void restartGame(); // will empty undo redo stack
	void undo();
	void redo();

private:
	void emptyUndoStack();
	void emptyRedoStack();

private:
	QString m_game;
	QVector< QVector<int> > m_mat;
	QVector< QVector<int> > m_ans;
	QVector< QVector< QVector<bool> > > m_user;
	QVector< QVector<bool> > m_preMode; // true is edit mode; false is input mode

	QStack< QVector<bool> > m_undoStack_user; // rank r grid status
	QStack< QVector< QVector<bool> > > m_undoStack_preMode;
	QStack<int> m_undoStack_chosen;
	QStack< QVector<bool> > m_redoStack_user; // rank r grid status
	QStack< QVector< QVector<bool> > > m_redoStack_preMode;
	QStack<int> m_redoStack_chosen;
	int m_emptyPlace;
	int m_size;
};

#endif // LOGICCONTROLLER_H

